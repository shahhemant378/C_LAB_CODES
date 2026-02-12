#include<stdio.h>
void main(){
    //WAP that takes a 2D Array as input and returns its Transpose.
    int r=0;
    int c=0;
    printf("Enter the dimension of 2D array:-");
    printf("\nEnter Rows:-");
    scanf("%d",&r);
    printf("Enter column:-");
    scanf("%d",&c);

    printf("\nYour Transpose matrix Dimension will be %d x %d\n",c,r);

    int arr[r][c];
    int i;
    int j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Enter %d x %d value:-",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
int arrT[c][r];

for(i=0;i<c;i++){
    for(j=0;j<r;j++){
        arrT[i][j]=arr[j][i];
    }
}

printf("Transpose of the Matrix is :-\n");

for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        printf("%d\t ",arr[i][j]); 
    }
    printf("\n");
}


printf("---------------------------\n");

for(i=0;i<c;i++){
    for(j=0;j<r;j++){
        printf("%d\t ",arrT[i][j]);
        
    }
    printf("\n");
}


}
