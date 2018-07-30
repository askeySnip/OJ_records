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
int n, t, m;
queue<int> ql, qr;
void solve(vector<pair<int, int> >& vp) {
	int dir = 0, ct = 0, c;
	queue<int> q[2];
	vector<pair<int, int> > ans;
	for(int i=0; i<vp.size() || !q[0].empty() || !q[1].empty(); ) {
		c = 0;
		while(!q[dir].empty() && c < n) {
			ans.push_back(make_pair(q[dir].front(), ct + t));
			q[dir].pop();
			c++;
		}
		if(c == 0) ct = max(ct, vp[i].first);
		while(i < vp.size() && c < n && vp[i].first <= ct) {
			if(dir == vp[i].second) {
				c++;
				ans.push_back(make_pair(i, ct+t));
			} else {
				q[1-dir].push(i);
			}
			i++;
		}
		ct += t;
//		for(int j=0; j<c; j++) printf("%d\n", ct);
		dir ^= 1;
	}
	sort(ans.begin(), ans.end());
	for(int i=0; i<ans.size(); i++) {
		printf("%d\n", ans[i].second);
	}
}
int main() {
	int ks;
	scanf("%d", &ks);
	while(ks--) {
		scanf("%d %d %d", &n, &t, &m);
		int arrive;
		vector<pair<int, int> > vp(m);
		char dir[10];
		for(int i=0; i<m; i++) {
			scanf("%d %s", &arrive, dir);
			if(dir[0] == 'l') {
				vp[i] = make_pair(arrive, 0);
			}else {
				vp[i] = make_pair(arrive, 1);
			}
		}
		solve(vp);
		if(ks) printf("\n");
	}
	return 0;
}