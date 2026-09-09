// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve()
{
        cin>>n>>s;
        int o=0,z=0;
        for(int i=0;i<n;i++)
        {
                if(s[i]=='1')o++;
                else z++;
        }
        if(abs(o-z)>1)cout<<"-1\n";
        else
        {

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
