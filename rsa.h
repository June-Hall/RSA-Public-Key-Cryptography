#ifndef RSA_H
#define RSA_H

#include "bigint.h"
#include "prime.h"

BigInt gcd(BigInt a, BigInt b);

BigInt modular_inverse(BigInt a, BigInt b);

void generate_keys(BigInt& p, BigInt& q, BigInt& n, BigInt& e, BigInt& d, bool is_generated=false);

BigInt rsa_encrypt(const BigInt& message, const BigInt& e, const BigInt& n);

BigInt rsa_decrypt(const BigInt& ciphertext, const BigInt& d, const BigInt& n);

#endif