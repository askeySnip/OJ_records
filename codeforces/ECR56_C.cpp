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
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, b;
	cin >> n;
	ll a[200024];
	cin >> b;
	a[0] = 0L; a[n-1] = b;
 	ll cur = 0, big = b;
	REP(i, 1, n/2) {
		cin >> b;
		if(big >= b) {
			a[i] = cur;
			a[n-i-1] = b-a[i];
			big = a[n-i-1];
		}else {
			a[i] = max(b - big, cur);
			cur = a[i];
			a[n-i-1] = b - a[i];
			big = b - a[i];
		}
	}
	REP(i, 0, n) {
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
	return 0;
}