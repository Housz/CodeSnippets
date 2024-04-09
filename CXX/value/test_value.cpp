#include <iostream>
#include <utility>
#include <vector>
#include <string>

struct Test
{
};

std::vector<Test> foo()
{
    std::vector<Test> v;
    v.push_back(Test{});
    std::cout << &v[0] << std::endl;

    return v;
}

int main()
{
    // int &&rr1 = 42; // rr: right reference
    // std::cout << rr1 << std::endl;
    // // int &&rr2 = rr1; error, rr1 is left value
    // int &&rr3 = std::move(rr1);
    // std::cout << rr3 << std::endl; // 42
    // std::cout << rr1 << std::endl; // 42
    // rr3 = 43;
    // std::cout << rr3 << std::endl; // 43
    // std::cout << rr1 << std::endl; // 43


    // std::string str = "Hello world";
    // std::vector<std::string> v;
    // v.push_back(std::move(str));
    // std::cout << str << std::endl;  // nothing
    // std::cout << v[0] << std::endl; // "Hello world"

    // int a = 1;
    // int& la = a;
    // int&& ra = std::move(a);
    // std::cout << a << std::endl;
    // std::cout << la << std::endl;
    // std::cout << ra << std::endl;


    // std::vector<int> vec {1, 2, 3};
    // auto vl = std::move(vec);
    // std::cout << vec.size() << std::endl;
    // std::cout << vl[0] << std::endl;


    // std::vector<Test> v;
    // v.push_back(Test{});
    // std::cout << &v[0] << std::endl;
    // std::vector<Test> v2 { std::move(v) };
    // std::cout << &v2[0] << std::endl;

    // return STL
    // std::vector<Test> v = foo();
    // std::cout << &v[0] << std::endl;

    return 0;
}

