#include<bits/stdc++.h>
typedef struct Stack
{
  int top;
  int capa;
  int *arr;
}st;

void create(st *s,int c)
{
  s->top=-1;
  s->capa=c;
  s->arr=(int *)calloc(s->capa,sizeof(int));
}


int size(st *s)
{
  return s->top+1;
}

void push(st *s,int ele)
{
  if(s->top>=s->capa-1)
{
    printf("\n Stack Overflow");
    return;
}
    s->top++;
    s->arr[s->top]=ele;
}

int pop(st *s)
{
  if(s->top==-1)
{
  printf("\n Stack Underflow.");
  return -1;
}
    int res=s->arr[s->top];
    s->top--;
    return res;

}
int peek(st *s)
{
  if(s->top==-1)
  {
    printf("\nStack Underflow");
    return -1;
  }
  return s->arr[s->top];
}
void print(st *s)
{
  int i;
  printf("\n");
  for(i=s->top;i>=0;i--)
  printf("%d\t",s->arr[i]);
  printf("\n");
}

void popNele(st *s,st *t,int n)
{
  int i=0;
  if(size(s) < n)
  {
  printf("Error!");
  return;
  }
  while(i<n)
  {
    push(t,pop(s));
    i++;
  }
  print(s);
  print(t);
  i=0;
  while(i<n)
  {
    push(s,pop(t));
    i++;
  }
  print(s);

}

int third_ele_from_top(st *s,st *t)
{
  int i;
  int y;
  for(i=0;i<2;i++)
  push(t,pop(s));
  y=peek(s);
  for(i=0;i<2;i++)
  push(s,pop(t));
  return y;
}

int third_ele_from_bottom(st *s,st *t)
{
  int i;
  int y;
  for(i=0;i<size(s)-2;i++)
  push(t,pop(s));
  y=peek(s);
  for(i=0;i<size(s)-2;i++)
  push(s,pop(t));
  return y;
}


int main()
{
  st s;
  st t;
  int result;
  create(&s,5);
  create(&t,5);
  push(&s,1);
    push(&s,2);
      push(&s,3);
        push(&s,4);
          push(&s,5);
          print(&s);
          result=third_ele_from_top(&s,&t);
          printf("Third element from top is:%d",result);
          popNele(&s,&t,3);
          result=third_ele_from_bottom(&s,&t);
          printf("\nThird element from bottom is:%d",result);

  return 0;
}
