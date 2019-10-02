#include<bits/stdc++.h>
using namespace std;

int dp[5001][5001] = {0};

int main(){
    for (int i = 0; i < 5001; i++)
    {
        dp[i][1] = i;
    }
    for (int i = 1; i <= 14; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i < 5001; i++)
    {
        for (int j = 2; j <= 14; j++)
        {
            dp[i][j] = INT32_MAX;
            for (int k = 1; k <= i; k++)
            {
                int a = dp[k-1][j-1];
                if(a==0 && k-1!=0)
                    a = 1 + log2(k-1);
                int b = dp[i-k][j];
                if(b==0 && i-k!=0)
                    b = 1 + log2(i-k);
                int c = 1+ max(a,b);
                dp[i][j] = min(c,dp[i][j]);   
            }
            if(dp[i][j]==(int)(1 + log2(i)))
                break;
        }    
    }
    int t;
    cin>>t;
    while(t--){
        int n,h;
        cin>>n>>h;
        int ans;

        if(n>14)
            ans =1 + log2(h);
        else{
            ans = dp[h][n];
            if(ans == 0)
                ans =1 + log2(h);
        }
        cout<<ans<<endl;   
    }
return 0;        
}