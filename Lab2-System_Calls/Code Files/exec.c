#include <stdio.h>
#include <unistd.h>    //include this header for fork()


int main(){
   int f;
   f = fork();
   if(f==0){
      char *args[] = {"./exec",NULL};
      execvp(args[0],args);
     
   }
   else if(f == -1){
      printf("Process Creation Unsuccessful. \n");
   }
   

   return 0;
}
