//====================================================
// http://cpp.sh/
// https://www.onlinegdb.com/
//====================================================

//====================================================
// Program example 1
// strtype1.cpp -- using the C++ string class
#include <iostream>
#include <string>  // make string class available
using namespace std;

int main() {
    char charr1[20];             // create an empty array
    char charr2[20] = "jaguar";  // create an initialized array

    string str1;              // create an empty string object
    string str2 = "panther";  // create an initialized string

    cout << "Enter a kind of feline: ";
    cin >> charr1;

    cout << "Enter another kind of feline: ";
    cin >> str1;  // use cin for input
    cout << "Here are some felines:\n";

    cout << charr1 << " " << charr2 << " " << str1 << " "
         << str2  // use cout for output
         << endl;

    cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
    cout << "The third letter in " << str2 << " is " << str2[2]
         << endl;  // use array notation

    return 0;
}

//====================================================
// Program example 2
// strtype3.cpp -- more string class features
#include <cstring>  // C-style string library
#include <iostream>
#include <string>  // make string class available
using namespace std;

int main() {
    char charr1[20];
    char charr2[20] = "jaguar";

    string str1;
    string str2 = "panther";
    // assignment for string objects and character arrays

    str1 = str2;             // copy str2 to str1
    strcpy(charr1, charr2);  // copy charr2 to charr1
    // appending for string objects and character arrays

    str1 += " paste";          // add paste to end of str1
    strcat(charr1, " juice");  // add juice to end of charr1

    // finding the length of a string object and a C-style string
    int len1 = str1.size();     // obtain length of str1
    int len2 = strlen(charr1);  // obtain length of charr1

    cout << "The string " << str1 << " contains " << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains " << len2 << " characters.\n";

    return 0;
}
//====================================================
// Program example 3
// strtype4.cpp -- line input
#include <cstring>  // C-style string library
#include <iostream>
#include <string>  // make string class available
using namespace std;
int main() {
    char charr[20];
    string str;

    cout << "Length of string in charr before input: " << strlen(charr) << endl;
    cout << "Length of string in str before input: " << str.size() << endl;

    cout << "Enter a line of text:\n";
    cin.getline(charr, 20);  // indicate maximum length
    cout << "You entered: " << charr << endl;

    cout << "Enter another line of text:\n";
    getline(cin, str);  // cin now an argument; no length specifier
    cout << "You entered: " << str << endl;

    cout << "Length of string in charr after input: " << strlen(charr) << endl;
    cout << "Length of string in str after input: " << str.size() << endl;

    return 0;
}

//====================================================
// Program example 4
// structur.cpp -- a simple structure
#include <iostream>
struct inflatable  // structure declaration
{
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    inflatable guest = {
        "Glorious Gloria",  // name value
        1.88,               // volume value
        29.99               // price value
    };                      // guest is a structure variable of type inflatable

    // It's initialized to the indicated values
    inflatable pal = {"Audacious Arthur", 3.12,
                      32.99};  // pal is a second variable of type inflatable

    // NOTE: some implementations require using
    // static inflatable guest =
    cout << "Expand your guest list with " << guest.name;
    cout << " and " << pal.name << "!\n";
    // pal.name is the name member of the pal variable
    cout << "You can have both for $";
    cout << guest.price + pal.price << "!\n";

    return 0;
}

//====================================================
// Program example 5
// assgn_st.cpp -- assigning structures
#include <iostream>
using namespace std;

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main() {
    inflatable bouquet = {"sunflowers", 0.20, 12.49};

    inflatable choice;
    cout << "bouquet: " << bouquet.name << " for $";
    cout << bouquet.price << endl;

    choice = bouquet;  // assign one structure to another

    cout << "choice: " << choice.name << " for $";
    cout << choice.price << endl;

    return 0;
}

//====================================================
// Program example 6
// address.cpp -- using the & operator to find addresses
#include <iostream>
int main() {
    using namespace std;
    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts;
    cout << " and donuts address = " << &donuts << endl;

    // NOTE: you may need to use unsigned (&donuts)
    // and unsigned (&cups)

    cout << "cups value = " << cups;
    cout << " and cups address = " << &cups << endl;
    return 0;
}

//====================================================
// pointer.cpp -- our first pointer variable
// Program example 7

#include <iostream>
int main() {
    using namespace std;
    int updates = 6;  // declare a variable
    int *p_updates;   // declare a pointer to an int

    p_updates = &updates;  // assign address of int to pointer

    // express values two ways
    cout << "Values: updates = " << updates;
    cout << ", *p_updates = " << *p_updates << endl;

    // express address two ways
    cout << "Addresses: &updates = " << &updates;
    cout << ", p_updates = " << p_updates << endl;

    // use pointer to change value

    *p_updates = *p_updates + 1;

    cout << "Now updates = " << updates << endl;
    return 0;
}

