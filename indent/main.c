/* OVERVIEW: indents an incoming text stream and puts the resulting text stream back into the same place it was in the source file. */

#include <stdio.h>

#define BUF		1024 /* max size allowed for the input stream */
#define MAX		1000

void get_input(char *s, char *line_pointer[]);
void indent(char *input);

int main (void){
	printf("Formatting incoming text stream\n");
}

void get_input(char *s, char *line_pointer[]) {
  int c;
  char *ps = s;
  for (; *ps < MAX-1 && (c = getchar()) != EOF && c != '\n'; ps++)
	 *ps = c;
  *ps = '\0';
}

void indent(char *input) {
	int i = 0;
}