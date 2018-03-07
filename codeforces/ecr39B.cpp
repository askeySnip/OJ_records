#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
int main() {
	ll a, b;
	cin >> a >> b;
	while(!(a == 0 || b == 0 || (a<2*b && b<2*a))){
		if(a>=2*b) a = a%(2*b);
		else if(b>=2*a) b = b%(2*a);
		else break;
	}
	
	cout << a << " " << b << endl;
	return 0;
}