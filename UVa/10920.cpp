/*
ID: leezhen1
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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
ll sz;
ll p;
ll dr[4] = {1, 0, -1, 0};
ll dc[4] = {0, -1, 0, 1};
int main() {
	while(scanf("%lld%lld", &sz, &p) == 2 && sz && p){
		ll len = 2, t=0, l = 1;
		ll c = 1;
		pair<ll, ll> pii = make_pair(sz/2+1, sz/2+1);
		while(1){
			if(c + len - 1 < p){
				pii = make_pair(pii.first+dr[t%4]*(len-1), pii.second+dc[t%4]*(len-1));
				t++;
				c += len-1;
				if(t%2 == 0) len++;
			}else{
				int tl = p - c;
				pii = make_pair(pii.first+dr[t%4]*tl, pii.second+dc[t%4]*tl);
				break;
			}
//			cout << pii.first << " " << pii.second  << " " << c << endl;
		}
		printf("Line = %lld, column = %lld.\n", pii.first, pii.second);
	}
	return 0;
}