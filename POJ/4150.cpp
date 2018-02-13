#include <iostream>

using namespace std;
int main() {
	int f[10000+1][4];
	int a[10000+1], b[10000+1], c[10000+1];
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		cin >> b[i];
	}
	for(int i=1; i<=n; i++){
		cin >> c[i];
	}
	f[1][0] = a[1];
	f[1][2] = b[1];
	for(int i=2; i<=n; i++){
		f[i][0] = max(f[i-1][2], f[i-1][3]) + a[i];
		f[i][1] = max(f[i-1][0], f[i-1][1]) + b[i];
		f[i][2] = max(f[i-1][2], f[i-1][3]) + b[i];
		f[i][3] = max(f[i-1][0], f[i-1][1]) + c[i];
	}
	cout << max(f[n][0], f[n][1]) << endl;
	return 0;
}