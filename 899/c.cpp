#include <bits/stdc++.h>
using namespace std;
int64_t n;
void solve() 
{
        cin>>n;
        int64_t sum=n*(n+1)/2;
        if(sum&1)
        {
                cout<<"1\n";
        }
        else
        {
                cout<<"0\n";
        }
        sum/=2;
        vector<int>ans;
        int ptr=n;
        while(sum>0&&ptr>=0)
        {
                if(ptr<=sum)
                {
                        sum-=ptr;
                        ans.push_back(ptr);
                }
                ptr--;
        }
        cout<<(int)ans.size()<<" ";
        for(int64_t x:ans)
        {
                cout<<x<<" ";
        }
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
