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
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
int main() {
	int n;
	map<ll, int> mp;
	while(scanf("%d", &n), n) {
		ll t=0;
		int maxv = 0;
		vector<int> crs(5);
		mp.clear();
		for(int i=0; i<n; i++) {
			t = 0;
			for(int j=0; j<5; j++) {
				scanf("%d", &crs[j]);
			}
			sort(crs.begin(), crs.end());
			for(int j=0; j<5; j++) {
				t *= 1000L;
				t += crs[j];
			}
//			cout << t << endl;
			mp[t]++;
			maxv = max(maxv, mp[t]);
		}
		int ans = 0;
		for(auto it = mp.begin(); it!=mp.end(); it++) {
			if(it->second == maxv) ans+= maxv;
		}
		printf("%d\n", ans);
	}
	return 0;
}