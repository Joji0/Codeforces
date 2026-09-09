#include <bits/stdc++.h>
using namespace std;
int n,a[1<<20];
void solve()
{
        cin>>n;
        set<int>st;
        for(int i=0;i<n;i++)
        {
                cin>>a[i];
                st.insert(a[i]);
        }
        if(st.size()==1||n==1)
        {
                cout<<"1\n";
                for(int i=0;i<n;i++)cout<<1<<" \n"[i==n-1];
                return;
        }
        if(n&1)
        {
                if(a[0]!=a[n-1]&&a[n-2]!=a[n-1])
                {
                        cout<<"3\n";
                        for(int i=0;i<n-1;i++)
                        {
                                if(i&1)cout<<"1 ";
                                else cout<<"2 ";
                        }
                        cout<<"3\n";
                }
                else
                {
                        cout<<"2\n";
                        for(int i=0;i<n;i++)
                        {
                                if(i&1)cout<<"1 ";
                                else cout<<"2 ";
                        }
                        cout<<'\n';
                }
        }
        else
        {
                cout<<"2\n";
                for(int i=0;i<n;i++)
                {
                        if(i&1)cout<<"1 ";
                        else cout<<"2 ";
                }
                cout<<'\n';
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
