// program to simulate Round Robin process scheduling in OS

#include <stdio.h>

struct process
{
 int pn, at, bt, tat, wt, ct, btcopy;
};
struct process p[30];

int swap(int *x,int *y)
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}
 
int f = -1;
int r = -1;
int q[30], n;

int enque(int i)
{
 if(f == -1)
   f = r = 0;
else
 if(r == n-1)
   r = 0;
 else
   r++;
  
 q[r] = i;
 return 0;
}

int deque()
{
 int item = q[f];

  if(f == -1)
    return -1;
  else
 if(f == r)
   f = r = -1;
  else
   f = (f+1)%n;

 return item;
}

void main() 
{ 
  int qt;
  
  int ncopy;

  printf("Enter quantum time: ");
   scanf("%d", &qt);
  printf("Enter number of process: ");
   scanf("%d", &n);
  for(int i=0; i<n; i++)
    p[i].pn=i+1;
  printf("Enter burst time of each process: ");
  for(int i=0; i<n; i++)
    scanf("%d", &p[i].bt);
  printf("Enter arrival time of each process: ");
  for(int i=0; i<n; i++)
    scanf("%d", &p[i].at);
   
  for(int i=0; i<n; i++)
    for(int j=0; j<(n-1-i); j++)
      if(p[j].at > p[j+1].at)
      {
       swap(&p[j].at, &p[j+1].at);
       swap(&p[j].bt, &p[j+1].bt);
       swap(&p[j].pn, &p[j+1].pn);
      }

  for(int i=0; i<n; i++)
   p[i].btcopy = p[i].bt;

  ncopy = n;
  
  //for(int i=0; i<n; i++)
  //  {
  //   if(p[i].at == 0)
  //     enque(i);
  //  }  

  int sum = 0;
  int flag;
  
  enque(0);
  int x=1;

  while(ncopy != 0)
 {
   int i = deque();

   if(i == -1)
   {
     sum++;
     flag = 0;
   }
   else
   if(p[i].btcopy <= qt)
   {
    sum = sum + p[i].btcopy;
    p[i].btcopy = 0;
    ncopy--;
    p[i].ct = sum;
    flag = 0;
     
   }
   else if(p[i].btcopy > qt)
   {
    sum = sum + qt;
    p[i].btcopy = p[i].btcopy - qt;
    flag = 1;
   }

   
   for(int j=x; j<n; j++)
     {
      if(sum >= p[j].at)
      {
       enque(j);
       x++;
      }
     }
   
  if(flag == 1)
   enque(i);
 }
  
  
  printf("\nprocess\t CT\t \n");
  for(int i=0; i<n; i++)
    printf("%d\t\t %d\t \n", p[i].pn, p[i].ct);
  
  printf("\nHello \n");
  // return 0;
}
