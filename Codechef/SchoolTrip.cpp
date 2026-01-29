#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, x, k;
        cin >> n >> x >> k;
        
        int rem = x%k;
        int nr = ((x/k)+1)*k - x;
        
        if (nr <= n - x) cout << min(rem, nr) << endl;
        else cout << rem << endl;
    }
}