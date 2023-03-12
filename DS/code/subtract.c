#include<stdio.h>
#include<string.h>

int cmp(char a[], char b[]) {
	int na = strlen(a);
	int nb = strlen(b);
	if (na > nb) return 1;
	if (na < nb) return -1;
	if (na == nb) {
		for (int i = 0; i < na; i++) {
			if (a[i] > b[i]) return 1;
			if (a[i] < b[i]) return -1;
			if (a[i] == b[i]) continue;
		}
		return 0;
	}
	return 0;
}


int main() {
	char a[85] = {0};
	char b[85] = {0};
	char c[85] = {0};
	scanf("%s\n%s", a, b);
	
	int na = strlen(a);
	int nb = strlen(b);
	int za = 0, zb = 0;
	
	while (a[za] == '0') za++;
	for (int i = za; i < na; i++) {
		a[i - za] = a[i];
	}
	a[na - za] = '\0';
	
	while (b[zb] == '0') zb++;
	for (int i = zb; i < nb; i++) {
		b[i - zb] = b[i];
	}
	b[nb - zb] = '\0';
	
	na = strlen(a);
	nb = strlen(b);
	int p = cmp(a, b);
	if (p == 0) {
		printf("0");
		return 0;
	} else if (p == -1) {
		printf("-");
	} else {
		strcpy(c, a);
		memset(a, 0, sizeof(a));
		strcpy(a, b);
		memset(b, 0, sizeof(b));
		strcpy(b, c);
		int k = nb;
		nb = na;
		na = k;
	}
	for (int i = nb - 1; i >= nb - na; i--) {
		if (b[i] < '0') {
			b[i] = b[i] + 10;
			b[i - 1]--;
		}
		if (b[i] - a[i - nb + na] >= 0) {
			b[i] -= a[i - nb + na];
		} else {
			b[i] = b[i] - a[i - nb + na] + 10;
			int k = 0;
			while (b[i - 1 - k] == '0') {
				b[i - 1 - k] = '9';
				k++;
			}
			b[i - 1 - k]--;
		}
		b[i] += '0';
	}
	
	int j = 0;
	while (b[j] == '0') j++;
	for (int i = j; b[i] != '\0'; i++) {
		printf("%c", b[i]);
	}
	
	return 0;
}



