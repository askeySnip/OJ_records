#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int t = abs(a-b);
	int ans = (1+t/2) * (t/2);
//	cout << ans << endl;
	if(t % 2 == 1) ans += t/2+1;
	cout << ans << endl;
	return 0;
}