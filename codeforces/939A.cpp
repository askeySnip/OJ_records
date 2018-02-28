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
	int f[5000+5];
	for(int i=1;i<=n; i++){
		cin >> f[i];
	}
	bool flag = false;
	for(int i=1; i<=n; i++){
		int a,b,c;
		a = i;
		b = f[a];
		c = f[b];
		if(a == f[c]) flag = true;
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}