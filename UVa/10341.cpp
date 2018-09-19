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
#define EPS 1e-9
int p, q, r, s, t, u;
double f(double i) {
	return p*exp(-i) + q*sin(i) + r*cos(i) + s*tan(i) + t*i*i + u;
}

bool can(double i) {
	double result = 0.0;
	result += p*exp(-i) + q*sin(i) + r*cos(i) + s*tan(i) + t*i*i + u;
	return fabs(result)<=0.00001;
}
int main() {
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF) {
		if(f(0) * f(1) > 0) {
			puts("No solution");
			continue;
		}
		double l = 0.0, h = 1.0, mid;
		while(h-l > EPS) {
			mid = (l+h)/2.0;
			if(f(mid) < 0) h = mid;
			else l = mid;
		}
		printf("%.4f\n", mid);
	}
	
	return 0;
}