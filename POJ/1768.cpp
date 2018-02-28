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
	int mtr[120][120];
	memset(mtr, 0, sizeof(mtr));
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> mtr[i][j];
			mtr[i][j] += mtr[i-1][j];
		}
	}
	int ans = -99999999;
	int sum[120];
	memset(sum, 0, sizeof(sum));
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int t = -99999999;
			for(int r=1; r<=n; r++){
				int t1 = mtr[j][r] - mtr[i-1][r];
				sum[r] = max(sum[r-1] + t1, t1);
				t = max(sum[r], t);
			}
			ans = max(ans, t);
		}
	}
	cout << ans << endl;
	return 0;
}