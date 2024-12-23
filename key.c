void create_key(int f[K][K]) {
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            f[i][j] =arc4random_uniform(B);
}