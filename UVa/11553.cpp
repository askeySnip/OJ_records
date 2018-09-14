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
	int t, n;
	int m[10][10], col[10];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		int choice[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		int ans = 10000000;
		do{
			int s = 0;
			for(int i=0; i<n; i++) {
				s += m[i][choice[i]];
			}
			ans = min(ans, s);
		}while(next_permutation(choice, choice+n));
		printf("%d\n", ans);
	}
	return 0;
}