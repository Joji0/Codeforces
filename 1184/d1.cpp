// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n,k,m,t;
void solve()
{
        cin>>n>>k>>m>>t;
        while(t--)
        {
                int type,idx;cin>>type>>idx;
                if(type==1)
                {
                        if(idx<=k)k++;
                        n++;
                        cout<<n<<" "<<k<<'\n';
                }
                else
                {
                        if(k<=idx)n-=n-idx;
                        else
                        {
                                n-=idx;
                                k-=idx;
                        }
                        cout<<n<<" "<<k<<'\n';

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
