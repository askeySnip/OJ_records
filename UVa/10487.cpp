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
	int n, q, t, ks = 0;
	int a[1024];
	while(scanf("%d", &n), n) {
		for(int i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		scanf("%d", &q);
		printf("Case %d:\n", ++ks);
		for(int i=0; i<q; i++) {
			scanf("%d", &t);
			int ans = a[0]+a[1];
			for(int j=0; j<n; j++) {
				for(int k=j+1; k<n; k++) {
					if(abs(a[j]+a[k]-t) < abs(ans-t)) {
						ans = a[j] + a[k];
						if(ans == t) break;
					}
				}
				if(ans == t) break;
			}
			printf("Closest sum to %d is %d.\n", t, ans);
		}
		
	}
	return 0;
}