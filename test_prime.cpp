#include <iostream>
#include <string>
#include "bigint.h"
#include "prime.h"


int main() {
    // 测试随机函数
    BigInt r1 = BigInt::random_bigint(1024);
    BigInt r2 = BigInt::random_bigint(1024);
    // assert(r1 != r2);

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;

    int bits = 1024;  // 生成128位的素数
    int k = 10;     // Miller-Rabin测试重复次数

    BigInt prime = GenerateRandomPrime(bits, k);
    std::cout << "Random prime: " << prime << std::endl;

    return 0;
}
