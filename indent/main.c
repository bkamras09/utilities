/* OVERVIEW: indents an incoming text stream and puts the resulting text stream back into the same place it was in the source file. */

#include <stdio.h>
#include <string.h>

#define MAX		1000 /* maximum allowed array length to indent */

char * get_input(char *input);
char * scan_input(char *input);
char * indent(char *input, char *output);

int main (void) {
	char input[MAX];
	char output[MAX];
	get_input(input);
	indent(input, output);
	printf("output:\n%s\n", output);
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

char * scan_input(char *s){
}

char * indent(char *in, char *out) {
	char *inp = in;
	char *outp = out;

	for (; *inp != '\0'; outp++, inp++){
		if (*inp != '\n'){
			*outp = *inp;
		} else {
			*outp++ = *inp;
			*outp = '\t';
		}
	}
	return out;
}