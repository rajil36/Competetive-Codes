#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli dp[100005],score[100005], ans;
vector<int> edge[100005];

void dfs(int n, int parent){
    dp[n] = score[n];
    for (int i = 0; i < edge[n].size(); i++)
    {
        if(edge[n][i]!= parent){
            dfs(edge[n][i],n);
            if(dp[edge[n][i]]>0)
                dp[n]+=dp[edge[n][i]];
        }
    }
    ans = max(ans,dp[n]);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%lld",&score[i]);

        for(int i=1;i<=n;++i)
            edge[i].clear();

        for (int i = 0; i < n-1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        ans = score[1];
        dfs(1,-1);

        printf("%lld\n",ans);
        
    }
    return 0;
}