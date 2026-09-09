// 我思う、故に我在り
#include <bits/stdc++.h>
#include "convolution/fft.hpp"
using namespace std;
int n;
vector<int>path;
void dfs1(int u, int par, vector<int>& d, const vector<vector<int>>& T)
{
        for(int v:T[u])
        {
                if(v==par)continue;
                d[v]=d[u]+1;
                dfs1(v,u,d,T);
        }
}
bool dfs2(int u, int par, const vector<vector<int>>& T, int targ)
{
        path.push_back(u);
        if(u==targ)return true;
        for(int v:T[u])
        {
                if(v==par)continue;
                if(dfs2(v,u,T,targ))return true;
        }
        path.pop_back();
        return false;
}
int dfs3(int u, int par, const int diam, int d, const vector<vector<int>>&T, vector<int>& poly)
{
        int cnt=0,ret=d;
        for(int v:T[u])
        {
                if(v==par)continue;
                int res=dfs3(v,u,diam,d+1,T,poly);
                ret=max(ret,res);
                cnt+=(bool)(res==diam);
        }
        if(cnt>1)poly[d]=1;
        return ret;
}
void solve()
{
        path.clear();
        cin>>n;
        vector<vector<int>>T(n+1);
        for(int i=0;i<n-1;i++)
        {
                int u,v;cin>>u>>v;
                T[u].push_back(v);
                T[v].push_back(u);
        }
        vector<int>d(n+1,0);
        dfs1(1,-1,d,T);
        int mx=0,at=0;
        for(int i=1;i<=n;i++)if(d[i]>mx)
        {
                mx=d[i];
                at=i;
        }
        d.assign(n+1,0);
        dfs1(at,-1,d,T);
        int root=at;
        mx=0,at=0;
        for(int i=1;i<=n;i++)if(d[i]>mx)
        {
                mx=d[i];
                at=i;
        }
        dfs2(root,-1,T,at);
        assert(!path.empty()&&(int)path.size()%2==0);
        int X=path[mx/2],Y=path[mx/2+1];
        d.assign(n+1,0);
        vector<int>dX(n+1,0),dY(n+1,0);
        dfs1(X,Y,dX,T);
        dfs1(Y,X,dY,T);
        int diaX=*max_element(dX.begin()+1,dX.end()),diaY=*max_element(dY.begin()+1,dY.end());
        vector<int>A(diaX+1,0),B(diaY+1,0);
        dfs3(X,Y,diaX,0,T,A);
        dfs3(Y,X,diaY,0,T,B);
        A[diaX]=1,B[diaY]=1;
        vector<int64_t>C=FFT::convolution_int(A,B);
        vector<int64_t>ans;
        for(int i=0;i<(int)C.size();i++)if(C[i])ans.push_back(i+1);
        cout<<(int)ans.size()<<" ";
        for(int64_t x:ans)cout<<x<<" ";
        cout<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
