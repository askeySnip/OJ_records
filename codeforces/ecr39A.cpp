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
	int a[103];
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int sum = 0;
	for(int i=1; i<=n; i++){
		if(a[i] < 0) sum -= a[i];
		if(a[i] > 0) sum += a[i];
	}
	cout << sum << endl;
	return 0;
}