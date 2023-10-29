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
    
    // 测试幂次方取模函数
    std::string bas = "1212334";
    std::string exp = "2";
    std::string mod = "10007";

    BigInt base(bas); 
    BigInt exponent(exp); 
    BigInt modulus(mod); 

    BigInt result = BigInt::pow(base, exponent, modulus);

    std::cout << base << " ^ " << exponent << " % " << modulus << " = " << result << std::endl;

    try {
        // 测试BigInt的构造函数
        BigInt a("12345");
        BigInt b(6789);
        BigInt c("-9876");

        // 测试BigInt的基本运算
        BigInt sum = a + b;
        BigInt difference = b - a;
        BigInt product = a * b;
        BigInt quotient = a / b;
        BigInt remainder = a % b;
        BigInt power = a ^ BigInt(3);
        divide_by_2(c);

        // 测试比较操作符
        bool isEqual = (a == b);
        bool isNotEqual = (a != b);
        bool isLessThan = (a < b);
        bool isGreaterThan = (a > b);
        bool isLessThanOrEqual = (a <= b);
        bool isGreaterThanOrEqual = (a >= b);

        // // 输出测试结果
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "a + b: " << sum << std::endl;
        std::cout << "a - b: " << difference << std::endl;
        std::cout << "a * b: " << product << std::endl;
        std::cout << "a / b: " << quotient << std::endl;
        std::cout << "a % b: " << remainder << std::endl;
        std::cout << "a^3: " << power << std::endl;
        std::cout << "c / 2: " << c << std::endl;
        std::cout << "a == b: " << isEqual << std::endl;
        std::cout << "a != b: " << isNotEqual << std::endl;
        std::cout << "a < b: " << isLessThan << std::endl;
        std::cout << "a > b: " << isGreaterThan << std::endl;
        std::cout << "a <= b: " << isLessThanOrEqual << std::endl;
        std::cout << "a >= b: " << isGreaterThanOrEqual << std::endl;
    } catch (const char* errorMessage) {
        std::cerr << "Error: " << errorMessage << std::endl;
    }

    return 0;
}
