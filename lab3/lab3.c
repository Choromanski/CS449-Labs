#include <stdio.h>
#include <stdlib.h>

struct Node{
	int grade;
	struct Node *next;
};

int main(int argc, char **argv){
	struct Node *root;
	struct Node *new;
	int score = 0;
	root = (struct Node*)malloc(sizeof(struct Node));
	root->grade = -1;
	printf("Enter first grade, or \"-1\" to exit: ");
	scanf("%i", &score);
	while(score != -1){
		if(root->grade == -1){
			root->grade = score;
			root->next = NULL;
			printf("Enter next grade, or \"-1\" to exit: ");
			scanf("%i", &score);
			continue;
		}
		new = root;
		while(new->next != NULL){
			new = new->next;
		}
		new->next = malloc(sizeof(struct Node));
		new = new->next;
		new->next = NULL;
		new->grade = score;
		printf("Enter next grade, or \"-1\" to exit: ");
		scanf("%i", &score);
	}
	//Calculate Average
	int count = 0;
	score = 0;
	new = root;
	while(new->next != NULL){
		score += new->grade;
		count++;
		new = new->next;
	}
	score += new->grade;
	count++;
	printf("average = %f\n", (double)score/count);

	//Free up space
	while(root->next != NULL){
		new = root->next;
		free(root);
		root = new;
	}
	free(root);
}	
