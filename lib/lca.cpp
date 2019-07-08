#include <vector>

// Lowest Common Ancestor
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3726169#1

// BEGIN

template<typename G>
class LCA {
private:
  int n;
  int l;
  std::vector<std::vector<int>> P;
  std::vector<int> D;
  void dfs(const G &g, int v, int p, int d) {
    P[0][v] = p;
    D[v] = d;
    for (auto &to : g[v]) {
      if (to != p) dfs(g, to, v, d + 1);
    }
  }
public:
  LCA(const G &g):
    n(g.size()),
    l(log2(n) + 1),
    P(l, std::vector<int>(n)),
    D(n)
  {
    dfs(g, 0, -1, 0);
    for (int k = 0; k + 1 < l; ++k) {
      for (int v = 0; v < g.size(); ++v) {
        if (P[k][v] < 0)
          P[k + 1][v] = -1;
        else
          P[k + 1][v] = P[k][P[k][v]];
      }
    }
  }
  int query(int u, int v) {
    if (D[u] > D[v]) std::swap(u, v);
    for (int k = 0; k < l; ++k) {
      if ((D[v] - D[u]) >> k & 1) {
        v = P[k][v];
      }
    }
    if (u == v) return u;
    for (int k = l - 1; k >= 0; --k) {
      if (P[k][u] != P[k][v]) {
        u = P[k][u];
        v = P[k][v];
      }
    }
    return P[0][u];
  }
};

// END
