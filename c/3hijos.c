
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
    pid_t pid1,pid2,pid3, pid21;
    int status;
    pid1 = fork();
    int i;
    if(pid1==0)//soy el hijo
    {
        printf("soy el hijo 1 (%d, hijo de %d)\n", getpid(), getppid());
    }
    else // padre
    {
        pid2 = fork(); //creo hijo 2
       if(pid2==0)//soy el hijo2
        {
          printf("soy el hijo 2 (%d, hijo de %d)\n", getpid(), getppid());
          pid21=fork(); //creo hijo 21
          if(pid21==0)//soy el hijo21
        {
             printf("soy el hijo 21 (%d, hijo de %d)\n", getpid(), getppid());
    } else{
          waitpid(pid21, &status, 0);// hijo21 espera a hijo2
    }}else // padre
    {  
       
        pid3 = fork(); //creo hijo 3
       if(pid3==0)//soy el hijo3
        {
          printf("soy el hijo 2 (%d, hijo de %d)\n", getpid(), getppid());
    }
    else // padre
    {
        waitpid(pid1, &status, 0);// padre espera a hijo1
         waitpid(pid2, &status, 0);// padre espera a hijo2
          waitpid(pid3, &status, 0);// padre espera a hijo3
    } //  else del hijo1
}//else del hijo2
    }//else del hijo3
    return 0;
}
