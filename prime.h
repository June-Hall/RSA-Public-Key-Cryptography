#ifndef PRIME_H
#define PRIME_H

#include "bigint.h"

bool MillerRabinTest(const BigInt& n, int k);

BigInt GenerateRandomPrime(int bits, int k);

#endif