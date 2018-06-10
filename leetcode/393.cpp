class Solution {
public:
    int count1(int& n){
        int ret = 0;
        for(int i=7; i>=0; i--){
            if(n&(1<<i)) ret++;
            else break;
        }
        return ret;
    }
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int type = 1;
        for(int i=0; i<n; i++){
            int& t = data[i];
            if(type == 1 && !(t&(1<<7))) continue;
            if(type != 1){
                if(t >= (1<<7) && t < (1<<7 + 1<<6)) type--;
                else return false;
            }else{
                type = count1(t);
                if(type > 4 || type == 1) return false;
            }
            // cout << t << " " << type << endl;
        }
        if(type == 1)return true;
        else return false;
    }
};