#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int t = n/2;
	if((a > t && b <= t) || (a<=t && b>t)){
		cout << "Final!" << endl;
	}
	else{
		if(a > b){
			if(a % 2 == 1) a += 1;
			if(b % 2 != 1) b -= 1;
		}else{
			if(a % 2 != 1) a -= 1;
			if(b % 2 == 1) b += 1;
		}
//		t = abs(a-b)+1;
////		cout << t << endl;
//		int c = 1;
//		while((1 << c) < t) c++;
//		cout << c << endl;
		int c = 1;
		while((a+(1<<c)-1)/(1<<c) != (b+(1<<c)-1)/(1<<c)) c++;
		cout << c << endl;
	}
	return 0;
}