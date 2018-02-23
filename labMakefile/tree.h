#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "malloc.h"

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

void freetree(struct tree *root);
void randominsert(struct tree *head, struct tree *new);
void printtree(struct tree *head);

void test1();
int comp(const void *a, const void *b);
void test2();