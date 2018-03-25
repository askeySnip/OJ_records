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
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
struct Point{
	int r, c;
	Point(int a, int b):r(a), c(b){}
};
int mover[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int movec[8] = {2, -2, 1, -1, 2, -2, 1, -1};
char st[10], ed[10];
int solve(){
	if(strcmp(st, ed) == 0) return 0;
	pair<Point, int> startp = make_pair(Point(st[0]-'a'+1, st[1]-'0'), 0);
	Point endp = Point(ed[0]-'a'+1, ed[1]-'0');
	queue<pair<Point, int> > q;
	q.push(startp);
	while(!q.empty()){
		pair<Point, int> u = q.front();
		q.pop();
		for(int i=0; i<8; i++){
			int rt = u.first.r + mover[i], ct = u.first.c + movec[i];
			if(rt == endp.r && ct == endp.c) return u.second+1;
			if(rt > 0 && ct > 0 && rt < 9 && ct < 9){
				q.push(make_pair(Point(rt, ct), u.second+1));
			}
		}
	}
	return -1;
}
int main() {
	
	while(scanf("%s%s", st, ed) == 2){
		printf("To get from %s to %s takes %d knight moves.\n", st, ed, solve());
	}
	return 0;
}