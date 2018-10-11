class Solution {
public:
    void deal(vector<int>& b) {
        int t = 0;
        vector<int> a;
        for(int i=0; i<b.size(); i++) {
            int v = t*10 + b[i];
            if(v < 2) {t = v; if(a.size()) a.push_back(0);}
            else {
                t = v%2;
                a.push_back(v/2);
            }
        }
        b = a;
    }
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        if(b.size() == 1 && b[0] == 1) return a%1337;
        if(b.back()%2 == 1) {
            b[b.size()-1]--;
            return ((a%1337)*(superPow(a, b)%1337))%1337;
        }else {
            deal(b);
            return superPow(((a%1337)*(a%1337))%1337, b)%1337;
        }
    }
};

// better solvtion
class Solution {
    const int base = 1337;
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
    }
};



class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int x = 1;
        a %= 1337;
        for (int i = 0; i < b.size(); ++i) {
            int t2 = x * x % 1337;
            int t4 = t2 * t2 % 1337;
            x = t4 * t4 % 1337 * t2 % 1337;
            for (int j = 0; j < b[i]; ++j) {
                x *= a;
                x = x % 1337;
            }
        }
        x = x % 1337;
        return x;
    }
};