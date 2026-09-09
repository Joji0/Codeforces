// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N];
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>ans;
        int bad=0,cnt=0;
        for(int i=0;i<n;i++)
        {
                if(a[i]<0&&bad>=2)
                {
                        ans.push_back(cnt);
                        cnt=1;
                        bad=1;
                }
                else if(a[i]<0)bad++,cnt++;
                else cnt++;
        }
        if(cnt)ans.push_back(cnt);
        cout<<(int)ans.size()<<'\n';
        for(int x:ans)cout<<x<<" ";
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
