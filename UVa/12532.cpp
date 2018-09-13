/*
ID: leezhen
TASK: practice
LANG: C++11                
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
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

class FenwickTree {
	private:
		vii ft;
		int last1(int i) {return i&(-i);}
	public:
		FenwickTree(int n) {
			ft.assign(n+1, ii(0, 0));
		}
		ii rmq(int a) {
			ii ttt = ii(0, 0);
			for(;a;a-=last1(a)) {
				ttt.first += ft[a].first;
				ttt.second += ft[a].second;
			}
			return ttt;
		}
		int rmq(int a, int b) {
			ii ta = rmq(a), tb = rmq(b);
			if(tb.first-ta.first) return 0;
			else {
				int t = tb.second - ta.second;
				if(t%2) return -1;
				else return 1;
			}
			return 0;
		}
		void update(int pos, int v, int op) {
			int ope[2] = {1, -1};
			if(v == 0) {
				for(;pos<(int)ft.size(); pos+=last1(pos)) {
					ft[pos].first += ope[op];
				}
			}else {
				for(; pos<(int)ft.size(); pos+=last1(pos)) {
					ft[pos].second += ope[op];
				}
			}
		}
};

int n, q;
vi lst;
int main() {
	
	while(scanf("%d%d", &n, &q) == 2) {
		FenwickTree fent(n);
		lst.resize(n+1);
		for(int i=1; i<=n; i++) {
			scanf("%d", &lst[i]);
			if(lst[i] == 0) fent.update(i, 0, 0);
			else if(lst[i] < 0) fent.update(i, -1, 0);
		}
		char nl, op;
		int s, e;
		for(int i=0; i<q; i++) {
			scanf("\n%c%d%d", &op, &s, &e);
//			cout << op << " " << s << " " << e << endl;
//			cout << i << endl;
			if(op == 'C') {
				if((lst[s]<0 && e<0) || (lst[s]>0&&e>0) || (lst[s]==0&&e==0)) continue;
				if(e == 0) {
					fent.update(s, 0, 0);
					if(lst[s]<0) fent.update(s, -1, 1);
				}
				else if(e < 0) {
					fent.update(s, -1, 0);
					if(lst[s] == 0) fent.update(s, 0, 1);
				}else {
					if(lst[s] == 0) fent.update(s, 0, 1);
					if(lst[s] < 0) fent.update(s, -1, 1);
				}
				lst[s] = e;
			}else {
				int t = fent.rmq(s-1, e);
				if(t == 0) cout << "0";
				else if(t < 0) cout << "-";
				else cout << "+";
			}
		}
		cout << endl;
	}
	return 0;
}