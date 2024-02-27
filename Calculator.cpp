#include <iostream>
#include <limits>

void clearScreen() {
    // Limpar a tela do console
    std::cout << "\033[2J\033[1;1H";
}

int main() {
    while (true) {

        // Entrada com checker de numeros, operadores
        // identifica de alguma coisa foi posta errada
        float first;
        std::cout << "Enter the first number: ";
        while (!(std::cin >> first)) {
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        float second;
        std::cout << "Enter the second number: ";
        while (!(std::cin >> second)) {
            std::cout << "Invalid input. Please enter a valid number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        char operador;
        std::cout << "Enter the operator (+, -, *, /, %): ";
        while (!(std::cin >> operador) || (operador != '+' && operador != '-' && operador != '*' && operador != '/' && operador != '%')) {
            std::cout << "Invalid operator. Please enter a valid operator (+, -, *, /, %): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Switch para calcular de acordo com o operador escolhido
        switch (operador) {
        case '+':
            std::cout << first << " + " << second << " = " << first + second << '\n';
            break;

        case '-':
            std::cout << first << " - " << second << " = " << first - second << '\n';
            break;

        case '*':
            std::cout << first << " * " << second << " = " << first * second << '\n';
            break;

        case '/':
            if (second == 0) {
                std::cout << "Error: Division by zero.\n";
            }
            else {
                std::cout << first << " / " << second << " = " << first / second << '\n';
            }
            break;

        case '%':
            std::cout << first << " % " << second << " = " << (first * second) / 100 << '\n';
            break;

        default:
            std::cout << "Operation not allowed. \n";
            break;
        }

        // Pede uma confirmação se a pessoa quer fazer outra conta ou não
        char choice;
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            #ifdef WIN32
            system("cls");
            #elif defined(__linux__) || defined(__APPLE__)
            system("clear");
            #endif
            std::cout << "Exiting... \n";
            break;
        }

        clearScreen();
    }

    return 0;
}
