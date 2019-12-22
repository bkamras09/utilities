#include <stdio.h>
#include <string.h>

#define MAX 10000
#define ML  1000

void getlines(char *s, char *lineptr[]);
void head(char *s);

char *lineptr[ML];

int main(int argc, char *argv[]) {
  char input[MAX];
  getlines(input, *lineptr);
  printf("%s", input);
  return 0;
}

void getlines(char *s, char *lineptr[]) {
  int c;
  char *ps = s;
  for (; *ps < MAX-1 && (c = getchar()) != EOF && c != '\n'; ps++)
	 *ps = c;
  *ps = '\0';
}

void head(char *s) {
}
