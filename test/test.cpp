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
TEST_CASE("Returns nullopt if node is not found", "[search_id]") {
	GatorBST tree;
	REQUIRE(!tree.SearchID(50).has_value());
}

TEST_CASE("Returns a string_view if node found", "[search_id]") {
	GatorBST tree;
	tree.Insert(50, "Martina");
	auto result = tree.SearchID(50);
	REQUIRE(result.has_value());
	REQUIRE(result.value() == "Martina");
}

//searchNAME tests:
// Searches for name. Since multiple UFID's can share the same name, returns a vector with all matching ID's in ascending order.
// If none are found, the returned vector will be empty.
TEST_CASE("Returns a vector with all matching ID's in ascending order", "[search_name]") {
	GatorBST tree;
	tree.Insert(50, "Martina");
	tree.Insert(30, "Martina");
	tree.Insert(70, "Martina");
	auto result = tree.SearchName("Martina");
    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == 30);
    REQUIRE(result[1] == 50);
    REQUIRE(result[2] == 70);
}

TEST_CASE("Returns empty vector for non-existent name", "[search_name]") {
	GatorBST tree;
	auto result = tree.SearchName("Martina");
	REQUIRE(result.empty());
}

//Remove tests:
// Deletes node with provided UFID. If found (and removed), return true. If node was not present, return false.
// If there are two children, replaces with inorder SUCCESSOR.
TEST_CASE("Remove existing node returns true", "[remove]") {
	GatorBST tree;
	REQUIRE(tree.Remove(50) == false);
}
TEST_CASE("Remove from empty tree returns false", "[remove]") {
	GatorBST tree;
	tree.Insert(50, "Martina");
	REQUIRE(tree.Remove(50) == true);
	REQUIRE(!tree.SearchID(50).has_value());
}

//preorder tests:
// Performs a preorder traversal and returns list of node pointers if there were nodes in the tree.
TEST_CASE("TraversePreorder empty tree returns empty vector", "[preorder_traversal]]") {
	GatorBST tree;
	REQUIRE(tree.TraversePreorder().empty());
}

//inorder tests:
// Performs an inorder traversal and returns list of node pointers if there were nodes in the tree.
TEST_CASE("TraverseInorder empty tree returns empty vector", "[inorder_traversal]]") {
	GatorBST tree;
	REQUIRE(tree.TraverseInorder().empty());
}

//postorder tests;
// Performs a postorder traversal and returns list of node pointers if there were nodes in the tree.
TEST_CASE("TraversePostorder empty tree returns empty vector", "[postorder_traversal]]") {
	GatorBST tree;
	REQUIRE(tree.TraversePostorder().empty());
}
