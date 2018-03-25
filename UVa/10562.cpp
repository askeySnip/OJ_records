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
const int maxn = 230;
int cnt;
char buf[maxn][maxn];
void dfs(int r, int c){
	printf("%c(", buf[r][c]);
	if(r+1 < cnt && buf[r+1][c] == '|'){
		int i = c;
		while(i-1>=0 && buf[r+2][i-1] == '-') i--;
		while(buf[r+2][i] == '-' && buf[r+3][i] != '\0'){
			if(!isspace(buf[r+3][i])) dfs(r+3, i);
			i++;
		}
	}
	printf(")");
}
void solve(){
	cnt = 0;
	for(;;){
		fgets(buf[cnt], maxn, stdin);
		if(buf[cnt][0] == '#') break;
		else cnt++;
	}
	printf("(");
	if(cnt){
		int l = strlen(buf[0]);
		for(int i=0; i<l; i++){
			if(buf[0][i] != ' '){
				dfs(0, i);
				break;
			}
		}
	}
	printf(")\n");
}
int main() {
	int t;
	fgets(buf[0], maxn, stdin);
	sscanf(buf[0], "%d", &t);
	while(t--) solve();
	return 0;
}