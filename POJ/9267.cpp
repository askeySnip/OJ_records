#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
int main() {
	int n, m;
	cin >> n >> m;
	long long a[53];
	memset(a, 0, sizeof(a));
	a[0] = 1L;
	for(int i=1; i<=n; i++){
		if(i > m) a[i] = 2*a[i-1]-a[i-1-m];
		if(i == m) a[i] = 2*a[i-1]-1;
		if(i < m) a[i] = 2*a[i-1];
	}
	cout << a[n] << endl;
	return 0;
}