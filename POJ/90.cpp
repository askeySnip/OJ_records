#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int m, n;
int f[103][103], a[103][103];
int ans = 0;
int dp(int i, int j){
	if(f[i][j]) return f[i][j];
	if(i-1>=1&&a[i-1][j]>a[i][j]) f[i][j] = max(f[i][j], dp(i-1, j)+1);
	if(i+1<=m&&a[i+1][j]>a[i][j]) f[i][j] = max(f[i][j], dp(i+1, j)+1);
	if(j-1>=1&&a[i][j-1]>a[i][j]) f[i][j] = max(f[i][j], dp(i, j-1)+1);
	if(j+1<=m&&a[i][j+1]>a[i][j]) f[i][j] = max(f[i][j], dp(i, j+1)+1);
	return f[i][j];
}
int main() {
	cin >> m >> n;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			ans = max(ans, dp(i, j)+1);
		}
	}
	cout << ans;
	return 0;
}