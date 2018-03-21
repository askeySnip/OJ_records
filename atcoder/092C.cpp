/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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
#include <cmath>

using namespace std;
struct Point{
	int x, y;
	int color;
	Point(int a, int b, int c):x(a), y(b), color(c){};
};
bool cmp(Point& p1, Point& p2){
	if(p1.x != p2.x){
		return p1.x < p2.x;
	}else{
		return p1.y < p2.y;
	}
}
int main() {
	int n;
	cin >> n;
	set<int> s;
	vector<Point> points;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		points.push_back(Point(a, b, 0));
	}
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		points.push_back(Point(a, b, 1));
	}
	sort(points.begin(), points.end(), cmp);
	int ans = 0;
	for(int i=0; i<points.size(); i++){
		if(points[i].color == 0){
			s.insert(points[i].y);
		}else{
			int y = points[i].y;
			int t = -1;
			auto it=s.begin();
			for(; it!=s.end(); it++){
				if(*it >= y) break;
				else
					t = *it;
			}
			if(t!= -1){
				s.erase(--it);
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}