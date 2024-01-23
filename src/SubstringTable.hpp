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

   private:
    std::string inputString;
    int minLength;
    int maxLength;
    std::vector<std::string> substrings;
    std::vector<int> occurrences;
};