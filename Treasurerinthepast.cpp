//https://codeforces.com/contest/2072/problem/B
#include <iostream>
using namespace std;

#define ll long long

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int r;
        cin >> r;
        string s;
        cin >> s;
        
        int m = 0, n = 0;
        for (char ch : s) 
        {
            if (ch == '-') m++;
            else if (ch == '_') n++;
        }
        
        int g = m / 2;
        int h = m-g; 
        
        ll total = (ll)n * g * h;
        cout << total << endl;
    }
    return 0;
}
