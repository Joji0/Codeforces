#include <bits/stdc++.h>
#include "nt/sieve.hpp"
using namespace std;
int n,a[1<<17];
NT::Sieve sieve(1<<20);
void solve() 
{
        cin>>n; 
        for(int i=0;i<n;i++)cin>>a[i];
        bool ok=true;
        for(int i=0;i<n-1;i++)ok&=(a[i]<=a[i+1]);
        if(ok)
        {
                cout<<"Bob\n";
                return;
        }
        for(int i=0;i<n;i++)
        {
                auto f=sieve.get_distinct_primes(a[i]);
                if((int)f.size()>1)
                {
                        cout<<"Alice\n";
                        return;
                }
        }
        vector<int>p;
        for(int i=0;i<n;i++)
        {
                if(a[i]==1)
                {
                        p.push_back(1);
                }
                else
                {
                        auto f=sieve.get_distinct_primes(a[i]);
                        for(int pr:f)
                        {
                                p.push_back(pr);
                        }
                }
        }
        ok=true;
        for(int i=0;i<(int)p.size()-1;i++)
        {
                ok&=(p[i]<=p[i+1]);
        }
        cout<<(ok?"Bob\n":"Alice\n");
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
