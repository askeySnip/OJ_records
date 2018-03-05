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
	long long f[1003];
	memset(f, 0, sizeof(f));
	f[1] = 3;
	f[2] = 7;
	for(int i=3; i<=n; i++){
		f[i] = (f[i-1] + f[i-2]*2 + f[i-1]-f[i-2])%12345;
	}
	cout <<f[n] << endl;
	return 0;
}