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
	int a[103][103];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cin >> a[i][j];
		}
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(j != 1) a[i][j] = max(a[i-1][j-1], a[i-1][j]) + a[i][j];
			else a[i][j] += a[i-1][j];
		}
	}
	int maxn=0;
	for(int i=1; i<=n; i++){
		if(a[n][i] > maxn) maxn = a[n][i];
	}
	cout << maxn << endl;
	return 0;
}