#include<bits/stdc++.h>
typedef long long int lli;
lli Max = 10000000001;
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q,k,l,r;
        cin>>n>>q>>k>>l>>r;
        lli a[10001*2];
        memset(a,Max,sizeof(a));
        l +=10000;
        r +=10000;
        k +=10000;
        for (int i = 0; i < n; i++)
        {
            int c;
            lli p;
            cin>>c>>p;
            a[c+10000]=p;   
        }
        if(l<=k&&k<=r)
        {
            lli mini = Max;
            for (int i = l; i < r+1; i++)
            {
                mini = min(mini,a[i]);
            }
            int k = l-1,m = r+1;
            for (int i = 1; i <= q; i++)
            {
                mini = min(mini,a[k]);
                if(k>0) 
                    k--;
                mini = min(mini,a[m]);
                if(m<100001*2-1)
                    m++;

            if(mini==10000000001)
                cout<<"-1"<<" ";
            else
                cout<<mini<<" ";
            }            
        }
        else if(l>k)
        {
            for (int i = 1; i <= q; i++)
            {
                lli mini = Max;
                for (int j = l+i; j <= r+i; j++)
                {
                    mini = min(mini,a[j]);
                }
                if(mini==10000000001)
                    cout<<"-1"<<" ";
                else
                {
                    cout<<mini<<" ";
                }                    
            }       
        }
        else
        {
            for (int i = 1; i <= q; i++)
            {
                lli mini = Max;
                for (int j = r-i; j >= l-i; j--)
                {
                    mini = min(mini,a[j]);
                }
                if(mini==10000000001)
                    cout<<"-1"<<" ";
                else
                {
                    cout<<mini<<" ";
                }                    
            }
        }
        cout<<endl;
    }
}