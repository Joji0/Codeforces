#include <bits/stdc++.h>
using namespace std;
int n,p[1<<10],q[1<<10];
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>p[i];
        for(int i=0;i<n;i++)q[i]=p[i];
        vector<int>bad;
        int mx=p[0];
        for(int i=0;i<n;i++)
        {
                mx=max(mx,p[i]);
                if(i+1==mx)
                {
                        bad.push_back(i);
                }
        }
        if((int)bad.size()>=1)
        {
                swap(q[bad[0]],q[n-1]);
        }
        for(int i=0;i<n;i++)cout<<q[i]<<" \n"[i==n-1];
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
