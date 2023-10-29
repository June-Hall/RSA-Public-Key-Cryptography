#include <iostream>
#include <random>
#include <ctime>

#include "bigint.h"
#include "prime.h"

// Miller-Rabin素数测试算法
bool MillerRabinTest(const BigInt& n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    BigInt d = n - 1;
    while ((d % BigInt(2))[0] == 0) {
        divide_by_2(d);
    }

    auto Witness = [n, d](const BigInt& a) {
        BigInt x = BigInt::pow(a, d, n);
        if (x == 1 || x == n - 1) return true;

        BigInt dp = d;
        while (dp != n - 1) {
            x = (x * x) % n;
            dp *= 2;

            if (x == 1) return false;
            if (x == n - 1) return true;
        }

        return false;
    };

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < k; i++) {
        BigInt a = BigInt::random_bigint(n.length()); // 随机选择测试基数
        if (!Witness(a)) return false;
    }

    return true;
}

// 生成一个随机的素数
BigInt GenerateRandomPrime(int bits, int k) {
    BigInt candidate = BigInt::random_bigint(bits);
    if ((candidate % BigInt(2))[0] == 0) candidate += 1;  // 确保生成的数是奇数

    while (true) {
        if (MillerRabinTest(candidate, k)) {
            return candidate;
        }
        candidate += 2;  // 尝试下一个奇数
    }
}
