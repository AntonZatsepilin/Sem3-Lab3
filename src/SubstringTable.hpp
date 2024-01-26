#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
class SubstringTable {
   public:
    SubstringTable(const std::string& s, int lmin, int lmax);

    void buildTable();
    void countOccurrences();
    void findMaxOccurrences();
    void printResults();
    void clear();
    const std::set<std::string>& getUniqueSubstrings() const { return uniqueSubstrings; }

    const std::string& getInputString() const { return inputString; }

    int getMinLength() const { return minLength; }

    int getMaxLength() const { return maxLength; }

   private:
    std::string inputString;
    int minLength;
    int maxLength;
    std::map<std::string, int> substringOccurrences;
    std::set<std::string> uniqueSubstrings;
};