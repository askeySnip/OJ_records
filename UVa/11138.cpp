#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

#define MAX_BOLTS 500
#define MAX_NUTS  500
/*~global~copy~of the input data */
int nuts,bolts;
int fits[MAX_BOLTS][MAX_NUTS];
void read_input_data(void){
  int n,b;
  scanf("%d%d",&bolts,&nuts);
  for(b=0;b<bolts;b++){
    for(n=0;n<nuts;n++){
      scanf("%d",&fits[b][n]);
    }
  }
}
/* data used to match nuts with bolts */
int nut_used[MAX_NUTS];
vi match;
int bestmatched;
void init_match(void){
  int n;
  bestmatched=0;
  for(n=0;n<nuts;n++) nut_used[n]=0;
}

int Aug(int l) {
  if(nut_used[l]) return 0;
  nut_used[l] = 1;
  for(int r=0; r<bolts; r++) {
    if(fits[r][l] == 0) continue;
    if(match[r] == -1 || Aug(match[r])) {
      match[r] = l; return 1;
    }
  }
  return 0;
}
void match_bolt(){
  // int n;
  // if(boltno==bolts){
  //   if(matched>bestmatched) bestmatched=matched;
  //   return;
  // }
  // /* don’t match this bolt */
  // match_bolt(boltno+1,matched);
  // /* match with all unused nuts that fit this bolt */
  // for(n=0;n<nuts;n++) if(!nut_used[n] && fits[boltno][n]){
  //     nut_used[n]=1;
  //     match_bolt(boltno+1,matched+1);
  //     nut_used[n]=0;
  //   }
  int MCBM = 0;
  match.assign(nuts+bolts, -1);
  for(int i=0; i<nuts; i++) {
    memset(nut_used, 0, sizeof nut_used);
    MCBM += Aug(i);
  }
  bestmatched = MCBM;
}
int main(){
  int cases,caseno;
  scanf("%d",&cases);
  for(caseno=1;caseno<=cases;caseno++){
    read_input_data();
    init_match();
    match_bolt();
    printf("Case %d: ",caseno);
    printf("a maximum of %d nuts and bolts ",bestmatched);
    printf("can be fitted together\n");
  }
  return 0;
}
