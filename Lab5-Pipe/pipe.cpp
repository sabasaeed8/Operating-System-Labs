#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main(){
   int buffer[2];
   char* message;
   pid_t pid;
     cout << " Student RoLL NO and Name";
 
   if(pipe(buffer) < 0){
      cout << "\n\tPipe Function Failed!";
      return 0;
   }

   if (fork() == 0){
       char* message = (char*)"Message From Child 1: My Name is SABA.";
       cout << "\n\t1st Child Process ID: " << getpid() << "\n";
       write(buffer[1], message, strlen(message));
    } 
   else {
      cout << "\n\tParent Process ID: " << getpid() << "\n";
//Your code here
      write(buffer[1], message, strlen(message));
   } 
   
   if (fork() == 0){
       char* message = (char*)"Message From Child 2: My RollNo is 256.";
       cout << "\n\t2nd Child Process ID: " << getpid() << "\n";
       write(buffer[1], message, strlen(message));
    } 

   else {
      cout << "\n\tParent Process ID: " << getpid() << "\n";
//Your code here
      write(buffer[1], message, strlen(message));
   }
   
   for (int i = 0; i < 2; i++) {
        /* read pipe */
        read(buffer[0], message, strlen(message));
        cout << "\n" << message;
    }
   return 0;
}
