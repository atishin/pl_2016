#include <iostream>

using namespace std;

struct Node {
	Node(int v) {
		this -> v = v;
		this -> next = NULL;
	}

	int v;
	Node * next;

	void add(int v) {
		Node * c = new Node(v);
		c -> next = this -> next;
		this -> next = c;
	}

	void remove_next() {
		if (this -> next -> next != NULL) {
			this -> next = this -> next -> next;
		} else {
			this -> next = NULL;
		}
	}

	void print() {
		cout << this -> v << " ";
		if (this -> next != NULL) this -> next -> print();
	}

};

int main() {

	Node * a = new Node(1);
	a -> add(2);

	a -> print();
	cout << endl;

	a -> add(3);
	
	a -> print();
	cout << endl;

	a -> remove_next();

	a -> print();

	return 0;
}