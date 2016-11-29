#include <iostream>
using namespace std;

struct Node {
	string name;
	Node * parent;
	Node ** children;
	int numberOfChildren;
	int cnt;

	Node(string name, Node * parent) {
	    this -> name = name;
		this -> parent = parent;
		cnt = 0;
		numberOfChildren = 0;
	}

	void addChild(string name) {
		Node * child = new Node(name, this);
		children[cnt ++] = child;
	}

	void printChildren() {
		for (int i = 0; i< numberOfChildren; i ++) {
			cout << children[i] -> name << " ";
		}
		cout << "\n";
	}
	
	void printGrandParent() {
		if (parent != NULL && parent -> parent != NULL) {
			cout << parent -> parent -> name << "\n";
		} else {
			cout << "NOT FOUND\n";
		}
  	}

  	void printGrandSons() {
		for (int i = 0; i < numberOfChildren; i ++) {
			for (int j = 0; j < children[i] -> numberOfChildren; j ++) {
				cout << children[i] -> children[j] -> name << " ";
			}
		}
		cout << "\n";
  	}

	Node * find(string name) {
		if (this -> name == name) {
			return this;
		}
		for (int i = 0; i < numberOfChildren; i++) {
			if (children[i] == NULL) continue; 
			Node * tmp = children[i] -> find(name);
			if (tmp != NULL) return tmp;
		}
		return NULL;
	}
};

int n, m;
Node * root;

void readNode(bool firstNode) {
	int k;
	string parent, child;
	cin >> k >> parent;

	Node * p;
	if (firstNode) {
	    root = new Node(parent, NULL);	
	    p = root;
	} else {
		p =	root -> find(parent);
	}
	p -> children = new Node*[k];
	p -> numberOfChildren = k;
	p -> cnt = 0;

	for (int i = 0; i< k; i ++) {
		cin >> child;
		p -> addChild(child);
	}
	
}

string name;
int command;

int main() {
	cin >> n;
	readNode(true);
	for (int i = 1; i < n; i ++) {
		readNode(false);
	}
	cin >> m;
	for (int i = 0; i< m; i ++) {
		cin >> name >> command;
		Node * p = root -> find(name);
		if (command == 1) {
			cout << p -> parent -> name << "\n";
		} else if (command == 2) {
			p -> printChildren();
		} else if (command == 3) {
			p -> printGrandParent();
		} else if (command == 4) {
			p -> printGrandSons();
		}
	}
	
}

