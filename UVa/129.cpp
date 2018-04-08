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
typedef vector<pair<int, int> > vii;
int n, l, cur;
int ans[100];
int dfs(int len){
	if(cur++ == n){
		for(int i=1; i<len; i++){
			printf("%c", 'A'+ans[i]);
			if(i%64 == 0) printf("\n");
			else if(i%4==0 && i!=len-1) printf(" ");	//notice: when i == len-1, do not print " "!
		}
		if((len-1)%64) printf("\n%d\n", len-1);
		else printf("%d\n", len-1);
		return 0;
	}
	for(int i=0; i<l; i++){
		ans[len] = i;
		int ok = 1;
		for(int j=1; j*2<=len; j++){
			int equal = 1;
			for(int k = 0; k<j; k++){
				if(ans[len-k] != ans[len-k-j]) {equal = 0; break;}
			}
			if(equal){
				ok = 0;
				break;
			}
		}
		if(ok) if(!dfs(len+1)) return 0;
	}
	return 1;
}
int main() {
	while(scanf("%d%d", &n, &l), (n || l)){
		cur = 0;
		dfs(1);
	}
	return 0;
}