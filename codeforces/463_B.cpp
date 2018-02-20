#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 1000003;
int g[MAXN];
int f[MAXN];
int gc[10][MAXN];
int get_g(int n){
	if(g[n] != 0){
		return g[n];
	}
	if(n < 10){
		return n;
	}else{
		return get_g(f[n]);
	}
}
int get_f(int n){
	int ret = 1;
	while(n){
		if(n%10 != 0){
			ret *= n%10;
		}
		n/=10;
	}
	return ret;
}
int main() {
	int q;
	cin >> q;
	memset(g, 0, sizeof(g));
	memset(f, 0, sizeof(f));
	memset(gc, 0, sizeof(gc));
	for(int i=1; i<MAXN; i++){
		f[i] = get_f(i);
	}
	for(int i=1; i<MAXN; i++){
		g[i] = get_g(i);
		for(int j=1; j<10; j++){
			if(g[i] == j){
				gc[j][i] = gc[j][i-1] + 1;
			}else{
				gc[j][i] = gc[j][i-1];
			}
		}
	}
	for(int i=0; i<q; i++){
		int l,r,k;
		cin >> l >> r >> k;
		int ans = 0;
		
		cout << gc[k][r]-gc[k][l-1] << endl;
	}
	return 0;
}