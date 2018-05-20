class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1; i<=n; i++){
            s += to_string(i);
        }
        int c = 1;
        while(c != k){
            c++;
            next_permutation(s.begin(), s.end());
        }
        return s;
    }
};

class BetterSolution {
    public String getPermutation(int n, int k) {
        int x =n;
        int[] nums = {1,2,3,4,5,6,7,8,9};
        //Calculating factorial
        int factorial = 1;
        for(int i=2; i<=n; i++) factorial*=i;
        String ans = "";
        //Frequency of nth digit from right will be (n-1)!. So the final number at that position will be the remainder of k/(n-1)!
        while(n>0) {
            factorial/=n;
            int q = k/factorial;
            int rem = k%factorial;
            if(rem==0 && q!=0) q--; //Boundary condition
            //if k=0, all the following string chars would be the non-negative numbers in nums array in desc order.
            if(k==0) {
                for(int j=x-1; j>=0; j--)
                    if(nums[j]>0) ans+=Integer.toString(nums[j]);
                return ans;
            }
            //Finding the right number at the current string position
            for(int j=0; j<x; j++) {
                if(nums[j]<0) q++;
                if(j==q) {ans+=Integer.toString(nums[j]); nums[j]=nums[j]*(-1); break;}                             
            }
            k=rem;
            n--;
        }
        return ans;  
    }
}