#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int gcd(int a, int b){
	if(a < b) {
		int t = a;
		a = b;
		b = t;
	}
	if(a % b == 0) return b;
	else return gcd(b, a-b);
}
int main() {
//	cout << (1 << 15);
	int n;
	while (cin >> n) {
		if(n == 0) break;
		int t = n*(n-1)/2;
		int l[50+1];
		int c = 0;
		for(int i=0; i<n; i++) cin >> l[i];
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(gcd(l[i], l[j]) == 1) c++;
			}
		}
//		cout << c << t << endl;
		if(c == 0) printf("No estimate for this data set.\n");
		else{
			double pi_square = 6.0/c*t;
			printf("%.6f\n", sqrt(pi_square));
		}
	}

	return 0;
}