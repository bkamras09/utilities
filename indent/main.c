/* OVERVIEW: indents an incoming text stream and puts the resulting text stream back into the same place it was in the source file. */

#include <stdio.h>
#include <string.h>

#define MAX		1000

char * get_input(char *input);
char * indent(char *input, char *output);

int main (void) {
	char input[MAX];
	char output[MAX];
	printf("Formatting incoming text stream\n");
	get_input(input);
	indent(input, output);
	printf("output: ", "%s", output, "\n");
}

/* get input from stdin and return a pointer to the input array */
char * get_input(char *s) {
	int c;
	char *ps = s;
	for (; *ps < MAX - 1 && (c = getchar()) != EOF; ps++)
		*ps = c;
	*ps = '\0';
	return s;
}

char * indent(char *in, char *out) {
	char *inp = in;
	char *outp = out;
	printf("in: %s", in);
	while (*inp < strlen(in)) {
		if (*inp != '\n') {
			*outp = *inp;
			outp++, inp++;
		} else {
			*outp = '\t';
			outp++, inp++;
		}
	}
	return out;
}