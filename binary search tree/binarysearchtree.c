#include <stdio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* getnewnode(int data)
{
    
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root -> data = data;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

struct Node* insert(struct Node* root, int data)
{
    if(root == NULL)
    {
        root = getnewnode(data);
    }
    else if(data <= root -> data)
    {
        root -> left = insert(root -> left, data);
    }
    else
    {
        root -> right = insert(root -> right, data);
    }
    return root;
}

void printinorder(struct Node* root)
{
    if(root != NULL)
    {
        printinorder(root -> left);
        printf("%d\t", root -> data);
        printinorder(root -> right);
    }
    
}

void printpreorder(struct Node* root)
{
    if(root != NULL)
    {
        
        printf("%d\t", root -> data);
        printpreorder(root -> left);
        printpreorder(root -> right);
    }
    
}

void printpostorder(struct Node* root)
{
    if(root != NULL)
    {
        printpostorder(root -> left);
        printpostorder(root -> right);
        printf("%d\t", root -> data);
       
      
    }
    
}

int findmin(struct Node* root)
{
	if(root== NULL)
	{
	printf("tree is empty\n");
	}
	else
	{
	while(root -> left != NULL)
	{
	root = root -> left;
	}
	return root -> data;
	}
}

int findmax(struct Node* root)
{
	if(root== NULL)
	{
	printf("tree is empty\n");
	}
	else
	{
	while(root -> right != NULL)
	{
	root = root -> right;
	}
	return root -> data;
	}
}


int main()
{
  struct Node* root = NULL;
  root = insert(root, 35);
  root = insert(root, 25);
  root = insert(root, 21);
  root = insert(root, 27);
  root = insert(root, 11);
  root = insert(root, 24);
  root = insert(root, 5);
  root = insert(root, 29);
  root = insert(root, 39);
  root = insert(root, 45);
  root = insert(root, 47);
  root = insert(root, 41);
  root = insert(root, 1);
  printf("\nthe bst node inorder is\n");
  printinorder(root);
  printf("\nthe bst node preorder is\n");
  printpreorder(root);
  printf("\nthe bst node postorder is\n");
  printpostorder(root);
  int min = findmin(root);
  printf("\nthe minimum value in the tree is %d\n", min);
  int max = findmax(root);
  printf("\nthe maximum value in the tree is %d\n", max);
    return 0;
}

