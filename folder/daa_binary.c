#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create(){
    Node* root;
    root=(Node*)malloc(sizeof(Node));
    int data;
    printf("enter the data for the node: ");
    scanf("%d",&data);
    if(data==-1){
        return 0;
    }
    root->data=data;
    printf("enter the left child of %d\n",data);
    root->left=create();
    printf("enter the right child of %d\n",data);
    root->right=create();
    return root;
    
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d, ",root->data);
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root!=NULL){
        printf("%d, ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d, ",root->data);
    }
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int c_node=0,leaf=0;

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

int countnode(Node* root){
    if(root==NULL){
        return c_node;
    }
    countnode(root->left);
    c_node++;
    countnode(root->right);

}

int countleaf(Node* root){
    if(root==NULL){
        return leaf;
    }
    countleaf(root->left);
    if(root->left==NULL && root->right==NULL){
        leaf++;
    }
    countleaf(root->right);

}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);

    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);

    return max(lheight+rheight+1, max(ldiameter,rdiameter));
}

int main(){
    Node* root=NULL;
    root=create();
    printf("inorder traversal: ");
    inorder(root);
    printf("\npostorder traversal: ");
    postorder(root);
    printf("\npreorder traversal: ");
    preorder(root);
    printf("\nheight of the tree is: %d",height(root));
    printf("\nnumber of leafs: %d",countleaf(root));
    printf("\nnumber of nodes: %d",countnode(root));
    printf("\ndiameter of tree: %d",diameter(root));
    return 0;
}