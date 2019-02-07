#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 100

struct DATA {
	char word[50];
	struct DATA *next;
};

typedef struct DATA data;
data hashTable[LEN];

int hash(char *s) {
	int len = strlen(s);
	int ret = s[0] * 101 + s[len - 1] * 103 + len * 107;
	return ret % LEN;
}

data *gNode(void) {
	data *p = (data *)malloc(sizeof(data));
	if (p != NULL) return p;
	else puts("Not enough memory.");
}

int insert(char *input) {
	int i = hash(input);
	data *p = &hashTable[i];
	if (strcmp(p -> word, "") == 0) {
		strcpy(p -> word, input);
	} else {
		data *new = gNode();
		p -> next = new;
		strcpy(new -> word, input);
	}
}

int load(void) {
	char fileName[50], str[100];
	printf("file name:");
	scanf("%s", fileName);
	FILE *fp = fopen(fileName, "r");
	while (fscanf(fp, "%s", str) != EOF) {
		insert(str);
	}
}

void display(void) {
	for (int i = 0; i < LEN; i++) {
		if (strcmp(hashTable[i].word, "") != 0) {
			data *p = &hashTable[i];
			while (p != NULL) {
				printf("%s ", p -> word);
				p = p -> next;
			}
			puts("");
		}
	}
}

int main() {
	load();
	display();
	return 0;
}