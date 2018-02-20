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
	int a[4] = {0, 0, 0, 0};
	for(int i=0; i<n; i++){
		int t;
		cin >> t;
		t--;
		if(t){
			a[1] = max(a[0], a[1]) + 1;
			a[3] = max(a[2], a[3]) + 1;
		}else{
			a[0]++;
			a[2] = max(a[1], a[2]) + 1;
		}
	}
	int ans = a[0];
	for(int i=1; i<4; i++){
		if(ans < a[i]) ans = a[i];
	}
	cout << ans << endl;
	return 0;
}