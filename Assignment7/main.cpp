#include <cstdio>
#include <iostream>
#include <string>
#include <type_traits>

struct A {
    int b;

    A operator++(int){
        A a;
        a.b = b;
        b++;
        return a;
    };

    A& operator++() {
        b++;
        return *this;
    }

    bool operator==(const A &rhs) const {
        return b == rhs.b;
    }
};

int main() {
    std::cout << std::boolalpha << is_incrementable<int>() << std::endl;
    std::cout << is_incrementable<std::string>() << std::endl;
    std::cout << is_incrementable<A>() << std::endl;
    return 0;
}
