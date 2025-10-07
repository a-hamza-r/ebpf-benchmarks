int x1 __attribute__((section("sec")));
int x2 __attribute__((section("sec")));
static volatile int y1 __attribute__((section("sec")));
static volatile int y2 __attribute__((section("sec")));
int test_mul() {
    return x1 * x2 + y1 * y2;
}
