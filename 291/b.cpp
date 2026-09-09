// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int instack=0,sp=0;
string s;
char c;
void solve()
{
        while(cin.get(c))
        {
                if(c=='\n')break;
                if(c=='"')
                {
                        if(instack)
                        {
                                cout<<"<"<<s<<">\n";
                                s="";
                                instack=0;
                        }
                        else instack=1;
                }
                else
                {
                        if(instack)s+=c;
                        else
                        {
                                if(c==' ')
                                {
                                        if(sp)
                                        {
                                                cout<<"<"<<s<<">\n";
                                                s="";
                                                sp=0;
                                        }
                                        continue;
                                }
                                sp=1;
                                s+=c;
                        }
                }
        }
        if(sp)cout<<"<"<<s<<">\n";
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
