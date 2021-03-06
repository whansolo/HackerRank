#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_ITEMS 30000

typedef struct Item {
    char *key;
    int quantity;
} Item;

int generateHash(char *key);

Item *search(char *key, Item **hashArray) {
    int index = generateHash(key);
    if (strcmp(hashArray[index]->key, key) == 0) {
        return hashArray[index];
    }
    else {
        // Move in the array until you find the item
        int looped = 0;
        while (strcmp(hashArray[index]->key, key) != 0) {
            ++index;

            // If we haven't looped wrap around
            if (!looped) {
                if (index == MAX_ITEMS) {
                    index %= MAX_ITEMS;
                    looped = 1;
                }
            }
            // If we have looped
            else {
                // And we reach the last element
                if (index == MAX_ITEMS - 1) break;
            }
        }
        if (strcmp(hashArray[index]->key, key) == 0)
            return hashArray[index];
        else
            return NULL;
    }
}

int generateHash(char *key) {
    unsigned long hash = 5381;
    int c;

    while ((c = *(key++)))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    // After this line, the hash has become an index
    int new_hash = (int)(hash % MAX_ITEMS);
    return new_hash;
}

void insert(char *key, Item **hashArray) {
    Item *item = malloc(sizeof(Item));
    assert(item != NULL);
    item->key = malloc(sizeof(char) * 6);
    strcpy(item->key, key);
    item->quantity = 1;

    int index = generateHash(key);

    // If the word has already been inserted into the array
    if (strcmp(hashArray[index]->key, key) == 0) {
        hashArray[index]->quantity+=1;
    }
    else {
    // Move in the array until you find an empty/deleted cell or the previous item
        while (hashArray[index]->key[0] != -1 && strcmp(hashArray[index]->key, key) != 0) {
            ++index;

            // Wrap around
            index %= MAX_ITEMS;
        }
    if (strcmp(hashArray[index]->key, key) == 0)
        hashArray[index]->quantity+=1;
    else
        hashArray[index] = item;
    }
}

Item **newHashArray() {
    Item *dummyItem = NULL;
    dummyItem = malloc(sizeof(Item));
    assert(dummyItem != NULL);
    dummyItem->key = malloc(sizeof(char) * 6);
    assert(dummyItem->key != NULL);
    memset(dummyItem->key, 0, sizeof(char) * 6);
    dummyItem->key[0] = 255;
    dummyItem->quantity = -1;

    Item **hashArray = malloc(sizeof(Item *) * MAX_ITEMS);
    assert(hashArray != NULL);
    for (int i = 0; i < MAX_ITEMS; i++) {
      	hashArray[i] = dummyItem;
    }
    return hashArray;
}

int main(){
  	int m;
  	int n;
    Item **hashArray = newHashArray();

    scanf("%d %d",&m,&n);
  	char* *magazine = malloc(sizeof(char*) * m);
  	for(int magazine_i = 0; magazine_i < m; magazine_i++){
  		  magazine[magazine_i] = (char *)malloc(10240 * sizeof(char));
  		  scanf("%s",magazine[magazine_i]);

  		  insert(magazine[magazine_i], hashArray);
  	}
  	char* *ransom = malloc(sizeof(char*) * n);
  	for(int ransom_i = 0; ransom_i < n; ransom_i++){
        ransom[ransom_i] = (char *)malloc(10240 * sizeof(char));
        scanf("%s",ransom[ransom_i]);

        Item *found_item = search(ransom[ransom_i], hashArray);
        if (found_item == NULL) {
            printf("No\n");
      			return 0;
        }
    		else found_item->quantity-=1;
    		if (found_item->quantity < 0) {
      			printf("No\n");
            return 0;
        }
    }

  	printf("Yes");

  	return 0;
}
