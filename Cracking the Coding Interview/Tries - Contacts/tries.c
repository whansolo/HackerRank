#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node{
    int index;
    struct node* child[26];
}node;

node *getNode(){
    node *n = (node *)malloc(sizeof(node));
    n->index = 0;
    for(int i = 0; i < 26; i++)
        n->child[i] = NULL;
    return n;
}

void insert(node *root, char* str){
    for(int i = 0; i < strlen(str); i++){
        int c = str[i] - 'a';
        if(root->child[c] == NULL){
            root->child[c] = getNode();
        }
        root = root->child[c];
        root->index += 1;
    }
}

int main(){
    int n;
    node *root = getNode();

    scanf("%d",&n);
    for(int a0 = 0; a0 < n; a0++){
        char* op = (char *)malloc(10 * sizeof(char));
        char* contact = (char *)malloc(1000 * sizeof(char));
        scanf("%s %s",op,contact);

        node *tmp = root;
        if(strcmp(op, "add") == 0){
            insert(tmp, contact);
        }
        else if(strcmp(op, "find") == 0){
            int no = 0;
            for(int i = 0; i < strlen(contact); i++)
            {
                if(tmp->child[contact[i] - 'a'] == NULL)
                {
                    printf("0\n");
                    no = 1;
                    break;
                }
                tmp = tmp->child[contact[i] - 'a'];
            }
            if(no)
            {
                continue;
            }
            printf("%d\n", tmp->index);
        }

    }
    return 0;
}
