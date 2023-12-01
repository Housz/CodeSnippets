#include <iostream>
#include <utility>
#include <vector>

int main()
{
    int &&rr1 = 42; // rr: right reference
    std::cout << rr1 << std::endl;

    // int &&rr2 = rr1; error, rr1 is left value

    int &&rr3 = std::move(rr1);
    std::cout << rr3 << std::endl; // 42
    std::cout << rr1 << std::endl; // 42

    rr3 = 43;
    std::cout << rr3 << std::endl; // 43
    std::cout << rr1 << std::endl; // 43

    


    return 0;
}