/*
ID: leezhen1
TASK: Division
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
int vist[10];
bool check(int t){
	int list[10];
	memset(list, 0, sizeof(list));
	int i=0;
	while(t){
		int k = t%10;
		if(vist[k] || list[k]) return false;
		list[k] = 1;
		t/=10;
		i++;
	}
	if(i<5 && vist[0]) return false;
	return true;
}
int main() {
	int kase = 0;
	while (scanf("%d", &n) && n) {
		if(kase) printf("\n");
		kase++;
		memset(vist, 0, sizeof(vist));
		bool flag = true;
		for(int i=0; i<10; i++){
			vist[i] = 1;
			int b=0;
			b+=i*10000;
			for(int j=0; j<10; j++){
				if(vist[j]) continue;
				vist[j] = 1;
				b+=j*1000;
				for(int k=0; k<10; k++){
					if(vist[k]) continue;
					vist[k] = 1;
					b += k*100;
					for(int l=0; l<10; l++){
						if(vist[l]) continue;
						vist[l] = 1;
						b += l*10;
						for(int p=0; p<10; p++){
							if(vist[p]) continue;
							vist[p] = 1;
							b += p;
							int t = b * n;
//							cout << b << " " << t << endl;
							if(check(t)){
								flag = false;
								if(i) printf("%d / %d = %d\n", t, b, n);
								else printf("%d / 0%d = %d\n", t, b, n);
							}
							vist[p] = 0;
							b -= p;
						}
						vist[l] = 0;
						b -= l*10;
					}
					vist[k] = 0;
					b -= k*100;
				}
				vist[j] = 0;
				b -= j*1000;
			}
			vist[i] = 0;
			b -= i*10000;
		}
		if(flag) printf("There are no solutions for %d.\n", n);
	}
	return 0;
}