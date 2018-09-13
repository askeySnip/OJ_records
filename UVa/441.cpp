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
	int k;
	int s[15];
	int c = 0;
	while(scanf("%d", &k), k) {
		if(c++) printf("\n");
		for(int i=0; i<k; i++) {
			scanf("%d", s+i);
		}
		for(int i=0; i<k; i++) {
			for(int i2=i+1; i2<k; i2++) {
				for(int i3=i2+1; i3<k; i3++) {
					for(int i4=i3+1; i4<k; i4++) {
						for(int i5=i4+1; i5<k; i5++) {
							for(int i6=i5+1; i6<k; i6++) {
								printf("%d %d %d %d %d %d\n", s[i], s[i2], s[i3], s[i4],
								s[i5], s[i6]);
							}
						}
					}
				}
			}
		}
	}
	return 0;
}