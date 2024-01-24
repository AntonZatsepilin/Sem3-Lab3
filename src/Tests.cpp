// tests.cpp
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SubstringTable.hpp"
#include "doctest.h"

TEST_CASE("Test SubstringTable") {
    SubstringTable substringTable("abracadabra", 2, 4);

    SUBCASE("Test buildTable") {
        substringTable.buildTable();
        CHECK(substringTable.getSubstrings().size() == 27);
    }

    SUBCASE("Test countOccurrences") {
        substringTable.buildTable();
        substringTable.countOccurrences();
        CHECK(substringTable.getOccurrences()[0] == 2);
        CHECK(substringTable.getOccurrences()[5] == 1);
    }

    SUBCASE("Test findMaxOccurrences") {
        substringTable.buildTable();
        substringTable.countOccurrences();
        substringTable.findMaxOccurrences();
    }

    SUBCASE("Test clear") {
        substringTable.clear();
        CHECK(substringTable.getSubstrings().empty());
        CHECK(substringTable.getOccurrences().empty());
    }
}

TEST_CASE("Test SubstringTable") {
    SUBCASE("Test buildTable") {
        SubstringTable substringTable1("abracadabra", 2, 4);
        substringTable1.buildTable();
        CHECK(substringTable1.getSubstrings().size() == 27);
        CHECK(substringTable1.getSubstrings()[0] == "ab");
        CHECK(substringTable1.getSubstrings()[26] == "abra");

        SubstringTable substringTable2("hello", 1, 3);
        substringTable2.buildTable();
        CHECK(substringTable2.getSubstrings().size() == 12);
        CHECK(substringTable2.getSubstrings()[0] == "h");
        CHECK(substringTable2.getSubstrings()[11] == "llo");
    }

    SUBCASE("Test countOccurrences") {
        SubstringTable substringTable3("aaaaaa", 2, 4);
        substringTable3.buildTable();
        substringTable3.countOccurrences();
        CHECK(substringTable3.getOccurrences()[0] == 5);
        CHECK(substringTable3.getOccurrences()[1] == 5);
        CHECK(substringTable3.getOccurrences()[3] == 5);

        SubstringTable substringTable4("abcabcabc", 1, 3);
        substringTable4.buildTable();
        substringTable4.countOccurrences();
        CHECK(substringTable4.getOccurrences()[0] == 3);
        CHECK(substringTable4.getOccurrences()[2] == 3);
        CHECK(substringTable4.getOccurrences()[5] == 3);
    }

    SUBCASE("Test clear") {
        SubstringTable substringTable6("testing", 2, 4);
        substringTable6.buildTable();
        substringTable6.countOccurrences();
        substringTable6.clear();
        CHECK(substringTable6.getSubstrings().empty());
        CHECK(substringTable6.getOccurrences().empty());
    }
}
