#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int x, y;
	cin >> x >> y;
	if(y%x){ cout << 0 << endl; return 0;}
	int t = y/x;
	int c = 0;
	for(int i=2; i<=t; i++){
		if(t%i == 0){
			c++;
			while(t%i==0)t/=i;
//			cout << t << " ";
		}
	}
	long long ans = 1 << c;
	cout << ans << endl;
	return 0;
}