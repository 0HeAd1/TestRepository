#include <iostream>
#include <conio.h>
#include <thread>   
#include <chrono>   
#include <vector>
#include <iomanip>


using namespace std;
double a, b, step;
int n;
vector<pair<double, double>> vt;

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
    for (double x = a; x <= b; x += step) {
        double y;
        if (x < 0) {
            y = 1;
            for (double i = 1; i <= n + 1; i++) y *= (double)(x + 3) / (i - x);
        }
        else {
            y = (double)1 / (3 * x + 1);
            double sum = 0;
            for (double j = 0; j <= n + 1; j++) {
                double mult = 1.0;
                for (double i = 1; i <= n; i++) mult *= (i + (double)(j * j) / (i + x));
                sum += mult;
            }
            y -= sum;
        }
        vt.push_back(make_pair(x, y));
    }
    cout << "\n--- CALCULATION ---\n\nThe program is calculating function values...\nCalculation completed successfully!\n\nPress B to return to the Main Menu...\n";
    char B = _getch();
    while (toupper(B) != 'B') B = _getch();
    system("cls");
}

void inputN() {
    while (true) {
        cout << "Enter n (n > 1): ";
        double temp;
        if (!(cin >> temp)) {
            cout << "Error: wrong data type. Please enter an integer!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (temp != (int)temp) {
            cout << "Error: n must be an integer!" << endl;
            continue;
        }
        n = (int)temp;
        if (n > 1) {
            cout << "Option added successfully!" << endl;
            return;
        }
        cout << "Error: n must be greater than 1!" << endl;
    }
}

void inputRange() {
    while (true) {
        cout << "Enter range (a, b) where a <= b: ";
        if (!(cin >> a >> b)) {
            cout << "Error: wrong data type. Please enter two numbers!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (a <= b) {
            cout << "Option added successfully!" << endl;
            return;
        }
        cout << "Error: a must be less than or equal to b!" << endl;
    }
}

void inputStep() {
    while (true) {
        cout << "Enter step > 0: ";
        if (!(cin >> step)) {
            cout << "Error: wrong data type. Please enter a number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (step > 0) {
            cout << "Option added successfully!" << endl;
            return;
        }
        cout << "Error: step must be greater than 0!" << endl;
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