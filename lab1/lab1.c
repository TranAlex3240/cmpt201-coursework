#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize(char text[], const char delim[]) {
  char *saveptr = NULL;
  char *token = strtok_r(text, delim, &saveptr);
  while (token != NULL) {
    printf("%s\n", token);
    token = strtok_r(NULL, delim, &saveptr);
  }
}

char *get_input() {
  char *lineptr = NULL;
  size_t n = 0;
  printf("Enter in some text: ");
  ssize_t read_bytes = getline(&lineptr, &n, stdin);
  if (read_bytes == -1) {
    perror("getline ran into an error.");
    exit(EXIT_FAILURE);
    free(lineptr);
  }
  return lineptr;
}

int main() {
  while (1) {
    char *lineptr = get_input();
    char text[strlen(lineptr) + 1];
    strcpy(text, lineptr);
    tokenize(text, " ");
    free(lineptr);
  }
  return 0;
}
