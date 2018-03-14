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
	int n, m;
	cin >> n >> m;
	int f[13000];
	memset(f, 0, sizeof(f));
	for(int i=0; i<n; i++){
		int w, d;
		cin >> w >> d;
		for(int j=m; j>=1; j--){
			if(j>=w) f[j] = max(f[j-w] + d, f[j]);
		}
	}
	cout << f[m] << endl;
	return 0;
}