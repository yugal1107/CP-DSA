#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(string s, int n){

    string t;
    
    int count = 0;
    for (char& c: s){
        if (c=='1') count++;
        t+='0';
    }

    for (int i=0 ; i<n ; i++){
        if (s[i]=='1'){
            if (i-1 >=0) t[i-1]='1';
            if (i+1 < n) t[i+1]='1';
        }
    }

    for (int i=0 ; i<n ; i++){
        if (s[i]=='1' || t[i]=='1') s[i]='1';
    }

    // cout << s << endl;

    int curr = 0;
    for (char& c: s){
        if (c=='1'){
            count+=((curr + 2)/3);
            curr = 0;
        } else {
            curr++;
        }
    }

    count+=((curr + 2)/3);

    cout << count << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
}