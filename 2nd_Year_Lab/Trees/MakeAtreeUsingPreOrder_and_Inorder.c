#include<stdio.h>
#include<stdlib.h>

struct TreeNode{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
};
int i=0;

int findIdx(int *arr,int val,int start,int end){
    int mid=start+(end-start)/2;
    if(arr[mid]==val){
        return mid;
    }
    if(arr[mid]>val){
        return findIdx(arr,val,start,mid-1);
    }
    return findIdx(arr,val,mid+1,end);
}
struct TreeNode* makeATree(int *preOrder,int *inOrder,int start,int end){
    if(start>end)
    return NULL;
    
    struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data=preOrder[i];
    int currIndex=findIdx(inOrder,root->data,start,end);
    i++;
    root->left=makeATree(preOrder,inOrder,start,currIndex-1);
   
    root->right=makeATree(preOrder,inOrder,currIndex+1,end);
    return root;
}
void p(struct TreeNode *root){
    if(root==NULL)
    return;

    p(root->left);
    p(root->right);
        printf("%d ",root->data);
}
void main(){
    int inOrder[12]={4,5,6,7,8,10,12,13,14,15,18,20};
    int preOrder[12]={10,6,5,4,7,8,15,13,12,14,18,20};
    struct TreeNode *root=makeATree(preOrder,inOrder,0,11);
    p(root);
    
}