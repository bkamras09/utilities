/* OVERVIEW: indents an incoming text stream and puts the resulting text stream back into the same place it was in the source file. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* #include <X11/Xlib.h> */

#define MAX		100 /* maximum allowed array length to indent */

char * get_input(char *input);
char * scan_input(char *input);
char * indent(char *input, char *output);
char * outdent(char *input, char *output);

int main (int argc, char *argv[]){
	FILE *fp;
	void filecopy(FILE *, FILE *);

	if (argc == 1)
		filecopy(stdin, stdout);
	else{
		while(--argc > 0){
			if((fp = fopen *++argv, "r")) == NULL){
				printf("ted: can\'t open %s", *argv);
				return 1;
			} else{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}

void filecopy(FILE *ifp, FILE *ofp){
	int c;
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
}

/* get input from stdin and return a pointer to the input array */
char * get_input(char *s) {
	unsigned long int c;
	char *ps = s;

	for (; *ps < MAX - 1 && (c = getchar()) != EOF; ps++)
		*ps = c;
	*ps = '\0';
	return s;
}

/* TODO: make indent increment by length of each array element */
char * indent(char *in, char *out) {
	char *inp = in;
	char *outp = out;

	*outp = '\t';
	outp++;
	for (; *inp != '\0'; outp++, inp++){
		if (*inp != '\n'){
			*outp = *inp;
		} else {
			*outp = *inp;
			outp++;
			*outp = '\t';
		}
	}
	return out;
}

/* TODO: make outdent increment by length of each array element */
/* TODO: make outdent only remove \t after a \n */
char * outdent(char *in, char *out){
	char *inp = in;
	char *outp = out;

	for (; *inp != '\0'; outp++, inp++){
		if (*inp != '\t' && inp-- && *inp == '\n'){
			inp++;
			*outp = *inp;
		} else {
			inp++;
			*outp = *inp;
		}
	}
	return out;
}

/* random function from 4chan that I need to test */
/*
char *indent(char *in)
{
    char *out, *q, *p, *p1;
    size_t c = 0;
    for (p = in; (p = strstr(p, "\n")); p++) c++;
    out = malloc(strlen(in) - 1 * c + 2 * c + 2);
    q = out; memcpy(q, "\t", 1); q++;
    for (p = in; (p = strstr(p1 = p, "\n")); p++) {
        memcpy(q, p1, p - p1); q += p - p1;
        memcpy(q, "\n\t", 2); q += 2;
    }
    memcpy(q, p1, strlen(p1) + 1);
    return out;
}
*/