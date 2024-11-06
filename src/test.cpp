#include <iostream>
#include "../include/libspectra.h"

class TestClass {
public:
    static void hello() {
        std::cout << "Hello from Spectra!" << std::endl;
    }

    static void greet() {
        std::cout << "Greetings from Spectra!" << std::endl;
    }
};

int main() {
    // 注册函数
    Spectra::registerFunction("hello", TestClass::hello);
    Spectra::registerFunction("greet", TestClass::greet);

    // 调用已注册的函数
    try {
        // 输出：Hello from TestClass!
        Spectra::invoke("hello");
        // 输出：Greetings from TestClass!
        Spectra::invoke("greet");
        // 尝试调用不存在的函数
//        Spectra::invoke("nonexistent");
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}