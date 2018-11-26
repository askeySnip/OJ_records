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
	int q;
	scanf("%d", &q);
	int l, r;
	for(int i=0; i<q; i++) {
		scanf("%d%d", &l, &r);
		if(l == r) {
			printf("%d\n", l * (l%2==0? 1:-1));
		}else{
			int n = r-l+1;
			if(n%2 == 0 && r%2 == 0) {
				printf("%d\n", n/2);
			}else if(n%2 == 0 && r%2 == 1) {
				printf("%d\n", -n/2);
			}else if(n%2 && r%2 == 0) {
				printf("%d\n", n/2+l);
			}else {
				printf("%d\n", -n/2-l);
			}
		}
	}
	return 0;
}