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

int n;
ii a[505];
vii pairs;
int ans, root;
vi edges[505];
bitset<505> vist;

void bfs(int s) {
	vist[s] = 1;
	queue<int> q;
	vi dist(n+1, inf);
	q.push(s);
	dist[s] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i=0; i<(int)edges[u].size(); i++) {
			int v = edges[u][i];
			if(dist[v] == inf) {
				dist[v] = dist[u]+1;
				q.push(v);
				vist[v] = 1;
			}
		}
	}
	ans = 0;
	for(int i=0; i<n; i++) {
		if(ans < dist[i]) {
			ans = dist[i];
			root = i;
		}
	}
	//cout << "!" << ans << endl;
}

int main() {
	scanf("%d", &n);
	int t;
	for(int i=0; i<n; i++) {
		scanf("%d", &t);
		a[i] = ii(t, i);
	}
	ans = 0;
	deque<ii> dq;
	sort(a, a+n, greater<ii>());
	bool b = true;
	for(int i=0; i<n; i++) {
		if(dq.empty()) dq.push_back(ii(a[i].second, a[i].first));
		else {
			if(b) {
				ii p = dq.back();dq.pop_back();
				if(p.second > 1) dq.push_back(ii(p.first, p.second-1));
				if(a[i].first > 1) dq.push_back(ii(a[i].second, a[i].first-1));
				if(p.second <= 1 && a[i].first <= 1) b = false;
				pairs.push_back(ii(p.first, a[i].second));
				edges[p.first].push_back(a[i].second);
				edges[a[i].second].push_back(p.first);
			}else {
				ii p = dq.front();dq.pop_front();
				if(p.second > 1) dq.push_front(ii(p.first, p.second-1));
				if(a[i].first > 1) dq.push_front(ii(a[i].second, a[i].first-1));
				if(p.second <= 1 && a[i].first <= 1) b = true;
				pairs.push_back(ii(p.first, a[i].second));
				edges[p.first].push_back(a[i].second);
				edges[a[i].second].push_back(p.first);
			}
		}
	}
//	for(int i=0; i<3; i++) {
//		for(int j=0; j<edges[i].size(); j++) {
//			cout << edges[i][j] << " ";
//		}
//		cout << endl;
//	}
	int c = 0;
	for(int i=0; i<n; i++) {
		if(!vist[i]) {
			bfs(i);
			c++;
		}
	}
	if(c > 1) printf("NO\n");
	else {
		bfs(root);
		//cout <<"!!" << ans << endl;
		printf("YES %d\n", ans);
		printf("%d\n", (int)pairs.size());
		for(int i=0; i<(int)pairs.size(); i++) {
			printf("%d %d\n", pairs[i].first+1, pairs[i].second+1);
		}
	}
	return 0;
}