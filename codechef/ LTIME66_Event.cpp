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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
const int inf = 1e9;
const int mod = 1e9+7;

int decode(string& s) {
	if(s == "saturday") return 5;
	else if(s == "sunday") return 6;
	else if(s == "monday") return 0;
	else if(s == "tuesday") return 1;
	else if(s == "wednesday") return 2;
	else if(s == "thursday") return 3;
	else if(s == "friday") return 4;
	return -1;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string s, e;
		cin >> s >> e;
		int l, r;
		cin >> l >> r;
		int start_day, end_day;
		start_day = decode(s);
		end_day = decode(e);
		while(end_day - start_day + 1 < l) end_day += 7;
		int c= 0;
		while(end_day - start_day+1 >= l && end_day-start_day+1 <= r) {
			c++;
			end_day += 7;
		}
		if(c == 0) cout << "impossible" << endl;
		else if(c == 1) cout << end_day-7-start_day+1 << endl;
		else cout << "many" << endl;
	}
	return 0;
}