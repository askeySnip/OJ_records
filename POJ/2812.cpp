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
int r, c;
int n;
int ans = 2;
inline bool is_inside(pair<int, int> p){
	return (p.first>=1 && p.first <= r && p.second>=1 && p.second <= c);
}
int main() {
	scanf("%d%d", &r, &c);
	scanf("%d", &n);
	vector<pair<int, int> > points;
	for(int i=0; i<n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		points.push_back(make_pair(a, b));
	}
	sort(points.begin(), points.end());
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int dx = points[j].first - points[i].first;
			int dy = points[j].second - points[i].second;
			if(is_inside(make_pair(points[i].first-dx, points[i].second-dy))){
				continue;
			}
			if(!is_inside(make_pair(points[i].first+ans*dx, points[i].second+ans*dy))){
				if(is_inside(make_pair(points[i].first+ans*dx, 1))) continue;
				else break;
			}
			int k;
			pair<int, int> p;
			for(k=2; ;k++){
				p = make_pair(points[i].first+k*dx, points[i].second+k*dy);
				int pos = lower_bound(points.begin(), points.end(), p) - points.begin();
				if(pos == points.size() || points[pos] != p) break;

			}
			if(!is_inside(p) && k > ans) ans = k;
		}
	}
	ans = ans == 2? 0:ans;
	cout << ans << endl;
	return 0;
}