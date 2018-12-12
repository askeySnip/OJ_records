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
vi s[100005];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a, b;
	for(int i=0; i<n; i++) {
		scanf("%d %d", &a, &b);
		s[a].push_back(b);
	}
	int max_p = 0;
	for(int i=1; i<=m; i++) {
		max_p = max(max_p, (int)s[i].size());
		sort(s[i].begin(), s[i].end(), greater<int>());
//		for(int j=1; j<=s[i].size(); j++) s[i][j] += s[i][j-1];
	}
	for(int i=1; i<=m; i++) {
		int sz = s[i].size();
		for(int j=1; j<=max_p; j++) {
			if(j >= sz) {s[i].push_back(-inf); break;}
			else s[i][j] += s[i][j-1];
		}
		//cout << endl;
	}
	queue<int> q;
	int ans = 0;
	for(int i=1; i<=m; i++) {
		if(s[i][0] > 0) {
			//in[i] = 1;
			q.push(i);
			ans += s[i][0];
		}
	}
	for(int i=1; i<max_p; i++) {
		int t_ans = 0;
		queue<int> q2;
		while(!q.empty()) {
			int j = q.front(); q.pop();
			if(s[j][i] > 0) {
				t_ans += s[j][i];
				q2.push(j);
			}
		}
		if(ans < t_ans) ans = t_ans;
		if(t_ans == 0) break;
		q = q2;
		//ans = max(ans, t_ans);
	}
	printf("%d\n", ans);
	return 0;
}