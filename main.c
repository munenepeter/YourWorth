#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUOTES 100

typedef struct {
    char quote[250];
    char author[100];
} Quote;

typedef struct {
    Quote quotes[MAX_QUOTES];  // static array; could also malloc dynamically
    size_t size;
} QuoteArray;

void add_quote(QuoteArray *arr, const char *author, const char *quote) {
  if (arr->size >= MAX_QUOTES) {
    fprintf(stderr, "Max quote limit reached.\n");
    return;
  }
  strncpy(arr->quotes[arr->size].author, author, sizeof(arr->quotes[arr->size].author) - 1);
  strncpy(arr->quotes[arr->size].quote, quote, sizeof(arr->quotes[arr->size].quote) - 1);
  arr->size++;
}

int main(void) {

  QuoteArray qoutesarr = { .size = 0 };

  add_quote(&qoutesarr, "Author 1", "quote 1");
  add_quote(&qoutesarr, "Author 2", "quote 2");
  add_quote(&qoutesarr, "Author 3", "quote 3");
  add_quote(&qoutesarr, "Author 4", "quote 4");
  add_quote(&qoutesarr, "Author 5", "quote 5");

  for (int i = 0; i < qoutesarr.size; i++) {
    printf("%s - %s\n", qoutesarr.quotes[i].author, qoutesarr.quotes[i].quote);
  }

  return 0;
}
