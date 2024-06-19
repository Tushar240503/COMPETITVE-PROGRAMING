#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#ifdef ONLINE_JUDGE
#define debug(...) ;
#else
template <typename T> void debug_out(T t) { cerr << t; }
template <typename A, typename B> void debug_out(pair<A, B> p) { cerr << "{" << p.first << ", " << p.second << "}"; }
template <typename T> void debug_out(vector<T> v) { cerr << "["; for (size_t i = 0; i < v.size(); ++i) { if (i > 0) cerr << ", "; debug_out(v[i]); } cerr << "]"; }
template <typename T> void debug_out(set<T> s) { cerr << "{"; bool first = true; for (const auto &x : s) { if (!first) cerr << ", "; debug_out(x); first = false; } cerr << "}"; }
template <typename T> void debug_out(multiset<T> s) { cerr << "{"; bool first = true; for (const auto &x : s) { if (!first) cerr << ", "; debug_out(x); first = false; } cerr << "}"; }
template <typename A, typename B> void debug_out(map<A, B> m) { cerr << "{"; bool first = true; for (const auto &p : m) { if (!first) cerr << ", "; debug_out(p.first); cerr << ": "; debug_out(p.second); first = false; } cerr << "}"; }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: "; debug_out(__VA_ARGS__); cerr << endl;
#endif

typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const long long mod = 1e9 + 7;
const long long mod1 = 998244353;
const long long mod2 = 1e9 + 9;
pair<long long, long long> has(string s) {
    long long h1 = 0, h2 = 0;
    for(long long i = 0; i < s.length(); i++) {
        h1 = (h1 * 31 + (s[i] - 'a' + 1)) % mod1;
        h2 = (h2 * 31 + (s[i] - 'a' + 1)) % mod2;
    }
    return {h1, h2};
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    fastio();
     string s, t;
    cin >> s >> t;
    
    pair<long long, long long> a = has(t);
    long long p1 = 1, p2 = 1;
    for(long long i = 0; i < t.length() - 1; i++) {
        p1 = (p1 * 31) % mod1;
        p2 = (p2 * 31) % mod2;
    }
    
    long long count = 0;
    pair<long long, long long> b = has(s.substr(0, t.length()));
    if(a == b) count++;
    
    long long i = 0;
    long long j = t.length();
    while(j < s.length()) {
        long long c1 = ((s[i] - 'a' + 1) * p1) % mod1;
        long long d1 = (s[j] - 'a' + 1);
        long long c2 = ((s[i] - 'a' + 1) * p2) % mod2;
        long long d2 = (s[j] - 'a' + 1);
        
        b.first = (b.first - c1 + mod1) % mod1;
        b.first = (b.first * 31) % mod1;
        b.first = (b.first + d1) % mod1;
        
        b.second = (b.second - c2 + mod2) % mod2;
        b.second = (b.second * 31) % mod2;
        b.second = (b.second + d2) % mod2;
        
        if(a == b) count++;
        i++;
        j++;
    }

    cout << count << endl;
    
    return 0;
}
