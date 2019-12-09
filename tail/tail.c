/* Author: David Davidson
 * email: daviddavidson@gmail.com
 * tail: print the last n lines of a file */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	MAX	1000
#define	DEF	10

int getlines(char *s);
char tail(char *s, int argc, char *argv[]);

int main(int argc, char *argv[]) {
	char s[MAX];
	getlines(s);
	tail(s, argc, argv);
	printf("\n");
	return 0;
}

int getlines(char *s) {
	int c, i;
	char *ps = s;
	for (; *ps< MAX-1 && (c = getchar()) != EOF; *ps++)
		*ps = c;
	*ps = '\0';
	return 0;
}

char tail(char *s, int argc, char *argv[]) {
	int i, n, nl;
	int k = 0;
	if (argc > 1)
		n = *argv[1] - '0';
	else
		n = DEF;

	for (i = strlen(s), nl = 0; i > 0; i--) {
		if (s[i] == '\n')
			++nl;
		if (nl == n)
			break;
	}
	for (k = i; k <= strlen(s); k++)
		printf("%c", s[k]);
}

