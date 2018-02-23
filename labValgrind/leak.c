#include <stdio.h>
#include <stdlib.h>

typedef
   struct _Node {
      struct _Node *l;
      struct _Node *r;
   } Node;

Node* mk(void)
{
   Node *x = malloc(sizeof(Node));
   x->l = NULL;
   x->r = NULL;
   return x;
}

void kill(Node *n){
	if (n->l != NULL){
		kill(n->l);
	}
	if (n->r != NULL){
		kill(n->r);
	}
	free(n);
}

Node* t;

void f(void)
{
   t       = mk();   // A
   t->l    = mk();   // B
   t->r    = mk();   // C
   t->l->l = mk();   // D
   t->l->r = mk();   // E
   t->r->l = mk();   // F
   t->r->r = mk();   // G

	kill(t->l->l);
	t->l->l = NULL;
	kill(t->r);
	t->r = NULL;
}

int main(void)
{
   f();
   kill(t);
   return 0;
}

