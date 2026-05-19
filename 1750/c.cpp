#include <bits/stdc++.h>
using namespace std;
int n;
string a,b;
void solve()
{
        cin>>n>>a>>b;
        bool ok=true;
        bool same=a==b;
        for(int i=0;i<n;i++)
        {
                ok&=(((a[i]-'0')^(b[i]-'0'))==1);
        }
        if(same)
        {
                int idx=-1;
                for(int i=0;i<n;i++)
                {
                        if(a[i]=='0')
                        {
                                idx=i;
                        }
                }
                if(idx!=-1)
                {
                        for(int i=0;i<n;i++)
                        {
                                if(i!=idx)
                                {
                                        b[i]=(b[i]=='0'?'1':'0');
                                }
                        }
                }
        }
        if(ok||same)
        {
                int cnt=0;
                vector<int>z,o;
                for(int i=0;i<n;i++)
                {
                        if(a[i]=='0')
                        {
                                cnt++;
                                z.push_back(i);
                        }
                        else
                        {
                                o.push_back(i);
                        }
                }
                if(!z.empty())
                {
                        if((int)z.size()%2==0)
                        {
                                cout<<"YES\n"<<cnt+1<<'\n';
                                for(int x:z)
                                {
                                        cout<<x+1<<" "<<x+1<<'\n';
                                }
                                cout<<1<<" "<<n<<'\n';
                        }
                        else
                        {
                                cout<<"YES\n"<<(int)o.size()+1<<'\n';
                                cout<<"1 "<<n<<'\n';
                                for(int x:o)
                                {
                                        cout<<x+1<<" "<<x+1<<'\n';
                                }
                        }
                }
                else
                {
                        cout<<"YES\n2\n";
                        cout<<"1 1\n";
                        cout<<"2 "<<n<<'\n';
                }
        }
        else
        {
                cout<<"NO\n";
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
