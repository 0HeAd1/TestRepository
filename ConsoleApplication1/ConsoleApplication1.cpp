#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include "InputN.h"
#include "InputRange.h"
#include "logic.h"
#include "InputStep.h"

using namespace std;
double a, b, step;
int n;
vector<pair<double, double>> vt;
vector<vector<pair<double, double>>> results;


void Exits() {
    cout << "Are you sure you want to exit ? (Y / N): ";
    char answ = _getch();
    while (toupper(answ) != 'Y' && toupper(answ) != 'N') answ = _getch();
    if (toupper(answ) == 'Y') {
        system("cls");
        cout << "===============================================================\n\nThank you for using " << '"' << "Function 23" << '"' << " Goodbye and have a great day!\n===============================================================";
        exit(0);
    }
    system("cls");
}


void Print() {
    cout << "---RESULTS TABLE---\n\n--------------------------------------\n";
    cout << setw(3) << "#" << setw(10) << "x" << setw(15) << "y" << "\n";
    cout << "--------------------------------------\n";
    int i = 1;
    for (pair<double, double> pr : vt) {
        cout << setw(3) << i++
            << setw(10) << fixed << setprecision(3) << pr.first
            << setw(15) << fixed << setprecision(3) << pr.second
            << "\n";
    }
    cout << "--------------------------------------\n\n";
    cout << "Press B to return to the Main Menu...";
    char B = _getch();
    while (toupper(B) != 'B') B = _getch();
    system("cls");
}


void calculate() {
    vt.clear();
    for (double x = a; x <= b; x += step) vt.push_back(make_pair(x, calculateY(x, n)));
    cout << "\n--- CALCULATION ---\n\nThe program is calculating function values...\nCalculation completed successfully!\n\nPress B to return to the Main Menu...\n";
    char B = _getch();
    while (toupper(B) != 'B') B = _getch();
    system("cls");
    results.push_back(vt);
}


void inputN() {
    while (true) {
        try {
            cout << "Enter n (n > 1): ";
            double temp;
            if (!(cin >> temp)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "wrong data type. Please enter an integer!";
            }
            ValidateN(temp);

            cout << "Option added successfully!" << endl;
            return;
        }
        catch (const char* errorhandle) {
            cout << "Error: " << errorhandle << '\n';
        }
    }
}


void inputRange() {
    while (true) {
        try {
            cout << "Enter range (a, b) where a <= b: ";
            if (!(cin >> a >> b)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "wrong data type. Please enter two numbers!";
            }
            ValidateRange(a, b);

            cout << "Option added successfully!" << endl;
            return;
        }
        catch (const char* errorhandle) {
            cout << "Error: " << errorhandle << '\n';
        }
    }
}


void inputStep() {
    while (true) {
        try {
            cout << "Enter step > 0: ";
            if (!(cin >> step)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw "wrong data type.Please enter a number!";
            }
            ValidateStep(step);

            cout << "Option added successfully!" << endl;
            return;
        }
        catch (const char* errorhandle) {
            cout << "Error: " << errorhandle << '\n';
        }
    }
}


void Input() {
    cout << "--- ENTER PARAMETERS ---\n\n";
    inputN();
    inputRange();
    if (a == b) {
        cout << "a == b, step = 1 automatically\n";
        step = 1;
    }
    else inputStep();
    cout << "All options were added succesfully!";
    this_thread::sleep_for(chrono::seconds(3));
    system("cls");
}


void output_spec(int ind) {
    for (auto val : results[ind - 1]) {
        cout << val.first << " " << val.second << '\n';
    }
    this_thread::sleep_for(chrono::seconds(3));
}
void Main_Menu() {
    char choice;
    bool calc = false, inp = false;
    do {
        system("cls");
        cout << "\n==================== MAIN MENU ====================\n\n"
            << "1. Enter parameters (n, range (a,b), step)\n"
            << "2. Calculate results\n"
            << "3. Show results\n"
            << "4. Exit\n\n"
            << "Please select an option: ";
        choice = _getch();
        switch (choice) {
        case '1':
            system("cls");
            Input();
            inp = true;
            break;
        case '2':
            system("cls");
            if (inp) {
                calculate();
                calc = true;
            }
            else {
                cout << "YOU CAN`T CALCULATE THE RESULT BEFORE INPUTING IT!\n";
                this_thread::sleep_for(chrono::seconds(3));
                system("cls");
            }
            break;
        case '3':
            system("cls");
            if (calc) Print();
            else {
                cout << "YOU CAN`T PRINT THE RESULT BEFORE COMPUTING IT!\n";
                this_thread::sleep_for(chrono::seconds(3));
                system("cls");
            }
            break;
        case '4':
            system("cls");
            Exits();
            break;
        case '5':
            system("cls");
            char chs = _getch();
            output_spec(chs - '0');
        }
    } while (true);
}


int main() {
    cout << "=========================================\nWelcome to " << '"' << "Calculator of Function 23" << '"' << "\n=========================================\n\nThis program will help you calculate the function values within a given range.\n\nPress[N] to go to the Main Menu\n";
    char N = _getch();
    while (toupper(N) != 'N') N = _getch();
    system("cls");
    Main_Menu();
    return 0;
}