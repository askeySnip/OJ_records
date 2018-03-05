#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[100003];
//	long long ans = 0L;
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a, a+n);
	int l = a[0], r = a[n-1];
	if(r - l <= 1){
		printf("%d\n", n);
		for(int i=0; i<n-1; i++) printf("%d ", a[i]);
		printf("%d\n", a[n-1]);
	}else{
		int t1 = lower_bound(a, a+n, l+1) - a;
		int t2 = lower_bound(a, a+n, r) - a;
		t2 -= t1;
		int t3 = n - t1 - t2;
		int t = min(t1, t3);
		if(t >= t2/2) {printf("%d\n", n - 2 * t);
		t1 -= t;
		t2 = t2 + (2 * t);
		t3 = t3 - t;}
		else{printf("%d\n", n - t2/2*2); t1+=t2/2;t3+=t2/2; t2-=t2/2*2; }
//		cout << t1 << " " << t2 << " " << t3 << endl;
		for(int i=0; i<t1; i++) printf("%d ", l);
		for(int i=0; i<t2; i++) printf("%d ", l+1);
		for(int i=0; i<t3; i++) printf("%d ", r);
		printf("\n");
	}
	return 0;
}