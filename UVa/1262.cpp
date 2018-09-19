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
int k, c;
char row[6][6], col[5][6];
int counts[5][26];
char ans[5];

void dfs(int u) {
	if(c == k) return;
	if(u == 5) {
		c++;
		return;
	}
	if(counts[u][col[u][0]-'A']) {
		ans[u] = col[u][0];
		dfs(u+1);
	}
	for(int i=1; i<6; i++) {
		if(c == k) return;
		if(col[u][i] == col[u][i-1]) continue;
		if(counts[u][col[u][i]-'A']) {
			ans[u] = col[u][i];
			dfs(u+1);
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(counts, 0, sizeof counts);
		scanf("%d", &k);
		for(int i=0; i<6; i++) {
			scanf("%s", row[i]);
		}
		for(int i=0; i<6; i++) {
			for(int j=0; j<5; j++) {
				col[j][i] = row[i][j];
			}
		}
		for(int i=0; i<6; i++) {
			scanf("%s", row[i]);
			for(int j=0; j<5; j++){
				counts[j][row[i][j]-'A']++;
			}
		}
		
		for(int i=0; i<5; i++) {
			sort(col[i], col[i]+6);
		}
		c = 0;
		dfs(0);
		if(c == k) {
			for(int i=0; i<5; i++) {
				printf("%c", ans[i]);
			}
			printf("\n");
		}else {
			printf("NO\n");
		}
	}
	return 0;
}