#include <iostream>
#include <vector>
#include <string>
#define SIZE 10
using namespace std;


class BinTree
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
		BinTree(int data);
		~BinTree();
		void setID(Node*cur);
		void deleteBinTree();
		Node* getroot();
		int to_count(Node* cur);
		void push_back(int key);
		void prefixoutput(Node* current);
		void infixoutput(Node* cur);
		void postfixoutput(Node* cur);
		Node* deleteNode();
		void output();
		void symetricaloutput();
		void reverseoutput();
		bool check2Values(Node* cur, int value);
		bool checkEql(Node* cur, int val);
		bool check2Nodes(Node* tree1, Node*tree2);
		bool checkEql(Node* cur, Node*cur2);
		Node* getparent(Node* tree, Node* cur);
		void deleteNodeByValue(int key);
		

		
};

BinTree::Node::Node(int data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
}

BinTree::BinTree(int data) {
	root = new Node(data);
	count++;
	setID(root);
}

BinTree::~BinTree() {
	deleteBinTree();
}


BinTree::Node* BinTree::getroot() {
	return root;
}

int BinTree::to_count(Node*cur) {
	cur = root;
	return 1 + to_count(cur->right) + to_count(cur->left);
}

void BinTree::push_back(int key) {
	Node* cur = root;
	int   cmd;
	while (true) {
		if ((cur->left != nullptr) && (cur->right != nullptr)) {
			cout << "Choose node to add info" << endl;
			cout << "Press 1 to add left-node" << endl;
			cout << "Press 2 to add righr node" << endl;
			cin >> cmd;
			switch (cmd) {
			 case 1:
				 cur = cur->left;
				 break;
			 case 2:
				 cur = cur->right;
				 break;
			 default:
				 cout << "ERROR" << endl;
			}
		}
		else{
			if ((cur->left == nullptr) && (cur->right != nullptr)) {
				cout << "Choose node to add info" << endl;
				cout << "Press 1 to add left-node" << endl;
				cout << "Press 2 to add right node" << endl;
				cin >> cmd;
				switch (cmd) {
				case 1:
					cur->left = new Node(key);
					setID(cur->left);
					count++;
					return;
				case 2:
					cur=cur->right;
					break;
				default:
					cout << "ERROR" << endl;
					break;
				}
			}
			else if ((cur->left != nullptr) && (cur->right == nullptr)) {
				cout << "Choose node to add info" << endl;
				cout << "Press 1 to add left-node" << endl;
				cout << "Press 2 to add right node" << endl;
				cin >> cmd;
				switch (cmd) {
				case 2:
					cur->right = new Node(key);
					setID(cur->right);
					count++;
					return;
				case 1:
					cur = cur->right;
					break;
				default:
					cout << "ERROR" << endl;
					break;
				}
			}
			else {
				cout << "Choose node to add info" << endl;
				cout << "Press 1 to add left-node" << endl;
				cout << "Press 2 to add right node" << endl;
				cin >> cmd;
				switch (cmd) {
				case 1:
					cur->left = new Node(key);
					setID(cur->left);
					count++;
					return;
				case 2:
					cur->right=new Node(key);
					setID(cur->right);
					count++;
					return;
				default:
					cout << "ERROR" << endl;
					break;
				}

			}
		}
	}
}

void BinTree::prefixoutput(Node* cur) {
	if (cur != nullptr) {
		cout << cur->data << endl;
		prefixoutput(cur->left);
		prefixoutput(cur->right);
	}
}

void BinTree::infixoutput(Node* cur) {
	
	if (cur != nullptr) {
		
		prefixoutput(cur->left);
		cout << cur->data << endl;
		prefixoutput(cur->right);
	}
}

void BinTree::postfixoutput(Node* cur) {
	
	if (cur != nullptr) {

		prefixoutput(cur->left);
		prefixoutput(cur->right);
		cout << cur->data << endl;
	}
}

BinTree::Node* BinTree::deleteNode()
{
	Node* previous = root;
	Node* current = root;
	if ((root->left == nullptr) && (root->right == nullptr)) {  
		std::cout << "Root hasn't got leaves" << std::endl;
		root = nullptr;
		std::cout << "Tree with root " << current << " is deleted." << std::endl;
		return nullptr;
	}
	while (true) { // ѕроход по дереву и затирание указателей
		if (current->left != nullptr) {
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
void BinTree::setID(Node* cur) {
	cur->index = count;
}

void BinTree::deleteBinTree() {
	while (root != nullptr) {
		deleteNode();
	}
}

void BinTree::output() {
	Node* cur = root;
	prefixoutput(cur);
}
void BinTree::symetricaloutput() {
	Node* cur = root;
	infixoutput(cur);
}

void BinTree::reverseoutput() {
	Node* cur = root;
	postfixoutput(cur);
}

bool BinTree::check2Values(Node* cur, int key) {
	if (cur->data >= key)
		return true;
	return false;
}

bool BinTree::check2Nodes(Node* tree1, Node* tree2) {
	if (tree1->data <= tree2->data)
		return true;
	return false;
}
bool BinTree::checkEql(Node* cur, int key) {
	if (cur->data == key)
		return true;
	return false;
}

bool BinTree::checkEql(Node* cur, Node* cur2) {
	if (cur->data == cur->data)
		return true;
	return false;
}

BinTree::Node* BinTree::getparent(Node* tree, Node* cur) {
	if (!checkEql(cur, tree)) {
		if (check2Nodes(cur, tree)) {
			Node* parent = getparent(tree->left, cur);
			if (parent)
				return parent;
		}
		else if (!check2Nodes(cur, tree)) {
			Node* parent = getparent(tree->right, cur);
			if (parent)
				return parent;
			return tree;
		}
	}
	else return nullptr;
}

void BinTree::deleteNodeByValue(int key) {
	Node* current = root;
	Node* parent = getparent(root, current);
	if (current->left == nullptr && current->right == nullptr) {
		if (checkEql(current,key)) {
			if (parent->left == current)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		else return;
	}
	else if (current->left == nullptr || current->right == nullptr) {
		if (checkEql(current, key)) {
			if (current->left == nullptr) {
				if (parent->left = current) {
					parent->left = current->left;
					current = parent->left;
				}
				else {
					parent->right = current->left;
					current = parent->right;
				}
			}
			else {
				if (parent->left = current) {
					parent->left = current->right;
					current = parent->left;
				}
				else {
					parent->right = current->right;
					current = parent->right;
				}
			}
		}
		else {

		}
	}
}

