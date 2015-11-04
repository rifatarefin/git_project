#include<stdio.h>
#include<stdlib.h>

#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;


void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    if(node==0) return 0;
    if(node->item==item) return node; //found, return node
    struct treeNode * t = 0;
    if(item < node->item)
        t = searchItem(node->left, item); //search in the left sub-tree
    else
        t = searchItem(node->right, item); //search in the right sub-tree
    return t;
};


struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    if(node==0) //insert as the root as the tree is empty
    {
        struct treeNode * newNode = makeTreeNode(item);
        root = newNode;
        return newNode;
    }

    if(node->item==item) return 0; //already an item exists, so return NULL

    if(item<node->item && node->left==0) //insert as the left child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->left = newNode;
        return newNode;
    }

    if(item>node->item && node->right==0) //insert as the right child
    {
        struct treeNode * newNode = makeTreeNode(item);
        node->right = newNode;
        return newNode;
    }

    if(item<node->item)
        return insertItem(node->left, item); //insert at left sub-tree
    else
        return insertItem(node->right, item); //insert at right sub-tree
}



int calcNodeHeight(struct treeNode * node) //return height of a node
{
    if(node==0) return -1;
    int l, r;
    l = calcNodeHeight(node->left);
    r = calcNodeHeight(node->right);
    if(l>r) return l+1;
    else return r+1;
}


int calcHeight(int item) //return height of an item in the tree
{
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
    if(node==0)return 0;
    return getSize (node->left)+getSize (node->right)+1;
}

int calcNodeDepth(struct treeNode * node) //return depth of a node
{
    //write your codes here
    struct treeNode *temp=root;
    int depth=0;
    while(temp!=0)
    {
        if(temp==node)return depth;
        depth++;
        if(node->item<temp->item)

            temp=temp->left;


        else
            temp=temp->right;


    }
}


int calcDepth(int item)//return depth of an item in the tree
{
    //write your codes here
    struct treeNode * node = 0;
    node = searchItem(root, item);
    if(node==0) return -1; //not found
    else return calcNodeDepth (node);
}

struct treeNode *ancestor(struct treeNode *node,int item)
{
    struct treeNode *ances=0;
    while(node!=0)
    {

        if(item==node->item)return ances;
        ances=node;
        if(item<node->item)node=node->left;
        else node=node->right;
    }
    return 0;
}
int deleteItem(struct treeNode * node, int item)
{
    //write your code here, return TRUE, FALSE
    node=searchItem (root,item);
    if(node==0)return FALSE_VALUE;
    if(node->left==0 && node->right==0)
    {
        if(node==root)
        {
            free(node);
            root=0;
            return TRUE_VALUE;
        }
        struct treeNode *anc=ancestor (root,item);
        if(anc->left==node)anc->left=0;
        else anc->right=0;

        free(node);
        return TRUE_VALUE;
    }
    else if(node->left==0)
    {
        if(node==root)
        {
            struct treeNode *temp=root->right;
            free(root);
            root=temp;
            return TRUE_VALUE;
        }
        struct treeNode *anc=ancestor (root,item);
        if(anc->left==node)

            anc->left=node->right;
        else
            anc->right=node->right;
        free(node);
        return TRUE_VALUE;
    }
    else if(node->right==0)
    {
        if(node==root)
        {
            struct treeNode *temp=root->left;
            free(root);
            root=temp;
            return TRUE_VALUE;
        }
        struct treeNode *anc=ancestor (root,item);
        if(anc->left==node)

            anc->left=node->left;
        else
            anc->right=node->left;
        free(node);
        return TRUE_VALUE;
    }
    else
    {
        struct treeNode *prev,*last;
        last=node->right;
        prev=last;
        while(last!=0)
        {
            prev=last;
            last=last->left;
        }
        int value=prev->item;
        deleteItem (root,value);
        node->item=value;
        return TRUE_VALUE;

    }


}



int getMinItem() //returns the minimum item in the tree
{
    //write your codes here
    struct treeNode *temp=root;
    int min=0;
    while(temp!=0)
    {
        min=temp->item;
        temp=temp->left;
    }
    return min;
}

int getMaxItem() //returns the maximum item in the tree
{
    //write your codes here
    struct treeNode *temp=root;
    int min=0;
    while(temp!=0)
    {
        min=temp->item;
        temp=temp->right;
    }
    return min;
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound) //returns number of items in the
{
    //write your codes here
    if(node==0)return 0;
//    if(node->item>=leftBound && node->item<=rightBound )return rangeSearch (node->left,leftBound,rightBound)+rangeSearch (node->right,leftBound,rightBound)+1;
//    return rangeSearch (node->left,leftBound,rightBound)+rangeSearch (node->right,leftBound,rightBound);

    if(node->item>rightBound)rangeSearch (node->left,leftBound,rightBound);
    else if(node->item<leftBound)rangeSearch (node->right,leftBound,rightBound);
    else return rangeSearch (node->left,leftBound,rightBound)+rangeSearch (node->right,leftBound,rightBound)+1;

}


void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return ;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}



int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf("6. PrintInOrder. 7. GetSize. 8. Print Depth of an item. \n");
        printf("9. Get minimum item. 10. Get maximum item. 11. Range Search. 12. Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf ("%d",&item);
            //struct treeNode *temp=searchItem (root,item);
            deleteItem (root,item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            printf("Size of the tree= %d\n",getSize (root));
        }
        else if(ch==8)
        {
            int item;
            scanf ("%d",&item);
            printf("Depth of %d= %d\n",item,calcDepth (item));
        }
        else if(ch==9)
        {
            printf("Minimum item of tree= %d\n",getMinItem ());
        }
        else if(ch==10)
        {
            printf("Maximum item of tree= %d\n",getMaxItem ());
        }
        else if(ch==11)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("Number of items in the given range= %d\n",rangeSearch (root,l,r));
        }
        else if(ch==12)
        {
            break;
        }

    }

}
