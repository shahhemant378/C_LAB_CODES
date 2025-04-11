
//Q2. Write a program that subtract two matrices.

#include <stdio.h>
void main(){
    printf("--Matrix Subtraction--\n\n");
    
    
    //Enter matrix details
    int r=0;
    int c=0;
    printf("Enter the size of Matrix:-\n");
    printf("Enter rows:-");
    scanf("%d",&r);
    printf("Enter column:-");
    scanf("%d",&c);
    
    int matrix1[r][c];
    
     
    
    int matrix2[r][c];
    
    printf("\n");
    
    // Taking value of first matrix
    int i;
    int j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter the first matrix %d row and %d column value:-",i,j);
            scanf("%d",&matrix1[i][j]);
        }
    }
    
    
     // Taking value of Second matrix
   printf("\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter the Second matrix %d row and %d column value:-",i,j);
            scanf("%d",&matrix2[i][j]);
        }
    }
    
    int matrix3[r][c];
   for(i=0;i<r;i++){
        for(j=0;j<c;j++){
           matrix3[i][j]=matrix1[i][j]-matrix2[i][j];
        }
    }
    
    //first
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
           printf("%d\t",matrix1[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    //second
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
           printf("%d\t",matrix2[i][j]);
        }
        printf("\n");
    }
    
    printf("-----------------------------------\n");
    //Result
     for(i=0;i<r;i++){
        for(j=0;j<c;j++){
           printf("%d\t",matrix3[i][j]);
        }
        printf("\n");
    }
    
    
}
