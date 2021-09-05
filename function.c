
void increment_me(int me, int amount) {
    // increment "me" by the "amount"
    me += amount;
    printf("  Inside increment_me: %d\n", me);
}

void increment_me_too(int* me, int amount) {

    *me = *me + amount;
    printf("  Inside increment_me: %d\n", *me);
}