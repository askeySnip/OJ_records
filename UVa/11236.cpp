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
	int a, b, c, d;
	long long p, s;
	for (a = 1; a+a+a+a <= 2000; a++)
	for (b = a; a+b+b+b <= 2000; b++)
	for (c = b; a+b+c+c <= 2000; c++) {
		p = (long long) a * b * c;
		s = a + b + c;
		if (p <= 1000000)
			continue;
		if ((s * 1000000) % (p - 1000000))
			continue;
		d = (s * 1000000) / (p - 1000000);
		s += d;
		if (s > 2000 || d < c)   continue;
		printf("%d.%02d %d.%02d ", a/100, a%100, b/100, b%100);
		printf("%d.%02d %d.%02d\n", c/100, c%100, d/100, d%100);
	}
	return 0;
}