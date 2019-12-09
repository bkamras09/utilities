/* Author: Brian Kamras
 * contact: bkamras09@gmail.com */
#include <stdio.h>

#define MAXLINE 1000
#define IN 2
#define OUT 3
#define NS from[i] != '\0'

int getinput(char s[], int maxline);
void uncom(char to[], char from[]);

int main(void)
{	
	char s[MAXLINE];
	char t[MAXLINE];
	
	printf("Commented input:\n");
	getinput(s, MAXLINE);
	uncom(t,s);
	printf("\nUncommented output:\n%s\n", t);

	return 0;
}

int getinput(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF; ++i)
		s[i] = c;
	s[i] = '\0';
	return i;	
}

void uncom(char to[], char from[])
{
	int state, i, j;
	state = OUT;
	i = j = 0;

	while (state == OUT && NS) {
		if (from[i] == '/') {
			to[j] = from[i];
			++i;
			++j;
			if (from[i] == '*') {
				++i;
				--j;
				state = IN;
				while (state == IN && NS) {
				if (from[i] == '*') {
					++i;
					if (from[i] == '/') {
						state = OUT;
						++i;
					}
					else
						++i;
				}
				else
					++i;
				}
			}
			else {
				to[j] = from[i];
				++i;
				++j;
			}
		}
		else {
			to[j] = from[i];
			++i;
			++j;
		}
	}
	to[j] = '\0';
}
