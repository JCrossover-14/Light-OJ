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
void dfs(int cur,int color, vector<vector<int>> &edges, int &zerocount, int &onecount,vector<int> &visited)
{
    visited[cur]=1;
    if(color==0) zerocount++;
    else onecount++;
    for(int x:edges[cur])
    {
        if(!visited[x])
        {
            if(color==0) dfs(x,1,edges,zerocount,onecount,visited);
            else dfs(x,0,edges,zerocount,onecount,visited);
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
    int n;
    cin>>n;
    vector<vector<int>> edges;
    forn(i,20001)
    {
        vector<int> edgel;
        edges.pb(edgel);
    }
    unordered_set<int> nums;
    forn(i,n)
    {
        int u,v;
        cin>>u>>v;
        edges[u].pb(v);
        edges[v].pb(u);
        if(nums.find(u)==nums.end()) nums.insert(u);
        if(nums.find(v)==nums.end()) nums.insert(v);
    }
    vector<int> visited(20001,0);
    int ans = 0;
    forn(i,20000)
    {
        if(!visited[i+1]&&nums.find(i+1)!=nums.end())
        {
            int onec = 0;
            int zeroc=0;
            dfs(i+1,0,edges,zeroc,onec,visited);
            ans+=max(onec,zeroc);
        }
    }
    cout<<"Case "<<it<<": ";
    cout<<ans<<ln;

 }
 return 0;
}