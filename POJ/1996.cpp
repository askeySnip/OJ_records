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
	int a[1003], up[1003], down[1003];
	for(int i=1; i<=n; i++){
		cin >> a[i];
		up[i] = 1;
		down[i] = 1;
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<i; j++){
			if(a[i] > a[j]){
				up[i] = max(up[i], up[j]+1);
			}
		}
	}
	for(int i=n; i>=1; i--){
		for(int j=n; j>i; j--){
			if(a[i]>a[j]) down[i] = max(down[j]+1, down[i]);
		}
	}
	int ans = -999999;
	for(int i=1; i<=n; i++){
		if(up[i] + down[i] > ans){
			ans = up[i] + down[i];
		}
	}
	cout << ans - 1 << endl;;
	return 0;
}