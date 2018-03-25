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
char expr[3333333];
map<long long, int> p;
void dfs(int l, int r, int d){
	if(expr[l] == '['){
		int p = 0;
		for(int i=l+1; i<r; i++){
			if(expr[i] == '[') p++;
			if(expr[i] == ']') p--;
			if(expr[i] == ',' && p==0){
				dfs(l+1, i-1, d+1);
				dfs(i+1, r-1, d+1);
			}
		}
	}else{
		int w;
		expr[r+1] = '\0';
		sscanf(expr+l, "%d", &w);
		p[(long long)w<<d]++;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		p.clear();
		scanf("%s", expr);
		dfs(0, strlen(expr)-1, 0);
	
		int maxn = 0, sum = 0;
		for(auto it=p.begin(); it!=p.end(); it++){
			sum += it->second; maxn = max(maxn, it->second);
		}
		printf("%d\n", sum-maxn);
	}
	return 0;
}