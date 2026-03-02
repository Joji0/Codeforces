#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool prime[105];
void solve() 
{
        cin>>n>>s;
        set<int>comp={1,4,6,8,9};
        for(char c:s)
        {
                int nw=c-'0';
                if(comp.count(nw))
                {
                        cout<<"1\n";
                        cout<<nw<<'\n';
                        return;
                }
        }
        for(int i=0;i<n;i++)
        {
                for(int j=i+1;j<n;j++)
                {
                        int nw=(s[i]-'0')*10+(s[j]-'0');
                        if(!prime[nw])
                        {
                                cout<<"2\n";
                                cout<<nw<<'\n';
                                return;
                        }
                }
        }
        assert(false);
}
int main() 
{
        for(int i=0;i<105;i++)prime[i]=true;
        prime[0]=prime[1]=false;
        for(int i=2;i<105;i++)
        {
                if(prime[i])
                        for(int j=i*i;j<105;j+=i)
                        {
                                prime[j]=false;
                        }
        }
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        cin>>tc;
        while(tc--)solve();
        return 0;
}
