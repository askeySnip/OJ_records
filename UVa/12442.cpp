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
#define MAX 50005
int T,N;
int vis[MAX], f[MAX], c[MAX];
int m, mu;
 
int dfs(int u){
    int v = f[u];
    int r = 0;
    vis[u] = 1;
    if(!vis[v])
        r = dfs(v) + 1;
    vis[u] = 0;
    c[u] = r;
    return r;
}
 
int main(){
    int t,i,u,v;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&N);
        for(i=1;i<=N;i++){
            scanf("%d %d",&u,&v);
            f[u] = v;
            vis[u] = 0;
            c[u] = -1;
        }
        m = -1;
        for(i=1;i<=N;i++){ 
            if(c[i]==-1) dfs(i);
            if(c[i]>m){
                m=c[i];
                mu=i;
            }
            /*printf("vertex %d children %dn",i,c[i]);*/
        }
        printf("Case %d: %d\n",t,mu);
    }
    return 0;
}
