int x1 __attribute__((section("sec")));
static volatile int y1 __attribute__((section("sec")));
int test_shift() {
    return (x1 << 1) + y1;
}
