// Note - the autograder expects this exact include for your catch code! If you use the manual catch compilation method, be sure you put this include back before submitting.
#include <catch2/catch_test_macros.hpp>

#include "GatorBST.h"

using namespace std;


// You are free to write as many tests as you want. Your credit for this
// assignment will be based on the proportion of passing tests as well as the
// number of mutants caught, so it might be a good idea to write many small,
// focused tests over a few large, potentially buggy tests...

//height tests:
// Returns 1-based height of tree. In other words, if it is empty, the height is 0, otherwise this returns the length
//  of the longest path in nodes.
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

//insert tests:
// Inserts into BST. If successful, returns true, otherwise false.
    // Will fail if UFID already exists in the tree.
    // We assume the name and ID are properly formatted at this point, so no validation happens within this function.
TEST_CASE("Insert returns true for new UFID", "[insert]") {
	GatorBST tree;
	REQUIRE(tree.Insert(50, "Martina") == true);
}

TEST_CASE("Insert duplicate returns false", "[insert]") {
	GatorBST tree;
	tree.Insert(50, "Martina");
	REQUIRE(tree.Insert(50, "Mikael") == false);
}

//searchID tests:
// Searches for node with given UFID. Returns an optional string view - if not found, returns std::nullopt and will
// fail .has_value check. If found, returns a string_view, which is essentially a fancier form of a pointer for a
// string that does not allocate new memory or take "ownership".
TEST_CASE("If not found, returns nullopt", "[search_id]") {
	GatorBST tree;
	REQUIRE(!tree.SearchID(50).has_value());
}

TEST_CASE("If found, returns a string_view", "[search_id]") {
	GatorBST tree;
	tree.Insert(50, "Martina");
	auto result = tree.SearchID(50);
	REQUIRE(result.has_value());
	REQUIRE(result.value() == "Martina");
}

//searchNAME tests:
// Searches for name. Since multiple UFID's can share the same name, returns a vector with all matching ID's in ascending order.
// If none are found, the returned vector will be empty.

//Remove tests:
// Deletes node with provided UFID. If found (and removed), return true. If node was not present, return false.
// If there are two children, replaces with inorder SUCCESSOR.

//preorder tests:
// Performs a preorder traversal and returns list of node pointers if there were nodes in the tree.

//inorder tests:
// Performs an inorder traversal and returns list of node pointers if there were nodes in the tree.

//postorder tests;
// Performs a postorder traversal and returns list of node pointers if there were nodes in the tree.
