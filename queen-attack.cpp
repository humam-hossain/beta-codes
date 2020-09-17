#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define ll long long
#define vll vector<long long>
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define INF 1000000000000
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main()
{
    ll n,k,rq,cq,row,col;
    cin>>n>>k>>rq>>cq;
    ll r=n+1,l=0,up=0,down=n+1;
    set<pii> s;
    for(int i=0;i<k;i++)
    {
        cin>>row>>col;
        if(row==rq)
        {
            if(col>cq)r=min(r,col);
            else l=max(l,col);
        }
        else if(col==cq)
        {
            if(row<rq)up=max(up,row);
            else down=min(down,row);
        }
        else
        {
            s.insert(make_pair(row,col));
        }
        
    }
    ll sum=0;
    sum+=(r-cq-1)+(cq-l-1)+(rq-up-1)+(down-rq-1);
    ll x=rq,y=cq;
    while(x>1 && y<n)
    {
        x--,y++;
        if(s.count(make_pair(x,y)))break;
        else sum++;
    }
    x=rq,y=cq;
    while(x>1 && y>1)
    {
        x--,y--;
        if(s.count(make_pair(x,y)))break;
        else sum++;
    }
    x=rq,y=cq;
    while(x<n && y>1)
    {
        x++,y--;
        if(s.count(make_pair(x,y)))break;
        else sum++;
    }
    x=rq,y=cq;
    while(x<n && y<n)
    {
        x++,y++;
        if(s.count(make_pair(x,y)))break;
        else sum++;
    }
    cout<<sum;
}
