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

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int a[1024][1024];
	memset(a, 0, sizeof a);
	REP(i, 0, n) {
		REP(j, 0, k) {
			scanf("%d", &a[i][j]);
			a[i][n] += a[i][j];
		}
	}
	REP(i, 0, k) {
		double choose = a[0][i]*1.0/a[0][n], not_choose = 1 - choose;
		REP(j, 1, n) {
			choose = (a[j][i]+1)*1.0/(a[j][n]+1)*choose + (a[j][i]*1.0)/(a[j][n]+1)*not_choose;
			not_choose = 1 - choose;
		}
		if(i) printf(" ");
		printf("%.6f", choose);
	}
	printf("\n");
	return 0;
}