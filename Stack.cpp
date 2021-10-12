#include<stdio.h>
#include<stdlib.h>

typedef struct myStack
{

int capacity;
int *arr;
int top;

}S;

void create(S *s,int c)
{
  s->capacity=c;
  s->top=-1;
  s->arr=(int *)calloc(s->capacity,sizeof(int));

}

void push(S *s,int element)
{
 if(s->top>s->capacity-1)
 {
 printf("Stack overflow!\n");
 return;
 }

 s->top++;
 s->arr[s->top]=element;


}

int pop(S *s)
{

if(s->top==-1)
{
printf("Stack underflow!\n");
return -1;
}

int result=s->arr[s->top];
s->top--;
return result;

}

int peek(S *s)
{

if(s->top==-1)
{
printf("Stack underflow!\n");
return -1;
}

return s->arr[s->top];

}

int size(S *s)
{

 return s->top+1;

}

void print(S *s)
{
  if(size(s)==0)
  {
  printf("Stack is Empty\n");
  return;

  }
   printf("****Current Stack Content****\n");

  for(int i=s->top;i>=0;i--)
  {

  printf("%d \n",s->arr[i]);

  }

}

int thirdFromTop(S *s,S *t)
{

if(size(s)<3)
{
  printf("Error\n");

 return-1;


}

int i=0;
while(i<2)
{

push(t,pop(s));
i++;

}

int Y=peek(s);

 i=0;
while(i<2)
{

push(s,pop(t));
i++;

}

return Y;


}



void popNelement(S *s,S *t,int n)
{

 if(size(s)<n)
 {
   printf("Error\n");
  return ;

 }

 int i=0;
 while(i<n)
 {
 push(t,pop(s));
 i++;
 }

 print(s);

i=0;
 while(i<n)
 {
 push(s,pop(t));
 i++;
 }



}

int thirdFromBottom(S *s,S *t)
{

if(size(s)<3)
{
  printf("Error\n");

 return -1;


}
  int sz=size(s);
  int i=0;
 while(i<sz-3)
 {
   push(t,pop(s));
   i++;

 }

int Y=peek(s);
 i=0;
 while(i<sz-3)
 {
   push(s,pop(t));
   i++;

 }


return Y;


}

int main()
{

  S s,t;
  int c;
  int o;
  int ele;
  printf("Enter capacity of the stack\n");

  scanf("%d",&c);

  create(&s,c);
  create(&t,c);

  do
  {
    printf("\n");
printf("****************************************************************\n");
  printf("Enter The Option\n");
  printf("1:push element equal to capacity of stack\n");
  printf("2:pop\n");
  printf("3:peek\n");
  printf("4:Current size\n");
  printf("5:To get Third element from top of the stack\n");
  printf("6:To get Third element from Bottom of the stack\n");
  printf("7:Pop N elements from the stack\n");
    printf("8:Print current stack\n");
    printf("9:Clear output\n");
  printf("0:exit the program\n");
  printf("****************************************************************\n");
  printf("\n");
  scanf("%d",&o);

  int n;
  int el;

  switch(o)
  {

  case 1:
         for(int i=0;i<c;i++)
         {
           if(size(&s)==c)
           {
             break;
           }
         printf("Enter the element to be pushed!\n");
         scanf("%d",&el);
         push(&s,el);
         }
         break;

   case 2:


         printf("%d Popped succesfully!\n",pop(&s));

         break;

          case 3:

         if(peek(&s)==-1)
         {

         }
         else
         printf("Peek: %d \n",peek(&s));

         break;

          case 4:

        printf("Current size: %d \n",size(&s));

         break;


          case 5:
            printf("Third element from top is %d\n",thirdFromTop(&s,&t));


            break;

     case 6:


        printf("Third element from Bottom is %d\n",thirdFromBottom(&s,&t));

         break;

            case 7:

                    printf("Enter the value of N\n");
                    scanf("%d",&n);
                   popNelement(&s,&t,n);
                   break;

        case 8:
                   print(&s);
                   break;

        case 9:
           system("cls");
           break;

        default:
                  printf("Invalid Input\n");
                  break;

  }
  }while(o!=0);
return 0;
}
