static volatile int l1 __attribute__((section("sec")));
static volatile int l2 __attribute__((section("sec")));
int test(int a, int b) {
  return l1 + l2;
}
