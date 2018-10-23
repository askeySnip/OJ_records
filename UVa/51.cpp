class Solution {
private:
    vector<vector<string> > ans;
    vector<int> row, rd, lu, record;
    int gn;
    void backtrack(int u) {
        if(u == gn) {
            vector<string> vs;
            for(int i=0; i<gn; i++) {
                string s;
                for(int j=0; j<gn; j++) {
                    if(j == record[i]) s+='Q';
                    else s+='.';
                }
                vs.push_back(s);
            }
            ans.push_back(vs);
        }
        for(int i=0; i<gn; i++) {
            if(row[i] || rd[i+u] || lu[i-u+gn]) continue;
            row[i] = 1; rd[i+u] = 1; lu[i-u+gn] = 1;
            record.push_back(i);
            backtrack(u+1);
            record.pop_back();
            row[i] = 0; rd[i+u] = 0; lu[i-u+gn] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        row.assign(n, 0);
        rd.assign(n*2+3, 0);
        lu.assign(n*2+3, 0);
        record.clear();
        gn = n;
        backtrack(0);
        return ans;
    }
};