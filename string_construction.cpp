#include<bits/stdc++.h>
using namespace std;

long long power(long long a,long long b,long long c)
{   if(b==0)
    return 1;
    long long p= power(a,b/2,c)%c;
    if((b&1)==0)
    return (p*p)%c;
    return ((p*p)%c*(a%c))%c;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        char a[k];
        for(int i=0;i<k;i++)
        cin>>a[i];
        long long ans=0,a1=25,mod=1000000007;
        if(n%2)
        {
            ans=((k%mod)*power(25+24*(k-1),(n-1)/2,mod)%mod)%mod;
        }
        else
        {
            ans=((k%mod)*(a1%mod)*power(25+24*(k-1),(n-2)/2,mod)%mod)%mod;
        }
      cout<<ans<<endl;  
    }
  return 0;  
}