//====================================================
// Program example 8
// use_new.cpp -- using the new operator
#include <iostream>
int main() {
    using namespace std;
    int nights = 1001;
    int *pt = new int;  // allocate space for an int
    *pt = 1001;         // store a value there

    cout << "nights value = ";
    cout << nights << ": location " << &nights << endl;
    cout << "int ";
    cout << "value = " << *pt << ": location = " << pt << endl;

    double *pd = new double;  // allocate space for a double
    *pd = 10000001.0;         // store a double there

    cout << "double ";
    cout << "value = " << *pd << ": location = " << pd << endl;
    cout << "location of pointer pd: " << &pd << endl;

    cout << "size of pt = " << sizeof(pt);
    cout << ": size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof pd;
    cout << ": size of *pd = " << sizeof(*pd) << endl;

    return 0;
}
//====================================================
// Program example 9
// arraynew.cpp -- using the new operator for arrays
#include <iostream>
using namespace std;
int main() {
    double *p3 = new double[3];  // space for 3 doubles

    p3[0] = 0.2;  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 + 1;  // increment the pointer
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 - 1;  // point back to beginning
    delete[] p3;  // free the memory

    return 0;
}
//====================================================
// Program example 10
// addpntrs.cpp -- pointer addition
#include <iostream>
int main() {
    using namespace std;
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    // Here are two ways to get the address of an array
    double *pw = wages;      // name of an array = address
    short *ps = &stacks[0];  // or use address operator

    // with array element
    cout << "pw = " << pw << ", *pw = " << *pw << endl;

    pw = pw + 1;
    cout << "add 1 to the pw pointer:\n";
    cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    cout << "ps = " << ps << ", *ps = " << *ps << endl;

    ps = ps + 1;
    cout << "add 1 to the ps pointer:\n";
    cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    cout << "access two elements with array notation\n";
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1]
         << endl;
    cout << "access two elements with pointer notation\n";
    cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1)
         << endl;

    cout << sizeof(wages) << " = size of wages array\n";
    cout << sizeof(pw) << " = size of pw pointer\n";

    return 0;
}

//====================================================
// Program example 11
// addpntrs.cpp -- pointer addition
#include <iostream>
int main() {
    using namespace std;

    short tell[10];  // tell an array of 10 bytes
    cout << "short type is: " << sizeof(short) << endl;

    cout << tell << endl;      // displays &tell[0]
    cout << &tell << endl;     // displays address of whole array
    cout << &tell[0] << endl;  // displays the address of first element

    cout << "tell + 1:     " << tell + 1 << endl;      // move 2 bytes
    cout << "&tell + 1:    " << &tell + 1 << endl;     // move 20 bytes
    cout << "&tell[0] + 1: " << &tell[0] + 1 << endl;  // move 2 bytes

    short(*pas)[10] = &tell;  // try to replace 10 by 20

    cout << "pas:       " << pas
         << endl;  // same to address of whole array  = &tell
    cout << "pas + 1: " << pas + 1 << endl;  // move 20 bytes

    cout << "*pas:     " << *pas
         << endl;  // same to address of first element = tell
    cout << "*pas + 1: " << *pas + 1 << endl;  // move 2 bytes

    cout << "&pas:     " << &pas << endl;
    cout << "&pas + 1: " << &pas + 1 << endl;

    return 0;
}
//====================================================
// Program example 12
// newstrct.cpp -- using new with a structure
#include <iostream>
struct inflatable  // structure definition
{
    char name[20];
    float volume;
    double price;
};

int main() {
    using namespace std;
    inflatable *ps = new inflatable;  // allot memory for structure

    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);  // method 1 for member access

    cout << "Enter volume in cubic feet: ";
    cin >> (*ps).volume;  // method 2 for member access

    cout << "Enter price: $";
    cin >> ps->price;
    cout << "Name: " << (*ps).name << endl;               // method 2
    cout << "Volume: " << ps->volume << " cubic feet\n";  // method 1
    cout << "Price: $" << ps->price << endl;              // method 1

    delete ps;  // free memory used by structure

    return 0;
}

//====================================================
// Program example 13
// delete.cpp -- using the delete operator
#include <cstring>  // or string.h
#include <iostream>
using namespace std;

char *getname(void);  // function prototype

int main() {
    char *name;  // create pointer but no storage

    name = getname();  // assign address of string to name
    cout << name << " at " << (int *)name << "\n";
    delete[] name;  // memory freed

    name = getname();  // reuse freed memory
    cout << name << " at " << (int *)name << "\n";
    delete[] name;  // memory freed again

    return 0;
}

char *getname()  // return pointer to new string
{
    char temp[80];  // temporary storage
    cout << "Enter last name: ";
    cin >> temp;

    char *pn = new char[strlen(temp) + 1];
    strcpy(pn, temp);  // copy string into smaller space

    return pn;  // temp lost when function ends
}

//====================================================
// Program example 14
// mixtypes.cpp -- some type combinations
#include <iostream>
struct antarctica_years_end {
    int year;
    /* some really interesting data, etc. */
};

int main() {
    antarctica_years_end s01, s02, s03;
    s01.year = 1998;

    antarctica_years_end *pa = &s02;
    pa->year = 1999;

    antarctica_years_end trio[3];  // array of 3 structures
    trio[0].year = 2003;

    std::cout << trio->year << std::endl;

    const antarctica_years_end *arp[3] = {&s01, &s02, &s03};
    std::cout << arp[1]->year << std::endl;

    const antarctica_years_end **ppa = arp;
    auto ppb = arp;  // C++11 automatic type deduction
    // or else use const antarctica_years_end ** ppb = arp;
    std::cout << (*ppa)->year << std::endl;
    std::cout << (*(ppb + 1))->year << std::endl;

    
    return 0;
}

/////////////////////////////////////////////////////////////////////////