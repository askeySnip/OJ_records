#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int k;
	cin >> k;
	while(k--){
		int n;
		cin >> n;
		int a[103];
		for(int i=1; i<=n; i++) cin >> a[i];
		int dpl[103], dpr[103];
		int ans = 0;
		dpl[1] = 1;
		dpr[1] = 1;
		for(int i=2; i<=n; i++){
			int tml = 0;
			for(int j=1; j<i; j++){
				if(a[j] > a[i] && dpl[j] > tml) tml = dpl[j];
			}
			dpl[i] = tml + 1;
			if(ans < dpl[i]) ans = dpl[i];
		}
		for(int i=2; i<=n; i++){
			int tmr = 0;
			for(int j=1; j<i; j++){
				if(a[j] < a[i] && dpr[j] > tmr) tmr = dpr[j];
			}
			dpr[i] = tmr + 1;
			if(ans < dpr[i]) ans = dpr[i];
		}
		cout << ans << endl;
	}
	return 0;
}