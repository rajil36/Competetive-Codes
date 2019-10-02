#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int dp[n+1][k+2][k+2][k+2][k+2] = {0};
        cout<<"here"<<endl;
        int chef1=0,che1=0,ch1=0,c1=0;
        for (int i = 0; i < n; i++)
        {
            for(int chef=0;chef<=k;++chef)
                for(int che=0;che<=k;++che)
                    for(int ch= 0;ch<=k;++ch)
                        for(int c = 0; c<=k;++ch)
                        {
                            if(s[i]=='c'){
                                dp[i+1][chef][che][ch][c] = max(dp[i+1][chef][che][ch][c],dp[i][chef][che][ch][c]) + max(dp[i+1][chef][che][ch][min(c+1,k+1)],dp[i][chef][che][ch][c]);
                                c1=min(k+1,c1+1); 
                            } 
                            else if(s[i]=='h'){
                                dp[i+1][chef][che][ch][c] = max(dp[i+1][chef][che][ch][c],dp[i][chef][che][ch][c]) + max(dp[i+1][chef][che][min(ch+c,k+1)][c],dp[i][chef][che][ch][c]);
                                ch1=min(k+1,c1+ch1);
                            }
                            else if(s[i]=='e'){
                                dp[i+1][chef][che][ch][c] = max(dp[i+1][chef][che][ch][c],dp[i][chef][che][ch][c]) + max(dp[i+1][chef][min(che+ch,k+1)][ch][c],dp[i][chef][che][ch][c]);
                                che1=min(k+1,ch1+che1);
                            }
                            else if(s[i]=='f'){
                                dp[i+1][chef][che][ch][c] = max(dp[i+1][chef][che][ch][c],dp[i][chef][che][ch][c]) + max(dp[i+1][min(chef+che,k+1)][che][ch][c],dp[i][chef][che][ch][c]);
                                chef1= min(k+1,chef1+che1);
                            }
                            cout<<dp[i+1][chef][che][ch][c];
                        }
        }
        cout<<endl<<chef1<<" "<<che1<<" "<<ch1<<" "<<c1<<endl;
        if(chef1<k)
            cout<<"-1"<<endl;
        else{
            int ans =0 ;
            for (int i = 1; i <=n; i++)
            {
                for (int j = 1; j <= k+1 ; j++)
                {
                    for (int l = 1; l <= k+1 ; l++)
                    {
                        for (int m = 1; m <= k+1 ; m++)
                        {
                            ans = max(ans,dp[i][k][j][l][m]) ;  
                        }
                    }
                }
                
            }
            ans = n - ans;
            cout<<ans<<endl;
        }
    }
    return 0;
}