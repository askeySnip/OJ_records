#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
int dp(int m, int n){
	if(n == 1 || m == 0) return 1;
	else if(m >= n) return dp(m-n, n) + dp(m, n-1);
	else return dp(m, m);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int m, n;
		cin >> m >> n;
		cout << dp(m, n) << endl;
	}
}