#include <stdio.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

int main(){   
    srand(time(NULL));
    printf("pid of parent: %d\n",getpid());
    int status;
    int f = fork();

    if(f){
        f = fork();
    }

    if(f){
        int c = wait(&status);
        printf("%d slept for %d seconds\n",c,WEXITSTATUS(status));
        printf("the parent is done\n");
        return 0;
    }

    if(!f){    
    printf("child pid: %d\n",getpid());
    int r = rand() % 9 + 2;
    sleep(r);
    printf("child is finished\n");
    return r;
    }    
}