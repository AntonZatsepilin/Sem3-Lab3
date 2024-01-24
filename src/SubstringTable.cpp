#include "SubstringTable.hpp"

#include <iostream>
#include <set>
SubstringTable::SubstringTable(const std::string& s, int lmin, int lmax)
    : inputString(s), minLength(lmin), maxLength(lmax) {}

void SubstringTable::buildTable() {
    for (int len = minLength; len <= maxLength; ++len) {
        for (int i = 0; i <= inputString.length() - len; ++i) {
            std::string substring = inputString.substr(i, len);
            substrings.push_back(substring);
            occurrences.push_back(0);
        }
    }
}

void SubstringTable::countOccurrences() {
    for (int i = 0; i < inputString.length(); ++i) {
        for (int j = 0; j < substrings.size(); ++j) {
            if (inputString.compare(i, substrings[j].length(), substrings[j]) == 0) {
                occurrences[j]++;
            }
        }
    }
}

void SubstringTable::findMaxOccurrences() {
    std::set<std::string> uniqueSubstrings;
    int maxCount = 0;

    for (int count : occurrences) {
        if (count > maxCount) {
            maxCount = count;
        }
    }

    for (int i = 0; i < occurrences.size(); ++i) {
        if (occurrences[i] == maxCount) {
            uniqueSubstrings.insert(substrings[i]);
        }
    }

    std::cout << "Substrings with maximum occurrences:" << std::endl;
    for (const auto& substring : uniqueSubstrings) {
        std::cout << "Substring: " << substring << ", Occurrences: " << maxCount << std::endl;
    }
}

void SubstringTable::printResults() {
    std::cout << "All substrings and their occurrences:" << std::endl;
    for (int i = 0; i < occurrences.size(); ++i) {
        std::cout << "Substring: " << substrings[i] << ", Occurrences: " << occurrences[i] << std::endl;
    }
}

void SubstringTable::clear() {
    substrings.clear();
    occurrences.clear();
}