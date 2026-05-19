#include <bits/stdc++.h>
using namespace std;
int n;
int64_t prv;
bool used[1<<20];
int64_t cuspop(int64_t x)
{
        return x&~prv;
}
void solve() 
{
        cin>>n;
        vector<array<int64_t,2>>a(n);
        for(int i=0;i<n;i++)cin>>a[i][0],a[i][1]=i,used[i]=false;
        prv=0;
        vector<int64_t>ans;
        for(int i=32;i>=0;i--)
        {
                if(a.empty())break;
                int64_t bst=-1,v=0;
                for(int i=0;i<n;i++)
                {
                        if(cuspop(a[i][0])>=v&&!used[a[i][1]])
                        {
                                bst=i;
                                v=cuspop(a[i][0]);
                        }
                }
                if(bst==-1)break;
                used[bst]=true;
                ans.push_back(a[bst][0]);
                prv|=ans.back();
        }
        for(int i=0;i<n;i++)if(!used[i])ans.push_back(a[i][0]);
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
