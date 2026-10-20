#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,x=0,y=0,t=0;
vector<int>a;
void solve()
{
        cin>>n;
        a.resize(n);
        for(int i=0;i<n;i++)
                cin>>a[i];
        while(!a.empty())
        {
                if(a[0]>a.back())
                {
                        if(t==0)
                        {
                                x+=a[0];
                        }
                        else
                        {
                                y+=a[0];
                        }
                        a.erase(a.begin());
                }
                else
                {
                        if(t==0)
                                x+=a.back();
                        else
                                y+=a.back();
                        a.pop_back();
                }
                t^=1;
        }
        cout<<x<<" "<<y<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
