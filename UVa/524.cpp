/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n;
int prime[40];
int vist[20];
int ans[20];
void solve(int cur){
	if(cur == n && prime[ans[0]+ans[n-1]]){
		for(int i=0; i<n-1; i++){
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[n-1]);
		return;
	}
	for(int i=2; i<=n; i++){
		if(!vist[i] && prime[ans[cur-1]+i]){
			ans[cur] = i;
			vist[i] = 1;
			solve(cur+1);
			vist[i] = 0;
		}
	}
}
int main() {
	int kase = 0;
	memset(prime, 0, sizeof prime);
	prime[2] = 1;
	prime[3] = 1;
	prime[5] = 1;
	prime[7] = 1;
	prime[11] = 1;
	prime[13] = 1;
	prime[17] = 1;
	prime[19] = 1;
	prime[23] = 1;
	prime[29] = 1;
	prime[31] = 1;
	prime[37] = 1;
	ans[0] = 1;
	memset(vist, 0, sizeof vist);
	while(~scanf("%d", &n)){
		if(kase) printf("\n");
		printf("Case %d:\n", ++kase);
		solve(1);
	}
	return 0;
}