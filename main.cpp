#include <iostream>
#include <limits>

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    // Variables
    double num1, num2, result;
    char operation;
    bool continueCalculation = true;

    std::cout << R"(
         _____  _                 _          _____                     _____      _            _       _
        / ____|(_)               | |        / ____|    _     _       /  ____|    | |          | |     | |
        | (___  _ _ __ ___  _ __ | | ___    | |      _| |_ _| |_     | |     __ _| | ___ _   _| | __ _| |_ ___  _ __
         \___ \| | ,_  ,_ \|  _ \| |/ _ \   | |     |_   _|_   _|    | |   / _, | |/ __| | | | |/ _` | __/ _ \| '__|
        ____) || | | | | | | |_) | |  __/   | |_____  |_|   |_|      |__|__(_| | | (__| |_| | | (_| | || (_) | |
        |_____/|_|_| |_| |_| ,__/|_|\___|    \_____|                 \____\\__,_|_|\___|\__,_|_|\__,_|\__\___/|_|
                           | |
                           |_|
    )" << '\n';

    while (continueCalculation) {
        // Get first number
        std::cout << "\nEnter first number: ";
        while (!(std::cin >> num1)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Get operation
        std::cout << "Enter operation (+, -, *, /): ";
        std::cin >> operation;

        // Get second number
        std::cout << "Enter second number: ";
        while (!(std::cin >> num2)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Perform calculation
        switch (operation) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                if (num2 == 0) {
                    std::cout << "Error: Division by zero!" << std::endl;
                    continue;
                }
                result = divide(num1, num2);
                break;
            default:
                std::cout << "Error: Invalid operation!" << std::endl;
                continue;
        }

        // Display result
        std::cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << std::endl;

        // Ask if user wants to continue
        char choice;
        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            continueCalculation = false;
        }
    }

    std::cout << "\nThank you for using the calculator!" << std::endl;
    return 0;
}

// Function implementations
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}