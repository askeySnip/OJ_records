#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;
const int N = 110000;
int n[6], num[150000];
int p[6] = {1, 2, 3, 5, 10, 20};
bitset <N> A;

int main() {
	int t = 0;
	for(int i=0; i<6; i++) {cin >> n[i]; t+=n[i]*p[i];}
	int m = 0;
	for(int i=0; i<6; i++){
		int base = 1;
		while(n[i] >= base){
			num[++m] = base * p[i];
			n[i] -= base;
			base *= 2;
		}
		if(n[i] > 0) num[++m] = n[i]*p[i];
	}
	A[0] = 1;
	for(int i=1; i<=m; i++)
		A |= (A << num[i]);
	cout << "Total=" << A.count() - 1 << endl;
	return 0;
}