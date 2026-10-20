#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
void solve()
{
        cin>>n>>m;
        vector<int>a;
        if(m>=n)
        {
                if(n==2)
                        if(m&1)
                                cout<<"2 1\n";
                        else
                                cout<<"1 2\n";
                else
                        for(int i=n;i>=1;i--)
                                cout<<i<<" \n"[i==1];
                return;
        }
        for(int i=n;i>n-m;i--)
                a.push_back(i);
        for(int i=1;i<=n-m;i++)
                a.push_back(i);
        for(auto&x:a)
                cout<<x<<" ";
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
