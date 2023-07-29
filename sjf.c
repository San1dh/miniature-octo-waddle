// program to simulate Shortest Job First algorithm in OS process scheduling

#include <stdio.h>

struct process
{
 int pn, at, bt, tat, wt, ct;
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
  int n;
  

  printf("Enter number of process: ");
   scanf("%d", &n);
  for(int i=0; i<n; i++)
    p[i].pn=i;
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
  int x, small;

  p[0].ct= p[0].at + p[0].bt;

  for(int i=1; i<n; i++)
    {
      small = i;
      if(p[i-1].ct >= p[i].at)
       // if(i!=n)
        {
      {
        for(int j=i; j<n; j++)
            if(p[i-1].ct >= p[j].at)
             x=j;
        for(int k=i; k<x; k++)
          {
          if(p[k+1].bt < p[small].bt)
           small = k+1;
           
          }
       swap(&p[i].at, &p[small].at);
       swap(&p[i].bt, &p[small].bt);
       swap(&p[i].pn, &p[small].pn);
        }
        p[i].ct = p[i-1].ct + p[i].bt;
             
        }
      else 
        p[i].ct = p[i].at + p[i].bt;
      }
  printf("\nprocess\t CT\t \n");
  for(int i=0; i<n; i++)
    printf("%d\t\t %d\t \n", p[i].pn++, p[i].ct);
  printf("\nHello \n");
  return 0;
}
