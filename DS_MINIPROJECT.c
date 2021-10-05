/*

                                    ____  ____    ____  ____   ___      _ _____ ____ _____
                                   |  _ \/ ___|  |  _ \|  _ \ / _ \    | | ____/ ___|_   _|
                                   | | | \___ \  | |_) | |_) | | | |_  | |  _|| |     | |
                                   | |_| |___) | |  __/|  _ <| |_| | |_| | |__| |___  | |
                                   |____/|____/  |_|   |_| \_\\___/ \___/|_____\____| |_|



*/
#include<stdio.h>
#include<stdlib.h>

float a[100],r[100],ans[100];
int cint=-1,atop=-1,otop=-1,s=1,flag=0,rtop=-1,cu=0;
char oper[100],c;
void undo();
void insert();
void display() ;
void redo() ;
int main()
{
    int i,choice;
      printf("_________________MENU________________\n\n\t\t1.Insert\n\t\t2.Display\n\t\t3.Undo\n\t\t4.Redo\n\t\t5.Exit\n");
      printf("\n_____________________________________\n");
    do{
        printf("\nEnter your choice :\t");
        scanf("%d",&choice);

    switch(choice)
    {
        case 1: insert();
            break;
        case 3: undo() ;

                break;
        case 2:display();
                break;
        case 4:if(cu>0)
                redo();
               else
                printf("\nNot Possible\n");
                break;
        case 5:exit(0);
        default :  printf("Oops!! It seems you have entered Invalid choice\n");



    }}while(choice);

 }
 void insert()
 {
   float d;
   cu=0;

   if(s==1)
  {


      printf("Enter the operand :\t");
      scanf("%f",&d);
      if(flag==0)
      {
          ans[++atop]=d;
          flag=1;

      }
      else
      {
          cint++;
          a[cint]=d;

      }
      if(oper[otop]=='+')
         ans[++atop]=ans[atop]+a[cint];

     else if(oper[otop]=='-')
             ans[++atop]=ans[atop]-a[cint];

      else if(oper[otop]=='*')
             ans[++atop]=ans[atop]*a[cint];

       else if(oper[otop]=='/')
              {  if(a[cint]!=0)
                   ans[++atop]=ans[atop]/a[cint];
                else
                   printf("\nError!!Divide by Zero\n");
              }

   s=s*(-1);
    }
    else

  {


      printf("Enter the operator:\t");
      scanf("%s",&c);
     if(c=='+'||c=='-'||c=='*'||c=='/')
     {
         oper[++otop]=c;

     }
     else

    {
      printf("Oops!! It seems you have entered Invalid opertor\n");

        s=1;
    }
     s=s*(-1);

 }
}

void display()
{
printf("_____________________________________\n\n");
    printf("\tAnswer :\t%.2f\n",ans[atop]);
    printf("_____________________________________\n");
}

void undo()
{
  r[++rtop]=ans[atop];
  --atop;
   cu+=1;
   printf("\nUndo is Successful\n");
  display();
}

void redo()
{
  --cu;
  ans[++atop]=r[rtop--];
  printf("\nRedo is Successful\n");
  display();
}
