#include <iostream>
#include <string>
#include "bigint.h"
#include "prime.h"


int main() {
    // 测试随机函数
    // BigInt r1 = BigInt::random_bigint(32);
    // BigInt r2 = BigInt::random_bigint(32);
    // assert(r1 != r2);

    // std::cout << "r1 = " << r1 << std::endl;
    // std::cout << "r2 = " << r2 << std::endl;

    int bits = 512;  // 生成素数的位数
    int k = 10;     // Miller-Rabin测试重复次数

    // 测试生成一个素数
    BigInt prime = GenerateRandomPrime(bits, k);
    std::cout << "Random prime: " << prime << std::endl;

    // 测试生成两个素数
    std::pair<BigInt, BigInt> primes = GenerateRandomPrimes(bits, k);

    std::cout << "First prime: " << primes.first << std::endl;
    std::cout << "Second prime: " << primes.second << std::endl;

    if (IsClose(primes.first, primes.second, bits)) {
        std::cout << "Generated primes are too close." << std::endl;
    } else {
        std::cout << "Generated primes are not too close." << std::endl;
    }

    return 0;
}