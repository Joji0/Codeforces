#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int n;
void solve()
{
        cin>>n;
        vector<pair<int,int>>ans;
        if(n==2)
        {
                cout<<"1 1\n1 2\n";
                return;
        }
        for(int col=1;col<=n-2;col++)
                ans.push_back({1,col});
        ans.push_back({2,n});
        // int prv=-1,want=1;
        // for(int col=1;col<=n-1;col++)
        //         for(int row=1;row<=n;row++)
        //         {
        //                 if(prv==-1)
        //                 {
        //                         prv=1;
        //                         ans.push_back({row,col});
        //                 }
        //                 else
        //                 {
        //                         if(1+abs(prv-row)==want)
        //                         {
        //                                 ans.push_back({row,col});
        //                                 ++want;
        //                                 prv=row;
        //                                 break;
        //                         }
        //                 }
        //         }
        ans.push_back({n,n});
        assert((int)ans.size()==n);
        // cerr<<"WANT: "<<want<<'\n';
        for(auto&[x,y]:ans)
                cout<<x<<" "<<y<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
