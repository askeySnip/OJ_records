#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n, b;
	cin >> n >> b;
	int a[20003];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a, a+n, greater<int>());
	int i=0;
	while(b>0) {
		b-=a[i];
		i++;
	}
	cout << i << endl;
	return 0;
}