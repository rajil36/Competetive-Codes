#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n,k;
    cin>>n>>k;
    unordered_map<int,int> M;
    int count=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(M.find(x)==M.end()){
            M[x]=1;
            count++;
        }
        else
            M[x]++;
    }
    if(count>k)
        cout<<"NO"<<endl;
    else
    {
        pair<int,int> a[M.size()];
        unordered_map<int,int>::iterator it = M.begin();
        for (int i=0; it !=M.end(); it++,++i)
        {
            a[i].first = it->second;
            a[i].second = it->first;
        }
        sort(a,a+M.size(),greater<pair<int,int>>());
        int A[n];
        bool flag = true;
        int j =0;
        int c =0;
        j=0;
        for (int i = 0; i < n; i++)
        {
            if(a[j].first>0)
            {
                A[i] = a[j].second;
                a[j].first--;
                ++j;
                ++c;
                if(j==M.size())
                    j=0;
                if(c==k){
                    c=0;
                    j=0;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(!flag)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for (int i = 0; i < n; i++)
            {
                cout<<A[i]<<" ";
            }
            cout<<endl;
        }
        
    }
       
}
return 0;
}