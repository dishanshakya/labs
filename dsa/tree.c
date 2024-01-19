#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int data;
    struct treenode *parent;
    struct treenode *leftchild;
    struct treenode *rightchild;
} treenode;


void insert(int data, treenode *root)
{
    treenode *newnode = (treenode*) malloc(sizeof(treenode));
    newnode->data = data;
    newnode->leftchild = NULL;
    newnode->leftchild = NULL;

    if (root->data > data)
    {
        if (root->leftchild == NULL)
		{
            root->leftchild = newnode;
			newnode->parent = root;
		}
        else 
        {
            free(newnode);
            insert(data, root->leftchild);
        }
    }
    else if (root->data < data)
    {
       if (root->rightchild == NULL)
	   {
            root->rightchild = newnode;
			newnode->parent = root;
	   }
        else 
        {
            free(newnode);
            insert(data, root->rightchild);
        }  
    }
}

void inorder(treenode *root)
{
    if (root->leftchild != NULL)
    {
        inorder(root->leftchild);
    }
    printf(" %d ", root->data);
    if (root->rightchild != NULL)
        inorder(root->rightchild);
}

void preorder(treenode *root)
{
    printf(" %d ", root->data);
    if (root->leftchild != NULL)
    {
        preorder(root->leftchild);
    }
    if (root->rightchild != NULL)
        preorder(root->rightchild);
}

void postorder(treenode *root)
{
    if (root->leftchild != NULL)
    {
        postorder(root->leftchild);
    }
    if (root->rightchild != NULL)
        postorder(root->rightchild);
    printf(" %d ", root->data);
}

void delete(int data, treenode *root)
{
    if (root->data == data)
    {
		if (root->leftchild != NULL && root->rightchild != NULL)
		{
			treenode *temp = root->rightchild;
			if (temp->leftchild != NULL)
			printf("%d\n", temp->leftchild->data);
			while (temp->leftchild != NULL)
				temp = temp->leftchild;
			temp->leftchild = root->leftchild;
			root->leftchild->parent = temp;
			root->parent->leftchild = root->rightchild;
			return;
		}
		else if (root->leftchild == NULL)
		{
			if (root->parent->leftchild == root)
			root->parent->leftchild = root->rightchild;
			else root->parent->rightchild = root->rightchild;
		}
		else if (root->rightchild == NULL)
		{
			if (root->parent->leftchild == root)
			root->parent->leftchild = root->leftchild;
			else root->parent->rightchild = root->leftchild;
		}
    }
	else if (root->data < data && root->rightchild != NULL)
		delete(data, root->rightchild);
	else if (root->data > data && root->leftchild != NULL)
		delete(data, root->leftchild);
	else printf("No element found\n");

}

int main()
{
    treenode root, left, right;
    root.parent = NULL;
    root.data = 40;
    root.leftchild = NULL;
    root.rightchild = NULL;

    int data, choice;
    char cont;
    do
    {
        printf("Binary Search Tree\n\n");
        printf("1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6. Exit\n\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
            loop: printf("Enter the data: ");
                scanf("%d", &data);
                insert(data, &root);
                printf("Continue inserting?(0 for no, 1 for yes): ");
                scanf("%d", &choice);
                if (choice == 1)
                    goto loop; 
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data, &root);
                break;
            case 3:
                printf("[");
                inorder(&root);
                printf("]\n\n\n");
                break;
            case 4:
                printf("[");
                preorder(&root);
                printf("]\n\n\n");
                break;
            case 5:
                printf("[");
                postorder(&root);
                printf("]\n\n\n");
                break;
            case 6:
                return 0;
        }
    } while (1);
}
