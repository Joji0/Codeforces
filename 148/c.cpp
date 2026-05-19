#include <bits/stdc++.h>
using namespace std;
int n,a,b;
void solve() 
{
        cin>>n>>a>>b;
        if(b==0&&a>0)
        {
                if(a==n-1)
                {
                        cout<<"-1\n";
                        return;
                }
                vector<int>ans;
                ans.push_back(1);
                ans.push_back(1);
                for(int i=0;i<a;i++)
                {
                        ans.push_back(ans.back()+1);
                }
                while((int)ans.size()<n)ans.push_back(1);
                for(int x:ans)cout<<x<<" ";
                cout<<'\n';
                return;
        }
        vector<int>ans;
        ans.push_back(1);
        int csum=1;
        for(int i=1;i<n;i++)
        {
                if(b)
                {
                        if(csum+1>50000)
                        {
                                ans.push_back(1);
                                csum++;
                        }
                        else 
                        {
                                ans.push_back(csum+1);
                                csum+=csum+1;
                                b--;
                        }
                }
                else if(a)
                {
                        ans.push_back(ans.back()+1);
                        csum+=ans.back();
                        a--;
                }
                else 
                {
                        ans.push_back(1);
                }
        }
        for(int x:ans)
        {
                if(x>50000)
                {
                        cout<<"-1\n";
                        return;
                }
        }
        if(a||b)
        {
                cout<<"-1\n";
                return;
        }
        for(int x:ans)cout<<x<<" ";
        cout<<'\n';
}
int main() 
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
