//Create a structure Book (B1,B2,B3)
//array of sturcture pointers
// Enter values in structure variables using pointer (eg sturct[0]-> name)

#include <stdio.h> 
struct Book{
char name[30];
int price;
int pages;

};
void main(){
struct Book B1,B2,B3;

struct Book *sptr[3];
sptr[0]=&B1;
sptr[1]=&B2;
sptr[2]=&B3;
int i;
for(i=0;i<3;i++){
  printf("Enter name: ");
  scanf("%s",&sptr[i]->name);
  printf("Enter pages: ");
  scanf("%d",&sptr[i]->pages);
  printf("Enter prices");
  scanf("%d",&sptr[i]->price);
  printf("\n");
}

for(i=0;i<3;i++){
  printf("%s\n ",(sptr[i]->name));
  printf("%d\n",(sptr[i]->price));
  printf("%d\n",(sptr[i]->pages));
}
}
