#include <iostream>
#include <string>
#include "bigint.h"

int main() {
    std::string n1 = "987654321098765432109876543210";
    BigInt a(n1);
    std::string n2 = "123456789012345678901234567890";
    BigInt b(n2);

    // 测试基本数学运算
    BigInt sum(a + b);
    BigInt difference(a - b);
    BigInt product(a * b);
    BigInt quotient(a / b);
    BigInt remainder(a % b);

    std::cout << "a + b = " << sum << std::endl;
    std::cout << "a - b = " << difference << std::endl;
    std::cout << "a * b = " << product << std::endl;
    std::cout << "a / b = " << quotient << std::endl;
    std::cout << "a % b = " << remainder << std::endl;

    // 测试自增和自减运算符
    BigInt x(a);
    BigInt y(b);
    x++;
    y--;
    std::cout << "a++ = " << x << std::endl;
    std::cout << "b-- = " << y << std::endl;

    // 测试平方根函数
    std::string n3 = "12345678901234567890123456789000000000";
    BigInt c(n3);
    BigInt sqrt_c = sqrt(c);
    std::cout << "sqrt(c) = " << sqrt_c << std::endl;

    // 测试比较运算符
    bool equal = (a == b);
    bool not_equal = (a != b);
    bool less_than = (a < b);
    bool greater_than = (a > b);
    bool less_equal = (a <= b);
    bool greater_equal = (a >= b);

    std::cout << "a == b: " << equal << std::endl;
    std::cout << "a != b: " << not_equal << std::endl;
    std::cout << "a < b: " << less_than << std::endl;
    std::cout << "a > b: " << greater_than << std::endl;
    std::cout << "a <= b: " << less_equal << std::endl;
    std::cout << "a >= b: " << greater_equal << std::endl;

    return 0;
}
