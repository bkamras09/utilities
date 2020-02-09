#include <stdio.h>

#define MAX 1024

void get(char *s);
int atoi(char *s);
unsigned long atol(char *s);

int main(int argc, char *argv[]) {
	char input[MAX];
	get(input);
	printf("Input string: %s\n", input);
	int in = atoi(input);
	printf("Output number (int): %d\n", in);
	return 0;
}

void get(char *s) {
	int c;
	char *ps = s;
	for (; *ps < MAX-1 && (c = getchar()) != EOF && c != '\n'; ps++)
	*ps = c;
	*ps = '\0';
}

int atoi(char *s) {
	int n = 0;
	int b = 10;
	for (; *s != '\0'; s++) {
        if (*s == '-') {
            n 
        }
		n = n * b + *s - '0';
		printf("n is now: %d\n", n);
    }
	return n;
}

unsigned long atol(char *s) {
	unsigned long n = 0;
	unsigned long b = 10;
	for (; *s != '\0'; s++)
		n = n * b + *s - '0';
	return n;
}
