/*
ID: leezhen1
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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int a[15];
int n;
bool dfs(int d, int maxd){
	if(a[d] == n) return true;
	if(d == maxd) return false;
	int maxv = a[0];
	for(int i=1; i<=d; i++){
		maxv = max(maxv, a[i]);
	}
	if((maxv << (maxd - d)) < n) return false;
	
	for(int i=d; i>=0; i--){
		a[d+1] = a[d] + a[i];
		if(dfs(d+1, maxd)) return true;
		a[d+1] = a[d] - a[i];
		if(dfs(d+1, maxd)) return true;
	}
	return false;
}
int main() {
	while(scanf("%d", &n) == 1 && n){
		a[0] = 1;
		if(n == 1){
			printf("0\n");
			continue;
		}
		for(int maxd = 1;; maxd++){
//			cout << maxd << "sdfa" << endl;
			if(dfs(0, maxd)) {
				printf("%d\n", maxd);
				break;
			}
		}
	}
	return 0;
}