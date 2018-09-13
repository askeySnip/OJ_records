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
int dis[25][25];
int ds(int i, int j) {
	if(dis[i][j] > -1) return dis[i][j];
	if(dis[j][i] > -1) return dis[j][i];
	int ri = i/5, rj = j/5;
	int ci = i%5, cj = j%5;
	dis[i][j] = abs(ri-rj) + abs(ci-cj);
	return dis[i][j];
}
int cacul(int i, int j, int k, int p, int q, int z) {
	int ret = ds(i, z);
	ret = min(ret, ds(j, z));
	ret = min(ret, ds(k, z));
	ret = min(ret, ds(p, z));
	ret = min(ret, ds(q, z));
	return ret;
}
int main() {
	int t, n, r, c, pp;
	int city[25], ans[5];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		memset(city, 0, sizeof city);
		memset(ans, 9, sizeof ans);
		memset(dis, -1, sizeof dis);
		for(int i=0; i<n; i++) {
			scanf("%d %d %d", &r, &c, &pp);
			city[r*5+c] = pp;
		}
		int val = 1e9;
		for(int i=0; i<25; i++) {
			for(int j=i+1; j<25; j++) {
				for(int k=j+1; k<25; k++) {
					for(int p=k+1; p<25; p++) {
						for(int q=p+1; q<25; q++) {
							int tval = 0;
							for(int z=0; z<25; z++) {
								if(city[z]>0) tval += cacul(i, j, k, p, q, z) * city[z];
							}
							if(val > tval) {
								val = tval;
								ans[0] = i, ans[1] = j, ans[2] = k, ans[3] = p, ans[4] = q;
							}
						}
					}
				}
			}
		}
		printf("%d %d %d %d %d\n", ans[0], ans[1], ans[2], ans[3], ans[4]);
	}
	
	return 0;
}