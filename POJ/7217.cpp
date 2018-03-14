#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
typedef long long ll;
using namespace std;
int main() {
	ll n;
	while(cin >> n && n>0){
		ll t = n-1;
		for(ll i=t; ; i+=t){
			ll x = i;
			int c=0;
			bool flag = false;
			while(x%t==0){
				x = x*n/t+1;
				c++;
				if(c == n){
					cout << x << endl;
					flag = true;
					break;
				}
			}
			if(flag) break;

		}
	}
	return 0;
}