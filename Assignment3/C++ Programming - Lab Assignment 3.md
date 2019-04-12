# CS205 C/C++ Programming - Lab Assignment 3

**Name**: 唐千栋 (Qiandong Tang)

**SID:** 11612730

### Part 1 - Analysis

> The program must search the cities in the table by their names and retrieve the latitudes and longitudes. If the city isn't found or if the length of the name is shorter than three letters, a message must be displayed and the user must be prompted for another name. The city names should be case-insensitive. 
>
> Please note that in the file New York appears as "New York City". If people type "New York", then "New York City" must be retrieved. However, if users only type "New" (minimum acceptable length), it can match several cities. The list of the matched cities must be displayed, and the user prompted for the right one. Finally, the names of the cities (as stored in the memory) and the distance
> between them must be displayed. 

The part 1 problem is to read the csv file into the structure. We can use `getline` and `istringstream` to read the csv file. 

The part 2 problem is to search the city in the table by their name and return the names of the cities and the distance between them. We would use `find` function to search all the matched cities and let the user choose one of them. Then use the following formula to calculate the distance between them.
$$
c=\sin(phi_1)*\sin(phi_2)*\cos(theta_1-theta_2)+\cos(phi_1)*\cos(phi_2)\\
d=R*\arccos(c)
$$

### Part 2 - Code

```c++
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define pb push_back
#define MAX_NAME_LENGTH 35
#define MAX_ARRAY_SIZE 1000
using namespace std;

const double PI = acos(-1);

string trim(string s) {
    s.erase(0, s.find_first_not_of(" \t\r\n"));
    s.erase(s.find_last_not_of(" \t\r\n") + 1);
    return s;
}

string truncate(string s) {
    s = trim(s);
    if (s.size() > MAX_NAME_LENGTH) {
        cout << s << " is longer than " << MAX_NAME_LENGTH
             << ", it is truncated to ";
        s = s.substr(0, MAX_NAME_LENGTH);
        cout << s << endl;
    }
    return s;
}

struct city {
    string name;
    string country;
    double latitude;
    double longitude;

    void print() {
        cout << "Name: " << name << ", ";
        cout << "Country: " << country << ", "
             << "Latitude: " << latitude << ", "
             << "Longitude: " << longitude << endl;
    }
};

int sz;
city cities[MAX_ARRAY_SIZE];

vector<int> search(string s) {
    vector<int> vec;
    for (int i = 0; i < sz; i++) {
        string name = cities[i].name;
        string lower_name = name;
        transform(lower_name.begin(), lower_name.end(), lower_name.begin(),
                  ::tolower);
        // cerr << lower_name << endl;
        if (name.size() >= s.size() &&
            lower_name.compare(0, s.size(), s) == 0) {
            vec.pb(i);
        }
    }
    return vec;
}

string remove_extra_space(string line) {
    string s = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != ' ')
            s.append(1, line[i]);
        else if (line[i + 1] != ' ')
            s.append(1, line[i]);
    }
    return s;
}

int read_city(string s) {
    string line;
    int id;

    while (true) {
        cout << "Please input " << s << " city name or input bye to exit"
             << endl;

        getline(cin, line);
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        line = trim(line);
        line = remove_extra_space(line);

        if (!line.compare("bye")) {
            cout << "program exit!" << endl;
            exit(0);
        }

        if (line.size() < 3) {
            cout << "Your input is too short, please input city name larger "
                    "than 3 letters"
                 << endl;
            continue;
        }
        vector<int> vec = search(line);
        if (vec.size() == 0) {
            cout << "Could not find any matched city" << endl;
            continue;
        } else if (vec.size() > 1) {
            cout << "Multiple matched cities are found, which city do you mean?"
                 << endl;

            for (int i = 0; i < vec.size(); i++) {
                cout << i << ") ";
                cities[vec[i]].print();
            }

            cout << "Please select the corresponding number, if none of them "
                    "is, enter -1 to type city again "
                 << endl;

            int number;
            string buf;
            while (true) {
                cin >> number;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(65536, '\n');
                    cout << "Input invalid, please type again" << endl;
                } else {
                    cin.ignore(65536, '\n');
                    if (number >= (int)vec.size() || number < -1) {
                        cout << "Input number should >= -1 and < " << vec.size()
                             << ", please type again" << endl;
                        continue;
                    }
                    break;
                }
            }
            if (number == -1) {
                continue;
            } else {
                id = vec[number];
                break;
            }
        } else {
            id = vec[0];
            break;
        }
    }
    return id;
}

double get_arc(double x) { return x * PI / 180; }

void dist(int id1, int id2) {
    double phi1, phi2, theta1, theta2;
    phi1 = cities[id1].latitude;
    theta1 = cities[id1].longitude;
    phi2 = cities[id2].latitude;
    theta2 = cities[id2].longitude;

    phi1 = 90 - phi1, phi2 = 90 - phi2;
    phi1 = get_arc(phi1);
    phi2 = get_arc(phi2);
    theta1 = get_arc(theta1);
    theta2 = get_arc(theta2);

    double c =
        sin(phi1) * sin(phi2) * cos(theta1 - theta2) + cos(phi1) * cos(phi2);
    double d = 6371 * acos(c);

    cout << "The distance between " << cities[id1].name << " and "
         << cities[id2].name << " is " << d << "km." << endl;
    cout << endl;
}

int main() {
    string file_path = "world_cities.csv";
    ifstream fin(file_path);
    if (!fin) {
        cout << file_path << " missed" << endl;
        return 0;
    }
    cout << "read data from " << file_path << endl << endl;
    string line;
    sz = 0;
    while (getline(fin, line)) {
        if (sz >= MAX_ARRAY_SIZE) {
            cout << endl;
            cout << "the number of cities in world_cities.csv > "
                 << MAX_ARRAY_SIZE << ", the remainig data is not loaded"
                 << endl;
            break;
        }
        istringstream sin(line);
        string field;
        vector<string> fields;
        while (getline(sin, field, ',')) {
            fields.pb(field);
        }
        cities[sz].name = truncate(fields[0]);
        cities[sz].country = truncate(fields[2]);
        cities[sz].latitude = stod(fields[3]);
        cities[sz].longitude = stod(fields[4]);
        // cities[sz].print();
        sz++;
    }
    cout << "read done!" << endl << endl;

    while (true) {
        int id1 = read_city("first");
        cout << "Your first chosen city name is " << cities[id1].name << endl;
        int id2 = read_city("second");
        cout << "Your second chosen city name is " << cities[id2].name << endl;
        dist(id1, id2);
    }
    return 0;
}

```

