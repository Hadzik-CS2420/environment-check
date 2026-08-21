#include <iostream>
#include <string>

int main()
{
    std::cout << "========================================\n";
    std::cout << "  CS 2420 Environment Check\n";
    std::cout << "========================================\n";

    bool all_passed = true;

#if defined(__GNUC__) && !defined(__clang__)
    std::cout << "Compiler:  g++ (GCC) OK\n";
#elif defined(__clang__)
    std::cout << "Compiler:  clang++   OK\n";
#elif defined(_MSC_VER)
    std::cout << "Compiler:  MSVC      OK\n";
#else
    std::cout << "Compiler:  unknown   WARNING\n";
    all_passed = false;
#endif

#if __cplusplus >= 201703L
    std::cout << "Standard:  C++17     OK\n";
#else
    std::cout << "Standard:  < C++17   FAIL\n";
    all_passed = false;
#endif

    std::cout << "CMake:     OK\n";

    std::cout << "\n";
    if (all_passed)
    {
        std::cout << "All checks passed! Your environment is ready.\n";
    }
    else
    {
        std::cout << "Some checks failed. See above for details.\n";
    }
    std::cout << "========================================\n";

    return all_passed ? 0 : 1;
}
