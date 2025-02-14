#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
typedef vector<ll> v64;
typedef vector<int> v32;

constexpr ll MOD = 998244353;
constexpr int MAXN = 5000001;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

v32 spf(MAXN);  // Smallest prime factor
v64 pref(MAXN); // Prefix sum of Euler's totient function

void preprocess() {
    // Step 1: Compute Smallest Prime Factor (SPF)
    iota(spf.begin(), spf.end(), 0); // spf[i] = i initially

    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { // Prime number
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i; // Mark the smallest prime factor
            }
        }
    }

    // Step 2: Compute Euler's Totient Function using SPF
    pref[1] = 0; // Base case: phi(1) = 1, but prefix sum should be 0
    for (int i = 2; i < MAXN; i++) {
        int n = i;
        ll phi = i;
        while (n > 1) {
            int prime = spf[n];
            while (n % prime == 0) n /= prime;
            phi -= phi / prime;
        }
        pref[i] = pref[i - 1] + phi*phi; // Prefix sum
        //if(i<=20)cout<<"phi for "<<i<<" is "<<phi<<" pref at this index is now "<<pref[i]<<endl;
        
    }
}

void solve() {
    ll a, b;
    cin >> a >> b;
    cout << pref[b] - pref[a - 1] << "\n";
}

int main() {
    fast_cin();
    preprocess();

    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        cout << "Case " << it << ": ";
        solve();
    }
    return 0;
}
