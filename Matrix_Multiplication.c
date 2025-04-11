//Matrix Multiplication

#include<stdio.h>
void main(){
    //matrix 1 Details 
    int r1=0;
    int c1=0;
    printf("Enter matrix-1 size:-\n");
    printf("Enter rows:-");
    scanf("%d",&r1);
    printf("Enter column:-");
    scanf("%d",&c1);
    
    //matrix 2 Details
    int r2=0;
    int c2=0;
    printf("\nEnter matrix-2 size:-\n");
    printf("Enter rows:-");
    scanf("%d",&r2);
    printf("Enter column:-");
    scanf("%d",&c2);
    
    if(c1!=r2){
        printf("\nYou have entered not suitable matrix for multiplication Reenter the Value\n");
        return;
    }
    printf("\nBased on provided details the resultant matrix row and column is %d X %d\n",r1,c2);
    
    //Filling matrix 1
    int matrix1[r1][c1];
    printf("\nFill matrix1\n-------------------\n");
    int i;
    int j;
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            printf("Enter %d X %d vlaue:-",i,j);
            scanf("%d",&matrix1[i][j]);
            
        }
    }
    
    //Filling matrix2
     printf("\nFill matrix2\n-------------------\n");
    int matrix2[r2][c2];
     for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            printf("Enter %d X %d vlaue:-",i,j);
            scanf("%d",&matrix2[i][j]);
            
        }
    }
    
    //Matrix multiplication
    int k=0;
    int sum=0;
    int Result[r1][c2];
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            sum=0;
            for(k=0;k<c1;k++){
                sum+=matrix1[i][k]*matrix2[k][j];
            }
            Result[i][j]=sum;
        }
    }
    
    
    //Display Result
    
    printf("Displaying Result\n");
    printf("----------------------------------------\n");
    
     for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
           
            printf("%d\t",matrix1[i][j]);
            
        }
        printf("\n");
    }
    
    printf("\n");
    
     for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
           
            printf("%d\t",matrix2[i][j]);
            
        }
        printf("\n");
    }
    
    printf("-------------------------\n");
    
    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
            
            printf("%d\t",Result[i][j]);
        }
        printf("\n");
    }
    
}
