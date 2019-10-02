#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d%d",&n,&q);
        char s[n];
        scanf("%s",s);
        int a[n-1]= {0};
        for (int i = 0; i < n-2; i++)
        {
            if(s[i]==s[i+1]||s[i]==s[i+2]||s[i+1]==s[i+2])
                a[i+1]=1;
        }
        for (int i = 2; i < n-1; i++)
        {
            a[i]+=a[i-1];
        }
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            if(r-l<2)
                printf("NO\n");
            else if(a[r-2]-a[l-1]>0)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}