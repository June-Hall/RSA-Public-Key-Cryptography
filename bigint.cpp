#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "bigint.h"
 
BigInt::BigInt(std::string &s) {
    digits = "";
    int n = s.size();
    int startIndex = 0;

    // 检查是否有负号
    if (n > 0 && s[0] == '-') {
        isNegative = true;
        startIndex = 1;
    } else {
        isNegative = false;
    }

    for (int i = n - 1; i >= startIndex; i--) {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}


BigInt::BigInt(unsigned long long nr) {
    // std::cout << nr << " ";
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}

BigInt::BigInt(const char *s) {
    digits = "";
    int startIndex = 0;

    if (s[0] == '-') {
        isNegative = true;
        startIndex = 1;
    }

    for (int i = strlen(s) - 1; i >= startIndex; i--) {
        if (!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}

BigInt::BigInt(const BigInt &a) {
    digits = a.digits;
    isNegative = a.isNegative;
}

BigInt::BigInt(BigInt&& other) {
    digits = std::move(other.digits);
    other.digits.clear();
    isNegative = other.isNegative;
    other.isNegative=false;
}


bool Null(const BigInt &a) {
    if (a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}

bool BigInt::null() const {
    if (this->digits.size() == 1 && this->digits[0] == 0)
        return true;
    return false;
}

int Length(const BigInt &a) {
    return a.digits.size();
}

int BigInt::length() const {
    return this->digits.size();
}

bool BigInt::negative() const {
    return this->isNegative;
}

int BigInt::operator[](const int index) const {
    if (digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}

bool operator==(const BigInt &a, const BigInt &b) {
    if (a.isNegative == b.isNegative && a.digits == b.digits)
    {
        return true;
    }
    return false;
}

bool operator!=(const BigInt &a, const BigInt &b) {
    return !(a == b);
}

bool operator<(const BigInt &a, const BigInt &b) {
    if (a.isNegative && !b.isNegative) {
        return true;
    }
    if (!a.isNegative && b.isNegative) {
        return false;
    }
    
    int n = Length(a), m = Length(b);
    if (n != m) {
        if (a.isNegative) {
            return n > m;
        }
        return n < m;
    }
    
    if (a.isNegative) {
        for (int i = n - 1; i >= 0; i--) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] > b.digits[i];
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
    }
    
    return false;
}


bool operator>(const BigInt &a, const BigInt &b) {
    return b < a;
}

bool operator>=(const BigInt &a, const BigInt &b) {
    return !(a < b);
}

bool operator<=(const BigInt &a, const BigInt &b) {
    return !(a > b);
}

BigInt &BigInt::operator=(const BigInt &a) {
    digits = a.digits;
    isNegative = a.isNegative;
    return *this;
}

BigInt &BigInt::operator=(const unsigned long long nr) {
    if (nr == 0)
        *this = BigInt();
    else
        *this = BigInt(nr);
    return *this;
}

BigInt &BigInt::operator++() {
    if (!isNegative) {
        int i, n = digits.size();
        for (i = 0; i < n && digits[i] == 9; i++)
            digits[i] = 0;
        if (i == n)
            digits.push_back(1);
        else
            digits[i]++;
    } else {
        int i, n = digits.size();
        for (i = 0; i < n && digits[i] == 0; i++)
            digits[i] = 9;
        if (i == n) {
            digits.push_back(9);
        } else {
            digits[i]--;
        }
    }
    return *this;
}

BigInt BigInt::operator++(int temp) {
    BigInt aux;
    aux = *this;
    ++(*this);
    return aux;
}

BigInt &BigInt::operator--() {
    if (!isNegative) {
        if (digits[0] == 0 && digits.size() == 1)
            throw("UNDERFLOW");
        int i, n = digits.size();
        for (i = 0; digits[i] == 0 && i < n; i++)
            digits[i] = 9;
        digits[i]--;
        if (n > 1 && digits[n - 1] == 0)
            digits.pop_back();
    } else {
        int i, n = digits.size();
        for (i = 0; i < n && digits[i] == 9; i++)
            digits[i] = 0;
        if (i == n)
            digits.push_back(1);
        else
            digits[i]++;
    }
    return *this;
}

BigInt BigInt::operator--(int temp) {
    BigInt aux;
    aux = *this;
    --(*this);
    return aux;
}

BigInt &operator+=(BigInt &a, const BigInt &b) {
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if (m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    if (a.isNegative != b.isNegative) {
        // 如果两个数的符号不同，执行减法操作
        if (a < b) {
            a.isNegative = b.isNegative;
            for (i = 0; i < n; i++) {
                if (i < m)
                    s = (b.digits[i] - a.digits[i]) + t;
                else
                    s = -a.digits[i] + t;
                if (s < 0)
                    s += 10, t = -1;
                else
                    t = 0;
                a.digits[i] = s;
            }
        } else {
            for (i = 0; i < n; i++) {
                if (i < m)
                    s = (a.digits[i] - b.digits[i]) + t;
                else
                    s = a.digits[i] + t;
                if (s < 0)
                    s += 10, t = -1;
                else
                    t = 0;
                a.digits[i] = s;
            }
        }
    } else {
        // 如果两个数的符号相同，执行加法操作
        for (i = 0; i < n; i++) {
            if (i < m)
                s = (a.digits[i] + b.digits[i]) + t;
            else
                s = a.digits[i] + t;
            t = s / 10;
            a.digits[i] = (s % 10);
        }
    }
    if (t)
        a.digits.push_back(t);
    return a;
}

BigInt operator+(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
}

BigInt &operator-=(BigInt &a, const BigInt &b) {
    if (a.isNegative != b.isNegative) {
        a += b;
    } else {
        if (a < b) {
            BigInt temp(b);
            temp -= a;
            a = temp;
            a.isNegative = !a.isNegative;
        } else {
            int n = Length(a), m = Length(b);
            int i, t = 0, s;
            for (i = 0; i < n; i++) {
                if (i < m)
                    s = a.digits[i] - b.digits[i] + t;
                else
                    s = a.digits[i] + t;
                if (s < 0)
                    s += 10, t = -1;
                else
                    t = 0;
                a.digits[i] = s;
            }
            while (n > 1 && a.digits[n - 1] == 0)
                a.digits.pop_back(), n--;
        }
    }
    return a;
}


BigInt operator-(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}

BigInt &operator*=(BigInt &a, const BigInt &b) {
    if (Null(a) || Null(b)) {
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    std::vector<int> v(n + m, 0);
    bool resultIsNegative = (a.isNegative != b.isNegative);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i + j] += (a.digits[i]) * (b.digits[j]);
        }
    }

    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++) {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i];
    }

    for (int i = n - 1; i >= 1 && !v[i]; i--) {
        a.digits.pop_back();
    }

    a.isNegative = resultIsNegative;

    return a;
}


BigInt operator*(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

BigInt &operator/=(BigInt &a, const BigInt &b) {
    if (Null(b))
        throw("Arithmetic Error: Division By 0");

    bool resultIsNegative = (a.isNegative != b.isNegative);

    if (a.isNegative) {
        a.isNegative = false;
    }
    if (b.isNegative) {
        a.isNegative = true;
    }

    if (a < b) {
        a = BigInt();
        a.isNegative = resultIsNegative;
        return a;
    }

    if (a == b) {
        a = BigInt(1);
        a.isNegative = resultIsNegative;
        return a;
    }

    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    std::vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }

    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }

    a.digits.resize(cat.size());
    for (i = 0; i < lgcat; i++) {
        a.digits[i] = cat[lgcat - i - 1];
    }
    a.digits.resize(lgcat);

    a.isNegative = resultIsNegative;

    return a;
}

