// program to implement full duplex communication between multiple processes in the same program

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
 int fd1[2], fd2[2], fd3[3];
  int ret1, ret2, ret3; // for pipes 1, 2, 3
  pid_t pid1;
  int mesg[5], buf[5], buf1[5];

  ret1 = pipe(fd1);
  ret2 = pipe(fd2);
  ret3 = pipe(fd3);
  if(ret1<0 || ret2<0 || ret3<0)
  {
    printf("Error during pipe creation");
    return -1; 
  }
   pid1 = fork(); // printf("%d", pid1);
   if (pid1 < 0)
   {
     printf("Error");
     return -1;
   }
  else if (pid1 == 0)
  {
     printf("Child 1\n");

    read(fd1[0], buf, sizeof(buf)); // read from pipe1

    for (int i=0; i<5; i++)
     buf[i]= buf[i]*buf[i];

    printf("\nSquared Numbers:\n");
    for (int i=0; i<5; i++)
      printf("%d\t", buf[i]);
    printf("\n\n");

   write(fd1[1], buf, sizeof(buf)); // write to pipe2
  }
   else if(pid1 > 0)
   {
    printf("Parent\n");
     
    printf("Input 5 numbers:\n");
    for (int i=0; i<5; i++)
       scanf("%d", &mesg[i]);

     write(fd1[1], mesg, sizeof(mesg)); // write to pipe1

     // fork again 
     pid_t pid2;
     pid2 = fork();
     if (pid2 < 0)
   {
     printf("Error");
     return -1;
   }
    else if(pid2 == 0) // 3rd process 
    {
     printf("Child 2\n");
    read(fd2[0], buf1, sizeof(buf1)); // read from pipe2

      int sum[5];
      for (int i=0; i<5; i++)
        sum[0] += buf1[i];

      write(fd3[1], sum, sizeof(sum)); // write to pipe3
    }
    else if(pid2 > 0)
    {
     // not necessary
    printf("Other\n");
    // wait(NULL);
      printf("some\n");
    }
     printf("back to parent\n");
     // wait(NULL);
     int s[5];
     read(fd3[0], s, sizeof(s)); // read from pipe3
     printf("\nFinal sum of squared numbers: %d", s[0]);
     printf("\n\n ended\n");
     }
  return 0;
  }
