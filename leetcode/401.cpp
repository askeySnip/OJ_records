class Solution {
public:
    string gen(int n){
        string s;
        int min = n%(1 << 6);
        if(min >= 60) return s;
        int h = n >> 6;
        if(h > 11) return s;
        s += to_string(h) + ":";
        if(min < 10) s += "0"+to_string(min);
        else s += to_string(min);
        // cout << n << " " << s << endl;
        return s;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        int s = (1 << 10);
        for(int i=0; i<s; i++){
            int c = 0;
            for(int j=0; j<10; j++){
                if(i&(1<<j)) c++;
            }
            if(c != num) continue;
            string s = gen(i);
            if(s != "") ret.push_back(s);
        }
        return ret;
    }
};