#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// vector<vector<ll>> dp;

ll mod = 1e9+7;

// ll recur(int t, int idx, vector<int>& coins){
//     int n = coins.size();

//     if (t<0 || idx == n) return 0;
//     if (t==0) return 1;

//     if (dp[t][idx]!=-1) return dp[t][idx]; 

//     ll take = recur(t-coins[idx], idx, coins);

//     ll nt = recur(t, idx+1, coins);

//     return dp[t][idx] = (take + nt)%mod;
// }

// //Using bottom-up DP approach
// ll solve(vector<int>& coins, int t){
//     dp.assign(t+1, vector<ll>(coins.size(), -1));
//     return recur(t, 0, coins);
// }

ll solve(vector<int>& coins, int t){
    int n = coins.size();

    vector<ll>dp(t+1, 0);

    dp[0]=1;

    for (int i = 0; i<n ; i++){
        for (int sum = 1 ; sum <= t ; sum++){
            if (sum - coins[i]>=0) dp[sum]+=dp[sum - coins[i]];
            if (dp[sum]>=mod) dp[sum]-=mod;
        }
    }

    return dp[t];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // your code goes here
    int n,x;
    cin >> n >> x;

    vector<int> v(n);

    for (int& i: v) cin >> i;

    cout << solve(v, x) << endl;
}