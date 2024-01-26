#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SubstringTable.hpp"
#include "doctest.h"

TEST_CASE("Test SubstringTable") {
    SUBCASE("Test buildTable and countOccurrences") {
        SubstringTable substringTable("12312312332123", 2, 4);
        substringTable.buildTable();
        substringTable.countOccurrences();

        CHECK(substringTable.getUniqueSubstrings().count("12") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("23") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("31") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("123") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("231") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("312") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("33") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("32") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("21") == 1);
        CHECK(substringTable.getUniqueSubstrings().count("11") == 0);

        CHECK(substringTable.getUniqueSubstrings().size() == 21);
    }

    SUBCASE("Test findMaxOccurrences") {
        SubstringTable substringTable("12312312332123", 2, 4);
        substringTable.buildTable();
        substringTable.countOccurrences();
        substringTable.findMaxOccurrences();
    }

    SUBCASE("Test printResults") {
        SubstringTable substringTable("12312312332123", 2, 4);
        substringTable.buildTable();
        substringTable.countOccurrences();
        substringTable.findMaxOccurrences();
    }

    SUBCASE("Test clear") {
        SubstringTable substringTable("12312312332123", 2, 4);
        substringTable.buildTable();
        substringTable.countOccurrences();
        substringTable.clear();

        CHECK(substringTable.getUniqueSubstrings().empty());
    }
}
