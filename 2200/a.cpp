#include <bits/stdc++.h>
using namespace std;
int n,a[11],use[11],b[11];
void solve() 
{
        cin>>n;
        int sum=0;
        for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];use[i]=0;}
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)b[j]=a[j];
                int pl=i,cr=sum,lp=-1;
                while(cr>0)
                {
                        if(b[pl]>0)
                        {
                                b[pl]--;
                                cr--;
                                lp=pl;
                        }
                        else 
                        {
                        }
                        pl=(pl+1)%n;
                }
                use[lp]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
                ans+=use[i];
        }
        cout<<ans<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
