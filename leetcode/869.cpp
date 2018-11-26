class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string s;
        while(N) {
            s = to_string(N%10) + s;
            N/=10;
        }
        sort(s.begin(), s.end());
        do {
            if(s[0] != '0') {
                int t = stoi(s);
                if(t == (t&(-t))) return true;
            }
        }while(next_permutation(s.begin(), s.end()));
        return false;
    }
};



class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(N==1)
            return true;
        int x=log2(N);
        if(pow(2,x)==N)
            return true;
        vector<int>d(10,0);
        int temp=N,count=0;
        while(temp>0)
        {
            d[temp%10]++;
            temp/=10;
            count++;
        }
        bool flag=false;
        for(int i=1;i<log2(N)+3;i++)
        {
            int x=pow(2,i);
            //cout<<x<<endl;
            vector<int>v(10,0);
            int tmp=x,cnt=0;
            bool y=true;
            while(tmp>0)
            {
                v[tmp%10]++;
                tmp/=10;
                cnt++;
            }
            // for(int j=0;j<10;j++)
            // {
            //     cout<<d[j]<<":"<<v[j]<<endl;
            // }
            if(cnt==count)
            {
                for(int j=0;j<10;j++)
                {
                    if(v[j]!=d[j])
                    {
                        y=false;
                        break;
                    }
                }
                
            }
            else
            {
                y=false;
            }
            flag=flag||y;
        }
        if(flag)
            return true;
        return false;
    }
};