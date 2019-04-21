//====================================================
// http://cpp.sh/
// https://www.onlinegdb.com/
//====================================================

//====================================================
// Program example 1
// choices.cpp -- array variations
#include <array>  // C++11
#include <iostream>
#include <vector>  // STL C++98
int main() {
    using namespace std;
    // C, original C++
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    // C++98 STL
    vector<double> a2(4);  // create vector with 4 elements
    // no simple way to initialize in C98

    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    // C++11 -- create and initialize array object
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;  // valid for array objects of same size

    // use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    // misdeed

    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    return 0;
}

//====================================================
// Program example 2
// forloop.cpp -- introducing the for loop
#include <iostream>
int main() {
    using namespace std;
    int i;  // create a counter

    // initialize; test ; update
    for (i = 0; i < 5; i++) cout << "C++ knows loops.\n";

    cout << "C++ knows when to stop.\n";
    return 0;
}

//====================================================
// Program example 3
// num_test.cpp -- use numeric test in for loop
#include <iostream>
int main() {
    using namespace std;
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    int i;

    for (i = limit; i; i--)  // quits when i is
        cout << "i = " << i << "\n";

    cout << "Done now that i = " << i << "\n";

    return 0;
}

//====================================================
// Program example 4
// formore.cpp -- more looping with for
#include <iostream>
const int ArSize = 16;  // example of external declaration
int main() {
    long long factorials[ArSize];

    factorials[1] = factorials[0] = 1LL;
    for (int i = 2; i < ArSize; i++)  // i = 1 works as well
        factorials[i] = i * factorials[i - 1];

    for (int i = 0; i < ArSize; i++)
        std::cout << i << "! = " << factorials[i] << std::endl;

    return 0;
}

//====================================================
// Program example 5
// bigstep.cpp -- count as directed
#include <iostream>
int main() {
    using std::cin;
    using std::cout;  // a using declaration
    using std::endl;

    cout << "Enter an integer: ";

    int by;
    cin >> by;
    cout << "Counting by " << by << "s:\n";

    for (int i = 0; i < 100; i = i + by) cout << i << endl;

    return 0;
}

//====================================================
// Program example 6
// plus_one.cpp -- the increment operator
#include <iostream>
int main() {
    using std::cout;
    int a = 20;
    int b = 20;

    cout << "a = " << a << ": b = " << b << "\n";
    cout << "a++ = " << a++ << ": ++b = " << ++b << "\n";
    cout << "a = " << a << ": b = " << b << "\n";

    return 0;
}
//====================================================
// Program example 7
// plus_one.cpp -- the increment operator
#include <iostream>
int main() {
    using std::cout;
    using std::endl;

    int b = 0;

    int y = (1 + (b++)) + (1 + b++);
    cout << y << endl;
    //=====================================

    double arr[5] = {21.1, 22.8, 23.7, 24.1, 25.4};

    double *pt = arr;  // pt points to arr[0], i.e. to 21.1
    ++pt;              // pt points to arr[1], i.e. to 22.8

    double x =
        *++pt;  // increment pointer, take the value; i.e., arr[2], or 23.7

    cout << "x is: " << x << endl;

    cout << ++*pt
         << endl;  // increment the pointed to value; i.e., change 23.4 to 24.4

    cout << (*pt)++ << endl;  // increment pointed-to value

    x = *pt++;  // dereference original location, then increment pointer

    cout << "x is: " << x << endl;

    return 0;
}

//====================================================
// Program example 8
#include <iostream>
int main() {
    using std::cout;
    using std::endl;

    int x = 20;  // original x

    {                       // block starts
        cout << x << endl;  // use original x
        int x = 100;        // new x
        cout << x << endl;  // use new x
    }                       // block ends

    cout << x << endl;  // use original x

    return 0;
}

