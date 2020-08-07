#include <bits/stdc++.h>
using namespace std;

class BST
{
	struct Node
	{
		Node* left;
		Node* right;
		int data;
	};

	Node* root;

	Node* findnAdd(Node*, Node*);
	void printInorder(Node* node);

public:
	BST() {
		root = NULL;
	}

	void add(int);	
	void print();
};

BST::Node* BST::findnAdd(Node* newNode, Node* node) {
	if (node == NULL)
	{
		cout << newNode->data << endl;
		return newNode;
	}

	if (newNode->data > node->data)
	{   
		cout << "right-> ";
		node->right = findnAdd(newNode, node->right);
	}
	else if (newNode->data < node->data)
	{
		cout << "left-> ";
		node->left = findnAdd(newNode, node->left);
	}
	else {
		cout << "Node already exists\n";
	}

	return node;
}

void BST::printInorder(Node* node) {
	if (node == NULL)
	{
		return;
	}

	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

/*===========End of private functions==========*/ 

void BST::add(int value) {
	Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;

	if(root == NULL) {
		root = temp;
		cout << "root-> " << root->data << endl;
	}
	else 
		findnAdd(temp, root);

	temp = NULL;
	delete temp;
}

void BST::print() {
	cout << "Inorder Traversal : ";
	printInorder(root);
}

int main(int argc, char const *argv[])
{
	BST t;
	t.add(5);
	t.add(1);
	t.add(4);
	t.add(2);
	t.add(6);
	t.add(8);
	t.add(7);
	t.add(7);
	t.add(7);
	t.add(3);
	t.add(9);
	t.print();
	return 0;
}