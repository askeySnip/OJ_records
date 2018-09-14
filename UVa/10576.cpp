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
	int s,d;  
	int ans;  
	while(cin>>s && cin>>d)  
	{  
		if(d>4*s)ans=10*s-2*d;  
		else if(2*d>3*s)ans=8*s-4*d;  
		else if(3*d>2*s)ans=6*(s-d);  
		else if(4*d>s)ans=3*(s-3*d);  
		else ans=-1;  
		if(ans<0)cout<<"Deficit"<<endl;  
		else cout<<ans<<endl;  
	}
	return 0;
}