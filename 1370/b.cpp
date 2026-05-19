#include <bits/stdc++.h>
using namespace std;
int n,a[1<<20];
void solve() 
{
        cin>>n; 
        vector<int>odd,even;
        for(int i=0;i<2*n;i++)
        {
                cin>>a[i];
                if(a[i]&1)odd.push_back(i+1);
                else even.push_back(i+1);
        }
        int o=(int)odd.size(),e=(int)even.size();
        if(o&1)
        {
                odd.pop_back(); 
                even.pop_back();
        }
        else 
        {
                if(!odd.empty())
                {
                        odd.pop_back();
                        odd.pop_back();
                }
                else 
                {
                        even.pop_back();
                        even.pop_back();
                }
        }
        for(int i=0;i<(int)odd.size();i+=2)
        {
                cout<<odd[i]<<" "<<odd[i+1]<<'\n';
        }
        for(int i=0;i<(int)even.size();i+=2)
        {
                cout<<even[i]<<" "<<even[i+1]<<'\n';
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
