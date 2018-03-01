#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int t;
	cin >> t;
	int d[103];
	while(t--){
		int n, k;
		cin >> n >> k;
		memset(d, 0, sizeof(d));
		int m[103], p[103];
		for(int i=1; i<=n; i++) cin >> m[i];
		for(int i=1; i<=n; i++) cin >> p[i];
		int ans = 0;
		for(int i=1; i<=n; i++){
			d[i] = p[i];
			for(int j=1; j<i; j++){
				if(m[i]-m[j] > k) d[i] = max(d[i], d[j] + p[i]);
			}
			ans = max(d[i], ans);
		}
		cout << ans << endl;
	}
	return 0;
}