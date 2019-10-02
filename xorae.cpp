#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;
const int N = 60;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        lli x;
        cin>>n>>x;
        lli num =x;
        lli one =1;
        bitset<60> b1(x);
        vector<int>v;
        if( n <= b1.count() ){
         for(lli i = 0;i<=60 && (v.size() < n-1);i++)
             if(x & (one<<i)) {num -= (one<<i) ; v.push_back((one<<i));}
       
         v.push_back(num);    
        }
        else if(x==1){
            if(n%2==0){
                v.push_back(2);
                v.push_back(3);
            }
             for(int i=1;i<=n-2;i++) v.push_back(1);
        }
        else{
            for (lli i = N; i >0 ; i--)
            {
                if((x&(one<<i))>0)
                    v.push_back(one<<i);
            }
            int rem = n-v.size();
            if(x%2==0 and rem%2==1)
                v[0]++;
            else if(x%2==1 and rem%2==0)
                v[0]++;
            for (int i = 0; i < rem; i++)
            {
                v.push_back(1);
            }
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}