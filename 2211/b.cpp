#include <bits/stdc++.h>
#include "nt/sieve.hpp"
using namespace std;
NT::Sieve sieve(1<<20);
int x,y;
void solve()
{
        cin>>x>>y;
        int n=abs(x-y);
        cout<<max(1,(int)sieve.count_divisors(n))<<'\n';
        if(x>y)
        {
                for(int i=0;i<x;i++)cout<<"1 ";
                for(int i=0;i<y;i++)cout<<"-1 ";
                cout<<'\n';
        }
        else
        {
                for(int i=0;i<y;i++)cout<<"-1 ";
                for(int i=0;i<x;i++)cout<<"1 ";
                cout<<'\n';
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
