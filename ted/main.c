/* OVERVIEW: indents an incoming text stream and puts the resulting text stream back into the same place it was in the source file. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/* #include <X11/Xlib.h> */

#define MAX		1000 /* maximum allowed array length to indent */
#define LENGTH	255 /* maximum allowed file name length */
#define IN 2
#define OUT 3
#define NS from[i] != '\0'

char * get_input(char *input);
char * scan_input(char *input);
char * indent(char *input, char *output);
char * outdent(char *input, char *output);
void uncom(char to[], char from[]);
void filecopy(FILE *ifp, FILE *ofp);

int main (int argc, char *argv[]){
	FILE *input_file;
	char input[MAX];
	if (argc > 1){
		printf("Welcome to ted, the tiny text editor.\n");
		if (access(argv[1], F_OK) != -1){
			printf("File exists.  Opening it now...\n");
			input_file = fopen(argv[1], "r+");
		} else {
			printf("File does not exist.  Creating it now...\n");
			input_file = fopen(argv[1], "w+");
		}
	} else{
		printf("usage: ted filename\n");
		return 0;
	}
	int c;
    while ((c = getc(input_file)) != EOF){
        putchar(c);
	}
	get_input(input);
	fputs(input, input_file);
    fclose(input_file);
	return 0;
}

/* get input from stdin and return a pointer to the input array */
char * get_input(char *s) {
	unsigned int c;
	char *ps = s;

	for (; strlen(s) < MAX - 1 && (c = getchar()) != EOF; ps++)
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