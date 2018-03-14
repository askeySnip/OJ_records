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
#include <cmath>

using namespace std;
const int inf = (1 << 20);
int n, t, m1, m2;
int ts[330], d[100], e[100];
int has_train[2][330][100];
int dp[330][100];
int main() {
	int id = 1;
	while(true){
		scanf("%d", &n);
		if(!n) break;
		memset(has_train, 0, sizeof(has_train));
		memset(ts, 0, sizeof(ts));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &t);
		for(int i=1; i<n; i++){
			scanf("%d", &ts[i]);
		}
		scanf("%d", &m1);
		for(int i=1; i<=m1; i++){
			scanf("%d", &d[i]);
			int tt = d[i];
			for(int j=1; j<=n; j++){
				tt += ts[j-1];
				has_train[0][tt][j] = 1;	// 1 -> n
			}
		}
		scanf("%d", &m2);
		for(int i=1; i<=m2; i++){
			scanf("%d", &e[i]);
			int tt = e[i];
			for(int j=n; j>=1; j--){
				tt += ts[j];
				has_train[1][tt][j] = 1;  //n -> 1
//				cout << tt << " " << j << endl;
			}
		}
		for(int i=1; i<=n-1; i++) dp[t][i] = inf;
		dp[t][n] = 0;
		for(int i=t-1; i>=0; i--){
			for(int j=1; j<=n; j++){
				dp[i][j] = dp[i+1][j] + 1;	//wait a time
				if(j < n && has_train[0][i][j] && i+ts[j] <= t){
					dp[i][j] = min(dp[i][j], dp[i+ts[j]][j+1]);		//right
				}
				if(j > 1 && has_train[1][i][j] && i+ts[j-1] <= t){
					dp[i][j] = min(dp[i][j], dp[i+ts[j-1]][j-1]);	//left
				}
			}
		}
		printf("Case Number %d: ", id++);
		if(dp[0][1] >= inf) printf("impossible\n");
		else printf("%d\n",dp[0][1]);
	}
	return 0;
}