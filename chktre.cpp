#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli dp[100000+10] = {0}, mod = 1000000007;
vector<long int> vertices[100010];

lli dfs(int n, bool visited[]){
    dp[n] = 1;
    visited[n] = true;
    // cout<<n<<" ";
    for (long int i = 0; i < vertices[n].size(); i++)
    {
        if(visited[vertices[n][i]]== false){
            dp[n]=(dp[n]%mod + (dp[n]%mod*dfs(vertices[n][i], visited)%mod)%mod)%mod;
        }
    }
    // cout<<n<<"-> "<<dp[n]<<" ";
    return dp[n]%mod;    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long int n;
        cin>>n;
        bool visited[100010]= {false};
        for (long int i = 1; i <= n; i++)
        {
            vertices[i].clear();
        }
        
        for (int i = 0; i < n-1; i++)
        {
            long int u,v;
            cin>>u>>v;
            vertices[u].push_back(v);
            vertices[v].push_back(u);
        }
        lli ans = dfs(1,visited);
        ans=0;
        for (int i = 1; i < n+1; i++)
        {
            ans= (ans%mod + dp[i]%mod)%mod;
        }
        if(n==1)
            ans=1;
        cout<<ans%mod<<endl;
    }
    return 0;
}