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
int n, t;
int p[1003];
int main() {
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<=n; i++){
			cin >> p[i];
		}
		sort(p+1, p+1+n);
		int t = 0;
		while(n){
			if(n == 1){
				t += p[n]; break;
			}else if(n == 2){
				t += p[n]; break;
			}else if(n == 3){
				t += p[1] + p[2] + p[3]; break;
			}else{
				t += min(p[n] + p[2] + p[1] + p[2], p[n] + p[1] + p[n-1] + p[1]);
				n -= 2;
			}
		}
		cout << t << endl;
	}
	return 0;
}