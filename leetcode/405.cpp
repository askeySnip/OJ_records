class Solution {
public:
    string toHex(int num) {
        int t = 15;
        string ans;
        char mp[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        for(int i=0; i<8; i++){
            int id = t & num;
            ans = mp[id] + ans;
            num = num >> 4;
            if(num == 0) break;
        }
        return ans;
    }
};