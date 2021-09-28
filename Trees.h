#include <iostream>
#include <vector>
using namespace std;
class Tree {
private:

	class Node {
	public:
		int ID;
		int data;
		vector<Node*> leaves;
		Node(int data);
	};
	int count;
	Node* root;
public:
	Tree(int data);
	~Tree();
	Node* getRoot();
	void append(int key);
	void setId(Node* current);
	void outputTree(Node* current, int temp = 0);
	void defaultOutput();
	Node* deleteNode();
	void deleteTree(Node* current);
	//Not completed
	void printNode(Node* current);
	void deleteNodeByIndex(int index);
	void deleteNodeByValue(int value);
	void searchNodeByValue(int value);
	Node* getParent(Node* current);
	void preOrder();

};
Tree::Node::Node(int data) {
	this->data = data;
}

Tree::Tree(int data) {
	root = new Node(data);
	count = 1;
	Tree::setId(root);
}

Tree::~Tree() {
	deleteTree(root);
}

Tree::Node* Tree::getRoot() {
	return root;
}

void Tree::outputTree(Node* current, int temp) {
	std::cout << "[" << current->ID << "]:" << current->data << "\n";
	temp++;
	int len = current->leaves.size();
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < temp; j++)
			cout << '\t';
		cout << i << ". ";
		outputTree(current->leaves[i], temp);
	}
}

void Tree::defaultOutput() {
	outputTree(root, 0);
}

void Tree::append(int key) {
	Node* current = root;
	int tmp;
	if (root->leaves.empty()) {
		Node* newNode = new Node(key);
		count++;
		Tree::setId(newNode);
		root->leaves.push_back(newNode);

		std::cout << "Tree is empty, node is added to root" << std::endl;
		return;
	}
	while (true) {
		Tree::outputTree(current);
		if (current->leaves.empty()) {
			Node* newNode = new Node(key);
			count++;
			Tree::setId(newNode);
			current->leaves.push_back(newNode);
			return;
		}
		std::cout << "Free leaves: ";
		for (int i = 0; i < current->leaves.size(); i++) {
			std::cout << i << ' ';
		}
		std::cout << "\nChoose the leap or enter\"-1\"\n";
		std::cin >> tmp;
		if (tmp == -1) {
			Node* newNode = new Node(key);
			count++;
			Tree::setId(newNode);
			current->leaves.push_back(newNode);
			return;
		}
		else
			current = current->leaves[tmp];
	}
}

Tree::Node* Tree::deleteNode() {
	Node* current = root;
	Node* previous = root;
	int tmp = -1, act;

	if (root->leaves.empty()) {
		std::cout << "There is no leaves..." << std::endl;
		return nullptr;
	}

	while (true) {
		Tree::outputTree(current);
		if (current->leaves.empty()) {
			std::cout << "That node hasn't got leaves." << std::endl;
			previous->leaves.erase(previous->leaves.begin() + tmp);
			std::cout << "Node " << current << " is deleted" << std::endl;
			return current;
		}

		std::cout << "Free leaves: ";
		for (int i = 0; i < current->leaves.size(); i++)
			std::cout << i << ' ';
		std::cout << "\nChoose the leafe or press \"-1\"\n";
		std::cin >> act;
		if (act == -1) {
			if (tmp == -1) {
				std::cout << "You can't delete root" << std::endl;
				continue;
			}
			previous->leaves.erase(previous->leaves.begin() + tmp);
			std::cout << "Node " << current << " is deleted" << std::endl;
			return current;

		}
		else {
			tmp = act;
			previous = current;
			current = current->leaves[tmp];
		}
	}
}

void Tree::deleteTree(Tree::Node* current) {
	for (auto& leaf : current->leaves)
		deleteTree(leaf);
	std::cout << "Node " << current << " is deleted" << std::endl;
	delete current;
}

void Tree::setId(Tree::Node* current) {
	current->ID = count;
}

void Tree::printNode(Tree::Node* current) {
	std::cout << "[" << current->ID << "]: " << current << " " <<
		current->data << endl;
}


void Tree::deleteNodeByIndex(int index) {
	Node* current = root;
	for (int i = 0; i < current->leaves.size(); i++) {
		if (current->leaves[i]->ID == index) {
			std::cout << "Node " << current->leaves[i] << " is deleted."
				<< std::endl;
			current = current->leaves[i];
			while (true) {
				if (current->leaves.size() == 0) {
					current = nullptr;
					return;
				}
				else {
					for (int i = 0; i < current->leaves.size(); i++) {
						current->leaves[i] = nullptr;
					}
				}
			}
		}
	}
}

Tree::Node* Tree::getParent(Node* current) {
	return nullptr;
}