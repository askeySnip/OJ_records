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
	int n;
	scanf("%d", &n);
	int a[2048];
	for(int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		a[i] += 5000;
	}
	printf("%d\n", n+1);
	printf("1 %d 5000\n", n);
	for(int i=1; i<=n; i++) {
		printf("2 %d %d\n", i, a[i]-i);
	}
	return 0;
}