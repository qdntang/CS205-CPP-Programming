#include <cstdio>
using namespace std;

enum Color {
    one = 2,
    two =4,
    three,
    four = 8
};

int f(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = f(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}

int main() {
    int x, y;
    int r = f(7, 9, x, y);
    printf("%d %d %d\n", r, x, y);
    printf("%d\n", three);
    return 0;
}
