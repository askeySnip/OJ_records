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
	multiset<int, greater<int> > msg, msb;
	int k, b, sg, sb, t;
	vi result;
	scanf("%d", &k);
	while(k--) {
		msg.clear();
		msb.clear();
		scanf("%d %d %d", &b, &sg, &sb);
		for(int i=0; i<sg; i++) {
			scanf("%d", &t);
			msg.insert(t);
		}
		result.clear();
		result.resize(b);
		for(int i=0; i<sb; i++) {
			scanf("%d", &t);
			msb.insert(t);
		}
		while(!msg.empty() && !msb.empty()) {
			int c = 0;
			for(int i=0; i<b && !msg.empty() && !msb.empty(); i++) {
				result[i] = (*msg.begin()) - (*msb.begin());
				msg.erase(msg.begin());
				msb.erase(msb.begin());
				c++;
			}
			for(int i=0; i<c; i++) {
				if(result[i] == 0) continue;
				else if(result[i] > 0) {
					msg.insert(result[i]);
				} else {
					msb.insert(-result[i]);
				}
			}
		}
		if(!msg.empty()) {
			printf("green wins\n");
			for(auto it=msg.begin(); it!=msg.end(); it++) {
				printf("%d\n", *it);
			}
		}
		else if(!msb.empty()) {
			printf("blue wins\n");
			for(auto it=msb.begin(); it!=msb.end(); it++) {
				printf("%d\n", *it);
			}
		} 
		else {
			printf("green and blue died\n");
		}
		if(k) printf("\n");
	}
	return 0;
}