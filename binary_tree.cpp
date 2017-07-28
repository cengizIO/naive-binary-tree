#include "binary_tree.h"

#include <iostream>
#include <memory>


std::ostream& operator<<(std::ostream& os, const Node& node) {
	os << "Node { keyValue: " << node.keyValue;
	if (node.left != nullptr)
		os << ", left: " << *node.left;
	if (node.right != nullptr)
		os << ", right: " << *node.right;

	return os << " }";
}

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::~BinaryTree() {
	destroyTree();
}

void BinaryTree::destroyTree(Node *leaf) {
	if (leaf != nullptr) {
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

void BinaryTree::insert(int key, Node *leaf) {
	if (key < leaf->keyValue) {
		if (leaf->left != nullptr) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new Node;
			leaf->left->keyValue = key;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else {
		if (leaf->right != nullptr) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new Node;
			leaf->right->keyValue = key;
			leaf->right->left = nullptr;
			leaf->right->right = nullptr;
		}
	}
}

Node *BinaryTree::search(int key, Node *leaf) {
	if (leaf != nullptr) {
		if (key == leaf->keyValue)
			return leaf;

		if (key < leaf->keyValue) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}

	}
	else {
		return nullptr;
	}

}

void BinaryTree::insert(int key) {
	if (root != nullptr) {
		insert(key, root);
	}
	else {
		root = new Node;
		root->keyValue = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

Node *BinaryTree::search(int key) {
	return search(key, root);
}

void BinaryTree::destroyTree()
{
	destroyTree(root);
}

int main()
{
	std::unique_ptr<BinaryTree> t(new BinaryTree);
	t->insert(10);
	t->insert(7);
	t->insert(5);
	t->insert(11);

	std::shared_ptr<Node> result(t->search(10));

	if (result != nullptr)
		std::cout << *result << "\n";

}

