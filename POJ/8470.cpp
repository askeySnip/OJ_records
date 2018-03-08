#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
int n, ans = 10000000, nodes;
vector<string> v;
int mp[13][13];
int vis[13];
int caclu(int a, int b){
	string& s1 = v[a];
	string& s2 = v[b];
	if(s1.find(s2) != string::npos) return 0;
	int len = min(s1.length(), s2.length());
	int i=len;
	for(;i>0;i--){
		bool ok = true;
		for(int j=s1.length()-i, k=0; j<s1.length() && k<len; j++, k++){
			if(s1[j] != s2[k]) {
				ok = false;
				break;
			}
		}
		if(ok){
			return s2.length() - i;
		}
	}
	return s2.length(); 
}
void dfs(int k, int t, int c){
	c++;
	if(c == nodes) {if(ans > t) ans = t; return ;} 
	vis[k] = 1;
	for(int i=0; i<n; i++){
		if(!vis[i] && t < ans) {
//			if(c == 1) t = v[0].length();
			dfs(i, t+mp[k][i], c);
		}
	}
	vis[k] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		nodes = n;
		v.clear();
		ans = 10000000;
		memset(mp, 999, sizeof(mp));
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<n; i++){
			string s;
			cin >> s;
			v.push_back(s);
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(v[i].find(v[j]) != string::npos) {vis[j] = 1; nodes--;}
				else if(v[j].find(v[i]) != string::npos) {vis[i] = 1; nodes--;}
			}
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				mp[i][j] = caclu(i, j);
				mp[j][i] = caclu(j, i);
//				cout << mp[i][j] << " " <<  mp[j][i];
			}
		}
		
		for(int i=0; i<n; i++) if(!vis[i]) dfs(i, v[i].length(), 0);
		cout << ans << endl;
	}
}