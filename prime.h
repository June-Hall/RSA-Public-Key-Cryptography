#ifndef PRIME_H
#define PRIME_H

#include "bigint.h"

bool MillerRabinTest(const BigInt& n, int k);

BigInt GenerateRandomPrime(int bits, int k);

std::pair<BigInt, BigInt> GenerateRandomPrimes(int bits, int k);

bool IsClose(const BigInt& a, const BigInt& b, const int bits);

#endif