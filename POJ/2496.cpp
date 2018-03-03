#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	while(cin >> n){
		int a, sum = 0, maxn = 0;
		for(int i=0; i<n; i++){
			cin >> a;
			maxn = max(maxn, a);
			sum += a;
		}
		int sum2 = sum - maxn;
		if(sum2 <= maxn) printf("%.1f\n", (double)sum2);
		else printf("%.1f\n", (double)((double)sum/2.0));
	}
	return 0;
}