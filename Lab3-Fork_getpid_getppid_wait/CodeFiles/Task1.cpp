#include <iostream> 
#include <unistd.h>    //include this header for fork()
using namespace std;

int main(){
   int pid;
   pid = fork();
   if(pid == 0){
      cout << "\n Parent Process id: "
           << getppid() << endl;
      cout << "\n Child Process id: "
           << getpid() << endl;
   }

   return 0;
}
