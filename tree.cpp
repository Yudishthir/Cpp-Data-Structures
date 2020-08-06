#include <bits/stdc++.h>
using namespace std;

class Tree
{
	struct Node
	{
		struct Node* left;
		struct Node* right;
		int data;
	};

	struct Node* root;

	void findnAdd(struct Node* newNode, struct Node* node);
	void findnRemove(struct Node* node);
	void printInorder(struct Node* node);
	void printPostorder(struct Node* node);
	void printPreorder(struct Node* node);

public:
	Tree() {
		root = NULL;
	}	

	void add(int value);
	void print(const char* type);
	void remove();
};


void Tree::findnAdd(struct Node* newNode, struct Node* node) {
	if (node->left == NULL && node->right == NULL) {
		node->left = newNode;
		cout<<"left : " << node->left->data << endl; 
		newNode = NULL;
		delete newNode;
	}
	else if(node->left != NULL && node->right == NULL) {
		node->right = newNode;
		cout<<"right : " << node->right->data << endl;
		newNode = NULL;
		delete newNode;
	}
	else{
		cout << "left -> ";
		Tree::findnAdd(newNode,node->left);
	}
}

void Tree::findnRemove(struct Node* node) {
	if (node->left != NULL && node->right == NULL) { 
		cout << "deleting :: " << node->left->data << endl;
		node->left = NULL;
	}
	else if(node->left == NULL && node->right != NULL) {
		cout << "deleting :: " << node->right->data << endl;
		node->right = NULL;
	}
	else if (node->left != NULL && node->right != NULL && node->left->left == NULL && node->left->right == NULL)
	{
		cout << "deleting :: " << node->left->data << endl;
		node->left = NULL;
	}
	else{
		Tree::findnRemove(node->left);
	}
}

void Tree::printInorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    Tree::printInorder(node->left); 
    cout << node->data << " "; 
    Tree::printInorder(node->right); 
} 

void Tree::printPostorder(struct Node* node) {
	if (node == NULL)
		return;

	Tree::printPostorder(node->left);
	Tree::printPostorder(node->right);
	cout << node->data << " ";
}

void Tree::printPreorder(struct Node* node) {
	if (node == NULL)
		return;

	cout << node->data << " ";
	Tree::printPreorder(node->left);
	Tree::printPreorder(node->right);
}

/*=============== Private Functions End ===============*/

void Tree::add(int value) {
	struct Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;

	if(root == NULL) {
		root = temp;
		cout << "root : " << root->data << endl;
	}
	else 
		Tree::findnAdd(temp,root);

	temp = NULL;
	delete temp;
}

void Tree::print(const char* type) {
	if(strcmp(type, "in") == 0) {
		cout << "Inorder traversal : ";
		printInorder(root);
		cout << endl;
	}
	else if (strcmp(type, "pre") == 0)
	{
		cout << "Preorder traversal : ";
		printPreorder(root);
		cout << endl;
	}
	else {
		cout << "Postorder traversal : ";
		printPostorder(root);
		cout << endl;
	}
}

void Tree::remove() {
	findnRemove(root);
}

int main(int argc, char const *argv[])
{
	Tree t;
	t.add(10);
	t.add(20);
	t.add(30);
	t.add(40);
	t.add(50);
	t.add(60);
	t.print("in");
	t.print("pre");
	t.print("post");
	t.remove();
	t.remove();
	t.remove();
	t.print("in");
	return 0;
}