#include <cstdio>
#include <iostream>
using namespace std;

class Box {
  private:
	int _length;
	int _breadth;
	int _height;
	bool in_range(int x) {return (0 <= x && x <= 100000) ? true : false;}
  public:
	Box() {_length = 0, _breadth = 0, _height = 0;}
	Box(const Box &box) {
		_length = box._length;
		_breadth = box._breadth;
		_height = box._height;
	}
	Box(int length, int breadth, int height) {
		if (in_range(length)) _length = length;
		else cerr << "Input length out of range" << endl;
		if (in_range(breadth)) _breadth = breadth;
		else cerr << "Input breadth out of range" << endl;
		if (in_range(height)) _height = height;
		else cerr << "Input height out of range" << endl;
	}
	int getLength() const {return _length;}
	int getBreadth() const {return _breadth;}
	int getHeight() const {return _height;}
	long long calculateVolume() {
		return 1LL * _length * _breadth * _height;
	}
	bool operator<(const Box &rhs) const {
		if (_length < rhs._length) return true;
		if (_breadth < rhs._breadth && _length == rhs._length) return true;
		if (_height < rhs._height && _breadth == rhs._breadth && _length == rhs._length) return true;
		return false;
	}
	friend ostream &operator<< (ostream &out, const Box &box) {
		out << box._length << " " << box._breadth << " " << box._height;
		return out;
	}
};