BigInt operator/(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp /= b;
    return temp;
}

BigInt &operator%=(BigInt &a, const BigInt &b) {
    if (Null(b))
        throw("Arithmetic Error: Division By 0");

    if (a.isNegative) {
        a.isNegative = false;
    }
    if (b.isNegative) {
        a.isNegative = false;
    }

    if (a < b) {
        return a;
    }

    if (a == b) {
        a = BigInt();
        return a;
    }

    int i, lgcat = 0, cc;
    int n = Length(a), m = Length(b);
    std::vector<int> cat(n, 0);
    BigInt t;
    for (i = n - 1; t * 10 + a.digits[i] < b; i--) {
        t *= 10;
        t += a.digits[i];
    }

    for (; i >= 0; i--) {
        t = t * 10 + a.digits[i];
        for (cc = 9; cc * b > t; cc--);
        t -= cc * b;
        cat[lgcat++] = cc;
    }

    a = t;

    return a;
}


BigInt operator%(const BigInt &a, const BigInt &b) {
    BigInt temp;
    temp = a;
    temp %= b;
    return temp;
}

BigInt &operator^=(BigInt &a, const BigInt &b) {
    if (a.null() && b.null()) {
        throw("Arithmetic Error: 0^0 is undefined");
    }

    if (b.negative()) {
        throw("Arithmetic Error: Negative exponent is not supported");
    }

    BigInt Exponent, Base(a);
    Exponent = b;
    a = 1;

    while (!Null(Exponent)) {
        if (Exponent[0] & 1) {
            a *= Base;
        }
        Base *= Base;
        divide_by_2(Exponent);
    }

    return a;
}

