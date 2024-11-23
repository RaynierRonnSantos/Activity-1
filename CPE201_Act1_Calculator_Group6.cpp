#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

void printBorder() {
    cout << "****************************************\n";
}

bool getValidNumber(double &num) {
    while (!(cin >> num)) {
        cout << "Error: Invalid input. Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main() {
    char operation;
    double num1, num2;
    char choice;

    do {
        printBorder();
        cout << "*         Simple Calculator            *\n";
        printBorder();
        cout << "* Choose an operation:                *\n";
        cout << "* + : Addition                        *\n";
        cout << "* - : Subtraction                     *\n";
        cout << "* * : Multiplication                  *\n";
        cout << "* / : Division                        *\n";
        printBorder();

        bool validOperation = false;
        do {
            cout << "* Enter your choice: ";
            cin >> operation;

            if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
                validOperation = true;
            } else {
                cout << "Error: Invalid operation selected. Please try again.\n";
            }
        } while (!validOperation);

        bool validInput = false;
        while (!validInput) {
            cout << "* Enter the first number: ";
            if (!getValidNumber(num1)) {
                continue; 
            }

            cout << "* Enter the second number: ";
            if (!getValidNumber(num2)) {
                continue; 
            }

            validInput = true;

            printBorder();
            switch (operation) {
                case '+':
                    cout << "* Result: " << num1 + num2 << "                       *\n";
                    break;
                case '-':
                    cout << "* Result: " << num1 - num2 << "                       *\n";
                    break;
                case '*':
                    cout << "* Result: " << num1 * num2 << "                       *\n";
                    break;
                case '/':
                    if (num2 != 0) {
                        cout << "* Result: " << num1 / num2 << "                       *\n";
                    } else {
                        cout << "Error: Division by zero is not allowed.\n";
                        validInput = false; 
                    }
                    break;
            }
            printBorder();
        }

        cout << "* Do you want to perform another calculation? (y/n): ";
        cin >> choice;

        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            cout << "Invalid choice. Please enter 'y' for yes or 'n' for no: ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!\n";

    return 0;
}
