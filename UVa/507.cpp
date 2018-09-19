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
	int b, s;
	int route[20024];
	scanf("%d", &b);
	for(int k=1; k<=b; k++) {
		scanf("%d", &s);
		for(int i=1; i<s; i++) scanf("%d", &route[i]);
		int max_val = -1;
		int start = 1, st=0, e=0;
		int tval = 0;
		for(int i=1; i<s; i++) {
			tval += route[i];
			if(tval < 0) {tval = 0; start = i+1;}
			else {
				if(max_val < tval || (max_val == tval && i+1-start > e-st)) {
					max_val = tval;
					st = start; e = i+1;
				}
			}
//			cout << tval << endl;
		}
//		if(max_val <= tval && s-start > e-st) {max_val = tval; st = start; e = s;}
		if(max_val>0) printf("The nicest part of route %d is between stops %d and %d\n", k, st, e);
		else printf("Route %d has no nice parts\n", k);
	}
	return 0;
}