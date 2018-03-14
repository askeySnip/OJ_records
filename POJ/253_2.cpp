/*
ID: leezhen1
TASK: test
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
#include <queue>

using namespace std;
int n;
struct edge{
	int u, v, w;
}e[100];
int fa[100];
bool cmp(edge& e1, edge& e2){
	return e1.w < e2.w;
}
int fnd(int x){
	if(fa[x] == x) return x;
	else return fa[x] = fnd(fa[x]);
}
int main() {
	while(scanf("%d", &n)){
		if(!n) break;
		int tot = 0;
		for(int i=0; i<n-1; i++){
			char s;
			cin >> s;
			int t = s-'A';
			int k, d;
			cin >> k;
			for(int j=0; j<k; j++){
				char c;
				cin >> c >> d;
				int t1 = c-'A';
				e[tot].u = t;
				e[tot].v = t1;
				e[tot++].w = d;
			}
		}
		sort(e, e+tot, cmp);
		int ans = 0;
		for(int i=0; i<n; i++) fa[i] = i;
		for(int i=0; i<tot; i++){
			int x = fnd(e[i].u);
			int y = fnd(e[i].v);
			if(x != y){
				fa[x] = y;
				ans += e[i].w;
			}
		}
		cout << ans << endl;
	}
	return 0;
}