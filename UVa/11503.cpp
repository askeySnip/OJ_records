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
class unionFind{
	private: 
		int c;
		vi p, rank, size;
		map<string, int> mp;
	public:
		unionFind(int n) {
			p.assign(n, 0);
			for(int i=0; i<n; i++) p[i] = i;
			rank.assign(n, 0);
			size.assign(n, 1);
			c = 0;
		}
		int findSet(int i) {
			return (p[i]==i)? i : (p[i] = findSet(p[i]));
		}
		bool isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j) {
			if(!isSameSet(i, j)) {
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y]) {
					p[y] = x;
					size[x] += size[y];
				} else {
					p[x] = y;
					if(rank[x] == rank[y]) rank[y]++;
					size[y] += size[x];
				}
			}
		}
		void setId(string s) {
			if(mp.find(s) == mp.end()) {
				mp[s] = c++;
			}
		} 
		int getId(string s) {
			return mp[s];
		}
		int getSize(int i) {
			return size[findSet(i)];
		}
};
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int k, f;
	cin >> k;
	while(k--) {
		cin >> f;
		string s1, s2;
		unionFind uf(f+1);
		for(int i=0; i<f; i++) {
			cin >> s1 >> s2;
			uf.setId(s1);
			uf.setId(s2);
			uf.unionSet(uf.getId(s1), uf.getId(s2));
			cout << uf.getSize(uf.getId(s2)) << endl;
		}
	}
	return 0;
}