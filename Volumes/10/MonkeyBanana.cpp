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

void solve()
{
    int n;
    cin>>n;
    vector<vector<ll>> grid(2*n+1,vector<ll>(n+1));
    vector<vector<ll>> dp(2*n+1,vector<ll>(2*n+1,0));
    forn(i,n)
    {
        forn(j,i)
        {
            cin>>grid[i][j];
        }
    }
    forn(i,n)
    {
        forn(j,n-i)
        {
            cin>>grid[n+i][j];
        }
    }
    ll maxs = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j==0) dp[i][j]=dp[i-1][j]+grid[i][j];
            else if(j==i-1) dp[i][j]=dp[i-1][j-1]+grid[i][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+grid[i][j];
            maxs=max(maxs,dp[i][j]);
        }
    }
    for(int i=n+1;i<=2*n-1;i++)
    {
        for(int j=0;j<grid[i].size();j++) 
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+grid[i][j];
            maxs = max(maxs,dp[i][j]);
        }
    }
    cout<<maxs<<ln;
    /**
     
    ll maxans = grid[0][0];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            if(j==0) dp[i][j]=dp[i-1][j]+grid[i][j];
            else if(j==i) dp[i][j]=dp[i-1][j-1]+grid[i][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+grid[i][j];
            maxans = max(maxans,dp[i][j]);
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            dp[n+i][j]=max(dp[i-1][j],dp[i-1][j+1])+grid[i][j];
            maxans=max(maxans,dp[n+i][j]);
        }
    }
    */
    

}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) 
 {
    cout<<"Case "<<it<<": ";
    solve();
 }
 return 0;
}