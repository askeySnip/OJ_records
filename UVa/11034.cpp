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
int l, m;
queue<int> lines[2];
void solve() {
	int dir = 0, len = l;
	int ans = 0;
	while(!lines[0].empty() || !lines[1].empty()) {
		len = l;
		while(!lines[dir].empty() && len >= lines[dir].front()) {
			len -= lines[dir].front();
			lines[dir].pop();
		}
		ans ++;
		dir ^= 1;
	}
	printf("%d\n", ans);
}
int main() {
	int c;
	scanf("%d", &c);
	int len;
	char d[10];
	while(c--) {
		scanf("%d %d", &l, &m);
		l *= 100;
		for(int i=0; i<m; i++) {
			scanf("%d %s", &len, d);
			if(d[0] == 'l') {
				lines[0].push(len);
			} else {
				lines[1].push(len);
			}
		}
		solve();
	}
	return 0;
}