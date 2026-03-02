#include <bits/stdc++.h>
using namespace std;
int mx=0;
void solve() 
{
        int n;cin>>n;
        vector<vector<int>>a(n,vector<int>(6));
        for(int i=0;i<n;i++)
                for(int j=0;j<6;j++)cin>>a[i][j];
        sort(a.begin(),a.end());
        do{
                int i;
                for(i=1;i<1000;i++)
                {
                        string s=to_string(i);
                        int mask=(1<<(int)s.size())-1;
                        for(int j=0;j<n;j++)
                        {
                                bool ok=false;
                                for(int k=0;k<6;k++)
                                {
                                        for(int l=0;l<(int)s.size();l++)
                                        {
                                                if(a[j][k]==s[l]-'0'&&(mask&(1<<l)))
                                                {
                                                        mask&=~(1<<l);
                                                        ok=true;
                                                        break;
                                                }
                                        }
                                        if(ok)break;
                                }
                        }
                        if(mask!=0)
                        {
                                break;
                        }
                }
                mx=max(mx,i);
        }while(next_permutation(a.begin(),a.end()));
        cout<<mx-1<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin >> tc;
        while(tc--)solve();
        return 0;
}
