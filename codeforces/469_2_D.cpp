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
typedef long long ll;
int main() {
	ll n, q;
	scanf("%lld%lld", &n, &q);
	for(ll i=0; i<q; i++){
		ll x;
		scanf("%lld", &x);
		while(x%2==0){
			x = n+x/2;
		}
		cout << (x+1)/2 << endl;
	}
	return 0;
}