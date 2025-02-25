//https://codeforces.com/contest/2072/problem/A
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, p;
        cin >> n >> k >> p;
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        int max_sum = n * p;
        if (abs(k) > max_sum) {
            cout << -1 << endl;
        } else {
            int m = (abs(k) + p - 1) / p;
            cout << m << endl;
        }
    }
    return 0;
}
