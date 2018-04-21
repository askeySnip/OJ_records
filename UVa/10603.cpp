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
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int cup[3];
int d, dd, ddis;
int vist[210][210];
struct status{
	int list[3];
	int dis;
};
bool operator<(status s1, status s2){
	return s1.dis > s2.dis;
}
bool check(status& s){
	for(int i=0; i<3; i++){
		if(s.list[i] == d) return true;
		if(s.list[i] < d && s.list[i] > dd) dd=s.list[i], ddis = s.dis;
	}
	return false;
}
void solve(){
	dd = 0;
	ddis = 0;
	status r;
	r.list[0]=0, r.list[1]=0, r.list[2]=cup[2];
	r.dis = 0;
	vist[0][0] = 1;
	priority_queue<status> q;
	q.push(r);
	while(!q.empty()){
		status t = q.top();
		q.pop();
		if(check(t)){
			printf("%d %d\n", t.dis, d);
			return;
		}
		for(int i=0; i<3; i++){
			if(t.list[i] != 0){
				for(int j=0; j<3; j++){
					if(i == j) continue;
					int dt = min(t.list[i], cup[j] - t.list[j]);
					status ss;
					ss.list[i] = t.list[i] - dt;
					ss.list[j] = t.list[j] + dt;
					ss.list[3-i-j] = cup[2] - ss.list[i] - ss.list[j];
					ss.dis = t.dis + dt;
					if(!vist[ss.list[0]][ss.list[1]]){
						vist[ss.list[0]][ss.list[1]] = 1;
						q.push(ss);
					}
				}
			}
		}
	}
	printf("%d %d\n", ddis, dd);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &cup[0], &cup[1], &cup[2], &d);
		if(d >= cup[2]){
			printf("%d %d\n", 0, cup[2]);
		}else{
			memset(vist, 0, sizeof vist);
			solve();
		}
	}
	return 0;
}