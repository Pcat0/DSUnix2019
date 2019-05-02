#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define true 1
#define false 0




typedef struct hashTable *hashTable;
typedef struct htEntry *htEntry;

hashTable newHT(unsigned int length, unsigned int memSize);

void setHT(hashTable table, char *key, void *value);
void *getHT(hashTable table, char *key);
void removeHT(hashTable table, char *key);
void printHT(hashTable table);

int hashStr(char *str, int range);








struct htEntry {
	char *key;
	void *value;
	struct htEntry * link;
};

struct hashTable {
	unsigned int length;
	unsigned int memSize;
	htEntry *data;
};

int hashStr(char *str, int range) {
	int sum = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		sum += str[i] * (i + 1);
	}
	return sum % range;
}


hashTable newHT(unsigned int length, unsigned int memSize) {
	hashTable table = malloc(sizeof(struct hashTable));
	table->data = calloc(sizeof(htEntry), length);
	table->length = length;
	table->memSize = memSize;
	return table;
}



void printHT(hashTable table) {
	for (int i = 0; i < table->length; i++) {
		htEntry step = table->data[i];
		while (step != NULL) {
			printf("Hash: %d) Key: %s, Value: %d\n", i, step->key, *(int*)step->value);
			step = step->link;
		}
  	}
}

void setHT(hashTable table, char *_key, void *_value) {
	//PBR protection
	char *key = malloc(sizeof(char) * strlen(_key));
	strcpy(key, _key);
	void *value = malloc(table->memSize);
	memcpy(value, _value, table->memSize);


	int hash = hashStr(key, table->length);

	htEntry newEntry = malloc(sizeof(struct htEntry));;
	newEntry->key = key;
	newEntry->value = value;
	newEntry->link = NULL;

	if (table->data[hash] == NULL) {
		table->data[hash] = newEntry;
	} else {
		htEntry step = table->data[hash];
		while(true) {
			if (strcmp(step->key, key) == 0) {
				step->value = value;
				break;
			}
			if (step->link == NULL){
				step->link = newEntry;
				break;
			}
			step = step->link;
		};
	}
}

void removeHT(hashTable table, char *key) {
	int hash = hashStr(key, table->length);
	if(table->data[hash] != NULL) {
		if(strcmp(table->data[hash]->key, key) == 0) {
			table->data[hash] = table->data[hash]->link;
		} else {
			htEntry step = table->data[hash];
			while(step->link != NULL){
				if(strcmp(step->link->key, key) == 0) {
					step->link = step->link->link;
					break;
				}
				step = step->link;
			}
		}
	}
}
void *getHT(hashTable table, char *key) {
	int hash = hashStr(key, table->length);
	htEntry step = table->data[hash];
	while (step != NULL) {
		if(strcmp(step->key, key) == 0)
			return step->value;
		step = step->link;
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	hashTable ht = newHT(100, sizeof(int));

	setHT(ht, "aaa", &(int){1});
	setHT(ht, "aab", &(int){2});
	setHT(ht, "aac", &(int){3});
	setHT(ht, "aad", &(int){4});

	//example collision
	setHT(ht, "bbb", &(int){5});

	setHT(ht, "aaa", &(int){0});

	printHT(ht);

	void *a;
	a = getHT(ht, "bbb");
	if (a != NULL)
		printf("bbb: %d\n", *(int*)a);
	else
		printf("bbb is not in the table\n");

	a = getHT(ht, "ccc");
	if (a != NULL)
		printf("ccc: %d\n", *(int*)a);
	else
		printf("ccc is not in the table\n");

	printf("removing aac\n");
	removeHT(ht, "aac");
	printHT(ht);

	return 0;
}

