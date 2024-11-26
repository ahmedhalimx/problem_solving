#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define GET_POSITION(c) ((c - 'a') + 1)

char *chposstr(char *s, int len) {
	int size = 0;
	char *r = calloc(len + len, sizeof(char));

	for (int i = 0; i < len; ++i) {
		int d = GET_POSITION(s[i]);
		if (d > 9) {
			r[size++] = '0' + (d % 10);
			d /= 10;
		}
		r[size++] = '0' + d;
	}
	r = realloc(r, (size + 1) * sizeof(char));
	r[size] = '\0';
	return r;
}

char *itos(int n) {
	char *rs = NULL;
	int ns = 0;

	for (int i = n; i != 0; i /= 10) ++ns;

	rs = calloc(ns + 1, sizeof(char));
	for (int i = n, j = ns - 1; i > 0; i /= 10, --j) {
		rs[j] = '0' + i % 10 ;
	}
	return rs;
}

size_t sumstrdig(char *s, int len) {
	size_t sum = 0;
	for (int i = 0; i < len; ++i) {
		sum += s[i] - '0';
	}
	return sum;
}


int getLucky(char* s, int k) {
	int len = strlen(s);
	char *cnvrt = chposstr(s, len);
	int clen = strlen(cnvrt);
	int result = sumstrdig(cnvrt, clen);
	
	--k;
	while (k > 0) {
		char *tr = itos(result);
		int tlen = strlen(tr);
		result = sumstrdig(tr, tlen);
		free(tr);
		--k;
	}
	free(cnvrt);
	return result;
}

int main() {
	char *s = "fleyctuuajsr"; int k = 5;
	
	int r = getLucky(s, k);
	printf("getLucky(%s, %d) => %d\n", s, k, r);
}
