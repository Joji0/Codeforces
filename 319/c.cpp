#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a[1<<17],b[1<<17],dp[1<<17];
struct Line
{
        int64_t m,c;
        int64_t val(int64_t x)
        {
                return m*x+c;
        }
        long double intersect(const Line &other) const
        {
                return (long double)(other.c-c)/(m-other.m);
        }
};
void solve()
{
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        dp[0]=0;
        vector<Line>dq;
        int head=0;
        dq.push_back({b[0],0});
        for(int i=1;i<n;i++)
        {
                while(head+1<(int)dq.size()&&dq[head].val(a[i])>=dq[head+1].val(a[i]))head++;
                dp[i]=dq[head].val(a[i]);
                Line nl={b[i],dp[i]};
                while((int)dq.size()>=head+2)
                {
                        Line l1=dq[(int)dq.size()-2],l2=dq[(int)dq.size()-1];
                        if(l1.intersect(nl)<=l1.intersect(l2))dq.pop_back();
                        else break;
                }
                dq.push_back(nl);
        }
        cout<<dp[n-1]<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
