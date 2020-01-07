#include <cstdint>
#include <unistd.h>

// BEGIN

namespace io {
  using i64 = std::int64_t;
  constexpr int is = 1 << 17;
  char ib[is], *ip = ib + is, it;
  inline char getc() {
    if (ip == ib + is) { read(STDIN_FILENO, ib, is); ip = ib; }
    return *ip++;
  }
  inline i64 scan() {
    i64 r = 0;
    if (ip + 16 > ib + is) while ((it = getc()) & 16) r = r * 10 + it - '0';
    else while ((it = *ip++) & 16) r = r * 10 + it - '0';
    return r;
  }
  constexpr int os = 1 << 17;
  char ob[os], *op = ob, ot;
  inline void putc(const char c) {
    *op++ = c;
    if (op == ob + os) { write(STDOUT_FILENO, ob, os); op = ob; }
  }
  /* x shoud be greater than or equal to zero */
  inline void print(i64 x) {
    char d[20];
    int i = 0;
    while (true) {
      d[i] = x % 10 + 48;
      x /= 10;
      ++i;
      if (x <= 0) break;
    }
    while (i--) {
      putc(d[i]);
    }
  }
  inline void flush() {
    write(STDOUT_FILENO, ob, op - ob);
  }
}

// END
