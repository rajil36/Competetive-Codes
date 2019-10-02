#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<lli>v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            if(x%2!=0){
                v.push_back(x);
                v.push_back(2*x);
            }
            else
            {
                v.push_back(x);
                while(x%2==0){
                    x=x/2;
                    v.push_back(x);
                }
            }  
        }
        sort(v.begin(),v.end());
        lli ans = INT64_MAX;
        for (lli i = 0; i < v.size()-1; i++)
        {
            ans = min(ans,v[i+1]-v[i]);
        }
        cout<<ans<<endl;
        
    }
}