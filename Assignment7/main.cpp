#include "template.hpp"
using namespace std;

struct A {
    int b;

    const A operator++(int){
        A a{};
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
    cout << std::boolalpha << is_incrementable<int>() << endl;
    cout << is_incrementable<string>() << endl;
    cout << is_incrementable<A>() << endl;
    return 0;
}
