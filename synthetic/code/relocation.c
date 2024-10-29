int g1 __attribute__((section("sec")));
int g2 __attribute__((section("sec")));
static volatile int l1 __attribute__((section("sec")));
static volatile int l2 __attribute__((section("sec")));
int test() {
  return g1 + g2 + l1 + l2;
}
