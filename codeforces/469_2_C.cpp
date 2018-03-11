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
	vector<int> z1,z0;
	vector<int> vec[200000+20];
	char s[200000+20];
	scanf("%s", s+1);
	int len = strlen(s+1);
	for(int i=1; i<=len; i++){
		if(s[i] == '0'){
			if(z1.empty()){
				z0.push_back(i);
				vec[i].push_back(i);
			}else{
				int t = z1.back();
				z1.pop_back();
				z0.push_back(t);
				vec[t].push_back(i);
			}
		}else{
			if(z0.empty()){
				puts("-1");
				return 0;
			}
			int t = z0.back();
			z0.pop_back();
			vec[t].push_back(i);
			z1.push_back(t);
		}
	}
	if(z1.size()){
		puts("-1");
		return 0;
	}
	printf("%u\n", z0.size());
	for(int i=0;i<z0.size(); i++){
		printf("%u", vec[z0[i]].size());
		for(int j=0; j<vec[z0[i]].size(); j++){
			printf(" %d", vec[z0[i]][j]);
		}
		puts("");
	}
	return 0;
}