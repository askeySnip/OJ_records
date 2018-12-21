/*
ID: leezhen
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
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, T;
	cin >> n >> T;
	ll a;
	ll sum = 0L;
	list<ll> mylist;
	REP(i, 0, n) cin >> a, sum += a, mylist.push_back(a);
	ll ans = 0L;
	ans += n * (T/sum);
	T = T%sum;
	//cout << ans << " " << T << endl;
	while(!mylist.empty() && T>0){
		sum = 0L;
	for(list<ll>::iterator it=mylist.begin(); it!=mylist.end();) {
		if(T == 0) break;
		//cout << T << " " << *it << " " << mylist.size() << endl;
		if(T >= *it) {
			T -= *it;
			ans++;
		}
		if(T < *it) it = mylist.erase(it);
		else {
			sum += *it;
			it++;
		}
		if(it == mylist.end()) break;
	}
	int sz = mylist.size();
	//cout << sz << endl;
	if(T >= sum && sum != 0) {
		ans += sz * (T/sum);
		T = T%sum;
	}
	}
	printf("%lld\n", ans);
	return 0;
}