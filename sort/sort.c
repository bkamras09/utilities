#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int getlines(char *s) 
int readlines( char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int stringcmp(char *s, char *t);

void qsorts(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;

  if (argc > 1 && stringcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsorts((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : stringcmp));
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

int getlines(char *s) {
	int c, i;
	char *ps = s;
	for (; *ps< MAX-1 && (c = getchar()) != EOF; *ps++)
		*ps = c;
	*ps = '\0';
	return ;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getlines(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/* qsort: sort left to right in increasing order */
void qsorts(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right) /* do nothing if array contains fewer than two elements */
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsorts(v, left, last-1, comp);
  qsorts(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 < v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* strcmp: returns <0 if s<t, 0 if s == t, >0 if s > t */
int stringcmp(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
