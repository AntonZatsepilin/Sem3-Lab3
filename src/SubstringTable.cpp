#include "SubstringTable.hpp"

SubstringTable::SubstringTable(const std::string& s, int lmin, int lmax)
    : inputString(s), minLength(lmin), maxLength(lmax) {}

void SubstringTable::buildTable() {
    for (int len = minLength; len <= maxLength; ++len) {
        for (int i = 0; i <= inputString.length() - len; ++i) {
            std::string substring = inputString.substr(i, len);
            substringOccurrences[substring] = 0;
        }
    }
}

void SubstringTable::countOccurrences() {
    for (int i = 0; i <= inputString.length() - minLength; ++i) {
        for (int len = minLength; len <= maxLength && i + len <= inputString.length(); ++len) {
            std::string sub = inputString.substr(i, len);
            substringOccurrences[sub]++;
        }

        for (const auto& entry : substringOccurrences) {
            if (entry.second > 0) {
                uniqueSubstrings.insert(entry.first);
            }
        }
    }
}

void SubstringTable::findMaxOccurrences() {
    int maxCount = 0;

    for (const auto& entry : substringOccurrences) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }

    std::cout << "Substrings with maximum occurrences:" << std::endl;
    for (const auto& entry : substringOccurrences) {
        if (entry.second == maxCount) {
            std::cout << "Substring: " << entry.first << ", Occurrences: " << maxCount << std::endl;
        }
    }
}

void SubstringTable::printResults() {
    std::vector<std::pair<std::string, int>> sortedResults;

    for (const auto& substring : uniqueSubstrings) {
        sortedResults.push_back(std::make_pair(substring, substringOccurrences[substring]));
    }

    std::sort(sortedResults.rbegin(), sortedResults.rend(),
              [](const auto& a, const auto& b) { return a.second < b.second; });

    std::cout << "Unique substrings and their occurrences (in descending order):" << std::endl;
    for (const auto& result : sortedResults) {
        std::cout << "Substring: " << result.first << ", Occurrences: " << result.second << std::endl;
    }
}

void SubstringTable::clear() {
    substringOccurrences.clear();
    uniqueSubstrings.clear();
}