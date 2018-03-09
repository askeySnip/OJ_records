#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;
int main() {
	int f[100];
	memset(f, 0, sizeof(f));
	int n;
	cin >> n;
//	if(n<60){
//		long long ans = 1 << n;
//		cout << ans << endl;
//		return 0;
//	}
	f[0] = 1;
	int carry = 0;
	int len=0;
	for(int i=0; i<n; i++){
		carry = 0;
		for(int j=0; j<=len;j++){
//			if(f[j]==0 && carry == 0) break;
			f[j] = f[j]*2 + carry;
			carry = f[j]/10;
			f[j] %= 10;
			if(j == len && carry) len++;
//			cout << f[j];
		}
	}
	for(int j=len;j>=0; j--){
		cout << f[j];
	}
	cout << endl;
	return 0;
}