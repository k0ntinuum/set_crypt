void write_x_bin(int x, int* b) {
	for (int i = 0; i < Y; i++) {
		b[i] = x / val[i];
		x -= b[i] * val[i];
    }
}
void write_y_bin(int y[Y], int* b) {
    for (int i = 0; i < Y; i++) write_x_bin(y[i], &b[Y*i]);
}
int int_val(int* v) {
    int s = 0;
    for (int j = 0 ; j < Y; j++) s += val[j]*v[j];
    return s;
}

void permute_bits(int f[Y*Y], int bits[Y*Y]) {
    int temp[Y*Y] = {-1};
    for (int i = 0 ; i < Y*Y; i++) temp[f[i]] = bits[i];
    for (int i = 0 ; i < Y*Y; i++) bits[i] = temp[i];
}