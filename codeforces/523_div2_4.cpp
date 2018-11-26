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

using namespace std;
typedef vector<int> vi;
typedef pair<long, long> ii;
typedef vector<pair<int, int> > vii;
const int mod = 1e9+7;
const int N = 1e5+5;
long long n, x, y, ans = 0;
long long cost[N];
ii a[N];
multiset<pair<pair<long long, long long>, long long> > s;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x >> y;
	for(int i=1; i<=n; i++) {
		cin >> a[i].first >> a[i].second;
		s.insert({{a[i].second, a[i].first}, i});
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; i++) {
		cost[i] = (x + y * (a[i].second - a[i].first));
		if(!s.size() || s.begin() -> first.first >= a[i].first) continue;
		auto it = s.lower_bound({{a[i].first, 0}, 0});
		long long pR = (--it) -> first.first;
		if(y * (a[i].second - pR) >= cost[i]) continue;
		cost[i] = y * (a[i].second - pR);
		s.erase(it);
	}
	for(int i=1; i<=n; i++) {
		ans += cost[i];
		ans %= mod;
	}
	ans%=mod;
	cout << ans;
	return 0;
}