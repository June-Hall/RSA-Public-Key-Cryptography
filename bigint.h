#ifndef BIGINT_H
#define BIGINT_H

class BigInt {
    std::string digits;

public:
    /**
     * @brief BigInt 类表示大整数的数据类型。支持大整数的各种数学运算。
     * 
     * @param n 初始值，默认为 0。
     */
    BigInt(unsigned long long n = 0);

    /**
     * @brief BigInt 类的构造函数。使用字符串初始化 BigInt 对象。
     * 
     * @param s 输入的字符串，表示大整数。
     */
    BigInt(std::string &s);

    /**
     * @brief BigInt 类的构造函数。使用 C 风格字符串初始化 BigInt 对象。
     * 
     * @param s 输入的 C 风格字符串，表示大整数。
     */
    BigInt(const char *s);

    /**
     * @brief BigInt 类的复制构造函数。使用另一个 BigInt 对象初始化 BigInt 对象。
     * 
     * @param a 要复制的 BigInt 对象。
     */
    BigInt(const BigInt &a);

    /**
     * @brief BigInt 类的移动构造函数。使用临时 BigInt 对象初始化 BigInt 对象。
     * 
     * @param other 要复制的 BigInt 对象。
     */
    BigInt(BigInt&& other);

    // Helper Functions:

    /**
     * @brief 除以 2：将 BigInt 对象除以 2，向下取整。
     * 
     * @param a BigInt 对象。
     */
    friend void divide_by_2(BigInt &a);

    /**
     * @brief 是否为零：检查 BigInt 对象是否为零。
     * 
     * @param a BigInt 对象。
     * @return 如果 BigInt 为零，则返回 true；否则返回 false。
     */
    friend bool Null(const BigInt &a);

    /**
     * @brief 获取 BigInt 对象的长度。
     * 
     * @param a BigInt 对象。
     * @return BigInt 对象的长度。
     */
    friend int Length(const BigInt &a);

    /**
     * @brief 获取 BigInt 对象的指定索引处的数字。
     * 
     * @param index 索引。
     * @return BigInt 对象在给定索引处的数字。
     */
    int operator[](const int index) const;

    // Operator Overloading:

    /**
     * @brief 运算符重载：直接赋值。
     * 
     * @param a BigInt 对象。
     * @return 修改后的 BigInt 对象。
     */
    BigInt &operator=(const BigInt &a);

    /**
     * @brief 后置自增运算符。
     * 
     * @return 修改后的 BigInt 对象。
     */
    BigInt &operator++();

    /**
     * @brief 前置自增运算符。
     * 
     * @param temp 用于区分前置和后置运算符的临时参数。
     * @return 修改后的 BigInt 对象。
     */
    BigInt operator++(int temp);

    /**
     * @brief 前置自减运算符。
     * 
     * @return 修改后的 BigInt 对象。
     */
    BigInt &operator--();

    /**
     * @brief 后置自减运算符。
     * 
     * @param temp 用于区分前置和后置运算符的临时参数。
     * @return 修改后的 BigInt 对象。
     */
    BigInt operator--(int temp);

    /**
     * @brief 运算符重载：加法赋值。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 修改后的 BigInt 对象。
     */
    friend BigInt &operator+=(BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：加法。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 新的 BigInt 对象，包含加法结果。
     */
    friend BigInt operator+(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：减法。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 新的 BigInt 对象，包含减法结果。
     */
    friend BigInt operator-(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：减法赋值。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 修改后的 BigInt 对象。
     */
    friend BigInt &operator-=(BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：等于。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 如果两个 BigInt 对象相等，返回 true；否则返回 false。
     */
    friend bool operator==(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：不等于。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 如果两个 BigInt 对象不相等，返回 true；否则返回 false。
     */
    friend bool operator!=(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：大于。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 如果 BigInt 对象 a 大于 BigInt 对象 b，返回 true；否则返回 false。
     */
    friend bool operator>(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：大于等于。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 如果 BigInt 对象 a 大于或等于 BigInt 对象 b，返回 true；否则返回 false。
     */
    friend bool operator>=(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：小于。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 如果 BigInt 对象 a 小于 BigInt 对象 b，返回 true；否则返回 false。
     */
    friend bool operator<(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：小于等于。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 如果 BigInt 对象 a 小于或等于 BigInt 对象 b，返回 true；否则返回 false。
     */
    friend bool operator<=(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：乘法赋值。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 修改后的 BigInt 对象。
     */
    friend BigInt &operator*=(BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：乘法。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 新的 BigInt 对象，包含乘法结果。
     */
    friend BigInt operator*(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：除法赋值。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 修改后的 BigInt 对象。
     */
    friend BigInt &operator/=(BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：除法。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 新的 BigInt 对象，包含除法结果。
     */
    friend BigInt operator/(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：取模。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 新的 BigInt 对象，包含取模结果。
     */
    friend BigInt operator%(const BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载：取模赋值。
     * 
     * @param a BigInt 对象。
     * @param b BigInt 对象。
     * @return 修改后的 BigInt 对象。
     */
    friend BigInt &operator%=(BigInt &a, const BigInt &b);

    /**
     * @brief 运算符重载:指数赋值
     * 
     * 实现 a ^= b, 计算a的b次方,并赋值给a
     * 使用快速幂算法进行计算
     *
     * @param a - 底数 
     * @param b - 指数
     * @return 修改后的a变量
    */
    friend BigInt &operator^=(BigInt &base, const BigInt &exponent);


    /**
     * @brief 运算符重载:指数运算
     * 
     * 实现 a ^ b, 计算a的b次方
     * 使用临时变量temp,不修改参数a
     * 调用指数赋值运算符进行计算
     * 
     * @param a 底数
     * @param b 指数 
     * @return 计算结果 
    */
    friend BigInt operator^(BigInt &base, const BigInt &exponent);


    // Square Root Function:

    /**
     * @brief 计算 BigInt 对象的平方根。
     * 
     * @param a BigInt 对象。
     * @return 一个新的 BigInt 对象，表示计算结果。
     */
    friend BigInt sqrt(BigInt &a);

    // Read and Write:

    /**
     * @brief 输入操作符重载：从输入流中读取 BigInt 对象。
     * 
     * @param in 输入流。
     * @param a 用于存储输入的 BigInt 对象。
     * @return 输入流，以支持连续输入。
     */
    friend std::istream &operator>>(std::istream &in, BigInt &a);

    /**
     * @brief 输出操作符重载：将 BigInt 对象输出到流中。
     * 
     * @param out 输出流。
     * @param a 要输出的 BigInt 对象。
     * @return 输出流，以支持连续输出。
     */
    friend std::ostream &operator<<(std::ostream &out, const BigInt &a);

    /**
     * @brief 计算 BigInt 对象的幂次方取模结果。
     * 
     * 使用重复平方法计算 (底数 ^ 指数) % 模数。
     * 
     * @param base 用于幂次方计算的底数 BigInt。
     * @param exponent 指数 BigInt。
     * @param modulus 模数 BigInt。
     * @return (底数 ^ 指数) % 模数 的结果。
     */
    static BigInt pow(const BigInt& base, const BigInt& exponent, const BigInt& modulus);

    int length() const;

    void randomize(int bits);

    static BigInt random_bigint(int bits);
};

#endif