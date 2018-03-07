#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n;
	int f[33];
	f[0] = 1;
	f[2] = 3;
	for(int i=4; i<33; i+=2){
		f[i] = 4*f[i-2] - f[i-4];
	}
	while(cin >> n){
		if(n == -1) break;
		if(n%2==1) cout << 0 << endl;
		else cout << f[n] << endl;;
	}
	return 0;
}