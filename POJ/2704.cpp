#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
vector<pair<int, int> > xy, yx;
bool check(pair<int, int> p){
//	cout << p.first << " " << p.second << endl;
	for(int i=0; i<yx.size(); i++){
//		cout << yx[i].first << " " << yx[i].second << endl;
		if(yx[i].first >= p.second && yx[i].second >= p.first && !(yx[i].first == p.second && yx[i].second == p.first)) return false;
		if(yx[i].first < p.second) break;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
		xy.push_back(make_pair(x, y));
		yx.push_back(make_pair(y, x));
	}
	sort(xy.begin(), xy.end());
	sort(yx.begin(), yx.end(), greater<pair<int, int> >());
	
	int c = 0;
	for(int i=0; i<n; i++){
		if(check(xy[i])) {if(c) cout << ","; c++; cout << "(" << xy[i].first << "," << xy[i].second << ")";}
	}
	cout << endl;
	return 0;
}