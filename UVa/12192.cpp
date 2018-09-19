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
	int h[512][512];
	int l_p[512], h_p[512];
	int q, l, u;
	int ans = 0;
	while(scanf("%d %d", &n, &m), n||m) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				scanf("%d", &h[i][j]);
			}
		}
		scanf("%d", &q);
		for(int i=0; i<q; i++) {
			scanf("%d %d", &l, &u);
			ans = 0;
			for(int j=0; j<n; j++) {
				l_p[j] = lower_bound(h[j], h[j]+m, l)-h[j];
				h_p[j] = upper_bound(h[j], h[j]+m, u)-h[j]-1;
//				cout << l_p[j] << " " << h_p[j] << endl;
			}
			
			for(int j=0; j<n; j++) {
				for(int k=1; k+l_p[j]-1<m && k+j-1<n; k++) {
					if(h_p[k+j-1] >= l_p[j]+k-1) {
						ans = max(ans, k);
//						cout << l_p[j] << " " << j << " " << k << endl;
					}
				}
			}
			printf("%d\n", ans);
		}
		printf("-\n");
	}
	return 0;
}