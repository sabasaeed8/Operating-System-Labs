#include <iostream>
#include <stdio.h>
#include <sys/types.h> //include this header for fork()
#include <unistd.h>    //include this header for fork()
using namespace std;

int main(){
   int f1,f2,f3;
   f1 = fork();
   if (f1 == 0){
      cout << "\n I am Parent-->child." << "\n";
      f2 = fork(); 
      if (f2 == 0){
         cout << "\n I am Parent-->child-->child." << "\n";
         f3 = fork(); 
         if (f3 == 0){
         cout << "\n I am Parent-->child-->child-->child." << "\n";}
      }   
   }
   else if (f1 == -1){
      cout << "\n Error" << "\n";
   }
   else{
      cout << "\n I am Parent." << "\n";
   }
}
