//====================================================
// http://cpp.sh/
// https://www.onlinegdb.com/
//====================================================

//====================================================
// Program example 1
// if.cpp -- using the if statement
#include <iostream>
int main() {
    using std::cin;  // using declarations
    using std::cout;
    char ch;
    int spaces = 0;
    int total = 0;
    cin.get(ch);

    while (ch != '.')  // quit at end of sentence
    {
        if (ch == ' ')  // check if ch is a space
            ++spaces;

        ++total;  // done every time
        cin.get(ch);
    }

    cout << spaces << " spaces, " << total;
    cout << " characters total in sentence\n";

    return 0;
}

//====================================================
// Program example 2
// ifelseif.cpp -- using if else if else
#include <iostream>
const int Fave = 27;
int main() {
    using namespace std;
    int n;
    cout << "Enter a number in the range 1-100 to find ";
    cout << "my favorite number: ";
    do {
        cin >> n;
        if (n < Fave)
            cout << "Too low -- guess again: ";
        else if (n > Fave)
            cout << "Too high -- guess again: ";
        else
            cout << Fave << " is right!\n";
    } while (n != Fave);

    return 0;
}

//====================================================
// Program example 3
// and.cpp -- using the logical AND operator
#include <iostream>
const int ArSize = 6;
int main() {
    using namespace std;
    float naaq[ArSize];
    cout << "Enter the NAAQs (New Age Awareness Quotients) "
         << "of\nyour neighbors. Program terminates "
         << "when you make\n"
         << ArSize << " entries "
         << "or enter a negative value.\n";

    int i = 0;
    float temp;
    cout << "First value: ";
    cin >> temp;
    while (i < ArSize && temp >= 0)  // 2 quitting criteria
    {
        naaq[i] = temp;
        ++i;

        if (i < ArSize)  // room left in the array,
        {
            cout << "Next value: ";
            cin >> temp;  // so get next value
        }
    }

    if (i == 0)
        cout << "No data--bye\n";
    else {
        cout << "Enter your NAAQ: ";
        float you;
        cin >> you;
        int count = 0;
        for (int j = 0; j < i; j++)
            if (naaq[j] > you) ++count;

        cout << count;
        cout << " of your neighbors have greater awareness of\n"
             << "the New Age than you do.\n";
    }

    return 0;
}

//====================================================
// Program example 4
// switch.cpp -- using the switch statement
#include <iostream>
using namespace std;
void showmenu();  // function prototypes
void report();
void comfort();
int main() {
    showmenu();
    int choice;
    cin >> choice;
    while (choice != 5) {
        switch (choice) {
            case 1:
                cout << "!!!!Here is alarm!!!!\n";
                break;
            case 2:
                report();
                break;
            case 3:
                cout << "The boss was in all day.\n";
                break;
            case 4:
                comfort();
                break;
            default:
                cout << "That's not a choice.\n";
        }

        showmenu();
        cin >> choice;
    }

    cout << "Bye!\n";
    return 0;
}

void showmenu() {
    cout << "Please enter 1, 2, 3, 4, or 5:\n"
            "1) alarm 2) report\n"
            "3) alibi 4) comfort\n"
            "5) quit\n";
}

void report() {
    cout << "It's been an excellent week for business.\n"
            "Sales are up 120%. Expenses are down 35%.\n";
}

void comfort() {
    cout << "Your employees think you are the finest CEO\n"
            "in the industry. The board of directors think\n"
            "you are the finest CEO in the industry.\n";
}

//====================================================
// Program example 5
// enum.cpp -- using enum
#include <iostream>
// create named constants for 0 - 6
enum { red, orange, yellow, green, blue, violet, indigo };
int main() {
    using namespace std;
    cout << "Enter color code (0-6): ";
    int code;
    cin >> code;
    while (code >= red && code <= indigo) {
        switch (code) {
            case red:
                cout << "Her lips were red.\n";
                break;
            case orange:
                cout << "Her hair was orange.\n";
                break;
            case yellow:
                cout << "Her shoes were yellow.\n";
                break;
            case green:
                cout << "Her nails were green.\n";
                break;
            case blue:
                cout << "Her sweatsuit was blue.\n";
                break;
            case violet:
                cout << "Her eyes were violet.\n";
                break;
            case indigo:
                cout << "Her mood was indigo.\n";
                break;
        }
        cout << "Enter color code (0-6): ";
        cin >> code;
    }

    cout << "Bye\n";
    return 0;
}

