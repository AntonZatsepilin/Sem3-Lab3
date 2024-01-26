#include "SubstringTable.hpp"

int main() {
    SubstringTable substringTable("", 0, 0);
    while (true) {
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Enter a new input string" << std::endl;
        std::cout << "2. Exit" << std::endl;
        std::cout << "--------------------------------------" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            substringTable.clear();
            std::string inputString;
            int lmin, lmax;

            std::cout << "Enter the input string: ";
            std::cin >> inputString;

            std::cout << "Enter the minimum length of substrings: ";
            std::cin >> lmin;

            std::cout << "Enter the maximum length of substrings: ";
            std::cin >> lmax;

            SubstringTable substringTable(inputString, lmin, lmax);
            substringTable.buildTable();
            substringTable.countOccurrences();
            substringTable.findMaxOccurrences();
            substringTable.printResults();
        } else if (choice == 2) {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}