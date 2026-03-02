#include <bits/stdc++.h>
using namespace std;
int n;
void solve() 
{
        cin>>n; 
        vector<vector<int>>a(n);
        for(int i=0;i<n;i++)
        {
                int l;cin>>l;
                for(int j=0;j<l;j++)
                {
                        int x;cin>>x;
                        a[i].push_back(x);
                }
                reverse(a[i].begin(),a[i].end());
                vector<int>ca;
                set<int>ste;
                for(int x:a[i])
                {
                        if(!ste.count(x))
                        {
                                ste.insert(x);
                                ca.push_back(x);
                        }
                }
                a[i]=ca;
        }
        set<int>st;
        vector<bool>used(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
                int bst=-1;
                vector<int>bstv;
                for(int j=0;j<n;j++)
                {
                        if(used[j])continue;
                        vector<int>tv;
                        for(int x:a[j])
                        {
                                if(!st.count(x))tv.push_back(x);
                        }
                        if(bst==-1||tv<bstv)
                        {
                                bst=j,bstv=tv;
                        }
                }
                used[bst]=true;
                for(int x:bstv)
                {
                        st.insert(x);
                        ans.push_back(x);
                }
        }
        for(int x:ans)
        {
                cout<<x<<" ";
        }
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
