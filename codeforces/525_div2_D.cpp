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
	int a = 0, b = 0, r1, r2, c, d;
	printf("? 0 0\n");
	fflush(stdout);
	scanf("%d", &r1);
	bool flag = (r1 == 1? true:false);
	for(int i=29; i>=0; i--) {
		c = a | (1 << i);
		d = b;
		printf("? %d %d\n", c, d);
		fflush(stdout);
		scanf("%d", &r1);
		c = a;
		d = b | (1 << i);
		printf("? %d %d\n", c, d);
		fflush(stdout);
		scanf("%d", &r2);
		if(r1 != r2) {
			if(r2 == 1) {
				a = a | (1 << i);
				b = b | (1 << i);
			}
		}else {
			if(flag) {
				a = a | (1 << i);
			}else {
				b = b | (1 << i);
			}
			flag = (r1 == 1? true:false);
		}
	}
	printf("! %d %d\n", a, b);
	fflush(stdout);
	return 0;
}