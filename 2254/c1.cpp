// 我思う、故に我在り
#include <bits/stdc++.h>
using namespace std;
int n;
string a,b;
void solve()
{
        cin>>n>>a>>b;
        string x,y;
        x=a,y=b;
        sort(x.begin(),x.end()),sort(y.begin(),y.end());
        if(x!=y)
        {
                cout<<"NO\n";
                return;
        }
        vector<char>stk1,stk2;
        for(int i=0;i<n;i++)
        {
                if(!stk1.empty()&&stk1.back()==a[i])stk1.pop_back();
                else stk1.push_back(a[i]);
        }
        for(int i=0;i<n;i++)
        {
                if(!stk2.empty()&&stk2.back()==b[i])stk2.pop_back();
                else stk2.push_back(b[i]);
        }
        int ok=1;
        if(stk1.size()!=stk2.size())ok=0;
        for(int i=0;i<(int)stk1.size();i++)ok&=(stk1[i]==stk2[i]);
        cout<<(ok?"YES":"NO")<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
