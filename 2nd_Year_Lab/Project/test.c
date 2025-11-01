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
//Insertion in file
void insertInFile(int* nums,int Size){
    FILE *f = fopen("data.txt", "a"); 
    //add all nums data to file
    for(int i=0;i<Size;i++){
        fprintf(f,"%d,%d.\n",i,nums[i]);
    }
    fclose(f);
}


//upgrade to the file
//delete file
void deleteFile(){
    FILE *f = fopen("data.txt", "w"); //deletes the file
}
//upgrade index
///

//main function
void main(){
//    int *nums=(int*)malloc(3*sizeof(int));
//    nums[0]=20;
//    nums[1]=30;
//    nums[2]=78;
   

//     insertInFile(nums,3);

    int size;

     int *arr=getData(&size);
     for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
     }



}
