#include <iostream>

using namespace std;

int a[100];
int n;

void print(int x) {
	for (int i = n - 1; i >= 0; i --) {
		a[i] = x % 2;
		x /= 2;
	}
	for (int i = 0; i < n; i ++) {
		cout << a[i];
	}
	cout << "\n";
}

int main() {
	cin >> n;
	int k = 1;
	for (int i = 0; i < n; i ++) {
		k *= 2;	
	}
	for (int i = 0; i < k; i ++) {
		print(i);	
	}
}