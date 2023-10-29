#include <iostream>
#include <string>
#include "rsa.h"

int main() {
    BigInt x("79380248390522737902399703986576");
    int bits = x.num_bits();
    std::cout << "bits = " << bits << std::endl;
    BigInt y(2);
    y ^= BigInt(10);
    std::cout << "y = " << y << std::endl;
    std::cout << "x > y = " << (x > y) << std::endl;

    BigInt p, q, n, e, d;
    generate_keys(p, q, n, e, d);

    BigInt plaintext = 12345;
    BigInt ciphertext = rsa_encrypt(plaintext, e, n);
    BigInt decrypted = rsa_decrypt(ciphertext, d, n);

    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;
    return 0;

  return 0;
}