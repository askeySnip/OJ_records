class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        while(i < bits.size()-1){
            if(bits[i]) i+=2;
            else i++;
        }
        return i == (bits.size()-1);
    }
};