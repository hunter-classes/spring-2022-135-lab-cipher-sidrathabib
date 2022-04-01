#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"


TEST_CASE("CAESAR CIPHER SOLVER") {
  SUBCASE("Cypher Tests") {
    std::string test1 = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    std::string answer1 = "QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD";

    std::string test2 = "Efgfoe uif fbtu xbmm pg uif dbtumf";
    std::string answer2 = "Defend the east wall of the castle,";

    CHECK(solve(test1) == answer1);
    CHECK(solve(test2) == answer2);
  }

  SUBCASE("Cipher Phrases") {
    CHECK(solve("Zljeft Dtot") == "Zombie Here");
    CHECK(solve("Bfd yt Lt!") == "Way to Go!");
  }
}