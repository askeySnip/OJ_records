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
	int t, n;
	char field[103];
	scanf("%d", &t);
	int kase = 0;
	while(t--) {
		scanf("%d", &n);
		scanf("%s", field);
		int ans = 0;
		for(int i=0; i<n; ) {
			if(field[i] == '.') {
				ans++;
				i+=3;
			}else i++;
		}
		printf("Case %d: %d\n", ++kase, ans);
	}
	return 0;
}