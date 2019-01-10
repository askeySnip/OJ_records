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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int n;
int a[103][103];

void solve() {
	int cnt = 1;
	REP(i, 0, n+n-1) {
		REP(j, 0, i+1) {
			if(i-j >= n || j >= n) continue;
			a[j][i-j] = cnt++;
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		solve();
		REP(i, 0, n) {
			REP(j, 0, n) {
				if(j) printf(" ");
				printf("%d", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}