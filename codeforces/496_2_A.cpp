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
	int l, r, a;
	cin >> l >> r >> a;
	int ans = min(l, r);
	int t = abs(l-r);
	ans += min(t, a);
	a -= min(t, a);
	ans += a/2;
	cout << 2*ans << endl;
	return 0;
}