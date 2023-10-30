#include <iostream>
#include <string>
#include "rsa.h"
#include "bigint.h"
#include "prime.h"

BigInt gcd(BigInt a, BigInt b) {
    if (b.length() == 1 && b[0] == 0) return a;
    return gcd(b, a % b); 
}

// BigInt modular_inverse(BigInt a, BigInt b) {
//     for (BigInt x(1); x < b; x++) {
//         std::cout << "x = " << x << std::endl;
//         std::cout << "(a * x) % b = " << (a * x) % b << std::endl;
//         if ((a * x) % b == 1) {
//             return x;
//         }
//     }
//     throw std::invalid_argument("No modular inverse exists");
// }

BigInt extended_gcd(BigInt a, BigInt m, BigInt &x, BigInt &y) {
    if (a.null()) {
        x = 0;
        y = 1;
        return m;
    }

    BigInt x1, y1;
    BigInt gcd = extended_gcd(m % a, a, x1, y1);

    x = y1 - (m / a) * x1;
    y = x1;

    return gcd;
}

BigInt modular_inverse(BigInt a, BigInt m) {
    BigInt x, y;
    BigInt gcd = extended_gcd(a, m, x, y);

    if (gcd != BigInt(1)) {
        // Modular inverse doesn't exist
        return BigInt();
    }

    // Ensure x is positive
    while (x.negative() || x.null()) {
        x += m;
    }

    return x;
}




// 生成 RSA 公钥和私钥
void generate_keys(BigInt& p, BigInt& q, BigInt& n, BigInt& e, BigInt& d, bool is_generated) {
    if (!is_generated) {
        int bits = 8;
        int k = 10; 
        std::pair<BigInt, BigInt> primes = GenerateRandomPrimes(bits / 2, k);
    
        p = primes.first;
        q = primes.second;
    }

    // 计算 n，n 是 p 和 q 的乘积
    n = p * q;

    // 计算 Euler 函数 φ(n)
    BigInt phi_n = (p - 1) * (q - 1);
    std::cout << "phi_n = " << phi_n << std::endl;
    
    // 选择一个加密指数 e
    // 确保 e 与 φ(n) 互质，且 1 < e < φ(n)
    e = BigInt::random_bigint(phi_n - BigInt(1));
    while (gcd(e, phi_n) != 1) {
        // std::cout << "e = " << e << std::endl;
        // std::cout << "gcd = " << gcd(e, phi_n) << std::endl;
        e = BigInt::random_bigint(phi_n - BigInt(1));
    }
    // std::cout << "hr" << std::endl;
    // 使用扩展欧几里得算法计算解密指数 d
    // d ≡ e^(-1) (mod φ(n))
    while(d.negative() || d.null()) {
        d = BigInt();
        d = modular_inverse(e, phi_n);
        std::cout << "d = " << d << std::endl;
        std::cout << "d.negative() = " << d.negative() << std::endl;
        std::cout << "d.null() = " << d.null() << std::endl;
    }

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "d = " << d << std::endl;
    
}

// 使用 RSA 公钥加密消息
BigInt rsa_encrypt(const BigInt& message, const BigInt& e, const BigInt& n) {
    // 密文 = message ^ e % n
    return BigInt::pow(message, e, n);
}

// 使用 RSA 私钥解密消息
BigInt rsa_decrypt(const BigInt& ciphertext, const BigInt& d, const BigInt& n) {
    // 消息 = ciphertext ^ d % n
    return BigInt::pow(ciphertext, d, n);
}
