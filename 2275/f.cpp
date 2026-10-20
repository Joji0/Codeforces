#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
namespace ZOBRIST
{
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ull RANDOM_SEED = rng();
ull splitmix64(ull x)
{
        x+=0x9e3779b97f4a7c15ULL;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9ULL;
        x=(x^(x>>27))*0x94d049bb133111ebULL;
        return x^(x>>31);
}
ull code(ll x){return splitmix64((ull)x+RANDOM_SEED);}
struct XorSet
{
unordered_set<ll> s;
ull h=0;
void insert(ll x)
{
        if(s.insert(x).second)
                h^=code(x);
}
void erase(ll x)
{
        if(s.erase(x))
                h^=code(x);
}
bool contains(ll x) const{return s.find(x)!=s.end();}
ull get() const{return h;}
int size() const{return (int)s.size();}
};
}
namespace SIEVE
{
const int N=1000005;
int primes[N],pr_cnt,spf[N],phi[N],mu[N];
bool is_pr[N];
ull hash[N];
void sieve(int n)
{
        fill(is_pr+2,is_pr+n+1,true);
        phi[1]=1;mu[1]=1;
        for(int i=2;i<=n;++i)
        {
                if(is_pr[i])
                {
                        primes[++pr_cnt]=i;
                        spf[i]=i;phi[i]=i-1;mu[i]=-1;
                        hash[i]=ZOBRIST::code(i);
                }
                for(int j=1;j<=pr_cnt&&i*primes[j]<=n;++j)
                {
                        int p=primes[j];
                        is_pr[i*p]=false;
                        spf[i*p]=p;
                        if(i%p==0)
                        {
                                phi[i*p]=phi[i]*p;
                                mu[i*p]=0;
                                break;
                        }
                        phi[i*p]=phi[i]*(p-1);
                        mu[i*p]=-mu[i];
                }
        }
}
}
int n,a[200005];
ull ha[200005],p[200005];
void solve()
{
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i];
                int nw=a[i];
                ha[i]=0;
                while(nw>1)
                {
                        ha[i]^=SIEVE::hash[SIEVE::spf[nw]];
                        nw/=SIEVE::spf[nw];
                }
        }
        map<ull,ll>mp;
        for(int i=1;i<=n;i++)
                p[i]=p[i-1]^ha[i],
                mp[p[i]]++;
        ll ans=0;
        for(int i=1;i<=n;i++)
                ans+=mp[ha[i]];
        cout<<ans<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        SIEVE::sieve(1000000);
        cin>>tc;
        while(tc--)solve();
        return 0;
}
