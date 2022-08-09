#include <iostream> 
#include <unistd.h>    //include this header for fork()
using namespace std;

int main(){

   for (int i = 0; i < 3; i++)
	{
		fork();
	}
   cout << "Hello from the process " << getpid() << endl;
}
