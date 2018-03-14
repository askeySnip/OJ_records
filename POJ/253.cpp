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
int mp[30][30];
int vist[30];
priority_queue<pair<int, int> > q;
int solve(){
	int ans = 0;
	for(int i=0; i<n; i++){
		if(!vist[i] && mp[0][i] != -1){
			q.push(make_pair(-mp[0][i], i));
		}
	}
	while(!q.empty()){
		pair<int, int> p = q.top();
		q.pop();
//		cout << p.second << endl;
		if(vist[p.second]) continue;
		vist[p.second] = 1;
		ans -= p.first;
		for(int i=0; i<n; i++){
			if(!vist[i] && mp[p.second][i] != -1){
				q.push(make_pair(-mp[p.second][i], i));
			}
		}
	}
	return ans;
}
int main() {
	while(cin >> n){
		if(!n) break;
		memset(mp, -1, sizeof(mp));
		for(int i=0; i<n-1; i++){
			char s;
			cin >> s;
			int t = s-'A';
			int k, d;
			cin >> k;
//			cout << s << " " << t << " " << k;
			for(int j=0; j<k; j++){
				char c;
				cin >> c >> d;
				int t1 = c-'A';
				mp[t][t1] = mp[t1][t] = d;
			}
		}
		memset(vist, 0, sizeof(vist));
		vist[0] = 1;
		cout << solve() << endl;
	}
	return 0;
}