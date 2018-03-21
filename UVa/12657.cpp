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
const int maxn = 100000+30;
int Left[maxn], Right[maxn];
int n, k, kase = 0;
void link(int l, int r){
	Right[l] = r;
	Left[r] = l;
}
int main() {
	while(scanf("%d%d", &n, &k) == 2){
		for(int i=1; i<=n; i++){
			Left[i] = i-1;
			Right[i] = (i+1)%(n+1);
		}
		Right[0] = 1;
		Left[0] = n;
		int op, x, y, inv = 0;
		while(k--){
			scanf("%d", &op);
			if(op == 4) inv = 1 - inv;
			else{
				scanf("%d%d", &x, &y);
				if(op == 3 && Right[y] == x) swap(x, y);
				if(op != 3 && inv) op = 3 - op;
				if(op == 1 && x == Left[y]) continue;
				if(op == 2 && x == Right[y]) continue;
				
				int lx = Left[x], rx = Right[x], ly = Left[y], ry = Right[y];
				if(op == 1){
					link(lx,rx); link(ly, x); link(x, y);
				}else if(op == 2){
					link(lx, rx); link(y, x); link(x, ry);
				}else if(op == 3){
					if(Right[x] == y) {
						link(lx, y); link(y, x); link(x, ry);
					}else{
						link(lx, y); link(y, rx); link(ly, x); link(x, ry);
					}
				}
			}
		}
		int b = 0;
		long long ans = 0;
		for(int i=1; i<=n; i++){
			b = Right[b];
			if(i%2==1) ans += b;
		}
		if(inv && n%2==0) ans = (long long)n*(n+1)/2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}