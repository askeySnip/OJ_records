#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	char a[23], b[23];
	scanf("%s", a+1);
	scanf("%s", b+1);
	int la = strlen(a+1);
	int lb = strlen(b+1);
	int dp[23][23];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for(int i=1; i<=la; i++){
		for(int j=0; j<=lb; j++){
			if(a[i] == b[j] || a[i] == '?') dp[i][j] = dp[i-1][j-1];
			else if(a[i] == '*'){
				for(int k=j; k>=0; k--){
					if(dp[i-1][k] == 1){
						dp[i][j] = 1;
						break;
					}
				}
			}
		}
	}
	if(dp[la][lb]) cout << "matched" << endl;
	else cout << "not matched" << endl;
	return 0;
}