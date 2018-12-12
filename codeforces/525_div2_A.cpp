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

int main() {
	int x;
	cin >> x;
	bool flag = false;
	for(int i=1; i<=x; i++) {
		if(flag) break;
		for(int j=1; j<=x; j++) {
			if(flag) break;
			if(i%j == 0) {
				if(i * j > x && i < j * x) {
					printf("%d %d\n", i, j);
					flag = true;
				}
			}
		}
	}
	if(!flag) printf("-1\n");
	return 0;
}