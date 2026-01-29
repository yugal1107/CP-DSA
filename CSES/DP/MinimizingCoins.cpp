#include <bits/stdc++.h>

using namespace std;
typedef long long ll;;

ll mod = 1e9+7;

int solve(vector<int> coins, int t){
    int n = coins.size();

    vector<int> dp(t+1, -1);

    dp[0]=0;

    // for (int i: coins){
    //     dp[i]=1;
    // }

    for (int i=1 ; i<=t ; i++){
        for (int coin: coins){
            if (i-coin>=0 && dp[i-coin]!=-1){
                if (dp[i]==-1) dp[i] = dp[i-coin]+1;
                else dp[i] = min(dp[i - coin] + 1, dp[i]);
            }
        }
    }

    return dp[t];
}


int main() {
    // your code goes here
    int t, n;
    cin >> n >> t;

    vector<int> coins(n);

    for (int& coin: coins) cin >> coin;
    cout << solve(coins, t) << endl;
}