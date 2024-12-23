
void create_M(int T_mat[Y][Z], int perm[Z]) {
	int v;
	for (int c = 0; c < Z; c++) {
		v = perm[c];
		for (int r = 0; r < Y; r++) {
			T_mat[r][c] = v / val[r];
			v -= T_mat[r][c] * val[r];
		}
	}
}

void create_T_set(int T[X], int T_mat[Y][Z], int r ) {
	int T_count = 0;
	for (int i = 0; i < Z && T_count < X; i++ )
		if (T_mat[r][i]) T[T_count++] = i;
}
void test_inverse(int f[Y*Y], int g[Y*Y]) {
	for (int i = 0; i < Y*Y; i++) if (f[g[i]] != i) {printf("\nnot inverses !!!\n");exit(0);}

}
void create_comp(int T[X], int TC[X]) {
	int flag = 0;
	int TC_count = 0;
	for (int i = 0; i < Z && TC_count < X; i++) {
		flag = 0;
		for (int j = 0; j < X; j++) if (T[j] == i) flag = 1;
		if (flag == 0) TC[TC_count++] = i;
	}
}

void create_S_set(int S[X]) {
	int p[Z];
	create_perm(p, Z);
	for (int i = 0; i < X; i++) S[i] = p[i];
}

void create_chi(int U[X], int chi[Z]) {
	for (int i = 0; i < Z; i++) chi[i] = 0;
	for (int i = 0; i < X; i++) chi[U[i]] = 1;
}

void disjoint(int T[X], int S[X]) {
	int m[Z] = {0};
	for (int i = 0; i < X; i++) m[S[i]] += 1;
	for (int i = 0; i < X; i++) m[T[i]] += 1;
	for (int i = 0; i < Z; i++) if (m[i] > 1) printf("overlap at %d\n", i);
}

int vec_equal(int* v, int* u , int L) {
	for (int i = 0; i < L; i++) if (v[i] != u[i]) return 0;
	return 1;
}

void create_Q(int q[Y*Y], int Q[Y*Y][Y]) {
	for (int i = 0; i < Y*Y; i++) write_x_bin(q[i], Q[i]);
}

void create_P(int q[Y*Y], int B[Y*Y][Z], int P[Y*Y][Z]) {
	for (int r = 0; r < Y*Y; r++ )
		for (int c = 0;   c < Z; c++ )
			P[q[r]][c] = B[r][c];
}


