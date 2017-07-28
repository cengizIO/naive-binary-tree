#pragma once

#include <stdio.h>

struct Node
{
	int keyValue;
	Node *left;
	Node *right;
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	void insert(int key);
	Node *search(int key);
	void destroyTree();

private:
	void destroyTree(Node *leaf);
	void insert(int key, Node *leaf);
	Node *search(int key, Node *leaf);

	Node *root;
};