// Rolling Hash (mod = 2 ^ 61 - 1)
// https://ei1333.github.io/luzhiled/snippets/string/rolling-hash.html
// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3897836#1

#include <vector>
#include <string>
#include <algorithm>

// BEGIN

class RollingHash {
private:
  using ull = unsigned long long;
  const ull mod = (1ULL << 61) - 1;
  std::vector<ull> hashed, power;
  inline ull add(ull a, ull b) const {
    ull ret = a + b;
    if (ret >= mod) ret -= mod;
    return ret;
  }
  inline ull sub(ull a, ull b) const {
    ull ret = a + mod - b;
    if (ret >= mod) ret -= mod;
    return ret;
  }
  inline ull mul(ull a, ull b) const {
    ull ah = a >> 31,
        al = a & ((1ULL << 31) - 1),
        bh = b >> 31,
        bl = b & ((1ULL << 31) - 1),
        m = ah * bl + al * bh,
        v = (ah * bh << 1) + (m >> 30) + ((m & ((1ULL << 30) - 1)) << 31) + al * bl;
    v = (v & ((1ULL << 61) - 1)) + (v >> 61);
    v = (v & ((1ULL << 61) - 1)) + (v >> 61);
    return v;
  }
public:
  RollingHash(const std::string &s, unsigned base = 10007) {
    size_t sz = s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for (int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = add(mul(hashed[i], base), s[i]);
    }
  }
  ull get(size_t l, size_t r) const {
    return sub(hashed[r], mul(hashed[l], power[r - l]));
  }
  ull connect(ull h1, int h2, size_t h2len) const {
    return add(mul(h1, power[h2len]), h2);
  }
  int LCP(const RollingHash &b, size_t l1, size_t r1, size_t l2, size_t r2) {
    int len = std::min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) >> 1;
      if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return low;
  }
};

// END
