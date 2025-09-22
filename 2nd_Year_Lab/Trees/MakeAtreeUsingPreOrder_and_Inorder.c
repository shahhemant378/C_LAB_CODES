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


//LEETCODE CODE FOR SAME PROBLEM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int i = 0; // Global index to keep track of current root in preorder array

// Function to find the index of a value in inorder using hashmap
int findIdx(int val, int *hashMap, int offset){
   return hashMap[val + offset]; // offset handles negative values
}

// Recursive function to construct the binary tree
struct TreeNode* makeATree(int *preOrder, int *inOrder, int start, int end, int *hashMap, int offset){
    if(start > end) 
        return NULL; // Base case: no elements to construct subtree
    
    // Allocate memory for current root node
    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    // Assign current root value from preorder
    root->val = preOrder[i];
    
    // Find index of root in inorder array
    int currIndex = findIdx(root->val, hashMap, offset);
    
    i++; // Move to the next root in preorder
    
    // Recursively build left subtree
    root->left = makeATree(preOrder, inOrder, start, currIndex - 1, hashMap, offset);
   
    // Recursively build right subtree
    root->right = makeATree(preOrder, inOrder, currIndex + 1, end, hashMap, offset);
    
    return root; // Return the constructed subtree
}

// Main function to be called by LeetCode
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    i = 0; // Reset global index for each test case
    
    int j;
    int offset = 3000; // Offset to handle negative values
    int hashMap[6001]; // [-3000, 3000] -> 6001 elements
    
    // Fill hashmap: key = value + offset, value = index in inorder
    for(j = 0; j < inorderSize; j++){
        hashMap[inorder[j] + offset] = j;
    }
    
    // Construct the tree using recursive function
    struct TreeNode *root = makeATree(preorder, inorder, 0, preorderSize - 1, hashMap, offset);
    
    return root;
}
