// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n;
int64_t b[N];
void solve()
{
        cin>>n;
        map<int64_t,int64_t>mp,remap;
        vector<int64_t>uniq;
        for(int i=0;i<n;i++)
        {
                cin>>b[i];
                mp[b[i]]++;
                uniq.push_back(b[i]);
        }
        sort(uniq.begin(),uniq.end());
        uniq.erase(unique(uniq.begin(),uniq.end()),uniq.end());
        if(!mp.contains(0))
        {
                cout<<"-1\n";
                return;
        }
        int m=(int)uniq.size();
        for(int i=0;i<m-1;i++)
        {
                int64_t df=uniq[i+1]-uniq[i];
                if(df%mp[uniq[i]]!=0)
                {
                        cout<<"-1\n";
                        return;
                }
                remap[uniq[i]]=df/mp[uniq[i]];
                if(i&&remap[uniq[i]]<=remap[uniq[i-1]])
                {
                        cout<<"-1\n";
                        return;
                }
        }
        if(m>1)remap[uniq[m-1]]=remap[uniq[m-2]]+1;
        else remap[uniq[m-1]]=1;
        for(int i=0;i<n;i++)cout<<remap[b[i]]<<" \n"[i==n-1];
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
