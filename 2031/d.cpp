#include <bits/stdc++.h>
using namespace std;
int n,a[1<<20],pmx[1<<20],pmn[1<<20];
struct DSU {
        vector<int> parent, sz, mx;
        DSU() {}
        DSU(int n) { init(n); }
        void init(int n) {
                parent.resize(n);
                iota(parent.begin(), parent.end(), 0);
                mx.assign(n,0);
                for(int i=0;i<n;i++)mx[i]=a[i];
                sz.assign(n, 1);
        }
        int find(int x) { return (x == parent[x] ? x : parent[x] = find(parent[x])); }
        bool same(int a, int b) { return find(a) == find(b); }
        int size(int x) { return sz[find(x)]; }
        bool join(int a, int b) {
                a = find(a), b = find(b);
                if (a != b) {
                        if (sz[a] < sz[b]) swap(a, b);
                        parent[b] = a;
                        sz[a] += sz[b];
                        mx[a]=max(mx[a],mx[b]);
                        return true;
                }
                return false;
        }
};
void solve() 
{
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];pmx[i]=a[i],pmn[i]=a[i];}
        for(int i=1;i<n;i++)
                pmx[i]=max(pmx[i-1],a[i]);
        for(int i=n-2;i>=0;i--)
                pmn[i]=min(pmn[i+1],a[i]);
        DSU dsu(n);
        for(int i=1;i<n;i++)
        {
                if(pmx[i-1]>pmn[i])dsu.join(i-1,i);
        }
        for(int i=0;i<n;i++)
        {
                cout<<dsu.mx[dsu.find(i)]<<" \n"[i==n-1];
        }
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin >> tc;
        while(tc--)solve();
        return 0;
}
