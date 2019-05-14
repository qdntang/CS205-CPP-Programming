#include <cstdio>
#include <iostream>
#include "Box.h"
using namespace std;

int main() {
	/*
	Expected output:
	b1: 0 0 0
	b2: 1 2 3
	b3: 1 2 4
	b4: 1 2 4
	b3's length = 1
	b3's breath = 2
	b3's height = 4
	b2 is smaller than b3
	Input length out of range
	b6's volume = 6000000000000
	*/
	Box b1;
	cout << "b1: " << b1 << endl;
	Box b2(1, 2, 3);
	cout << "b2: " << b2 << endl;
	Box b3(1, 2, 4);
	cout << "b3: " << b3 << endl;
	Box b4 = b3;
	cout << "b4: " << b4 << endl;
	cout << "b3's length = " << b3.getLength() << endl;
	cout << "b3's breath = " << b3.getBreadth() << endl;
	cout << "b3's height = " << b3.getHeight() << endl;
	if (b2 < b3) cout << "b2 is smaller than b3" << endl;
	else cout << "b2 is not smaller than b3" << endl;
	Box b5(1000000, 1000, 100000);
	Box b6(10000, 20000, 30000);
	cout << "b6's volume = " << b6.calculateVolume() << endl;
	return 0;
}
