#ifndef CBTREE_TREE_H
#define CBTREE_TREE_H
#define NULL 0

typedef struct tnode{
    struct tnode *left;
    struct tnode *right;
    char *name;
  };
struct tnode* root;


/* gets user input */
void userSelection();
/*delete name */
void delete();
/*list name */
void list();
/*create*/
struct tnode* create();

struct tnode* insert(struct tnode *r, char *line);



#endif //CBTREE_TREE_H
