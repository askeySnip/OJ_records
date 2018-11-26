/*
ID: leezhen
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
const int inf = 1e9;
const int mod = 1e9+7;

ll get_len(ll n, ll k) {
	ll div = 1;
	k--;
	ll len = 1;
	while(div < n && k >= 4 * len - 1) {
		k -= 4 * len - 1;
		len *= 2;
		div++;
	}
	return n - div;
}

int main() {
	IOS
	int t;
	cin >> t;
	while(t--) {
		ll n, k;
		cin >> n >> k;
		if(n == 2 && k == 3) {
			cout << "NO" << endl;
			continue;
		}
		if(n < 40) {
			ll _n = n, _k = k;
			ll pow4 = 1;
			while(n--) {
				k -= pow4;
				pow4 *= 4;
			}
			if(k > 0) {
				cout << "NO" << endl;
			}else {
				cout << "YES " << get_len(_n, _k) << endl;
			}
		}else {
			cout << "YES " << get_len(n, k) << endl;
		}
	}
	return 0;
}