// Note - the autograder expects this exact include for your catch code! If you use the manual catch compilation method, be sure you put this include back before submitting.
#include <catch2/catch_test_macros.hpp>

#include "GatorBST.h"

using namespace std;


// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...

TEST_CASE("Height of empty tree is 0", "[height]") {
	GatorBST tree;
	REQUIRE(tree.Height() == 0);
}

TEST_CASE("Height increases with insertions", "[height]") {
	GatorBST tree;
	tree.Insert(50, "Martina");
	tree.Insert(30, "Mikael");
	tree.Insert(70, "Austin");
	tree.Insert(20, "David");
	REQUIRE(tree.Height() == 3);
}