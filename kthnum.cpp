#include<bits/stdc++.h>
typedef long long int lli;
using namespace std;

lli gcd(lli a, lli b){
    if(a==0)
        return b;
    return gcd(b%a,a);
}

lli lcm(lli a, lli b){
    return (a*b)/gcd(a,b);
}

lli binary_search(lli start,lli end, lli a,lli b, lli c,lli ab,lli bc,lli ac, lli abc, lli k){
    if(start>end){
        return -1;
    }
    lli mid = (start + end)/2;
    lli rank = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
    if(rank==k){
        if(mid%a==0 or mid%b==0 or mid%c==0 )
            return mid;
        return binary_search(start,mid,a,b,c,ab,bc,ac,abc,k);
    }
    else if(rank<k)
        return binary_search(mid+1,end,a,b,c,ab,bc,ac,abc,k);
    else
        return binary_search(start,mid,a,b,c,ab,bc,ac,abc,k);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        lli a,b,c;
        lli k;
        cin>>a>>b>>c>>k;
        if(a>b){
            if(b>c){
                swap(a,c);
            }
            else
            {
                swap(a,c);
                swap(a,b);
            }
        }
        if(b>c){
            if(a>c){
                swap(a,c);
                swap(b,c);
            }
            else
                swap(b,c);
        }
        
        lli ab = lcm(a,b);
        lli bc = lcm(b,c);
        lli ac = lcm(a,c);
        lli abc = lcm(ab,c);
        cout<<binary_search(1,a*k,a,b,c,ab,bc,ac,abc,k)<<endl;
    }
}