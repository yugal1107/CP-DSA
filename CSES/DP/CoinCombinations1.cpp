#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<ll> dp;

ll mod = 1e9+7;

//Using bottom-up DP approach
ll solve(vector<int> coins, int t){
    vector<ll> dp(t+1, 0);
    dp[0]=1;

    for (int i=1 ; i<=t ; i++){
        for (int& coin: coins){
            if (i-coin >= 0) dp[i] += dp[i-coin];
        }
        dp[i] %= mod;
    }

    return dp[t];
}

int main() {
    // your code goes here
    int n,x;
    cin >> n >> x;

    vector<int> v(n);

    for (int& i: v) cin >> i;

    cout << solve(v, x) << endl;
}