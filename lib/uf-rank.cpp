#include <numeric>
#include <vector>

// union-by-rank

// BEGIN

class UnionFind {
private:
  std::vector<size_t> P;
  std::vector<size_t> R;
  size_t find(size_t x) { return P[x] == x ? x : P[x] = find(P[x]); }
public:
  UnionFind(size_t n) {
    P.resize(n);
    iota(P.begin(), P.end(), 0);
    R.resize(n);
    fill(R.begin(), R.end(), 0);
  }
  void unite(size_t x, size_t y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (R[x] < R[y]) {
      P[x] = y;
    } else {
      P[y] = x;
      if (R[x] == R[y]) ++R[x];
    }
  }
  bool same(size_t x, size_t y) { return find(x) == find(y); }
};

// END
