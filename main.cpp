#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T> constexpr T inf = numeric_limits<T>::has_infinity ? numeric_limits<T>::infinity() : numeric_limits<T>::max() / 4;

#define REP(i, stop) FOR(i, 0, stop)
#define FOR(i, start, stop) for (ll i = start, i##_len = stop; i < i##_len; ++i)
#define RREP(i, n) for (ll i = n; i-- > 0;)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define COMP(key) [](const auto& a, const auto& b) { return a.key < b.key; }

template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& a) { return is >> a.first >> a.second; }
template<typename T> istream& operator>>(istream& is, vector<T>& a) { for (T& x : a) is >> x; return is; }

template<typename T> using pop_max = std::priority_queue<T>;
template<typename T> using pop_min = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T> void LOG(const T& x) { cerr << x << "\n"; }
template<typename T> void LOG(const vector<T>& a) { for (const T& x : a) cerr << x << " "; cerr << "\n"; }
template<typename T> void LOG(const vector<vector<T>>& a) { for (const auto& x : a) LOG(x); }
template<typename T, std::size_t S> void LOG(const T (&a)[S]) { REP(i, S) cerr << a[i] << " "; cerr << "\n"; }
template<typename T, std::size_t S, std::size_t R> void LOG(const T (&a)[S][R]) { REP(i, S) { REP(j, R) cerr << a[i][j] << " "; cerr << "\n"; } }

ll ceil(ll a, ll b) { return a > 0 ? (a - 1) / b + 1 : a / b; }
ll gcd(ll a, ll b) { while (b != 0) { ll t = b; b = a % b; a = t; } return a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll gcd(const vector<ll>& v) { return accumulate(v.begin(), v.end(), 1LL, static_cast<ll(*)(ll, ll)>(gcd)); }
ll lcm(const vector<ll>& v) { return v.empty() ? 0LL : accumulate(v.begin() + 1, v.end(), v[0], static_cast<ll(*)(ll, ll)>(lcm)); }
ll pow(ll x, ll y, ll z) { ll a = 1; while (y > 0) { if (y & 1) a = a * x % z; x = x * x % z; y /= 2; } return a; }
ll inv(ll x, ll m) { return pow(x, m - 2, m); }

template<typename T> bool chmax(T& x, const T& y) { return x < y ? x = y, true : false; }
template<typename T> bool chmin(T& x, const T& y) { return x > y ? x = y, true : false; }

struct InitCpp { InitCpp() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(10); } } init_cpp;

const ll INF = inf<ll>;
using P = pair<ll, ll>;
const ll M = 1000000007;
signed main() {
}
