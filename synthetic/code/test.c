__attribute__((noinline)) __attribute__((section("sec1")))
int gfunc(int a, int b) {
  return a * b;
}
static __attribute__((noinline)) __attribute__((section("sec1")))
int lfunc(int a, int b) {
  return a + b;
}
int global __attribute__((section("sec2"))) = 42;
static volatile int l1 __attribute__((section("sec2"))) = 16;
static volatile int l2 __attribute__((section("sec2"))) = 32;
int test(int a, int b) {
  return gfunc(a, b) +  lfunc(a, b) + global + l1 + l2;
}
