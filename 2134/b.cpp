#include <bits/stdc++.h>
using namespace std;
int n;
int64_t k,a[1<<17];
void solve() 
{
        cin>>n>>k; 
        for(int i=0;i<n;i++)cin>>a[i];
        if(k&1)
        {
                for(int i=0;i<n;i++)
                {
                        if(a[i]&1)a[i]+=k;
                        cout<<a[i]<<" \n"[i==n-1];
                }
        }
        else
        {
                // target = congruent mod n + 1
                for(int i=0;i<n;i++)
                {
                        int mv=a[i]%(k+1);
                        if(a[i]%(k+1))
                        {
                                a[i]+=mv*(k);
                        }
                        cout<<a[i]<<" \n"[i==n-1];
                }
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
