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
	int b, s;
	int bach[10024], spin[10024];
	int kase = 0;
	while(scanf("%d %d", &b, &s), b||s) {
		for(int i=0; i<b; i++) scanf("%d", &bach[i]);
		for(int i=0; i<s; i++) scanf("%d", &spin[i]);
		printf("Case %d: ", ++kase);
		if(b <= s) {printf("0\n"); continue;}
		int m = bach[0];
		for(int i=0; i<b; i++) m=min(m, bach[i]);
		printf("%d %d\n", b-s, m);
	}
	return 0;
}