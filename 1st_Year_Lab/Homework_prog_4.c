# include<stdio.h>
# include<stdlib.h>  //Complete All the functions

//Function Prototype
void* createArray(int size);
void printArray(int *A, int size);
void assignValue(int *arr,int size);
int findMax(int *arr,int size);
int findMin(int *arr,int size);
void swapArray();
//Main Function
int main()
{
	int size = 0;
	printf("\nEnter the size of the Array :: ");
	scanf("%d",&size);
	int *arr = (int*) createArray(size);
	assignValue(arr,size);
	printf("The maximum value in this array is %d",findMax(arr,size));
	printf("\n");
	printf("The maximum value in this array is %d\n",findMin(arr,size));
	printArray(arr, size);
	return 0;
}


//Function Definition
void* createArray(int size)
{
	void *temp =  malloc(size * sizeof(int));
	return temp;
}


void printArray(int *A, int size)
{
	int i = 0;
	for(i = 0; i<size; i++)
	{
		printf("%d,\t",A[i]);
	}
	printf("\n");
}
void assignValue(int *arr,int size){
for(int i=0;i<size;i++){
    printf("Enter %d value",i+1);
    scanf("%d",&arr[i]);
}
    
}
int findMax(int *arr,int size){
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
int findMin(int *arr,int size){
       int min=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

