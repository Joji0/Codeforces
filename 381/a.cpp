#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,t,x,y;
vector<int>a;
void solve()
{
        cin>>n;
        a.resize(n);
        for(int i=0;i<n;i++)
                cin>>a[i];
        while(!a.empty())
        {
                if(t)
                {
                        if(a[0]>a.back())
                                y+=a[0],
                                a.erase(a.begin());
                        else
                                y+=a.back(),
                                a.pop_back();
                }
                else
                {
                        if(a[0]>a.back())
                                x+=a[0],
                                a.erase(a.begin());
                        else
                                x+=a.back(),
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