BigInt operator^(BigInt &a, const BigInt &b) {
    BigInt temp(a);
    temp ^= b;
    return temp;
}

void divide_by_2(BigInt &a) {
    int add = 0;
    for (int i = a.digits.size() - 1; i >= 0; i--) {
        int digit = (a.digits[i] >> 1) + add;
        add = ((a.digits[i] & 1) * 5);
        a.digits[i] = digit;
    }
    while (a.digits.size() > 1 && !a.digits.back())
        a.digits.pop_back();
}

std::istream &operator>>(std::istream &in, BigInt &a) {
    std::string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const BigInt &a) {
    for (int i = a.digits.size() - 1; i >= 0; i--)
        out << (short) a.digits[i];
    return out;
}

BigInt BigInt::pow(const BigInt& base, const BigInt& exponent, const BigInt& modulus) {
    BigInt result = BigInt(1);
    BigInt baseCopy = base % modulus;

    BigInt exp(exponent);
    while (!Null(exp)) {
        if ((exp % BigInt(2))[0] == 1) {
            result = (result * baseCopy) % modulus;
        }
        exp /= 2;
        baseCopy = (baseCopy * baseCopy) % modulus;
    }

    return result;
}

void BigInt::randomize(int bits) {
    std::string digits;

    for(int i = 0; i < bits; i++) { 
        digits += (rand() % 10 + '0');
    }

    *this = BigInt(digits);
}

BigInt BigInt::random_bigint(int bits) {
    BigInt result;
    result.randomize(bits);
    return result; 
}

int BigInt::num_bits() {
  // 找到最高位数字
  int index = length() - 1;
  while (index >= 0 && (*this)[index] == 0) {
    index--; 
  }

  // 计算二进制位数
  if (index < 0) return 0; // 特殊情况:0
  int bit = index * log10(2); // 每位数字对应log10(2)个二进制位
  bit += floor(log10((*this)[index])); // 加上最高位的位数contribution

  return bit + 1; // 加1是因为从1开始计数  
}

BigInt BigInt::random_bigint(BigInt max) {
  int num_bits = max.num_bits();
  // std::cout << "num_bits = " << num_bits << std::endl;

  int rand_bits = rand() % num_bits + 1;
  // std::cout << "rand_bits = " << rand_bits << std::endl;

  BigInt result;

  result.randomize(rand_bits);

  if (result > max) {
    result = result % max;
  }
  // std::cout << "result = " << result << std::endl;
  return result;
}
