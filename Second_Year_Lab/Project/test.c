#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// adding to the file
void appendTofile(int idx,int val){
    FILE *f=fopen("data.txt","a"); //opent the file

    //rewind(f);//move to starting of pointer

    fprintf(f,"%d,%d.\n",idx,val); // appended in file
    fclose(f);


}
// fetch data from file and store in array and return
int* getData(int *returnSize){
    int idx=-1; //for storing the index of array 
    int val;    //for storing the value of array
    bool tracker=false; // is the tracking system for fetching the index and vale for false it fetch the index and for true it fetch val
    
    int* arr=(int*)calloc(1,sizeof(int)); // Array creation for storing 
    int size=1; // size of array;
    
    FILE *f=fopen("data.txt","r");// opened file
     
    int ch;
    char num[30];   // big enough buffer
    num[0] = '\0';// initialize as empty string

    while ((ch = fgetc(f)) != EOF) { //fetching the data and string in idx and val
        if(ch==' ' || ch=='\n')
            continue;
    if(!tracker){
    if(ch!=','){
     char temp[2];     // small string to hold one character + '\0'
     temp[0] = ch;     
     temp[1] = '\0';
     strcat(num, temp);
    }else{
        idx=atoi(num); // index fetch;
       num[0] = '\0';
        tracker=true;
    }
    }else{
        if(ch!='.'){
        char temp[2];     // small string to hold one character + '\0'
        temp[0] = ch;     
        temp[1] = '\0';
        strcat(num, temp);
        }else{
            val=atoi(num); // index fetch;
           num[0] = '\0';
            tracker=false;
        } 
    }
    if(idx!=-1){
        //check the array size if have then add it , if not then expand it and add it
        if(size<(idx+1)){
            size=idx+1;//incresed the size
            int* temp=(int*)realloc(arr,size * sizeof(int)); //realloced the size 
            arr=temp;
           
        }
         arr[idx]=val; //stored in array
    }
    }
    fclose(f);
    *returnSize=size;
    return arr;

}

//upgrade to the file
//delete file
void deleteFile(){
    FILE *f = fopen("data.txt", "w"); //deletes the file
}

//Insertion in file
void insertInFile(int* nums,int Size){
    FILE *f = fopen("data.txt", "a"); 
    deleteFile();
    //add all nums data to file
    for(int i=0;i<Size;i++){
        fprintf(f,"%d,%d.\n",i,nums[i]);
    }
    fclose(f);
}







//-------------------------------------------------
void merge(int *arr, int l, int m, int r){
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int *arr, int l, int r){
    
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void del(int *arr, int *size, int key) { // deleting the particular key in array
  
  	// Find the element
  	int i = 0;
  	while (arr[i] != key) i++;
  	
    // Shifting the right side elements one
  	// position towards left
    for (int j = i; j < *size - 1; j++) {
        arr[j] = arr[j + 1];
    }
  
  	// Decrease the size
    (*size)--; 
}
void main(){
// getting the data from the text file
    int size;
     int *arr=getData(&size);
    
    mergeSort(arr, 0, size - 1); // doing sorting to the array
    del(arr,&size,arr[2]);

      for(int i=0;i<size;i++){ // print all the values of sorted array
        printf("%d ",arr[i]);
     }
     arr[0]=5;  // changing the value
    insertInFile(arr,size);// Inserting sorted array in file
}
