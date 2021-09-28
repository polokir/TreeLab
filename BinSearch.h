#include <iostream>
#include <vector>
#include <string>
#define SIZE 10
using namespace std;


class BinTreeSearch
{
private:
	class Node {
	public:
		int data;
		int index;
		Node* left;
		Node* right;
		Node(int data);
	};
	Node* root;
	int count;
public:
	BinTreeSearch(int data);
	void SetId(Node* cur);
	void push(int key);
	void output(Node* cur);
	void output1();
	void SearchByValue(int key);
	void printNode(Node* cur);
	Node* deleteNode();
	Node* getParent(Node* tree1, Node* tree2);
};

BinTreeSearch::Node::Node(int data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
}

BinTreeSearch::BinTreeSearch(int data) {
	root = new Node(data);
	count++;
	SetId(root);
}

void BinTreeSearch::SetId(Node* cur) {
	cur->index = count;
}

void BinTreeSearch::push(int key) {
	Node* cur = root;
	if (root == nullptr) {
		cur = new Node(key);
		cur->left = nullptr;
		cur->right = nullptr;
	}
	else if (key < root->data) {
		root->left = new Node(key);
		count++;
		SetId(cur);
	}
	else {
		root->right = new Node(key);
		count++;
		SetId(cur);
	}
}

void BinTreeSearch::output(Node* cur) {
	if (cur != nullptr) {
		cout << cur->data << endl;
		output(cur->left);
		output(cur->left);
	}
}

void BinTreeSearch::output1() {
	Node* cur = root;
	output(cur);
}

void BinTreeSearch::printNode(Node* cur) {
	cout << "[" << cur->index << "]" << cur->data<<endl;
}


 void BinTreeSearch::SearchByValue(int val) {
	Node*cur = root;

	while (true) {
		if (cur->data >= val) {
			if (cur->data == val) {
				cout << "Finded" << endl;
				printNode(cur);
			}
			else
				if (cur->left != nullptr)
					cur = cur->left;
				else {
					cout << "Nothing to search" << endl;
					return;
				}
		}
		else {
			if (cur->left != nullptr)
				cur = cur->left;
			else {
				cout<<"nothing to search"<<endl;
				return;
			}
		}
	}	
}

 BinTreeSearch::Node* BinTreeSearch::deleteNode() {
	 Node* previous = root;
	 Node* current = root;
	 if ((root->left == nullptr) && (root->right == nullptr)) { 
		 std::cout << "Root hasn't got leaves" << std::endl;
		 root = nullptr;
		 std::cout << "Tree with root " << current << " is deleted." << std::endl;
		 return nullptr;
	 }
	 while (true) { 
		 if (((current->left != nullptr) && (current->right == nullptr)) ||
			 ((current->left != nullptr) && (current->right != nullptr))) {
			 previous = current;
			 current = current->left;
		 }
		 else if ((current->left == nullptr) && (current->right != nullptr)) {
			 previous = current;
			 current = current->right;
		 }
		 else {
			 std::cout << "Node " << current << " is deleted." << std::endl;
			 if (previous->left == current)
				 previous->left = nullptr;
			 else
				 previous->right = nullptr;
			 current = nullptr;
			 return nullptr;
		 }
	 }
 }

 BinTreeSearch::Node* BinTreeSearch::getParent(Node* tree, Node* current) {
	 if (tree->data!=current->data) {
		 if (tree->data <= current->data) {
			 Node* res = getParent(tree->left, current); 
			 if (res)
				 return res;
			 return tree;
		 }
		 else if (tree->data >= current->data) {
			 Node* res = getParent(tree->right, current);
			 if (res)
				 return res;
			 return tree;
		 }
	 }
	 else return nullptr;
 }