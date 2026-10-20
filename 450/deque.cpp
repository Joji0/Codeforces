#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int q,x;
void solve()
{
        cin>>q;
        deque<int>dq;
        while(q--)
        {
                int t;cin>>t;
                if(t==0)
                {
                        cin>>x;
                        dq.push_front(x);
                }
                else if(t==1)
                {
                        cin>>x;
                        dq.push_back(x);
                }
                else if(t==2)
                {
                        dq.pop_front();
                }
                else if(t==3)
                {
                        dq.pop_back();
                }
                else
                {
                        cin>>x;
                        cout<<dq[x]<<'\n';
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
