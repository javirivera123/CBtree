#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 	/* for malloc */
#include "tree.h"
#include <ctype.h>
#include <string.h>


char line[];


void userSelection(){
    int input;
    printf("What would you like to do?\n");
    printf("1: insert employee\n2: delete employee\n3: list employees\n4: to quit\n");
    scanf("%d", &input);
    switch (input){
        case 1 :
            /*
            FILE *file;
            size_t nread;

            file = fopen("file.txt", "r");
            if (file) {
                printf("entered\n");
                while ((nread = fread(line, 1, sizeof line, file)) > 0)
                    fwrite(line, 1, nread, stdout);
                printf("%s" , line);
                fclose(file);
            }*/


            strcpy(line,"woop woop");
            printf("entering 1st root insertion\n");
            root = insert(root, line);
            break;
        case 2 :
            delete();
            break;
        case 3 :
            /*list();*/
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

    /* struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(r));*/

    printf("has entered insert ..\n");
    if(r) {
        printf("inserting..\n");
        r = create(r, line);
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

    r = (struct node*) malloc(sizeof(struct tnode)); //allocates mem for new tree
    r->right = NULL;
    r->left = NULL;
    r->name = line;

    return r;
}
void delete(){

}

void list(){

}





