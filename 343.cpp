#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SZ(v) ((int)(v.size()))
const int N = 2e5+9;
map<char, int> mp;
void pre_calc () {
    int val = 0;
    for (char c = '0'; c <= '9'; ++c, ++val) {
        mp[c] = val;
    }
    for (char c = 'A'; c <= 'Z'; ++c, ++val) {
        mp[c] = val;
    }
}
ll ConvertToDecimal (int base, string s) {
    reverse(s.begin(), s.end());
    ll val = 0;
    ll mul = 1;
    for (int i = 0; i < SZ(s); ++i, mul *= base) {
        val += mp[s[i]] * mul;
    }
    return val;
}
int get_base (string s) {
    int val = 0;
    for (int i = 0; i < SZ(s); ++i) {
        val = max(val, mp[s[i]]);
    }
    return max(val + 1, 2);
}
void run () {
    pre_calc();
    string a, b;
    while (cin >> a >> b) {
        int aMnBase = get_base(a);
        int bMnBase = get_base(b);
        bool done = false;
        pair<int, int> base;
        for (int baseA = aMnBase; baseA <= 36; ++baseA) {
            int CurValOfA = ConvertToDecimal(baseA, a);
            for (int baseB = bMnBase; baseB <= 36; ++baseB) {
                int CurValOfB = ConvertToDecimal(baseB, b);
                if (CurValOfA == CurValOfB) {
                    done = true;
                    base.first = baseA;
                    base.second = baseB;
                    break;
                }
            }
            if(done) break;
        }
        if(done)
            cout << a << " (base " << base.first << ") = " << b << " (base " << base.second << ")\n";
        else
            cout << a << " is not equal to " << b << " in any base 2..36\n";
    }

}
int main () {
    int tt;
    tt = 1;
//    cin >> tt;
    while (tt--)
        run();
    return 0;
}
