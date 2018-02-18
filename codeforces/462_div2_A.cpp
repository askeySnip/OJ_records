#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll;
const ll INF = (1LL << 60) - 1;
ll a[55], b[55];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
		cin >> a[i];
	for(int i=0; i<m; i++)
		cin >> b[i];
	ll res = INF;
	for(int i=0; i<n; i++){
		ll now = -INF;
		for(int j=0; j<n; j++){
			if(j!=i){
				for(int k=0; k<m; k++){
					now = max(now, a[j]*b[k]);
				}
			}
		}
		res = min(res, now);
	}
	cout << res << endl;
	return 0;
}