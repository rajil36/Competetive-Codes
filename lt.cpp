#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int S[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        S[i] = s[i]-'0';
    }
    int q;
    cin>>q;
    while (q--)
    {
        int dp[s.length()][500]={0};
        int m,l;
        cin>>m>>l;
        for (int i = 0; i < s.length(); i++)
        {
            dp[i][S[i]%m]=1;
        }        
        for (int i = 1; i < s.length(); i++)
        {
            for (int j = 0; j < 500; j++)
            {
                dp[i][((j*(10%m))%m + S[i]%m)%m]+=dp[i-1][j];
            }
            
        }
        long int ans=0;
        for (int i = 0; i < s.length();i++)
        {
            ans+=dp[i][l];
        }
        cout<<ans<<endl;
    }
return 0; 
}