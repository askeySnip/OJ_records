class Solution {
public:
    // // unordered_map<string, int> ump;
    vector<vector<int> > vv;
    vector<int> vist;
    bool check(string& a, string& b){
        if(a.length() != b.length()) return false;
        int c=0;
        for(int i=0; i<a.length(); i++){
            if(a[i] == b[i]) continue;
            if(c > 1) return false;
            c++;
        }
        return true;
    }
    void dfs(int i){
        vist[i] = 1;
        for(int j=0; j<vv[i].size(); j++){
            if(!vist[vv[i][j]]) {
                dfs(vv[i][j]);
            }
        }
    }
    int numSimilarGroups(vector<string>& A) {
        // for(int i=0; i<A.size(); i++){
        //     ump[A[i]] = i;
        // }
        vv.resize(A.size());
        vist.assign(A.size(), 0);
        for(int i=0; i<A.size(); i++){
            for(int j=i+1; j<A.size(); j++){
                if(check(A[i], A[j])){
                    vv[i].push_back(j);
                    vv[j].push_back(i);
                }
            }
        }
        int id = 0;
        for(int i=0; i<A.size(); i++){
            if(vist[i]) continue;
            // cout << id << endl;
            dfs(i);
            id++;
        }
        return id;
    }
};