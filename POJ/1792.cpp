#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int m[103][103];
int n;
int ha,la,hb,lb;
int r[4] = {0, 1, 0, -1};
int c[4] = {-1, 0, 1, 0};
int vist[103][103];
bool dfs(int i, int j){
	if(!m[i][j] || vist[i][j]) return false;
	if(i == hb && j == lb) return true;
	vist[i][j] = 1;
	for(int k=0; k<4; k++){
		int ii = r[k] + i, jj = c[k] + j;
		if((ii>=0&&ii<n&&jj>=0&&jj<n) && !vist[ii][jj]){
			bool flag = dfs(ii, jj);
			if(flag) return true;
		}
	}
	return false;
}
void solve(){
	memset(vist, 0, sizeof(vist));
	if(!m[ha][la] || !m[hb][lb]){
		cout << "NO" << endl;
	}else{
		if(dfs(ha, la))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}
int main() {
	int k;
	cin >> k;
	while (k--) {
		cin >> n;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				char c;
				cin >> c;
				if(c=='.') m[i][j] = 1;
				else m[i][j] = 0;
			}
		}
		cin >> ha >> la >> hb >> lb;
		solve();
	}
	return 0;
}