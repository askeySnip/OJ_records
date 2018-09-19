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
	unsigned int n, l, u, m, temp;
	while(~scanf("%u%u%u", &n, &l, &u)) {
		m = 0;
		for(int i=31; i>=0; i--) {
			temp = m | (1u<<i);
			if((((n>>i)&1)==0 && temp <= u) || ((l>>i)&1 && m < l)) m = temp;
		}
		printf("%u\n", m);
	}
	return 0;
}