#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int a[100000];
int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];

	map<int, int> mp;
	for (int i = 0; i < N; i++)
		mp[a[i]]++; //a[i] is the key of the map and value of the key will increase by one.

	int ans = 0;
	for (auto p: mp) {
		int x = p.first;  //key
		int n = p.second; //value
		if (n < x)
            ans += n;
		else
            ans += n - x;
	}

	cout << ans << endl;
}
