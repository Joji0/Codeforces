#include <bits/stdc++.h>
#include "geometry/geometry.hpp"
using namespace std;
const int N=200005;
int n;
int64_t r;
const Point<int64_t>origin={0,0};
const double PI=acos(-1);
void solve()
{
        cin>>n>>r;
        vector<Point<int64_t>>p(n);
        for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
        vector<Point<int64_t>>hull=convex_hull(p);
        int k=(int)hull.size();
        for(int i=0;i<k;i++)
        {
                if(cross(hull[i],hull[(i+1)%k],origin)<=0)
                {
                        cout<<fixed<<setprecision(10)<<PI*(double)r*(double)r/2.0<<'\n';
                        return;
                }
        }
        double d=1e9;
        for(int i=0;i<k;i++)d=min(d,1.0*abs(cross(hull[i],hull[(i+1)%k]))/sqrt((double)norm2(hull[i]-hull[(i+1)%k])));
        double f=(double)r*(double)r*acos(d/r),s=d*sqrt(r*r-d*d);
        cout<<fixed<<setprecision(10)<<f-s<<'\n';
}
int main()
{
        ios::sync_with_stdio(false);cin.tie(NULL);
        int tc=1;
        // cin>>tc;
        while(tc--)solve();
        return 0;
}
