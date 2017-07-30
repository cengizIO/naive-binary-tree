#define CATCH_CONFIG_MAIN

#include "include/catch/single_include/catch.hpp"
#include "binary_tree.h"

TEST_CASE("Nodes are found or not found", "[search]") {

	std::shared_ptr<BinaryTree> tree(new BinaryTree);

	for (auto &i : { 10, 7, 5, 11 }) {
		tree->insert(i);
	}

	REQUIRE(tree->search(10) != nullptr);
	REQUIRE(tree->search(99) == nullptr);
}