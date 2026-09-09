// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
        cin>>s;
        int i=0;
        if(s.substr(0,3)=="ftp")
        {
                cout<<"ftp://";
                i+=3;
        }
        else
        {
                cout<<"http://";
                i+=4;
        }
        string acc;
        for(;i<(int)s.size()-1;)
        {
                if(s[i]=='r'&&s[i+1]=='u'&&acc!="")
                {
                        cout<<acc<<".ru";
                        if(i+2==(int)s.size());
                        else cout<<"/";
                        i+=2;
                        break;
                }
                else acc+=s[i++];
        }
        for(;i<(int)s.size();i++)cout<<s[i];
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
