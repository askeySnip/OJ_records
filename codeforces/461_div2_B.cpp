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
	int ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			int t = i^j;
			if(t >= j && t <= n && t < i+j) {
				ans++;
//				cout << i << " " << j << " " << t << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}