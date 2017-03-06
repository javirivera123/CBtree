#ifndef CBTREE_TREE_H
#define CBTREE_TREE_H
#define NULL 0

/* bst node declaration */
struct tnode{
    struct tnode *left;
    struct tnode *right;
    char name[1024];
};struct tnode *root;

/* for fgets to get user input and file */
char *fgets(char *str, int n, FILE *stream);

/* allocates memory for nodes */
struct tnode *btAlloc();

/* gets user input for system */
void userSelection();

/* delete name wrapper */
void employeeDelete();

/* function that's given node and name to delete */
struct tnode* employeeDelete2(struct tnode *r, char *empName);

/* insert name wrapper for insert method */
void enterName();

/* fuction that inserts into tree */
struct tnode* insert(struct tnode *r, char *line);

/* reads file and inserts all names that are not in the tree */
void readFile();

/* writes to file declaration */
void writeFile();

/* declaration for minSearch */
struct tnode* minSearch(struct tnode *r);

/* declaration for padding */
void padding ( char ch, int n );

/* declaration for bst print */
void structure ( struct tnode *root, int level );


#endif //CBTREE_TREE_H
