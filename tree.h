#ifndef CBTREE_TREE_H
#define CBTREE_TREE_H
#define NULL 0

char *fgets(char *str, int n, FILE *stream);

struct tnode{
    struct tnode *left;
    struct tnode *right;
    char name[1024];
  };

struct tnode *root;




struct tnode *btAlloc();

/* gets user input */
void userSelection();
/*delete name */
void employeeDelete();
struct tnode* employeeDelete2(struct tnode *r, char *empName);
void enterName();

/*list name */

void list();
/*create*/
struct tnode* create();

void readFile();
void writeFile();
struct tnode* insert(struct tnode *r, char *line);

struct tnode* minSearch(struct tnode *r);



#endif //CBTREE_TREE_H
