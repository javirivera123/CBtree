#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>  /*http://stackoverflow.com/questions/1921539/using-boolean-values-in-c*/

char *line[1024];
char *empN[1024];
char *p;

struct tnode *btAlloc(){
    struct tnode *t =  (struct tnode*) malloc(sizeof(struct tnode));
    t->left = t->right = NULL;
    strcpy(t->name,line);
    return t;
}

void enterName(){
    printf("Please enter the name:");
    getchar();
    fgets(line, 1024, stdin);

    root = insert(root, line);
}

void userSelection() {

    int i = 0;
    int input;
    LOOP:
    if (i == 0) {
        printf("What would you like to do?\n");
        printf("1: insert employee\n2: delete employee\n3: list employees\n4: read file\n");
        printf("5: write to file\n6: quit\n");

        scanf("%d", &input);
        switch (input) {
            case 1 :
                enterName();
                printf("New employee has been inserted!...\n");
                break;
            case 2 :
                employeeDelete();
                printf("Employee has been deleted...\n");
                break;
            case 3 :
                structure(root, 2);
                break;
            case 4 :
                readFile();
                break;
            case 5 :
                writeFile();
                break;
            case 6 :
                printf("Bye... \n ");
                i = 1;
                break;
            default:
                printf("Incorrect input, try again: \n ");
                break;
        }
        goto LOOP;
    }
}





struct tnode* insert(struct tnode *r, char *line){

    if(!r) {
        printf("inserting...\n");
        struct tnode *temp =  btAlloc(line);
        return temp;
    }


    if( strcmp(line,r->name) < 0 ){        /*compares if should be in left subtree*/
        //printf("goin down left\n");
        r->left = insert(r->left, line);
    }
        /*else this will be in the right subtree*/
    else {
        //printf("goin down right\n");
        r->right = insert(r->right, line);
    }
    return r;
}

void list(struct tnode *r){ /*Lists names in tree in order format */
    if (r){
        list(r->left);
        printf(", %s", r->name);
        list(r->right);
    }
}

void readFile(){
    char *word[1024];
    FILE *file;
    size_t nread;

    file = fopen("file.txt", "r");
    if (!file)
        printf("No file found\n");
    else {
        while ((fread(word, 1, sizeof word, file)) == 1 )
            fwrite(word, 1, nread, stdout);


        printf("This is what is in file:\n");
        printf("%s\n", word);
        fclose(file);
    }

}
void writeFile() { //http://stackoverflow.com/questions/30792278/counting-lines-in-a-file-excluding-the-empty-lines-in-c
    FILE *f = fopen("file.txt", "a");
    if (f == NULL) {
        printf("No file detected\n");
        return;
    }

    char word[1024];
    printf("What is the name of the employee?\n");
    getchar();
    fgets(word, 1024, stdin);
    fprintf(f, "%s", word);


    fclose(f);



}

void employeeDelete(){  /*wrapper for deleting employee from tree if exists*/


    printf("Please enter name of employee: \n");
    getchar();
    fgets(empN,1024,stdin);
    printf("entering emp del 2\n");
    root = employeeDelete2(root, empN);

}

struct tnode* employeeDelete2(struct tnode *r, char *empName){
    struct tnode *t;

    if(r == NULL)
        printf("Not in the system...\n");

    else if( strcmp(empName, r->name) < 0)
        r->left = employeeDelete2(r->left, empName);

    else if(strcmp(empName, r->name) > 0)
        r->right = employeeDelete2(r->right, empName);

    else{
        if(r->right && r->left){
            t = minSearch(r->left);
            strcpy(r->name,t->name);
            r->right = employeeDelete2(r->right,t->name);

        }else{
            t = r;
            if(r->right == NULL)
                r = r->left;
            else if(r->left == NULL)
                r = r->right;

        }
    }
    return r;

}

struct tnode* minSearch(struct tnode *r){
    if(!r)
        return NULL;

    if(r->left)                  /*checking in leftmost subtree*/
        return minSearch(r->left);
    else
        return r;
}

void padding ( char ch, int n ){
    int i;
    for ( i = 0; i < n; i++ )
        putchar ( ch );
}
void structure ( struct tnode *root, int level ){
    if ( root == NULL ) {
        padding ( '\t', level );
        puts ( "~" );
    }
    else {
        structure ( root->right, level + 1 );
        padding ( '\t', level );
        printf ( "%s\n", root->name );
        structure ( root->left, level + 1 );
    }
}
