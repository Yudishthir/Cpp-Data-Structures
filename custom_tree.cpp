#include <bits/stdc++.h>
#include <string>
using namespace std;

class Tree
{
	struct Node
	{
		Node* left;
		Node* right;
		int data;
	};

	Node* root;

	void upper(string& loc);
	void findnAdd(Node* newNode, Node* node, string loc, int pos);
	void findnRemove(Node* node, string loc, int pos);
	void printInorder(Node*);
	void printPostorder(Node*);
	void printPreorder(Node*);

public:
	Tree() {
		root = NULL;
	}	

	void add(int, string);
	void remove(string);
	void print(const char*);
};

void Tree::upper(string& loc) {
	string temp = "";
	for (int i = 0; i < loc.size(); ++i)
	{
		if((int)loc[i] <= 90)
			continue;
		else {
			loc[i] = loc[i] - 32;
		}
	}
}

/*
void Tree::findnRemove(Node* node, string loc, int pos) {
	if(node == NULL) {
		cout << "Invalid code";
		return;
	}

	if(pos == loc.size() - 1) {
		if (loc[pos] == 'L')
		{	
			cout << "left : " << node->left->data << endl;
			node->left = node->left->left;
			return;
		}
		else if (loc[pos] == 'R')
		{
			cout << "right : " << node->right->data << endl;				
			node->right = node->right->left;
			return;
		}
	}
	if (loc[pos] == 'L')
	{
		cout << "left->";
		findnRemove(node->left,loc,++pos);
	}
	else if (loc[pos] == 'R')
	{
		cout << "right->";
		findnRemove(node->right,loc,++pos);
	}
}
*/

void Tree::findnAdd(Node* newNode, Node* node, string loc, int pos) {
	if(node == NULL) {
		cout << "Invalid code";
		return;
	}

	if(pos == loc.size() - 1) {
		if (loc[pos] == 'L')
		{	
			cout << "left : " << newNode->data << endl;
			node->left = newNode;
			return;
		}
		else if (loc[pos] == 'R')
		{
			cout << "right : " << newNode->data << endl;				
			node->right = newNode;
			return;
		}
	}
	if (loc[pos] == 'L')
	{
		cout << "left->";
		findnAdd(newNode,node->left,loc,++pos);
	}
	else if (loc[pos] == 'R')
	{
		cout << "right->";
		findnAdd(newNode,node->right,loc,++pos);
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

/*===========End of private functions===========*/

void Tree::add(int value, string loc) {
	Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = value;

	upper(loc);

	if (root == NULL){
		root = temp;
		cout << "root : " << root->data << endl;
	}
	else if (loc != "ROOT")
	{
		findnAdd(temp, root, loc, 0);
	}

	temp = NULL;
	delete temp;
}

/*
void Tree::remove(string loc) {
	findnRemove(root,loc,0);
}
*/

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

int main(int argc, char const *argv[])
{
	Tree t;
	t.add(10,"ROOT");
	t.add(50, "l");
	t.add(60, "R");
	t.add(70, "Ll");
	t.add(80, "lr");
	t.add(90, "lr");

	t.print("in");
	t.print("pre");
	t.print("post");

	/*
	t.remove("L");
	t.print("in");
	t.print("pre");
	t.print("post");
	*/
	return 0;
}