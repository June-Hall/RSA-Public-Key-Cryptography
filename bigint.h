#ifndef BIGINT_H
#define BIGINT_H

class BigInt {
    std::string digits;
    bool isNegative = false;

public:
    BigInt(unsigned long long n = 0);

    BigInt(std::string &s);

    BigInt(const char *s);

    BigInt(const BigInt &a);

    BigInt(BigInt&& other);

    // Helper Functions:

    friend void divide_by_2(BigInt &a);

    friend bool Null(const BigInt &a);

    bool null() const;

    friend int Length(const BigInt &a);

    int length() const;

    bool negative() const;

    BigInt abs();

    BigInt abs() const; 

    static void swap(BigInt& a, BigInt& b);

    int operator[](const int index) const;

    // Operator Overloading:

    BigInt &operator=(const BigInt &a);

    BigInt &operator=(const unsigned long long nr);

    BigInt &operator++();

    BigInt operator++(int temp);

    BigInt &operator--();

    BigInt operator--(int temp);

    friend BigInt &operator+=(BigInt &a, const BigInt &b);

    friend BigInt operator+(const BigInt &a, const BigInt &b);

    friend BigInt operator-(const BigInt &a, const BigInt &b);

    friend BigInt &operator-=(BigInt &a, const BigInt &b);

    friend bool operator==(const BigInt &a, const BigInt &b);

    friend bool operator!=(const BigInt &a, const BigInt &b);

    friend bool operator>(const BigInt &a, const BigInt &b);

    friend bool operator>=(const BigInt &a, const BigInt &b);

    friend bool operator<(const BigInt &a, const BigInt &b);

    friend bool operator<=(const BigInt &a, const BigInt &b);

    friend BigInt &operator*=(BigInt &a, const BigInt &b);

    friend BigInt operator*(const BigInt &a, const BigInt &b);

    friend BigInt &operator/=(BigInt &a, const BigInt &b);

    friend BigInt operator/(const BigInt &a, const BigInt &b);

    friend BigInt operator%(const BigInt &a, const BigInt &b);

    friend BigInt &operator%=(BigInt &a, const BigInt &b);

    friend BigInt &operator^=(BigInt &base, const BigInt &b);

    friend BigInt operator^(BigInt &base, const BigInt &b);

    // Read and Write:
    
    friend std::istream &operator>>(std::istream &in, BigInt &a);

    friend std::ostream &operator<<(std::ostream &out, const BigInt &a);

    // Others:

    static BigInt pow(const BigInt& base, const BigInt& exponent, const BigInt& modulus);

    void randomize(int bits);

    static BigInt random_bigint(int bits);

    static BigInt random_bigint(BigInt max);

    int num_bits();
};

#endif