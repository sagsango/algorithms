    lg[1] = 0;
    for (int i = 2; i < maxN; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
