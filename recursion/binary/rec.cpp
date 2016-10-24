#include <iostream>

using namespace std;

int a[100];
int n;

void print() {
	for (int i = 0; i < n; i ++) {
		cout << a[i];
	}
	cout << "\n";
}

void rec(int x) {
	if (x >= n) {
		print();
		return;
	}
	a[x] = 0;
	rec(x + 1);
	a[x] = 1;
	rec(x + 1);
		
}

int main() {
	cin >> n;
	rec(0);
}