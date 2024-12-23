#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "text.c"
#include "bin.c"
#include "print.c"
#include "random.c"
#include "F.c"
#include "compute.c"



int main() {
    cls();
    int x[A];int d[A];int y[A][Y];
    int B[Y*Y][Z];
    int P[Y*Y][Z];
    int x_bin[Y];
    int d_bin[Y];
    int y_bin[Y*Y];
    int z_bin[Y*Y];
    
    int p[Z];
    int n[Z];
    int M[A][Y][Z] = {0};
    int T[Y][X];
    int TC[Y][X];
    int S[Y][X];
    int SC[Y][X];
    int F[Y][Z];
    int G[A][Y][Z];
    int chi_S[A][Y][Z];
    //int chi_T[Y][Z];
    int code[Y];
    int q[Y*Y];
    int q_inv[Y*Y];
    int Q[Y*Y][Y];
    int Q_inv[Y*Y][Y];
    for (int a = 0; a < A; a++) {
        create_perm(p, Z);
        create_M(M[a], p);
        for (int i = 0; i < Y; i++)  create_T_set(T[i], M[a], i);
        for (int i = 0; i < Y; i++)  create_comp(T[i], TC[i]);
        for (int i = 0; i < Y; i++)  disjoint(T[i],TC[i]);
        for (int i = 0; i < Y; i++)  create_S_set(S[i]);
        for (int i = 0; i < Y; i++)  create_comp(S[i], SC[i]);
        for (int i = 0; i < Y; i++)  disjoint(S[i],SC[i]);
        for (int i = 0; i < Y; i++)  create_chi(S[i], chi_S[a][i]);
        for (int i = 0; i < Y; i++)  create_F(T[i], TC[i], S[i], SC[i], G[a][i]);
    }
    
    for (int i = 0; i < Z; i++) {
        for (int k = 0; k < A; k++) x[k] = arc4random_uniform(256);
        enc_G( G, x, y);
        dec_G(chi_S, M, y, d);
        //print_G_enc_bin(x,y,d);
        //printf("\n\n");
        print_G_enc(x,y,d);
        printf("\n\n");
        //if (x != d) printf("DECODE ERROR");
        //print_enc(x,y);printf("\n");
        

    }
    


    
}
      