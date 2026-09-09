#line 1 "a.cpp"
#include <bits/stdc++.h>
#line 5 "ds/unionfind/unionfind.hpp"

struct UnionFind
{
        std::vector<int> parent, sz, gov;
        int num_comps;
        UnionFind(int n = 0) { init(n); }
        void init(int n)
        {
                parent.resize(n);
                iota(parent.begin(), parent.end(), 0);
                sz.assign(n, 1);
                gov.assign(n, 0);
                num_comps = n;
        }
        int find(int x) { return (x == parent[x] ? x : parent[x] = find(parent[x])); }
        bool same(int a, int b) { return find(a) == find(b); }
        int size(int x) { return sz[find(x)]; }
        bool join(int a, int b)
        {
                a = find(a), b = find(b);
                if (a != b)
                {
                        if (sz[a] < sz[b]) std::swap(a, b);
                        parent[b] = a;
                        sz[a] += sz[b];
                        int ok = gov[a] || gov[b];
                        gov[a] = (bool)ok;
                        num_comps--;
                        return true;
                }
                return false;
        }
        std::vector<std::vector<int>> groups()
        {
                int n = parent.size();
                std::vector<std::vector<int>> res(n);
                std::vector<int> group_size(n, 0);
                for (int i = 0; i < n; i++)
                {
                        group_size[find(i)]++;
                }
                std::vector<std::vector<int>> result;
                std::vector<int> root_map(n, -1);
                for (int i = 0; i < n; i++)
                {
                        int r = find(i);
                        if (root_map[r] == -1)
                        {
                                root_map[r] = result.size();
                                result.push_back({});
                                result.back().reserve(group_size[r]);
                        }
                        result[root_map[r]].push_back(i);
                }
                return result;
        }
};
#line 3 "a.cpp"
using namespace std;
const int N=1005;
int n,m,k;
void solve()
{
        cin>>n>>m>>k;
        UnionFind dsu(n);
        for(int i=0;i<k;i++)
        {
                int u;cin>>u;u--;
                dsu.gov[u]=1;
        }
        for(int i=0;i<m;i++)
        {
                int u,v;cin>>u>>v;u--,v--;
                dsu.join(u,v);
        }
        int64_t bonus=0;
        vector<int64_t>govs;
        vector<int>touch(n,0);
        for(int i=0;i<n;i++)
        {
                int rt=dsu.find(i);
                if(touch[rt])continue;
                touch[rt]=1;
                if(dsu.gov[rt])govs.push_back(dsu.sz[rt]);
                else bonus+=dsu.sz[rt];
        }
        sort(govs.rbegin(),govs.rend());
        int64_t ans=0;
        if(!govs.empty())
        {
                ans=govs[0]+bonus;
                ans=ans*(ans-1)/2;
        }
        for(int i=1;i<(int)govs.size();i++)ans+=govs[i]*(govs[i]-1)/2;
        cout<<ans-m<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