//====================================================
// Program example 9
// equal.cpp -- equality vs assignment
#include <iostream>
int main() {
    using namespace std;
    int quizscores[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

    cout << "Doing it right:\n";
    int i;
    for (i = 0; quizscores[i] == 20; i++) cout << "quiz " << i << " is a 20\n";

    // Warning: you may prefer reading about this program
    // to actually running it.
    cout << "Doing it dangerously wrong:\n";

    for (i = 0; quizscores[i] = 20; i++) cout << "quiz " << i << " is a 20\n";

    return 0;
}
//====================================================
// Program example 10
// compstr1.cpp -- comparing strings using arrays
#include <cstring>  // prototype for strcmp()
#include <iostream>
int main() {
    using namespace std;
    char word[5] = "?ate";
    for (char ch = 'a'; strcmp(word, "mate"); ch++) {
        cout << word << endl;
        word[0] = ch;
    }
    cout << "After loop ends, word is " << word << endl;

    return 0;
}

//====================================================
// Program example 11
// compstr2.cpp -- comparing strings using arrays
#include <iostream>
#include <string>  // string class
int main() {
    using namespace std;
    string word = "?ate";
    for (char ch = 'a'; word != "mate"; ch++) {
        cout << word << endl;
        word[0] = ch;
    }

    cout << "After loop ends, word is " << word << endl;

    return 0;
}

//====================================================
// Program example 12
// while.cpp -- introducing the while loop
#include <iostream>
const int ArSize = 20;
int main() {
    using namespace std;
    char name[ArSize];
    cout << "Your first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";

    int i = 0;  // start at beginning of string

    // while (name[i])
    while (name[i] != '\0')  // process to end of string
    {
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;  // don��t forget this step
    }

    return 0;
}

//====================================================
// Program example 13
// dowhile.cpp -- exit-condition loop
#include <iostream>
int main() {
    using namespace std;
    int n;
    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n";
    do {
        cin >> n;      // execute body
    } while (n != 7);  // then test

    cout << "Yes, 7 is my favorite.\n";

    return 0;
}

//====================================================
// Program example 14
// range-based for loop
#include <iostream>
using namespace std;

int main() {
    double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
    for (double x : prices) cout << x << std::endl;

    /*
    for (double &x : prices)
    {
       x = x * 0.80; //20% off sale
       cout << x << endl;
    }*/

    /*
    for (int x : {3, 5, 2, 8, 6})
       cout << x << " ";
    

    cout << '\n';*/

    return 0;
}
//====================================================
// textin1.cpp -- reading chars with a while loop
// Program example 15
#include <iostream>
int main() {
    using namespace std;
    char ch;
    int count = 0;  // use basic input
    cout << "Enter characters; enter # to quit:\n";
    cin >> ch;         // get a character
    while (ch != '#')  // test the character
    {
        cout << ch;  // echo the character
        ++count;     // count the character
        cin >> ch;   // get the next character
    }

    cout << endl << count << " characters read\n";

    return 0;
}
//====================================================
// Program example 16
// textin2.cpp -- using cin.get(char)
#include <iostream>
int main() {
    using namespace std;
    char ch;
    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
    cin.get(ch);  // use the cin.get(ch) function
    while (ch != '#') {
        cout << ch;
        ++count;
        cin.get(ch);  // use it again
    }
    cout << endl << count << " characters read\n";
    return 0;
}

//====================================================
// Program example 17
// nested.cpp -- nested loops and 2-D array
#include <iostream>
const int Cities = 5;
const int Years = 4;
int main() {
    using namespace std;
    const char *cities[Cities] =  // array of pointers
        {                         // to 5 strings
         "Gribble City", "Gribbletown", "New Gribble", "San Gribble",
         "Gribble Vista"};

    int maxtemps[Years][Cities] =  // 2-D array
        {
            {96, 100, 87, 101, 105},  // values for maxtemps[0]
            {96, 98, 91, 107, 104},   // values for maxtemps[1]
            {97, 101, 93, 108, 107},  // values for maxtemps[2]
            {98, 103, 95, 109, 108}   // values for maxtemps[3]
        };

    cout << "Maximum temperatures for 2008 - 2011\n\n";
    for (int city = 0; city < Cities; ++city) {
        cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            cout << maxtemps[year][city] << "\t";

        cout << endl;
    }

    // cin.get();
    return 0;
}
//====================================================

//====================================================

//====================================================

/////////////////////////////////////////////////////////////////////////