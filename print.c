void print_bit(int b) { b == 0 ? printf("O") : printf("|"); }
void print_v(int* v, int L) { for (int i = 0; i < L; i++) print_bit(v[i]); }
// void print_key(int k[pk_rows][pk_cols]) {
//     for (int i = 0; i < pk_rows; i++)  { print_v(k[i], pk_cols); printf("\n"); }
// }
void print_M(int k[Y][Z]) {
    for (int i = 0; i < Y; i++)  { print_v(k[i], Z); printf("\n"); }
}
void print_Q(int k[Y*Y][Y]) {
    for (int i = 0; i < Y*Y; i++)  { print_v(k[i], Y); printf("\n"); }
}
void print_perm(int* p, int L) {
    for (int i = 0; i < L; i++) printf("%03d ", p[i]);
}
void print_F(int F[Z]) {
    for (int i = 0 ; i < Z; i++)
        printf("F(%03d) = %03d\n", i, F[i]);
}
void print_enc(int x, int y[Y]) {
    printf("  f %03d  =  ", x);
    for (int i = 0 ; i < Y; i++) printf("%03d ", y[i]);
    printf("\n");
}
void print_enc_bin(int* x_bin, int* y_bin) {
    printf("  f "); print_v(x_bin, Y);printf("  =  ");
    print_v(y_bin, Y*Y);//printf("\n");
}
void print_dec_bin(int* d_bin, int* y_bin) {
    printf("  g "); print_v(y_bin, Y*Y);printf("  =  ");
    print_v(d_bin, Y);printf("\n");
}
void print_chi(int chi[Z]) {
    for (int i = 0; i < Z; i++) {
        if (i >0 && i % 64 == 0 ) printf("\n");
        print_bit(chi[i]);
    }
    printf("\n\n");
}

void print_chi_code(int chi[Y][Z], int y[Y]) {
    for (int i = 0; i < Y; i++ ) print_bit(chi[i][y[i]]);
    //printf("\n");
}
void val_print(int* v, int L) {
    for (int i = 0; i < L; i++) printf("%d ", v[i]);
    printf("\n");

}
void print_B(int B[Y*Y][Z]) {
    for (int i = 0; i < Y*Y; i++)  { print_v(B[i], Z); printf("\n"); }
}

void print_G_enc(int x[A], int y[A][Y],int d[A]) {
    printf("f ");
    for (int i = 0; i < A; i++) printf("%03d ", x[i] );
    printf("\n\n");
    for (int i = 0; i < A; i++) {
        printf("  ");
        for (int j = 0; j < Y; j++) printf("%03d ", y[i][j] );
        printf("\n");
    }
    printf("\nd ");
    for (int i = 0; i < A; i++) printf("%03d ", d[i] );
    printf("\n\n");
    printf("\n\n");
}
void print_G_enc_bin(int x[A], int y[A][Y], int d[A]) {
    int x_bin[Y*Y];
    int y_bin[Y*Y];
    printf("f ");
    write_y_bin(x, x_bin);
    print_v(x_bin, Y*Y);
    printf("\n\n");
    for (int i = 0; i < A; i++) {
        write_y_bin(y[i], y_bin);
        printf("  ");
        print_v(y_bin, Y*Y);
        printf("\n");
    }
    printf("\nd ");
    write_y_bin(d, x_bin);
    print_v(x_bin, Y*Y);
    printf("\n\n");
    printf("\n\n");
}



