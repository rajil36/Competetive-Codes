#include <bits/stdc++.h>
using namespace std;

int main(){
 int t;
 cin>>t;
 while (t--)
 {
    string s;
    cin>>s;
    int n = s.size();
    int c[n+1] ;
    c[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        c[i] = c[i-1] + s[i-1] - '0';
    }
    long int res = 0;
    for (int i = 0;  i <= n; i++)
    {
        int x = 1;
        while(true){
            int j = i + x*x + x;
            if(j>n)
                break;
            if(c[j]-c[i]== x)
                res++;
            x++;    
        }
    }
    
    cout<<res<<endl;
 }
return 0;    
}