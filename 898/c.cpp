#include <bits/stdc++.h>
using namespace std;
int n;
map<string,set<string>>mp;
set<string>filter(const set<string>&st)
{
        set<string>ret;
        vector<string>nw;
        for(string x:st)
        {
                nw.push_back(x); 
        }
        for(int i=0;i<(int)nw.size();i++)
        {
                bool suff=false;
                for(int j=0;j<(int)nw.size();j++)
                {
                        if(i==j)continue;
                        string now=nw[i],chk=nw[j];
                        reverse(now.begin(),now.end());
                        reverse(chk.begin(),chk.end());
                        if((int)nw[i].size()<(int)nw[j].size())
                        {
                                int cnt=0;
                                for(int k=0;k<(int)nw[i].size();k++)
                                {
                                        cnt+=(now[k]==chk[k]);
                                }
                                if(cnt==(int)nw[i].size())suff=true;
                        }
                }
                if(!suff)ret.insert(nw[i]);
        }
        return ret;
}
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++)
        {
                string nm;
                int cnt;
                cin>>nm>>cnt;
                for(int j=0;j<cnt;j++)
                {
                        string ph;cin>>ph;
                        mp[nm].insert(ph);
                }
        }
        cout<<(int)mp.size()<<'\n';
        for(auto&[name,st]:mp)
        {
                set<string>nw=filter(st);
                cout<<name<<" "<<(int)nw.size()<<" ";
                for(string x:nw)
                {
                        cout<<x<<" ";
                }
                cout<<'\n';
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
