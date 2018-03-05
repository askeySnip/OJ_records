#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
int main() {
	int h, w, d;
	scanf("%d%d%d", &h, &w, &d);
	pair<int, int> pa[90009];
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			int a;
			cin >> a;
			pa[a] = make_pair(i, j);
		}
	}
	int q;
	cin >> q;
	int ch[90009];
	for(int j=1; j<=d; j++){
		ch[j] = 0;
		int lx = pa[j].first, ly = pa[j].second;
		for(int i=j+d; i<=h*w; i+=d){
			ch[i] = ch[i-d] + abs(pa[i].first - lx)+ abs(pa[i].second - ly);
			lx = pa[i].first;
			ly = pa[i].second;
		}
	}
	for(int i=0; i<q; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		
		printf("%d\n", ch[r]-ch[l]);
	}
	return 0;
}