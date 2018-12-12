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
int n, x, y, d;
int rollup() {
	int a=-1, b=-1, ret = -1;
	if(y >= x && (y-x)%d == 0){
		a = (y-x)/d;
	}
	if(a != -1) ret = a;
	if((n-y)%d == 0) {
		b = (n-y)/d + (n-x)/d;
		if((n-x)%d) b++;
	}
	if(b != -1) {
		if(ret != -1) ret = min(a, b);
		else ret = b;
	}
	return ret;
}
int rolldown() {
	int a = -1, b=-1, ret = -1;
	if(x >= y && (x-y)%d == 0) {
		a = (x-y)/d;
	}
	if(a != -1) ret = a;
	if((y-1)%d == 0){
		b = y/d + x/d;
		if(x%d) b++;
	}
	if(b != -1) {
		if(ret != -1) ret = min(ret, b);
		else ret = b;
	}
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &n, &x, &y, &d);
		int ans = -1;
		int t = rollup();
		//cout << t << endl;
		if(t != -1) ans = t;
		int tt = rolldown();
		//cout << tt << endl;
		if(tt != -1) {
			if(ans == -1) ans = tt;
			else ans = min(ans, tt);
		}
		printf("%d\n", ans);
	}
	return 0;
}