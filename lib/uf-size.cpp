#include <numeric>
#include <vector>

// union-by-size
// https://atcoder.jp/contests/abc120/submissions/4640165

// BEGIN

class UnionFind {
private:
  std::vector<size_t> P;
  std::vector<size_t> S;
  size_t find(size_t x) { return P[x] == x ? x : P[x] = find(P[x]); }
public:
  UnionFind(size_t n) {
    P.resize(n);
    iota(P.begin(), P.end(), 0);
    S.resize(n);
    fill(S.begin(), S.end(), 1);
  }
  void unite(size_t x, size_t y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (S[x] < S[y]) {
      P[x] = y;
      S[y] += S[x];
    } else {
      P[y] = x;
      S[x] += S[y];
    }
  }
  bool same(size_t x, size_t y) { return find(x) == find(y); }
  size_t size(size_t x) { return S[find(x)]; }
};

// END
