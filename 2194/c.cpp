#include <bits/stdc++.h>
using namespace std;
int n,k,msk[1<<17],o;
string s[1<<17],av,ans;
vector<int> dv;
bool ok;
void solve() 
{
        dv.clear();
        cin>>n>>k;
        for(int i=0;i<n;i++)msk[i]=0;
        for(int i=0;i<k;i++){cin>>s[i];for(int j=0;j<n;j++){msk[j]|=1<<(s[i][j]-'a');}}
        for(int i=1;i*i<=n;i++)
        {
                if(n%i==0)
                {
                        dv.push_back(i);
                        if(n%(n/i)==0&&i!=n/i)dv.push_back(n/i);
                }
        }
        sort(dv.begin(),dv.end());
        for (int d:dv)
        {
                av.clear();
                ok=true;
                for(int i=0;i<d;i++)
                {
                        o=(1<<26)-1;
                        for(int j=i;j<n;j+=d)o&=msk[j];
                        if(!o)
                        {
                                ok=false;break;
                        }
                        for(int j=0;j<26;j++)
                        {
                                if(o&(1<<j)){av+=(char)('a'+j);break;}
                        }
                }
                if(ok)
                {
                        ans.clear();
                        for(int i=0;i<n/d;i++)
                        {
                                ans+=av;
                        }
                        cout<<ans<<'\n';
                        return;
                }
        }
        assert(false);
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
