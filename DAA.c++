// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    bool visit(int i,int cnt,int N,vector<int> m[],vector<bool> &vis){
        if(cnt==N )return true;
        
        vis[i] = true;
        
        for(auto j:m[i]){
            if(vis[j]==false && visit(j,cnt+1,N,m,vis)) return true;
        }
        vis[i] = false;
        
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<bool> vis(N+1,false);
        
        vector<int> m[N+1];
        
        for(int i=0;i<Edges.size();i++){
            m[Edges[i][0]].push_back(Edges[i][1]);
            m[Edges[i][1]].push_back(Edges[i][0]);
        }
        
        for(int i=1;i<=N;i++){
            if(visit(i,1,N,m,vis)) return true;
        }
        
        return false;
    }
};
