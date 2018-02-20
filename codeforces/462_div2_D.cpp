#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
ll p, k;
ll ans[120];
int cnt = 0;
ll get(){
	ll x = p%k;
	if(x < 0) x += k;
	return x%k;
}
int main() {
	cin >> p >> k;
	while(p != 0){
		cnt++;
		ans[cnt] = get();
		p -= ans[cnt];
		p /= (-k);
	}
	cout << cnt << endl;
	for(int i=1; i<cnt; i++){
		cout << ans[i] << " ";
	}
	cout << ans[cnt] << endl;
	return 0;
}