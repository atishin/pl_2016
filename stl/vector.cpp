#include <iostream>
#include <vector>
#include <set>

using namespace std;

int a;
vector <int> b;

int main() {
	
	set <int> c;
	int n;
	cin >> n;
	for (int i = 0; i< n; i ++) {
		cin >> a;
		c.insert(a);
	}	



	cout << c.begin();
	for (set<int>::iterator it = c.begin(); it != c.end(); it ++) {
		cout << *it << " ";
	}
	cout << "\n";

	cin >> n;
	for (int i = 0; i< n; i ++) {
		cin >> a;
		if (c.find(a) != c.end()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}



	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);	

	for (int i = 0; i < b.size(); i ++) {
		cout << b[i] << " ";
	}
	cout << "\n";

//	b.clear();

	//b.pop_back();

	b.erase(b.begin(), b.end());

	for (int i = 0; i < b.size(); i ++) {
		cout << b[i] << " ";
	}
	cout << "\n";

	return 0;
}