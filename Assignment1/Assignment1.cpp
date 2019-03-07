#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e3 + 10;
const double PI = acos(-1);

char s1[maxn];
char s2[maxn];

double phi1, phi2;
double theta1, theta2;
string buffer;

double get_arc(double x) { return x * PI / 180; }

int main() {
    printf("Please input the first city: <city name> <latitude> <longitude>\n");
    cin.getline(s1, maxn);
    scanf("%lf%lf", &phi1, &theta1);
    getchar();
    printf("Please input the second city: <city name> <latitude> <longitude>\n");
    cin.getline(s2, maxn);
    scanf("%lf%lf", &phi2, &theta2);

    phi1 = 90 - phi1, phi2 = 90 - phi2;
    phi1 = get_arc(phi1);
    phi2 = get_arc(phi2);
    theta1 = get_arc(theta1);
    theta2 = get_arc(theta2);

    double c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    double d = 6371 * acos(c);

    printf("The distance between %s and %s is %.2f km", s1, s2, d);
    return 0;
}
