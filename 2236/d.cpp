#include <bits/stdc++.h>
using namespace std;
int n,k,a[1<<20];
void solve()
{
  map<int,int>mp;
  int mx=-1<<30,cnt=0;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
    mp[a[i]]++;
    mx=max(mx,a[i]);
  }
  mp[1<<30]++;
  for(int i=0;i<n;i++)cnt+=(bool)(a[i]==mx);
  if(n==1)
  {
    cout<<"NO\n";
    return;
  }
  bool ok=false;
  vector<array<int,2>>vc;
  for(auto&[v,c]:mp)vc.push_back({v,c});
  for(int i=0;i<(int)vc.size()-1;i++)
  {
    auto[v,c]=vc[i];
    auto[nv,nc]=vc[i+1];
    if((nv-v>k&&c%2==0)||(i<(int)vc.size()-2&&vc[i+2][0]-nv>k&&(nc&1)&&nv-v<=k))
    {
      ok=true;
      break;
    }
  }
  if(cnt%2==0||ok)
  {
    cout<<"YES\n";
  }
  else
  {
    cout<<"NO\n";
  }
}
int main()
{
  ios::sync_with_stdio(false);cin.tie(NULL);
  int tc=1;
  cin>>tc;
  while(tc--)solve();
  return 0;
}