//====================================================
// Program example 6
// jump.cpp -- using continue and break
// let's eat lunch outside. i pay it
#include <iostream>
const int ArSize = 80;
int main() {
    using namespace std;
    char line[ArSize];
    int spaces = 0;
    cout << "Enter a line of text:\n";
    cin.get(line, ArSize);

    cout << "Complete line:\n" << line << endl;
    cout << "Line through first period:\n";

    for (int i = 0; line[i] != '\0'; i++) {
        cout << line[i];     // display character
        if (line[i] == '.')  // quit if it's a period
            break;

        if (line[i] != ' ')  // skip rest of loop
            continue;

        spaces++;
    }

    cout << "\n" << spaces << " spaces\n";
    cout << "Done.\n";
    return 0;
}

//====================================================
// Program example 7
// cinfish.cpp -- non-numeric input terminates loop
#include <iostream>
const int Max = 5;
int main() {
    using namespace std;
    // get data
    double fish[Max];
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max << " fish <q to terminate>.\n";

    cout << "fish #1: ";
    int i = 0;
    while (i < Max && cin >> fish[i]) {
        if (++i < Max) cout << "fish #" << i + 1 << ": ";
    }

    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++) total += fish[j];

    // report results
    if (i == 0)
        cout << "No fish\n";
    else
        cout << total / i << " = average weight of " << i << " fish\n";

    cout << "Done.\n";
    return 0;
}

//====================================================
// Program example 8
// cingolf.cpp -- non-numeric input skipped
#include <iostream>
const int Max = 5;
int main() {
    using namespace std;
    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0; i < Max; i++) {
        cout << "round #" << i + 1 << ": ";
        while (!(cin >> golf[i])) {
            cin.clear();                         // reset input
            while (cin.get() != '\n') continue;  // get rid of bad input

            cout << "Please enter a number: ";
        }
    }

    // calculate average

    double total = 0.0;
    for (i = 0; i < Max; i++) total += golf[i];

    // report results
    cout << total / Max << " = average score " << Max << " rounds\n";
    return 0;
}

//====================================================
// Program example 9
// outfile.cpp -- writing to a file
#include <fstream>  // for file I/O
#include <iostream>

using namespace std;
int main() {
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;             // create object for output
    outFile.open("carinfo.txt");  // associate with a file

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = 0.913 * a_price;

    // display information on screen with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;

    // now do exact same things using outFile instead of cout
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;
    outFile.close();  // done with file

    return 0;
}

//====================================================
// Program example 10
// sumafile.cpp -- functions with an array argument
#include <cstdlib>  // support for exit()
#include <fstream>  // file I/O support
#include <iostream>
const int SIZE = 60;
using namespace std;

void create_file();

int main() {
    char filename[SIZE];

    create_file();

    ifstream inFile;  // object for handling file input

    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);  // associate inFile with a file
    if (!inFile.is_open())  // failed to open file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    double value;
    double sum = 0.0;
    int count = 0;         // number of items read
    inFile >> value;       // get first value
    while (inFile.good())  // while input good and not at EOF
    {
        ++count;          // one more item read
        sum += value;     // calculate running total
        inFile >> value;  // get next value
    }

    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";

    if (count == 0)
        cout << "No data processed.\n";
    else {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();  // finished with the file

    return 0;
}

void create_file() {
    ofstream outFile;            // create object for output
    outFile.open("scores.txt");  // associate with a file

    const int M_N_1 = 5;
    const int M_N_2 = 6;
    const int M_N_3 = 1;

    double row1[M_N_1] = {18, 19, 18.5, 13.5, 14};
    double row2[M_N_2] = {16, 19.5, 20, 18, 12, 18.5};
    double row3[M_N_3] = {17.5};

    for (int i = 0; i < M_N_1; i++) outFile << row1[i] << " ";
    outFile << endl;

    for (int i = 0; i < M_N_2; i++) outFile << row2[i] << " ";
    outFile << endl;

    for (int i = 0; i < M_N_3; i++) outFile << row3[i] << " ";
    outFile << endl;

    outFile.close();
}

//====================================================

18 19 18.5 13.5 14

    16 19.5 20 18 12 18.5

    17.5

    //====================================================
    /////////////////////////////////////////////////////////////////////////