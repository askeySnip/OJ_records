#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;
const int mod = 1e5;
int main() {
	int t, n;
	scanf("%d",&t);
	int f[200000+30], sum=0;
	f[1] = 1;
	f[2] = 2;
	f[3] = 5;
	sum = 3;
	for(int i=4; i<200003; i++){
		f[i] = (sum%mod + (2*f[i-1])%mod)%mod;
		sum = (sum%mod + f[i-1]%mod)%mod;
	}
	while(t--){
		scanf("%d", &n);
		printf("%d\n", f[n]);
	}
	return 0;
}