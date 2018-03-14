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
	int a[6];
	while(1){
		bool flag = false;
		for(int i=0; i<6; i++){
			cin >> a[i];
			if(a[i]) flag = true;
		}
		if(!flag) break;
		int ans = 0, one = 0, two = 0;;
		ans += a[5];
		ans += a[4];
		one += a[4] * 11;
		ans += a[3];
		two += a[3] * 5;
		ans += a[2]/4;
		if(a[2]%4!=0) ans++;
		if(a[2]%4 == 1){
			two += 5;
			one += 7;
		}else if(a[2]%4 == 2){
			two += 3;
			one += 6;
		}else if(a[2]%4 == 3){
			two += 1;
			one += 5;
		}
		if(a[1] > two){
			a[1] -= two;
			ans += a[1]/9;
			if(a[1]%9!=0) ans++;
			one += (36 - (a[1]%9)*4);
		}else{
			one += (two-a[1])*4;
		}
		if(one <a[0]){
			a[0] -= one;
			ans += a[0]/36;
			if(a[0]%36!=0) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}