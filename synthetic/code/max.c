int g1 __attribute__((section("sec")));
int g2 __attribute__((section("sec")));

int max() {
    if (g1 > g2) {
        return g1;
    } else {
        return g2;
    }
}
