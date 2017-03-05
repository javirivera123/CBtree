#ifndef CBTREE_TREE_H
#define CBTREE_TREE_H
#define NULL 0

char *fgets(char *str, int n, FILE *stream);

struct tnode{
    struct tnode *left;
    struct tnode *right;
    char name[1024];
};struct tnode *root;

/*allocates memory for nodes*/
struct tnode *btAlloc();

/* gets user input for system*/
void userSelection();

/*delete name wrapper */
void employeeDelete();

/*function that's given node and name to delete*/
struct tnode* employeeDelete2(struct tnode *r, char *empName);

/*insert name wrapper for insert method*/
void enterName();

/*fuction that inserts into tree*/
struct tnode* insert(struct tnode *r, char *line);

/*list name */
void list();

/*create*/
struct tnode* create();

void readFile();
void writeFile();


struct tnode* minSearch(struct tnode *r);

void padding ( char ch, int n );

void structure ( struct tnode *root, int level );



#endif //CBTREE_TREE_H
