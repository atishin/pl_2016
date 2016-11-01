#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Person {
	string name;
	int age;

	void print() {
		cout << name << " " << age << "\n";
	}

};

struct Car {
	string color;
	string number;
	Person person;

	void print() {
		cout << "Car: color - " << color << " number - " << number << " Person: ";
		person.print();
	}

};

int main() {
	string a = "abcdefg";
	cout << a.length();
	cout << a.substr(2, 3);

}