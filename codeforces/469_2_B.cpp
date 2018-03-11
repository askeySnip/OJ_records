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
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int x[100000+10], y[100000+10];
	for(int i=0; i<n; i++){
		scanf("%d", &x[i]);
	}
	for(int i=0; i<m; i++) scanf("%d", &y[i]);
	int ans = 0;
	int i=1, j=1;
	int sumx=x[0], sumy=y[0];
	while(i < n && j < m){
		if(sumx == sumy){
			sumx = x[i];
			sumy = y[j];
//			cout << i << " " << j << endl;
			ans++;
			i++;
			j++;
		}
		if(sumx < sumy) {sumx += x[i]; i++;}
		else if(sumy < sumx) {sumy += y[j]; j++;}
//		cout << i << " " << j << endl;
	}
//	if(i<n || j < m) ans++;
	printf("%d\n", ans+1);
	return 0;
}