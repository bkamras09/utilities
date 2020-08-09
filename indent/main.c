/* OVERVIEW: indents an incoming text stream and puts the resulting text stream back into the same place it was in the source file. */

#include <stdio.h>
#include <string.h>

#define MAX		1000

void get_input(char *in);
void indent(char *in);

int main (void) {
	char input[MAX];
	printf("Formatting incoming text stream\n");
	get_input(input);
	/*indent(input); */
	printf("%c\n", input);
}

void get_input(char *s) {
	int c;
	char *ps = s;
	for (; *ps < MAX-1 && (c = getchar()) != EOF; ps++) {
	 *ps = c;
	}
	*ps = '\0';
}

void indent(char *in) {
	char *inp = in;
	char out[MAX - 1];
	char *outp = out;
	for (char *inp = in; *inp < strlen(in); inp++) {
		if (*inp != '\n') {
			*outp = *inp;
			printf("out", "%c\n", out);
			outp++;
		} else {
			*outp = '\t';
			outp++;
		}
	}
}