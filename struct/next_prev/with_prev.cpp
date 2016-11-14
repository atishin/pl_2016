#include <iostream>

using namespace std;

struct Node {
	Node(int v) {
		this -> v = v;
		this -> next = NULL;
		this -> prev = NULL;
	}

	int v;
	Node * next;
	Node * prev;

	Node * add(int v) {
		Node * c = new Node(v);
		c -> next = this -> next;
		c -> prev = this;
		if (c -> next != NULL) {
			c -> next -> prev = c;
		}
		this -> next = c;
		return c;
	}

	void remove_next() {
		if (this -> next -> next != NULL) {
			this -> next -> next -> prev = this;
			this -> next = this -> next -> next;
		} else {
			this -> next = NULL;	
		}
	}

	void remove_prev() {
		if (this -> prev -> prev != NULL) {
			this -> prev -> prev -> next = this;
			this -> prev = this -> prev -> prev;
		} else {
			this -> prev = NULL;
		}
	}

	void remove() {
		this -> prev -> next = this -> next;
		this -> next -> prev = this -> prev;
	}

	void print() {
		cout << this -> v << " ";
		if (this -> next != NULL) this -> next -> print();
	}

};

int main() {

	Node * a = new Node(1);
	Node * b = a -> add(2);

	a -> print();
	cout << endl;

	Node * c = a -> add(3);
	
	a -> print();
	cout << endl;

	c -> remove();

	a -> print();

	return 0;
}