#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;S

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return (a.first * b.second > a.second * b.first);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<ll, ll> > v;
	ll A = 0, ans = 0;
	for(ll i=0; i<n; i++){
		string s;
		cin >> s;
		int a=0, b=0;
		for(int i=0; i<s.length(); i++){
			if(s[i] == 's') a++;
			else{
				ans += a;
				b++;
			}
		}
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), cmp);
	for(ll i=0; i<n; i++){
		ans += A*v[i].second;
		A+=v[i].first;
	}
	cout << ans << endl;
	return 0;
}