### Part 3 - Result & Verification

Part 1 (1)

```c++
// When the maximum length is set to 25, and the array size is 800
```

![Snipaste_2019-04-12_13-08-32](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-08-32.png)

Part 1 (2)

```c++
// When the maximum length is set to 35, and the array size is 1000
```

![Snipaste_2019-04-12_13-09-57](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-09-57.png)

Part 1 (3)

![Snipaste_2019-04-12_13-10-33](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-10-33.png)

Test case #1

```
New 
2
Shenz
```

![Snipaste_2019-04-12_13-11-58](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-11-58.png)

Test case #2

```
George
-1
George Town
0
Dub
0
```

![Snipaste_2019-04-12_13-13-05](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-13-05.png)

Test case #3

```
ams
     shenzhen
```

![Snipaste_2019-04-12_13-14-24](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-14-24.png)

```
     bYe
```

![Snipaste_2019-04-12_13-14-55](C:\Users\sttee\Downloads\Screenshots\Snipaste_2019-04-12_13-14-55.png)

### Part 4 - Difficulties & Solutions

When user type a string when he is required to type a integer, it would cause error. We use the `cin.clear` and `cin.ignore` to cope with this problem.

```c++
while (true) {
	cin >> number;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "Input invalid, please type again" << endl;
	} else {
		cin.ignore(65536, '\n');
		if (number >= (int)vec.size() || number < -1) {
			cout << "Input number should >= -1 and < " << vec.size()
			<< ", please type again" << endl;
			continue;
		}
		break;
	}
}
```

