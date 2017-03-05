#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>  /*http://stackoverflow.com/questions/1921539/using-boolean-values-in-c*/


/* &(pointer name) = used for address of pointer and to just print is name casted with %p*/
char *line[1024];
char *empN[1024];

char *p;

struct tnode *btAlloc(){
    printf("entered bt alloc...\n");

    struct tnode *t =  (struct tnode*) malloc(sizeof(struct tnode));
    t->left = t->right = NULL;
    strcpy(t->name,line);
    t = NULL;
    return t;
}

void enterName(){
    printf("Please enter the name:");
    getchar();
    fgets(line, 1024, stdin);

        printf("%s\n", line);
        printf("This should print name: %s\n", line);
        printf("entering 1st root insertion\n");

        root = insert(root, line);
        printf("has exited insert method\n");
        printf("now print whats in root..\n");
        printf("%s\n", root->name);


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
            break;
        case 2 :
            employeeDelete();
            break;
        case 3 :
            list(root);
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

    printf("has entered insert ..\n");
    if(!r) {
        printf("inserting...\n");
        struct tnode *temp =  (struct tnode*) malloc(sizeof(struct tnode));
        temp->right = temp->left = NULL;
        strcpy(temp->name,line);
        return temp;
    }


    if( strcmp(line,r->name) < 0 ){
        printf("goin down left\n");
        r->left = insert(r->left, line);
     }
         /*else this will be in the right subtree*/
    else {
        printf("goin down right\n");
        r->right = insert(r->right, line);
    }
    return r;
}

void list(struct tnode *r){ /*Lists names in tree inorder*/
    if (r){
        list(r->left);
        printf(", %s", r->name);
        list(r->right);
    }
}

void readFile(){
    FILE *file;
    size_t nread;

    file = fopen("file.txt", "r");
    if (file)
        printf("entered\n");
    while ((nread = fread(line, 1, sizeof line, file)) > 0)
        fwrite(line, 1, nread, stdout);
    printf("%s" , line);
    fclose(file);

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

void employeeDelete(){


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

    if(r->left)                  /*checking is leftmost subtree*/
        return minSearch(r->left);
    else
        return r;
}


