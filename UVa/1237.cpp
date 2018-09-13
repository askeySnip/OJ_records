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
	int t, d, m, q, p;
	char name[10024][23];
	int l[10024], h[10024];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &d);
		for(int i=0; i<d; i++) {
			scanf("%s %d %d", name[i], &l[i], &h[i]);
		}
		scanf("%d", &q);
		for(int j=0; j<q; j++) {
			scanf("%d", &p);
			int cnt = 0, mi;
			for(int i=0; i<d; i++) {
				if(l[i] <= p && h[i] >= p) {
					cnt ++;
					mi = i;
				}
				if(cnt > 1) break;
			}
			if(cnt == 1) printf("%s\n", name[mi]);
			else printf("UNDETERMINED\n");
		}
		
		if(t) printf("\n");
	}
	return 0;
}