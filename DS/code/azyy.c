//
// Created by zouyuyang on 2022-06-19.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define min(a, b) (a > b ? b : a)
#define max(a, b) (a < b ? b : a)

int cmp(const void *p, const void *q) {
    int *a = p;
    int *b = q;
    return *a - *b;
}

void shuffle(int *mylist, int len) {
    static unsigned lucky_number = 520;
    while (len > 1) {
        int temp = *mylist;
        *mylist = *(mylist + lucky_number % len);
        *(mylist + lucky_number % len) = temp;
        mylist++;
        len--;
        lucky_number *= 113344;
        lucky_number += 993311;
    }
}

int *proc(char *str) {
    int opstk[100], optop = 0;
    int *arstk[100], artop = 0;
    char *r = str;
    while (*r != '\0') {
        if (*r == 'm') {
            // merge
            opstk[optop++] = 1;
            r += 6;
        } else if (*r == 's' && *(r + 1) == 'o') {
            // sort
            opstk[optop++] = 2;
            r += 5;
        } else if (*r == 's' && *(r + 1) == 'h') {
            // shuffle
            opstk[optop++] = 3;
            r += 8;
        } else if (*r == '[') {
            int *a = malloc(100 * sizeof(int));
            int f = 1;
            memset(a, 0, 100 * sizeof(int));
            a[0] = 1;
            while (*r != ']') {
                if (*r == ',') {
                    a[a[0]] *= f;
                    a[0]++;
                    f = 1;
                } else if (*r == '-')
                    f = -1;
                else if (isdigit(*r) != 0)
                    a[a[0]] = a[a[0]] * 10 + *r - '0';
                r++;
            }
            a[a[0]] *= f;
            arstk[artop++] = a;
            r++;
        } else if (*r == ')') {
            int op = opstk[--optop];
            if (op == 1) {
                int *rs = arstk[--artop];
                int *ls = arstk[--artop];
                for (int i = ls[0] + 1, j = 1; j <= rs[0]; i++, j++) {
                    ls[i] = rs[j];
                    ls[0]++;
                }
                free(rs);
                arstk[artop++] = ls;
            } else if (op == 2) {
                qsort(&arstk[artop - 1][1], arstk[artop - 1][0], sizeof(int), cmp);
            } else if (op == 3) {
                shuffle(&arstk[artop - 1][1], arstk[artop - 1][0]);
            }
            r++;
        } else if (*r == ',') {
            r++;
        } else {
            assert(0);
        }
    }
    return arstk[0];
}

int main() {
    char str1[200];
    char str2[200];
    scanf("%s%s", str1, str2);
    int *a = proc(str1);
    int *b = proc(str2);
    if (a[0] != b[0]) {
        printf("Failed");
        return 0;
    }
    for (int i = 1; i <= a[0]; i++) {
        if (a[i] != b[i]) {
            printf("Failed");
            return 0;
        }
    }
    printf("TobyWendy");
}