#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int value;
	Node * left_child = NULL;
	Node * right_child = NULL;

	void add_left_child(int val) {
		Node * n = new Node();
		n -> value = val;
		left_child = n;
	}

	void add_right_child(int val) {
		Node * n = new Node();
		n -> value = val;
		right_child = n;
	}

	void print() {
		cout << "[ " << value << " ";
		if (left_child != NULL) {
			left_child->print();
		}
	 
	    if (right_child != NULL) {
	    	right_child -> print();
	    } 

		cout << "]";
	}

};


int main() {
	Node root;
	root.value = 1;
	
	Node * a = new Node();
	a -> value = 2;

	root.add_left_child(2);

	(*(root.left_child)).add_left_child(3);

	root.add_right_child(5);

	root.print();








}