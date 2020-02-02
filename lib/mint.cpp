#include <iostream>

// BEGIN

template <int M>
class ModInt {
private:
  int v;
public:
  ModInt() : v(0) {}
  ModInt(const int &x) : v((x % M + M) % M) {}
  ModInt(const ModInt &m) : v(m.v) {}
  ModInt &operator=(const int &n) { v = (n % M + M) % M; return *this; }
  operator int() const { return v; }
  ModInt &operator+=(const ModInt &o) { v += o.v; if (v >= M) v -= M; return *this; }
  ModInt &operator-=(const ModInt &o) { v -= o.v; if (v < 0) v += M; return *this; }
  ModInt &operator*=(const ModInt &o) { v = v * o.v % M; return *this; }
  friend std::istream &operator>>(std::istream &is, ModInt &m) { int n; is >> n; m = n; return is; }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &m) { return os << m.v; }
  friend ModInt operator+(ModInt m, const ModInt &n) { return m += n; }
  friend ModInt operator-(ModInt m, const ModInt &n) { return m -= n; }
  friend ModInt operator*(ModInt m, const ModInt &n) { return m *= n; }
};

using mint = ModInt<1000000007>;

// END
