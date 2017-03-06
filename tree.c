#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <ctype.h>
#include <string.h>

char *line[1024];
char *empN[1024];
char *word[1024];

/* allocates memory for new node */
struct tnode *btAlloc(){
    struct tnode *t =  (struct tnode*) malloc(sizeof(struct tnode));   /* allocates memory for new node */
    t->left = t->right = NULL;
    strcpy(t->name,line);      /*copies whatever is in line to name value */
    return t;
}

/*insertion name wrapper*/
void enterName(){
    printf ("Please enter the name:");
    getchar();
    fgets(line, 1024, stdin);

    root = insert(root, line);
}


void userSelection() {

    int i = 0;
    int input;
    LOOP:
    if (i == 0) {
        printf("\n\nWhat would you like to do?\n");
        printf("1: insert employee\n2: delete employee\n3: list employees\n4: read file\n");
        printf("5: write to file\n6: quit\n");

        scanf("%d", &input);
        switch (input) {
            case 1 :
                enterName();
                break;
            case 2 :
                employeeDelete();
                printf("Employee has been deleted...\n");
                break;
            case 3 :
                structure(root, 3);
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

/* main insertion funtion */
struct tnode* insert(struct tnode *r, char *line) {


    if (!r) {                               /* whens on correct child node */
        printf("inserting...\n");
        struct tnode *temp = btAlloc(line);
        return temp;
    }

    if (strcmp(r->name, line) == 0) {   /* checks for repeated values */
        printf("HEADS UP! Someone with same name already exists in file...not going to insert.\n");
        return r;
    }

    if( strcmp(line,r->name) < 0 ){        /* compares if should be in left subtree, uses ASCII values*/
        r->left = insert(r->left, line);
    }
                                          /*else this will be in the right subtree*/
    else {
        r->right = insert(r->right, line);
    }

    return r;

}

/*reads file and inserts all names that are not in the tree */
void readFile(){
    FILE *file;
    int i;

    file = fopen("file.txt", "r");
    if (!file)
        printf("No file found\n");
    else {
        while (fgets(line,1024,file)) {
            printf("scanned word: %s", line);
            root = insert(root, line);
        }
        fclose(file);
    }

}

/* gets user input to write to the file */
void writeFile() {
    FILE *f = fopen("file.txt", "a");
    if (f == NULL) {
        printf("No file detected\n");
        return;
    }

    char word[1024];
    printf("What is the name of the employee?\n");
    getchar();
    fgets(word, 1024, stdin);
    fprintf(f, "%s", word);    /* prints to next line in file */


    fclose(f);
}

/*wrapper for deleting employee from tree if exists*/
void employeeDelete(){

    printf("Please enter name of employee: \n");
    getchar();
    fgets(empN,1024,stdin);
    printf("entering emp del 2\n");
    root = employeeDelete2(root, empN);

}

/* recursive method for deleting node from tree */
struct tnode* employeeDelete2(struct tnode *r, char *empName){
    struct tnode *t;   /* declaring temp */

    if(r == NULL)
        printf("Not in the system...\n");

    else if( strcmp(empName, r->name) < 0)           /*if given negative value, the name may be in the left subtree*/
        r->left = employeeDelete2(r->left, empName);

    else if(strcmp(empName, r->name) > 0)            /*if greater, may be in right subtree*/
        r->right = employeeDelete2(r->right, empName);

    else{                                                           /*If passes through both if statements..*/
        if(r->right && r->left){  /*checks for children*/            /*we know that we found what we need to delete*/
            t = minSearch(r->right); /*getting the min value of right subtree*/
            strcpy(r->name,t->name); /*overwriting*/
            r->right = employeeDelete2(r->right,t->name);  /*delete that replaced node*/

        }else{          /* If there's 1 < children, we remove it from the tree and link its parent to its child */
            t = r; /* assigning temp the child node */
            if(r->right == NULL)
                r = r->left;
            else if(r->left == NULL)
                r = r->right;

        }
    }
    return r;

}

/* finds minimum in tree */
struct tnode* minSearch(struct tnode *r){
    if(!r)
        return NULL;

    if(r->left)                  /*checking in leftmost subtree*/
        return minSearch(r->left);
    else
        return r;
}


void padding ( char ch, int n ){ /*Help with the format of printing the bst*/
    int i;
    for ( i = 0; i < n; i++ )
        putchar ( ch );  /* places indention */
}


void structure ( struct tnode *root, int level ){ /*prints the structure of bst (sideways)*/
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
