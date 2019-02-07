#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct DATA {
	char word[50];
	struct DATA *next;
};

typedef struct DATA data;
data *start = NULL;

data *gNode(void) {
	data *p = (data *)malloc(sizeof(data));
	if (p != NULL) return p;
	else puts("Not enough memory.");
}

int add(char *input) {
	if (start == NULL) {
		start = gNode();
		strcpy(start -> word, input);
		return 0;
	}
	data *now = start, *prev;
	while (now != NULL) {
		if (strcmp(now -> word, input) == 0) return 0;
		prev = now;
		now = now -> next;
	}
	now = gNode();
	strcpy(now -> word, input);
	prev -> next = now;
}

int load(void) {
	char fileName[50], str[100];
	printf("file name:");
	scanf("%s", fileName);
	FILE *fp = fopen(fileName, "r");
	if (fp == NULL) {
		puts("Cannot open file.");
		return 1;
	}
	while (fscanf(fp, "%s", str) > 0) {
		add(str);
	}
}

void display(void) {
	data *p = start;
	while (p != NULL) {
		printf("%s\n", p -> word);
		p = p -> next;
	}
}

int main() {
	load();
	display();
	return 0;
}