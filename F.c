int index(int* f, int k, int l) {
    for (int i = 0; i < l; i++)
        if (f[i] == k ) return i;
    return -1;
}
void invert(int* f, int* g, int l) {
    for (int i = 0; i < l; i++) g[i] = index(f, i, l);
}

void create_F( int T[X],int TC[X],int S[X],int SC[X], int F[Z] ) {
    int T_to_S[X] = {0};
    int TC_to_SC[X] = {0};
    create_perm(T_to_S, X);
    create_perm(TC_to_SC, X);
    for (int i = 0; i < X; i++) F[T[i]] = S[T_to_S[i]];
    for (int i = 0; i < X; i++) F[TC[i]] = SC[T_to_S[i]];
}

void enc_F(int F[Y][Z], int x, int y[Y]) {
    for (int i = 0; i < Y; i++) y[i] = F[i][x];
}
void enc_G(int G[A][Y][Z], int x[Y], int y[A][Y]) {
    for (int r = 0; r < A; r++)
        for (int c = 0; c < Y; c++) y[r][c] = G[r][c][x[r]];
}





void create_B(int F[Y][Z], int B[Y*Y][Z]) {
    int x,y[Y], x_bin[Y], y_bin[Y*Y];
    for (x = 0; x < Z; x++) {
        enc_F( F , x , y);
        write_x_bin(x, x_bin);
        write_y_bin(y, y_bin);
        for (int r = 0; r < Y*Y; r++) B[r][x] = y_bin[r];
    }

}

void enc_B(int B[Y*Y][Z], int x_bin[Y], int y_bin[Y*Y]) {
    int c = 0;
    for (int i = 0 ; i < Y; i++) c += val[i]*x_bin[i];
    for (int i = 0 ; i < Y*Y; i++) y_bin[i] = B[i][c];
}
int dec_F(int chi_S[Y][Z], int M[Y][Z],  int y[Y] ) {
    int code[Y];int fail_flag;
    for (int i = 0 ; i < A; i++) code[i] =  chi_S[i][y[i]];
    for (int c = 0; c < Z; c++) {
        fail_flag = 0;
	    for (int r = 0; r < Y; r++) if ( code[r] != M[r][c] ) fail_flag = 1;
        if (fail_flag == 0) return c;
	}
    printf("\n\ncould not invert\n\n");
    return -1;
}
void dec_G(int chi_S[A][Y][Z], int M[A][Y][Z],  int y[A][Y], int d[Y] ) {
    for (int a = 0; a < A; a++) d[a] = dec_F(chi_S[a], M[a], y[a]);
}
void dec_B(int chi_S[X][Z], int M[Y][Z], int y_bin[Y*Y], int d_bin[Y]) {
    int code[Y];int fail_flag = 1;
    //for (int i = 0; i < Y; i++) y[i] = int_val(&y_bin[i*Y]);
    for (int i = 0 ; i < Y; i++) code[i] =  chi_S[i][int_val(&y_bin[i*Y])];
    for (int c = 0; c < Z; c++) {
        fail_flag = 0;
	    for (int r = 0; r < Y; r++) if ( code[r] != M[r][c] ) fail_flag = 1;
        if (fail_flag == 0) {write_x_bin(c, d_bin);return;}
	}
    printf("\n\ncould not invert\n\n");exit(0);

}
void dec_P(int chi_S[X][Z], int M[Y][Z], int f[Y*Y], int y_bin[Y*Y], int d_bin[Y]) {
    int code[Y];int fail_flag = 1;int z_bin[Y*Y] = {0};
    for (int i = 0; i < Y*Y; i++) z_bin[i] = y_bin[i];
    permute_bits(f, z_bin);
    for (int i = 0 ; i < Y; i++) code[i] =  chi_S[i][int_val(&z_bin[i*Y])];
    for (int c = 0; c < Z; c++) {
        fail_flag = 0;
	    for (int r = 0; r < Y; r++) if ( code[r] != M[r][c] ) fail_flag = 1;
        if (fail_flag == 0) {write_x_bin(c, d_bin);return;}
	}
    //printf("\n\ncould not invert\n\n");exit(0);

}