#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <cmath>

using namespace std;
double esp = 1e-5;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	double l, d, c;
	while(cin >> l >> d >> c){
		if(l < 0 && d < 0 && c < 0) break;
		double ll = (1+d*c)*l;
		double low, high;
		double mid, r;
		low = 0;
		high = l/2;
		while(high - low > esp){
			mid = (high + low) / 2;
			r = (4*mid*mid+l*l)/(8*mid);
			if(2*r*asin(l/(2*r)) < ll){
				low = mid;
			}else {
				high = mid;
			}
		}
		printf("%.3f\n", mid);
	}
	return 0;
	
}