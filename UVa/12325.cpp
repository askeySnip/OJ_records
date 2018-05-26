/*
ID: leezhen1
TASK: practice
LANG: C++11                
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
ll N, s1, v1, s2, v2;
ll ans = 0;
int gcd(ll a, ll b){
	if(a%b == 0) return b;
	return gcd(b, a%b);
}
void solve(){
	ans = 0;
	if(N/s1 < 10000){
		for(ll i=0; i*s1<=N; i++){
			ans = max(ans, i*v1+(N-s1*i)/s2*v2);
		}
	}else if(N/s2 < 10000){
		for(ll i=0; i*s2<=N; i++){
			ans = max(ans, i*v2+(N-s2*i)/s1*v1);
		}
	}else{
		ll mc = s1 * s2 / gcd(s1, s2);
		ll t1 = mc/s1, t2 = mc/s2;
		if(t1 * v1 > t2 * v2){
			for(ll i=0; i<=t2; i++){
				ans = max(ans, i*v2 + (N-i*s2)/s1*v1);
			}
		}else{
			for(ll i=0; i<=t1; i++){
				ans = max(ans, i*v1 + (N-i*s1)/s2*v2);
			}
		}
	}
	printf("%lld\n", ans);
}
int main() {
	int kase = 0;
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%lld%lld%lld%lld%lld", &N, &s1, &v1, &s2, &v2);
		printf("Case #%d: ", ++kase);
		solve();
	}
	return 0;
}