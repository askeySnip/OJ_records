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
	int n;
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 24, 27, 30, 22, 33, 36, 26, 39, 28, 42, 45, 32, 48, 34, 51, 54, 38, 57, 40, 60, 50};
	sort(a, a+43);
	map<pair<int, ii>, int> mp;
	while(scanf("%d", &n), n>0) {
		if(n > 180) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
		else {
			mp.clear();
			int c = 0, p = 0;
			for(int i=0; i<43; i++) {
				for(int j=0; j<43; j++) {
					for(int k=0; k<43; k++) {
						if(a[i]+a[j]+a[k] == n) {
							p++;
							pair<int, ii> piii;
							if(i>=j && j>=k) piii = make_pair(i, make_pair(j, k));
							else if(i>=k && k>=j) piii = make_pair(i, make_pair(k, j));
							else if(j>=i && i>=k) piii = make_pair(j, make_pair(i, k));
							else if(j>=k && k>=i) piii = make_pair(j, make_pair(k, i));
							else if(k>=i && i>=j) piii = make_pair(k, make_pair(i, j));
							else piii = make_pair(k, make_pair(j, i));
							if(mp.find(piii) == mp.end()) {
								c++;
								mp[piii] = 1;
							}
						}
					}
				}
			}
			if(c == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
			else {
				printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, c);
				printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, p);
			}
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}