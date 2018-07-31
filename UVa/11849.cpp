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
	int n, m;
	map<int, int> ump;
	while (scanf("%d %d", &n, &m), m || n) {
		int t, ans = 0;
		ump.clear();
		for(int i=0; i<n; i++) {
			scanf("%d", &t);
			ump[t] = 1;
		}
		for(int i=0; i<m; i++) {
			scanf("%d", &t);
			if(ump.find(t) != ump.end()) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}