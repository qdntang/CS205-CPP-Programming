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
char buffer[maxn];

double get_arc(double x) { return x * PI / 180; }

void get_double(double& x) {
	cin >> x;
	while (cin.fail()) {
		cout << "wrong format, please try again" << endl;
		cin.clear();
		cin.getline(buffer, maxn);
		cin >> x;
	}
}

int main() {
	printf("Please input the first city: <city name>\n");
	cin.getline(s1, maxn);
	printf("Please input <latitude>\n");
	get_double(phi1);
	printf("Please input <longitude>\n");
	get_double(theta1);
	getchar();
	printf("Please input the second city: <city name>\n");
	cin.getline(s2, maxn);
	printf("Please input <latitude>\n");
	get_double(phi2);
	printf("Please input <longitude>\n");
	get_double(theta2);

	phi1 = 90 - phi1, phi2 = 90 - phi2;
	phi1 = get_arc(phi1);
	phi2 = get_arc(phi2);
	theta1 = get_arc(theta1);
	theta2 = get_arc(theta2);

	double c = sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
	double d = 6371 * acos(c);

	printf("The distance between %s and %s is %.2f km\n", s1, s2, d);
	return 0;
}
