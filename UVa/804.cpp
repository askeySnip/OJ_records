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
struct transition{
	map<int, int> in, out;
};
int np, nt, nf;
int p[130];
transition tr[130];
void init(){
	for(int i=0; i<130; i++){
		tr[i].in.clear();
		tr[i].out.clear();
	}
	memset(p, 0, sizeof(p));
}
bool check(transition& tt){
	map<int, int>& mp = tt.in;
	for(auto it = mp.begin(); it!=mp.end(); it++){
		if(p[it->first] < it->second) return false;
	}
	for(auto it = mp.begin(); it!=mp.end(); it++){
		p[it->first] -= it->second;
	}
	for(auto it = tt.out.begin(); it!=tt.out.end(); it++){
		p[it->first] += it->second;
	}
	return true;
}
int solve(){
	int cnt = 0;
	while(true){
		bool flag = false;
		for(int i=1; i<=nt; i++){
			if(check(tr[i])) {
				cnt++;
				flag = true;
			}
			if(cnt == nf) {flag = false; break;}
		}
//		cout << cnt << endl;
		if(!flag) break;
	}
	return cnt;
}
void print_status(){
	printf("Places with tokens:");
	vector<pair<int, int> > v;
	for(int i=1; i<=np; i++){
		if(p[i] > 0) v.push_back(make_pair(p[i], i));
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		printf(" %d (%d)", v[i].second, v[i].first);
	}
}
int main() {
	int kase = 0;
	while(scanf("%d", &np) == 1 && np){
		init();
		for(int i=1; i<=np; i++)
			scanf("%d", &p[i]);
		scanf("%d", &nt);
		for(int i=1; i<=nt; i++){
			int t;
			while(scanf("%d", &t)==1 && t!=0){
				if(t>0){
					tr[i].out[t]++;
				}else{
					tr[i].in[-t]++;
				}
			}
		}
		scanf("%d", &nf);
		int act = solve();
		if(act == nf) {
			printf("Case %d: still live after %d transitions\n", ++kase, nf);
		}else{
			printf("Case %d: dead after %d transitions\n", ++kase, act);
		}
		print_status();
		printf("\n\n");
	}
	return 0;
}