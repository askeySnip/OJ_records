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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
const int inf = 1e9;
const int mod = 1e9+7;
ll white = 0, black = 0, change = 0;
ll do_deal(ll x1, ll y1, ll x2, ll y2) {
	if(x1 > x2 || y1 > y2) return 0;
	change = 0;
	if((x1%2) == (y1%2)) {
		ll dy = y2-y1+1, dx = x2-x1+1;
		if(dx%2==0 || dy%2==0) {
			change = dx*dy/2;
		}else {
			change = dx*dy/2;
		}
	}else {
		ll dy = y2-y1+1, dx = x2-x1+1;
		if(dx%2 == 0 || dy%2 == 0) {
			change = dx*dy/2;
		}else {
			change = dx*dy/2+1;
		}
	}
	return change;
//	if(x1 > x2 || y1 > y2) return 0;
//	ll t = (x2-x1+1) * (y2-y1+1);
//	if((x1+y1)&111) return (t+1)/2;
//	return t/2;
}
ll do_deal2(ll x, ll y, ll xx, ll yy) {
	if(x > xx || y > yy) return 0;
	ll t = (xx-x+1) * (yy-y+1);
	if((x+y)&111) return t/2;
	return (t+1)/2;
}
ll maxll(ll a, ll b) {
	return a < b? b : a;
}
ll minll(ll a, ll b) {
	return a < b? a : b;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, m;
		cin >> n >> m;
		white = 0, black = 0;
		if(n%2 && m%2) {
			white = n*m/2 + 1;
			black = n*m-white;
		}else {
			white = n*m/2;
			black = n*m/2;
		}
		ll x1, x2, y1, y2;
		ll x3, x4, y3, y4;
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		change = do_deal(x1, y1, x2, y2);
		white += change;
		black -= change;
		change = do_deal(x3, y3, x4, y4);
		change = (x4-x3+1) * (y4-y3+1) - change;
		white -= change;
		black += change;
		change = do_deal(maxll(x1, x3), maxll(y1, y3), minll(x2, x4), minll(y2, y4));
		white -= change;
		black += change;
		cout << white << " " << black << endl;
	}
	return 0;
}