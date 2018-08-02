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
int main() {
	char s[10];
	int rid, period;
	priority_queue<ii, vector<ii>, greater<ii>> pri_que;
	map<int, int> mp;
	while(scanf("%s", s), s[0] != '#') {
		scanf("%d %d", &rid, &period);
		pri_que.push(make_pair(period, rid));
		mp[rid] = period;
	}
	scanf("%d", &rid);
	for(int i=0; i<rid; i++) {
		printf("%d\n", pri_que.top().second);
		pri_que.push(make_pair(pri_que.top().first+mp[pri_que.top().second], pri_que.top().second));
		pri_que.pop();
	}
	return 0;
}