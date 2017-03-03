#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 	/* for malloc */
#include "tree.h"
#include <ctype.h>
#include <string.h>




char line[];

struct tnode *btAlloc(){
    printf("entered bt alloc...\n");

    struct tnode *t =  (struct tnode*) malloc(sizeof(struct tnode));
    t->left = t->right = NULL;
    t->name = NULL;
    t = NULL;
    return t;
}

void userSelection(){
    int input;
    printf("What would you like to do?\n");
    printf("1: insert employee\n2: delete employee\n3: list employees\n4: to quit\n");
    scanf("%d", &input);
    switch (input){
        case 1 :
           /*h4h55re/* strcpy(line,"woop woop");              /*testing insert*/
            printf("entering 1st root insertion\n");
            root = btAlloc();                     /*allocating memory for root*/
            root = insert(root,line);
            printf("has exited insert method\n");
            printf("%s",root->name);
            break;
        case 2 :
           /* employeeDelete();*/
            break;
        case 3 :
            list();
            break;
        case 4 :
            printf("Bye... \n ");
            break;
        default:
            printf("Incorrect input, try again: \n ");
            break;

    }

}



struct tnode* insert(struct tnode *r, char *line){

    printf("has entered insert ..\n");
    if(!r) {
        printf("inserting...\n");
        r = create(&r,line);
    }


    else if( (int)(line[0]) < (int)(r->name[0]) ){
        printf("goin down left\n");
        r->left = insert(r->left, line);
     }
        // else this will be in the right subtree
    else {
        printf("goin down right\n");
        r->right = insert(r->right, line);
    }
    return r;
}

struct tnode* create(struct tnode *r, char *line){

    printf("entered create..\n");
    printf("allocating mem for bst...\n");
    struct tnode *tree = malloc(sizeof(struct tnode));


    r->right = NULL;
    r->left = NULL;
    r->name = line;

    printf("returning tree\n");
    return r;
}


void list(struct tnode *r){
    if (!r){

    }

}





