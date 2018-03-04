#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int v, n;
	cin >> v >> n;
	int a;
	int f[20003];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int ans = 0;
	for(int i=0; i<n; i++){
		cin >> a;
		for(int j=v; j>=a; j--) if(f[j-a]){
			f[j] = 1;
			if(j > ans) ans = j;
		}
	}
	cout << v-ans << endl;
	return 0;
}