#include <iostream>
#include <fstream>

using namespace std;

struct Node {
	int value;
	Node * left_child = NULL;
	Node * right_child = NULL;

	Node * add_left_child(int val) {
		Node * n = new Node();
		n -> value = val;
		left_child = n;
		return this -> left_child;
	}

	Node * add_right_child(int val) {
		Node * n = new Node();
		n -> value = val;
		right_child = n;
		return this -> right_child;
	}

	Node * find(int x) {
		if (x == this -> value) return this;
		if (this -> left_child != NULL) {
			Node * left = this -> left_child -> find(x);
			if (left != NULL) return left;
		}
		if (this -> right_child != NULL) {
			Node * right = this -> right_child -> find(x);
			if (right != NULL) return right;
		}

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
      Node * root = new Node();
      root -> value = 1;

      root -> add_left_child(2);
      root -> add_right_child(4);
      
      root -> print();
      cout << "\n";

      Node * n = root -> find(2);
      if (n != NULL) n -> add_left_child(3) -> add_right_child(6);

      n = root -> find(4);
      if (n != NULL) n -> add_left_child(5);

      root->print();
      cout << "\n";
      root -> find(2) -> print();




}