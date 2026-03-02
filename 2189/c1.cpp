#include <bits/stdc++.h>
using namespace std;
int n;
bool used[1<<20];
void solve() 
{
        cin>>n;
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
        for(int x:p)
        {
                cout<<x<<" ";
        }
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
