#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace__gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define otree tree<ll,ll,less<ll>,rb_tree_tag,tree_order_statistics_node_update> 
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

void solve(){
}
void djikstra(ll s,vector<vector<pair<ll,ll>>> &weightedEdges, vector<ll> &distance, vector<ll> &prev)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    distance.assign(distance.size(),10000000000);
    distance[s]=0;
    pq.push(mp(0,s));
    while(!pq.empty())
    {
        pair<ll,ll> cur = pq.top();
        //cout<<"distance "<<cur.first<<" is city "<<cur.second<<ln;
        pq.pop();
        for(pair<ll,ll> edge:weightedEdges[cur.second])
        {
            if(distance[edge.first]==10000000000)
            {
                //cout<<"updated distance of "<<edge.first<<" from "<<distance[edge.first]<<" to "<<distance[cur.second]+edge.second<<ln;
                //cout<<"hasn't been reached so "<<edge.second<<" is forced to city "<<edge.first<<ln;
                distance[edge.first]=max(edge.second,distance[cur.second]);
                prev[edge.first]=cur.second;
                pq.push(mp(distance[edge.first],edge.first));
            }
            else
            {
                if(distance[edge.first]>max(distance[cur.second],edge.second))
                {
                    //cout<<edge.first<<" current distance is "<<distance[edge.first]<<ln;
                    //cout<<"but we can get there from city "<<cur.second<<" dist "<<distance[cur.second]<<" or distance "<<edge.second<<ln;
                    distance[edge.first]=max(distance[cur.second],edge.second);
                    prev[edge.first]=cur.second;
                    pq.push(mp(distance[edge.first],edge.first));
                }
            }
        }
    }
}

int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) 
 {
    string blank;
    getline(cin,blank);
    int n,m;
    cin>>n>>m;
    //cout<<"n and m are "<<n<<" "<<m<<ln;
    vector<vector<pair<ll,ll>>> weightedEdges;
    forn(i,n+4)
    {
        vector<pair<ll,ll>> temp;
        weightedEdges.pb(temp);
    }
    forn(i,m)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        weightedEdges[u].pb(mp(v,w));
        weightedEdges[v].pb(mp(u,w));
    }
    ll source;
    cin>>source;
    vector<ll> prev(n+4,-1);
    vector<ll> distances(n+4,0);
    djikstra(source,weightedEdges,distances,prev);
    cout<<"Case "<<it<<":"<<ln;
    forn(i,n)
    {
        if(distances[i]<1000000000)cout<<distances[i]<<ln;
        else cout<<"Impossible"<<ln;
    }
 }
 return 0;
}