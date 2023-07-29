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
int main() 
{ 
  int n, q, que[30];
  
  int f, r;
  int ncopy;

  printf("Enter quantum time: ");
   scanf("%d", &q);
  printf("Enter number of process: ");
   scanf("%d", &n);
  ncopy=n;
  for(int i=0; i<n; i++)
    p[i].pn=i;
  printf("Enter burst time of each process: ");
  for(int i=0; i<n; i++)
    {
      scanf("%d", &p[i].bt);
      p[i].btcopy = p[i].bt;
    }
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
       swap(&p[j].btcopy, &p[j+1].btcopy);
      }

  int max=1;
  f=r=0;
  p[0].ct = 0;
  
  if(p[0].at != 0)
  {
   p[0].ct = p[0].at;
  }
  
  if(p[0].btcopy <= q)
  {
    p[0].ct = p[0].ct + p[0].bt;
    p[0].btcopy = 0;
    max = 0;
    ncopy--;
    
  }
  else
  {
    p[0].ct = p[0].ct + q;
    p[0].btcopy = p[0].btcopy - q;
  }
  int prev = 0;
  
  while(ncopy != 0)
  {
    printf("hi\n");
    if(max != 0)
    {
   for(int i=prev+1; i<n; i++)
    if(p[prev].ct >= p[i].at)
    {
       r++;
       que[r]=prev;
       que[f]=i;
       f++;
       max++;
     }
    }
    else
     for(int i=prev+1; i<n; i++)
      if(p[prev].ct >= p[i].at)
      {
       max++;
       que[f]=i;
        f++;
      }

    for(int i=0; i<max; i++)
      printf("%d\t", que[i]);
    break;
  } 
  
  //printf("\nprocess\t CT\t \n");
  //for(int i=0; i<n; i++)
    //printf("%d\t\t %d\t \n", p[i].pn, p[i].ct);
  
  printf("\nHello \n");
  return 0;
}
