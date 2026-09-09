#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,x[N],ans[N];
array<int,2>t[N];
void solve()
{
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
                cin>>t[i][0]>>x[i];
                t[i][1]=i;
        }
        sort(t,t+n);
        int time=0;
        for(int i=0;i<n;i+=m)
        {
                vector<array<int,2>>curr;
                for(int j=i;j<min(i+m,n);j++)
                {
                        curr.push_back({x[t[j][1]],t[j][1]});
                        time=max(time,t[j][0]);
                }
                if(curr.empty())break;
                sort(curr.begin(),curr.end());
                int j=0,curpos=0;
                while(j<(int)curr.size())
                {
                        int targ=curr[j][0];
                        time+=targ-curpos;
                        curpos=targ;
                        int k=j;
                        while(k<(int)curr.size()&&curr[k][0]==targ)
                        {
                                ans[curr[k][1]]=time;
                                k++;
                        }
                        time+=1+(k-j)/2;
                        j=k;
                }
                time+=curpos;
        }
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
