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
    const std::vector<std::string>& getSubstrings() const { return substrings; }

    const std::vector<int>& getOccurrences() const { return occurrences; }

    const std::string& getInputString() const { return inputString; }

    int getMinLength() const { return minLength; }

    int getMaxLength() const { return maxLength; }

   private:
    std::string inputString;
    int minLength;
    int maxLength;
    std::vector<std::string> substrings;
    std::vector<int> occurrences;
};