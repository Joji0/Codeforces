#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)
        {
                int x;cin>>x;
        }
        if(n==1)cout<<"1\n";
        else {for(int i=0;i<n;i++)cout<<"2 ";
        cout<<'\n';}
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
