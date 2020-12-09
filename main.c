#include <stdio.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    printf("this is the initial message\n");
    int status;
    int f = fork();
    if(f){
    int r = rand() % 2 + 2;
    printf("pid: %d\n",f);
    sleep(r);
    return r;
    }
    wait(&status);
    printf("status: %d\n",status);
    printf("child slept for %d seconds\n",WEXITSTATUS(status));

    return 0;

}