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
int main() {
	int c, n, t, ans, s;
	scanf("%d", &c);
	map<int, int> mp;
	while(c--) {
		mp.clear();
		ans = 0;
		s = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			scanf("%d", &t);
			if(mp.find(t) == mp.end() || mp[t] < s)
				mp[t] = i;
			else {
				ans = max(ans, i-s);
				s = mp[t]+1;
				mp[t]=i;
			}
		}
		ans = max(ans, n-s);
		printf("%d\n", ans);
	}
	return 0;
}