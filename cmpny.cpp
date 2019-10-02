#include<bits/stdc++.h>
using namespace std;
set<int> market;

int solve(unordered_map<int,set<int>>&map){
    int ans =1000;
    for(auto it:market){
       int count =0;
       vector<int>cmp;
       for(auto i:map){
           if(i.second.find(it)!=i.second.end())
            {
                count++;
                cmp.push_back(i.first);
            }
       }
       market.erase(it);
        if(count==3){
            // ans+=1;
            for(int i=0;i<cmp.size()-1;++i)
            {
                for(int j=i+1;j<cmp.size();j++){
                    unordered_map<int,set<int>>temp=map;
                    for(auto itr:temp[cmp[j]]){
                        temp[cmp[i]].insert(itr);
                    }
                    temp.erase(cmp[j]);

                    ans = min(ans,1+solve(temp));
                    if(ans<=1)
                        goto label;
                }
            }
        }
        if(count==4){
            for(int i=0;i<cmp.size()-2;++i)
            {
                for(int j=i+1;j<cmp.size()-1;j++){
                    for(int k = j+1;k<cmp.size();k++){
                    unordered_map<int,set<int>>temp=map;
                    for(auto itr:temp[cmp[j]]){
                        temp[cmp[i]].insert(itr);
                    }
                    temp.erase(cmp[j]);
                    for(auto itr:temp[cmp[k]]){
                        temp[cmp[i]].insert(itr);
                    }
                    temp.erase(cmp[k]);

                    ans = min(ans,2+solve(temp));
                    if(ans<=2)
                        goto label;
                    }
                }
            }
        }
        if(count==5){
            ans =3;
            break;
        }
    }
    if(ans==1000)
        ans=0;
label:    
return ans;
}

int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,set<int>>map;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           int x;
           cin>>x;
           market.insert(x);
           map[i].insert(x); 
        }
    }
    int ans = solve(map);
    cout<<ans<<endl;  
}