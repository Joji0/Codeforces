#include <bits/stdc++.h>
using namespace std;
int q;
string s;
bitset<1<<17>B[26];
void solve()
{
        cin>>s>>q;
        int n=(int)s.size();
        for(int i=0;i<n;i++)B[s[i]-'a'][i]=1;
        while(q--)
        {
                int k;string m;cin>>k>>m;
                bitset<1<<17>ans;
                ans.set();
                for(int i=0;i<(int)m.size();i++)
                {
                        ans&=(B[m[i]-'a']>>i);
                }
                vector<int>pos;
                for(int i=ans._Find_first();i<1<<17;i=ans._Find_next(i))
                {
                        if(i>(int)s.size()-(int)m.size())break;
                        pos.push_back(i);
                }
                if((int)pos.size()<k)cout<<"-1\n";
                else
                {
                        int mn=1<<30;
                        for(int i=0;i+k-1<(int)pos.size();i++)
                        {

                                int curr=pos[i+k-1]-pos[i]+(int)m.size();
                                mn=min(mn,curr);
                        }
                        cout<<mn<<'\n';
                }
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
