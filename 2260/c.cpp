#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define inf 0x3f3f3f3f
int x,y;
// int go(int idx, int v)
// {
//         int ret=0;
//         for(int i=idx;i>=0;i--)
//                 if(v>>i&1)
//                         ret+=1<<i;
//         return ret;
// }
void solve()
{
        cin>>x>>y;
        int mx=x+y,op=inf;
        if((x^y)==mx)
        {
                cout<<mx<<" 0\n";
                return;
        }
        int res=0;
        for(int i=31;i>=0;i--)
        {
                if((mx>>i&1))
                {
                        if((res|1<<i)<=x)
                                res|=1<<i;
                        // int res=go(i,mx);
                        // if(res<=x&&(((res)^(y+(x-res)))==mx))
                        // {
                        //         op=x-res;
                        //         break;
                        // }
                }
        }
        assert((res^(y+x-res))==mx);
        cout<<mx<<" "<<(x-res)<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
// 0010,1000, ori: 0110, 0100, target: 1010
