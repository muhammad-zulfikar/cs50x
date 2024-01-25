void meow(int n) {
    int i = 0;
    while (i < n) {
        printf("meow\n");
        i++;
    }
}

void star(int n) {
    for (int i = 0; i < n; i++) {
        printf("**********-----------\n");
    }
}

void strip(int n) {
    for (int i = 0; i < n; i++) {
        printf("---------------------\n");
    }
}
