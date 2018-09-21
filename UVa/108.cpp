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
	scanf("%d", &n);
	int m[103][103];
	memset(m, 0, sizeof m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) 
			scanf("%d", &m[i][j]);
	int ans = m[0][0];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			{m[i][j] = m[i][j-1]+m[i][j]; ans = max(ans, m[i][j]);}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			int t = 0;
			for(int k=1; k<=n; k++) {
				t += m[k][j] - m[k][i-1];
				ans = max(ans, t);
				if(t < 0) t = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}