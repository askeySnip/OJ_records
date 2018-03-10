#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;
int main() {
	int n;
	cin >> n;
	if(n%2) {cout << 0 << " " << 0 << endl;return 0;}
	if(n%4) cout << n/4+1;
	else cout << n/4;
	cout << " " << n/2 << endl;
	return 0;
}