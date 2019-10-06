//
//  main.c
//  20261_A2
//
//  Created by Xcode User on 2019-10-06.
//  Copyright © 2019 Huynh. All rights reserved.
//

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// function handler for child process declaration
void sighup(){
    signal(SIGHUP, sighup);
    printf("CHILD: I have received a SIGHUP\n");
}

void sigint(){
    signal(SIGINT, sigint);
    printf("CHILD: I have received a SIGINT\n");
}

void sigquit(){
    printf("My DADDY has Killed me!!!\n How thoughful of him to not leave me an orphan.");
    exit(0);
}

//main method
int main(int argc, const char * argv[]) {
 
    int pid = fork();
    
    //check to see if for worked
    if (pid < 0) {
        printf("fork error");
        exit(1);
    }
    
    if (pid == 0) { //checking for child
        while(pid == 0){ //making sure child is a child then runs handler
        signal(SIGHUP, sighup);
        signal(SIGINT, sigint);
        signal(SIGQUIT, sigquit);
        }
    }
    else //parent
    {
        sleep(3);
        printf("PARENT: sending SIGHUP\n");
        kill(pid, SIGHUP);
        sleep(3);
        
        printf("PARENT: sending SIGINT\n");
        kill(pid, SIGINT);
        sleep(3);
        
        printf("PARENT: sending SIGQUIT\n");
        kill(pid, SIGQUIT);
        sleep(3);
        
    }
    return 0;
}


