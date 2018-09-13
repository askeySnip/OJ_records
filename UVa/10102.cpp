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
	int n;
	char field[10024][10024];
	int r1[10024], r3[10024], c1[10024], c3[10024];
	while(scanf("%d", &n) == 1) {
		for(int i=0; i<n; i++) {
			scanf("%s", field[i]);
		}
		int t1 = 0, t3 = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(field[i][j] == '1') {
					r1[t1] = i;
					c1[t1] = j;
					t1++;
				}
				if(field[i][j] == '3') {
					r3[t3] = i;
					c3[t3] = j;
					t3++;
				}
			}
		}
		int ans = 0, m;
		for(int i=0; i<t1; i++) {
			m = 99999999;
			for(int j=0; j<t3; j++) {
				m = min(m, abs(r1[i]-r3[j]) + abs(c1[i]-c3[j]));
			}
			ans = max(ans, m);
		}
		printf("%d\n", ans);
	}
	return 0;
}