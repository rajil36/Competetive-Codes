#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli mod = 1000000007;

lli solve (int n,int k, int mask){
    if(n==1){
        if(mask==0)
            return k;
        else
            return 25;
    }
    if(mask==0){
        return (k*solve(n-1,k,1))%mod;
    }
    else
    {
        return (((26-k)*solve(n-1,k,0))%mod + ((k-1)*solve(n-1,k-1,0))%mod)%mod;
    }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        char c[k];
        for (int i = 0; i < k; i++)
        {
            cin>>c[i];
        }
        lli ans = solve(n,k,0);
        cout<<ans<<endl;
    }
}