#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define TRUE_VALUE 1
#define FALSE_VALUE 0
#define LEFT 1
#define RIGHT 2
#include<bits/stdc++.h>
struct treeNode
{
    int item ;
    struct treeNode * left ; //will point to left child
    struct treeNode * right ; //will point to right child
} ;
struct treeNode * root ; //global variable to store tree

void initializeTree()
{
    root = 0 ;
}

int insertRoot(int ritem)
{
    struct treeNode * newNode ;
    newNode = (struct treeNode*)malloc(sizeof(struct treeNode)) ;
    newNode->item=ritem;
    newNode->left = 0 ;
    newNode->right = 0 ;
    root = newNode ;
    return TRUE_VALUE ;
}

int insertItem(struct treeNode * node, int oldItem, int newItem, int childType)
{
    if ( node == 0 ) return 0 ;
    //check if item is matched with this node
    if ( node->item == oldItem )
    {
        if( childType==LEFT && node->left==0 )
        {
            struct treeNode * newNode ;
            newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
            newNode->item = newItem ;
            newNode->left = 0 ;
            newNode->right = 0 ;
            node->left = newNode ;
            return TRUE_VALUE ;
        }
        else if( childType==RIGHT && node->right==0 )
        {
            struct treeNode * newNode ;
            newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
            newNode->item = newItem ;
            newNode->left = 0 ;
            newNode->right = 0 ;
            node->right = newNode ;
            return TRUE_VALUE ;
        }
        else return FALSE_VALUE ;
    }
    //search the left sub-tree for possible insertion
    int t;
    t = insertItem(node->left, oldItem, newItem, childType) ;
    if (t == TRUE_VALUE) return t ;
    //search the right sub-tree for possible insertion
    t = insertItem(node->right, oldItem, newItem, childType) ;
    if (t == TRUE_VALUE) return t ;
    //finally, return NULL because item was not found
    return FALSE_VALUE ;
}
int deleteItem(struct treeNode *Node,int item)
{
    if(Node==0)return 0;
    if(Node->left!=0 && Node->left->item==item)
    {
        free(Node->left);
        Node->left=0;
        return  TRUE_VALUE;
    }
    else if(Node->right!=0 && Node->right->item==item)
    {
        free(Node->right);
        Node->right=0;
        return  TRUE_VALUE;
    }
    int t=FALSE_VALUE;
    t=deleteItem (Node->left,item);
    if(t==TRUE_VALUE)return t;
    t=deleteItem (Node->right,item);
    return t;

}

void printTreeInOrder(struct treeNode * node)
{
    if ( node == 0 ) return  ;
    printTreeInOrder(node->left) ;
    printf("%d ", node->item) ;
    printTreeInOrder (node->right) ;
}
int main()
{
    initializeTree ();
    while(1)
    {
        printf("1.Insert Root. 2. Insert Node. 3. Print. 4. Delete Item\n");
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int root;
            printf("Root?\n");
            scanf("%d",&root);
            insertRoot (root);
        }
        else if(ch==2)
        {
            int old,nw,type;
            printf("old ? New ? Type(1/2) ?\n");
            scanf("%d%d%d",&old,&nw,&type);
            insertItem (root,old,nw,type);
        }
        else if(ch==3)
        {
            printTreeInOrder (root);
            printf("\n");
        }
        else if(ch==4)
        {
            int item;
            printf("ITEM?\n");
            scanf("%d",&item);
            deleteItem (root,item);
        }
    }

}
