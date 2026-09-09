// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
        cin>>n;
        if(n<3)cout<<"-1\n";
        else if(n==3)cout<<"210\n";
        else
        {
                string s="1"+string(n-4,'0');
                int64_t pw=1;
                for(int i=0;i<n-1;i++)
                {
                        pw*=10;
                        if(pw>210)pw%=210;
                }
                pw=210-pw;
                string spw=to_string(pw);
                s+=string(3-(int)spw.size(),'0')+spw;
                cout<<s<<'\n';
        }

}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
