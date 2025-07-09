#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

// Function declarations
void displayMainMenu();
void performArithmeticOperations();
void performNumberConversions();

float add(float, float);
float subtract(float, float);
float multiply(float, float);
float divide(float, float);

string decToBin(int);
string decToOct(int);
string decToHex(int);
int binToDec(const string&);
int octToDec(const string&);
int hexToDec(const string&);

bool isBinary(const string&);
bool isOctal(const string&);
bool isHex(const string&);

int main() {
    int choice;
    do {
        displayMainMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(INT_MAX, '\n'); // ignore last input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            performArithmeticOperations();
            break;
        case 2:
            performNumberConversions();
            break;
        case 3:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

// Display the main menu
void displayMainMenu() {
    cout << "\n===== C++ Calculator =====\n";
    cout << "1. Arithmetic Operations\n";
    cout << "2. Number Base Conversions\n";
    cout << "3. Exit\n";
}

// Arithmetic module
void performArithmeticOperations() {
    int choice;
    float num1, num2;

    do {
        cout << "\n--- Arithmetic Operations ---\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
        }

        switch (choice) {
        case 1:
            cout << "Result: " << add(num1, num2) << endl;
            break;
        case 2:
            cout << "Result: " << subtract(num1, num2) << endl;
            break;
        case 3:
            cout << "Result: " << multiply(num1, num2) << endl;
            break;
        case 4:
            if (num2 == 0)
                cout << "Error: Division by zero is not allowed.\n";
            else
                cout << "Result: " << divide(num1, num2) << endl;
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

// Arithmetic operations
float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }

// Conversion module
void performNumberConversions() {
    int choice;
    string input;

    do {
        cout << "\n--- Number Base Conversions ---\n";
        cout << "1. Decimal to Binary\n";
        cout << "2. Decimal to Octal\n";
        cout << "3. Decimal to Hexadecimal\n";
        cout << "4. Binary to Decimal\n";
        cout << "5. Octal to Decimal\n";
        cout << "6. Hexadecimal to Decimal\n";
        cout << "7. Return to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int num;
            cout << "Enter a decimal number: ";
            cin >> num;
            cout << "Binary: " << decToBin(num) << endl;
            break;
        }
        case 2: {
            int num;
            cout << "Enter a decimal number: ";
            cin >> num;
            cout << "Octal: " << decToOct(num) << endl;
            break;
        }
        case 3: {
            int num;
            cout << "Enter a decimal number: ";
            cin >> num;
            cout << "Hexadecimal: " << decToHex(num) << endl;
            break;
        }
        case 4: {
            cout << "Enter a binary number: ";
            cin >> input;
            if (isBinary(input))
                cout << "Decimal: " << binToDec(input) << endl;
            else
                cout << "Invalid binary number.\n";
            break;
        }
        case 5: {
            cout << "Enter an octal number: ";
            cin >> input;
            if (isOctal(input))
                cout << "Decimal: " << octToDec(input) << endl;
            else
                cout << "Invalid octal number.\n";
            break;
        }
        case 6: {
            cout << "Enter a hexadecimal number: ";
            cin >> input;
            if (isHex(input))
                cout << "Decimal: " << hexToDec(input) << endl;
            else
                cout << "Invalid hexadecimal number.\n";
            break;
        }
        case 7:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);
}

// Conversion helpers
string decToBin(int num) {
    if (num == 0) return "0";
    string bin = "";
    while (num > 0) {
        bin = to_string(num % 2) + bin;
        num /= 2;
    }
    return bin;
}

string decToOct(int num) {
    if (num == 0) return "0";
    string oct = "";
    while (num > 0) {
        oct = to_string(num % 8) + oct;
        num /= 8;
    }
    return oct;
}

string decToHex(int num) {
    if (num == 0) return "0";
    string hex = "";
    string digits = "0123456789ABCDEF";
    while (num > 0) {
        hex = digits[num % 16] + hex;
        num /= 16;
    }
    return hex;
}

int binToDec(const string& bin) {
    int dec = 0;
    for (char c : bin) {
        dec = dec * 2 + (c - '0');
    }
    return dec;
}

int octToDec(const string& oct) {
    int dec = 0;
    for (char c : oct) {
        dec = dec * 8 + (c - '0');
    }
    return dec;
}

int hexToDec(const string& hex) {
    int dec = 0;
    for (char c : hex) {
        dec *= 16;
        if (isdigit(c))
            dec += c - '0';
        else if (isalpha(c)) {
            c = toupper(c);
            dec += c - 'A' + 10;
        }
    }
    return dec;
}

// Validators
bool isBinary(const string& s) {
    return all_of(s.begin(), s.end(), [](char c) { return c == '0' || c == '1'; });
}

bool isOctal(const string& s) {
    return all_of(s.begin(), s.end(), [](char c) { return c >= '0' && c <= '7'; });
}

bool isHex(const string& s) {
    return all_of(s.begin(), s.end(), [](char c) {
        return isdigit(c) || (toupper(c) >= 'A' && toupper(c) <= 'F');
        });
}
