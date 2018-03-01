#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	cin >> n;
	while(n--){
		string s1, s2;
		cin >> s1 >> s2;
		s1 = '0' + s1;
		s2 = '0' + s2;
//		cout << s1  << " " << s2;
		int dp[1003][1003];
		memset(dp, 0, sizeof(dp));
//		dp[0][0] = 0;
		for(int i=1; i<1003; i++) {
			dp[i][0] = i;
			dp[0][i] = i;
		}
		for(int i=1; i<s1.length(); i++){
			for(int j=1; j<s2.length(); j++){
				if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
				else{
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
				}
			}
		}
		cout << dp[s1.length()-1][s2.length()-1] << endl;
	}
	return 0;
}