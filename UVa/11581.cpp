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
int n;
char m[3][3], tm[3][3];
int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};
char update(int i, int j){
	int ret = 0;
	for(int k=0; k<4; k++){
		int ti = i + di[k], tj = j + dj[k];
		if(ti>=0&&ti<3&&tj>=0&&tj<3) ret+=(m[ti][tj]-'0');
	}
	ret%=2;
	return ret+'0';
}
bool check(){
	bool flag = false;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
//			cout << m[i][j];
			if(m[i][j]=='1') flag=true;
			tm[i][j] = update(i, j);
		}
//		cout << endl;
	}
	memcpy(m, tm, sizeof tm);
	return flag;
}
void solve(){
	int ans = -1;
	while(check()){
		ans++;
	}
	printf("%d\n", ans);
}
int main() {
	scanf("%d", &n);
	while(n--){
		for(int i=0; i<3; i++){
			scanf("%s", m[i]);
		}
		solve();
	}
	return 0;
}