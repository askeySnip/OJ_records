class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length() != B.length()) return false;
        A = A + A;
        if(A.find(B) != string::npos) return true;
        else return false;
    }
};