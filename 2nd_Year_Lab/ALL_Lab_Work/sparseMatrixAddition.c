#include<stdio.h>
#include<stdlib.h>

// int** addSparseMatrix(int** m1,int** c2,int c2ColSize){
//     int c;
//     for(c=0;c<c2ColSize;c++){
//         int row=c2[0][c];
//         int col=c2[1][c];
//         int value=c2[2][c];

//         m1[row][col]+=value;
//     }
//     return m1;
// }

int** addSparseMatrix(int **c1Arr,int **c2Arr,int c1ColSize,int c2ColSize,int M1RowSize,int M1ColSize){
    int **result=(int**)malloc(M1RowSize*sizeof(int*));
    int i;
    for(i=0;i<M1RowSize;i++){
        result[i]=(int*)malloc(M1ColSize*sizeof(int));

    }
    int j;
    for(i=0;i<M1RowSize;i++){
        for(j=0;j<M1ColSize;j++){
            result[i][j]=0;
        }
    }
    for(i=0;i<c1ColSize;i++){
        int Row=c1Arr[0][i];
        int Col=c1Arr[1][i];
        int Val=c1Arr[2][i];
        result[Row][Col]=Val;
    }
     for(i=0;i<c2ColSize;i++){
        int Row=c2Arr[0][i];
        int Col=c2Arr[1][i];
        int Val=c2Arr[2][i];
        result[Row][Col]+=Val;
    }
    return result;
}

int countMatrixSize(int** mat,int rowSize,int colSize){
    int i,j,count=0;
    for(i=0;i<rowSize;i++){
        for(j=0;j<colSize;j++){
            if(mat[i][j]>0){
                count++;
            }
        }
    }
    return count;
}

int** createCompactArr(int** mat,int rowSize,int colSize,int comColSize){
    int **c=(int**)malloc(3*sizeof(int*));
    int i;
    for(i=0;i<3;i++){
        c[i]=(int*)malloc(comColSize*sizeof(int));
    }
   
    int tracker=0;
    int j;
    for(i=0;i<rowSize;i++){
        for(j=0;j<colSize;j++){
            if(mat[i][j]>0){
                c[0][tracker]=i;
                c[1][tracker]=j;
                c[2][tracker]=mat[i][j];
                tracker++;
            }
        }
    }
    return c;
}
void print(int** mat,int rowSize,int colSize){
    int i,j;
    for(i=0;i<rowSize;i++){
        for(j=0;j<colSize;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int** createStatictoDynamic(int arr[][5],int rows,int col){
    int** mat=(int**)malloc(rows*sizeof(int*));
    int i;
    for(i=0;i<rows;i++){
        mat[i]=(int*)malloc(col*sizeof(int));
        int j=0;
        for(j=0;j<col;j++){
            mat[i][j]=arr[i][j];
        }
    }
    return mat;
}
void main(){
int arr1[7][5]={
    {0,0,3,2,0},
    {0,0,1,0,0},
    {1,0,0,0,0},
    {0,0,6,0,0},
    {0,0,0,0,1},
    {0,0,2,0,3},
    {4,5,0,0,0}
};

int mat1RowSize=7;
int mat1ColSize=5;

int arr2[7][5]={
    {0,0,4,0,0},
    {0,1,0,0,0},
    {0,6,1,0,0},
    {0,0,0,1,0},
    {0,2,3,0,0},
    {0,0,1,0,0},
    {0,2,0,0,0}
};

int mat2RowSize=7;
int mat2ColSize=5;

int** mat1=createStatictoDynamic(arr1,mat1RowSize,mat1ColSize);
int** mat2=createStatictoDynamic(arr2,mat2RowSize,mat2ColSize);

int com2ColSize=countMatrixSize(mat2,mat2RowSize,mat2ColSize);
int com1ColSize=countMatrixSize(mat1,mat1RowSize,mat1ColSize);
int** comArr2=createCompactArr(mat2,mat2RowSize,mat2ColSize,com2ColSize);
int** comArr1=createCompactArr(mat1,mat1RowSize,mat1ColSize,com1ColSize);
int** Result=addSparseMatrix(comArr1,comArr2,com1ColSize,com2ColSize,mat1RowSize,mat1ColSize);
print(Result,mat2RowSize, mat2ColSize);
}