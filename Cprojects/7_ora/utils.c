void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int *bigger(int *a, int *b) {
	if ( *a > *b) {
		return a;
	}
	return b;
}
