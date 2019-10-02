#include<bits/stdc++.h>
typedef long long int lli; 
using namespace std;
const int N = 5000000;
bool prime[N+1];
vector<int> divi(5000000+1);

int main(){
    int t;
    cin>>t;
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    for (int i = 2; i*i <= N; i++){
        if(prime[i]){
            for (int j = i*2; j <= N; j+=i){
                prime[j]=false;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <=N ; j+=i)
        {
            divi[j]++;
        }
        
    }
    vector<int> a(N+1);
    for (int i = 1; i <= N; i++)
    {
        if(prime[divi[i]])
            a[i]=1;
        else
            a[i]=0;
    }
    for (int i = 1; i <= N; i++)
    {
        a[i]+=a[i-1];
    }  
    while(t--){
        int l,r;
        cin>>l>>r;
        cout<<a[r]-a[l-1]<<endl;;
    }
}