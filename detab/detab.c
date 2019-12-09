/* Author : Brian Kamras
 * contact: bkamras09@gmail.com */

#include<stdio.h>

#define BUF		8192	/* initial array buffer */
#define	DEFTAB		4	/* default tab width */

void detab(char tab[], char space[], int argc, char *argv[]);
int getin(char tab[]);

int main(int argc, char *argv[])
{
	char tab[BUF];
	char space[BUF];

	getin(tab);
	detab(tab, space, argc, argv);
	printf("\n%s\n", space);
}

int getin(char tab[])
{
	int c, i;
	for (i = 0; i < BUF-1 && (c = getchar()) != EOF; ++i)
		tab[i] = c;
        tab[i] = '\0';
	return 0;
}
	
void detab(char tab[], char space[], int argc, char *argv[])
{
	int i, j, k;
	char width;

	if (argc > 1)
		width = *argv[1] - '0';
	else
		width = DEFTAB;
	for (i = k = 0; tab[i] != '\0'; ++i) {
		if (tab[i] == '\t') {
			for (j = 0; j <= width-1; j++)
				space[k++] = ' ';
		}
		else
			space[k++] = tab[i];
	space[k] = '\0';
	}
}
