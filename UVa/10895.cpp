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
	int m, n, t, g;
	vi pos;
	while(scanf("%d %d", &m, &n) == 2) {
		vector<vii> adj_list(n+1);
		for(int j=1; j<=m; j++) {
			scanf("%d", &t);
			if(!t) continue;
			for(int i=0; i<t; i++) {
				scanf("%d", &g);
				pos.push_back(g);
			}
			for(int i=0; i<t; i++) {
				scanf("%d", &g);
				adj_list[pos[i]].push_back(make_pair(j, g));
			}
			pos.clear();
		}
		printf("%d %d\n", n, m);
		for(int i=1; i<=n; i++) {
			t = adj_list[i].size();
			if(t) {
				printf("%d", t);
				for(int j=0; j<t; j++) {
					printf(" %d", adj_list[i][j].first);
				}
				printf("\n%d", adj_list[i][0].second);
				for(int j=1; j<t; j++) {
					printf(" %d", adj_list[i][j].second);
				}
				printf("\n");
			} else {
				printf("0\n\n");
			}
		}
	}
	return 0;
}