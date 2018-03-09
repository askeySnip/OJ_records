#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
const int mod = 5000011;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	int f[2][100000+13];
//	int n, k;
//	cin >> n >> k;
////	for(int i=0; i<=n; i++) f[1][i] = 2;
//	f[1][1] = 2;
//	for(int i=1; i<=n; i++) f[i][0] = 1;
//	for(int i=2; i<=n; i++){
//		int t = i%2;
//		for(int j=1; j<=n; j++){
//			if(j > k) f[t][j] = (f[1-t][j-k-1]%mod + f[t][j-1]%mod)%mod;
//			else f[t][j] = (1 + f[t][j-1])%mod;
//		}
//	}
//	cout << f[n%2][n] << endl;
	int f[100000+13];
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=k+1; i++) f[i] = i+1;
	for(int i=k+2; i<=n; i++) f[i] = (f[i-1]%mod + f[i-k-1]%mod)%mod;
	cout << f[n]%mod << endl;
	return 0;
}