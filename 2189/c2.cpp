#include <bits/stdc++.h>
using namespace std;
int n;
bool used[1<<20];
bool ok(const vector<int>&p)
{
        int n=(int)p.size();
        bool ret=true;
        for(int i=0;i<n-1;i++)
        {
                bool f=false;
                for(int j=i;j<n;j++)
                {
                        f|=(((i+1)^p[j])==p[i]);
                }
                ret&=f;
        }
        return ret;
}
void solve() 
{
        cin>>n;   
        if((n&(n-1))==0)
        {
                cout<<"-1\n";
                return;
        }
        for(int i=1;i<=n;i++)used[i]=false;
        vector<int>p;
        p.push_back(1);
        used[1]=true;
        for(int i=n-1;i>=2;i--)
        {
                p.push_back(i^1);
                assert(1<=(i^1)&&(i^1)<=n);
                used[i^1]=true;
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
                if(!used[i]){
                        p.push_back(i);
                        cnt++;
                }
        }
        assert(cnt==1);
        reverse(p.begin(),p.end());
        if(!(n&1))
        {
                int b=n&-n;
                swap(p[0],p[b-1]);
        }
        for(int x:p)
        {
                cout<<x<<" ";
        }
        cout<<'\n';
        // assert(ok(p));
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
/*
 * 6 -> 3 6 2 5 4 1
 *
 */
