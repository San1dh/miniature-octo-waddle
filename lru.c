// program to simulate Least Recently Used (LRU) page replacement algorithm in mapping pages to frames in memory

#include <stdio.h>

int m;
int f[10];
int q[10];

void printseq()
{
 for(int l=0; l<m; l++)
  printf("%d\t", f[l]);

 printf("\n");
}
int fr = -1;
int re = -1;

int enque(int i)
{
 if(fr == -1)
  fr = re = 0;
 else
  for(int o=0; o<(m-1); o++)
   q[o+1] = q[o];

 q[fr] = i;
 return 0;
}
int deque()
{
 int item = q[re];
 if(fr == re)
  fr = re = -1;
 else if(re == 0)
  printf("None");
 else if(re<m)
  re++;

 return item;
}
int delelm(int ele)
{
 for(int pos=0; pos<m; pos++)
  if(ele == q[pos])
   for(int a = pos; a<(m-1); a++)
    q[a] = q[a+1];

 return 0;
}

int main()
{
 int n;
 printf("input number of pages: ");
  scanf("%d", &n); 
 int p[n];
 printf("input pages: ");
 for(int i=0; i<n; i++)
  scanf("%d", &p[i]);
 printf("input number of frames: ");
  scanf("%d", &m);

 int hit, pf;
 int i, j, flag;
 flag = 0;
 f[0] = p[0];
 enque(0);
 printseq();
 i = j = 1;
 while(i < m)
 {
  for(int k=0; k<i; k++)
   if(p[j] == f[k])     // error
   {
    j++;
    delelm(k);
     printf("yo ");
    enque(k);
     printf("yo ");
    flag = 1;
    printseq();
   }
   if(flag == 0)
   {
    f[i] = p[j];
     printseq();
    j++;
    i++;
    enque(i);
     printf("yo ");
    
   }
 }
   
 return 0;
}
