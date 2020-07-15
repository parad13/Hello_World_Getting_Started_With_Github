#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
   int pid,status,w1;
   
   pid = fork();
   
   if(pid==0)
   {
       printf("Welcome to child process! \n");
       printf("In child process pid value = %d \n",pid);
       
       printf("Child process ID : %d \n",getpid());
       printf("Childs parent process ID : %d \n",getppid());
       
   }
   else
   {
       printf("Welcome to parent process! \n");
       printf("In parent process pid value = %d \n",pid);
       
       printf("Parent process ID : %d \n",getpid());
       //wait(NULL);
       w1=wait(&status);
       printf("Status is %d",WIFEXITED(status));
       printf("Return value of wait!,w1=%d \n",w1);
   }
    return 0;
}
