/*
ID: leezhen1
TASK: practice
LANG: C++14                 
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

using namespace std;
int n;
long long s[20];
int main() {
	int kase = 0;
	s[0] = 1L;
	while(scanf("%d", &n) == 1){
		vector<int> zeros;
		long long minx = 0L;
		for(int i=1; i<=n; i++){
			long long t;
			scanf("%lld", &t);
			if(t!=0) s[i] = s[i-1] * t;
			else {
				s[i] = 1;
				zeros.push_back(i);
			}
		}
		
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				bool flag = false;
				for(int k=0; k<zeros.size(); k++){
					if(zeros[k]>=i && zeros[k]<=j) {
						flag = true;
						break;
					}
				}
				if(flag) break;
				if(s[j]/s[i-1] > minx) minx = s[j]/s[i-1];
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", ++kase, minx);
	}
	return 0;
}