#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int k;
	cin >> k;
	while(k--){
		int w, s;
		cin >> w >> s;
		vector<pair<double, int> > l;
		for(int i=0; i<s; i++){
			int n, v;
			cin >> n >> v;
			l.push_back(make_pair(v*1.0/n, n));
		}
		sort(l.begin(), l.end(), greater<pair<double, int> >());
		double ans=0;
		for(int i=0; i<l.size(); i++){
			int t = min(w, l[i].second);
			ans += l[i].first * t;
			w -= t;
			if(w == 0) break;
		}
		printf("%.2f\n", ans);
	}
	return 0;
}