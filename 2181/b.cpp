#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve() 
{
        // brute force
        cin>>n>>m;
        priority_queue<int64_t>pqa,pqb;
        for(int i=0;i<n;i++)
        {
                int64_t x;cin>>x;
                pqa.push(x);
        }
        for(int i=0;i<m;i++)
        {
                int64_t x;cin>>x;
                pqb.push(x);
        }
        int64_t timer=1;
        while(!pqa.empty()&&!pqb.empty())
        {
                if(timer&1)
                {
                        if(pqb.top()<=pqa.top())
                        {
                                pqb.pop();
                        }
                        else 
                        {
                                int64_t nw=pqb.top()-pqa.top();
                                pqb.pop();pqb.push(nw);
                        }
                }
                else 
                {
                        if(pqa.top()<=pqb.top())
                        {
                                pqa.pop();
                        }
                        else 
                        {
                                int64_t nw=pqa.top()-pqb.top();
                                pqa.pop();pqa.push(nw);
                        }
                }
                timer++;
        }
        if(pqa.empty())
        {
                cout<<"Bob\n";
        }
        else 
        {
                cout<<"Alice\n";
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
