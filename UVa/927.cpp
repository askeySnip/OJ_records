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

long long mypow(long long x, long long y) {
	if(y == 0) return 1;
	if(y&1) return x*mypow(x*x, y/2);
	else return mypow(x*x, y/2);
}

int main() {
	int t, n, d, k, tb, tk;
	long long c[30];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i=0; i<=n; i++) {
			scanf("%lld", &c[i]);
		}
		scanf("%d %d", &d, &k);
		tk = 0; tb = 0;
		for(int i=1; ; i++) {
			long long an = 0;
			for(int j=0; j<=n; j++) an+=c[j] *mypow(i, j);
			tb += d;
			tk += tb;
			if(tk >= k) {
				printf("%lld\n", an);
				break;
			}
		}
	}
	return 0;
}