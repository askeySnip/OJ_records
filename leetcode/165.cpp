class Solution {
public:
    // string::size_type next1 = 0, next2 = 0;
    int get(string& s, string::size_type& next){
        if(next == string::npos) return 0;
        string::size_type t = s.find('.', next);
        int ret = stoi(s.substr(next, t-next));
        next = (t == string::npos)? string::npos:t+1;
        return ret;
    }
    int compareVersion(string version1, string version2) {
        int v1=0, v2 = 0;
        string::size_type next1 = 0, next2 = 0;
        while(v1 == v2){
            v1 = get(version1, next1);
            v2 = get(version2, next2);
            if(next1 == string::npos && next2 == string::npos) break;
            // cout << v1 << " " << v2 << " " << next1 << " " << next2 << endl;
        }
        if(v1 < v2) return -1;
        else if(v1 == v2) return 0;
        else return 1;
    }
};