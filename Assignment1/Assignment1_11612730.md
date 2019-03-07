## CS205 C/ C++ Programming - Lab Assignment 1

**Name**: 唐千栋(Qiandong Tang)

**SID**: 11612730

### Part 1 - Analysis

The problem is to calculate the distance between two cities.  We have to read the name, latitude and longitude of two's cities. Then calculate the distance and output. Because the angle, which is described in the statement, is measured with degree, we need to first convert degree to radian. 
$$
phi=90-Latitude\\
theta=Longitude\\
c=\sin(phi_1)*\sin(phi_2)*\cos(theta_1-theta_2)+\cos(phi_1)*\cos(phi_2)\\
d=R*\arccos(c)
$$


### Part 2 - Code

```c++
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

```

### Part 3 - Result & Verification

> The verification is combined with the result queried in the website.

Test case #1:

```
Input: 
Shenzhen
22.55 
114.1
Paris
48.8567 
2.3508	   
Output: The distance between Shenzhen and Beijing is 9601.85 km
```

![Screen Shot 2019-03-07 at 20.12.30](/Users/macbook/Documents/STEVEN/SUSTECH/C:C++/CS205-CPP-Programming/Assignment1/Screen Shot 2019-03-07 at 20.12.30.png)

Test case #2:

```
Input:
Shenzhen
Paris // incorrect format
22.55 
114.1
Paris
48.8567 
2.3508	   
Output: The distance between Shenzhen and Beijing is 9601.85 km
```

![Screen Shot 2019-03-07 at 20.32.47](/Users/macbook/Documents/STEVEN/SUSTECH/C:C++/CS205-CPP-Programming/Assignment1/Screen Shot 2019-03-07 at 20.32.47.png)

Test Case #3:

```
Shenzhen
22.55
114.1
San Francisco
37.7833
-122.4167
```

![Screen Shot 2019-03-07 at 20.36.37](/Users/macbook/Documents/STEVEN/SUSTECH/C:C++/CS205-CPP-Programming/Assignment1/Screen Shot 2019-03-07 at 20.36.37.png)

### Part 4 - Difficulties & Solutions

1. The difficulty is to convert degree to radian. 

   We can multiply degree with pi/180 to get radian.

2. The second problem is how to read a line from input.

   We can use `cin.getline()`to read a line. 

