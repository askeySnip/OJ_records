#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
int main() {
	ll n, k;
	cin >> n >> k;
	ll type=1L, cb=0L, s=0L;
	for(ll i=1; i<=k; i++){
		ll a;
		cin >> a;
		if(a <= n){
			if(n/a*a > s){
				cb = n/a;
				s = n/a*a;
				type = i;
			}
		}
	}
	cout << type << " " << cb << endl;
	return 0;
}