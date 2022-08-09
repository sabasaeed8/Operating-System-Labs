#include <iostream> 
#include <unistd.h>    //include this header for fork()
using namespace std;

       
 int main(){      
       int rank = 0;

	for(int i = 1; i <= 3; ++i) 
	{
		if (fork() == 0)
		{
			rank = rank + i;
			break;
		}
	}
	if (rank == 0){
	   cout << "Process 0 :";
	   for(int i = 1; i <= 25; ++i) 
	{
		cout << i << ",";
		
	}cout << endl;}
	
	if (rank == 1){
	   cout << "Process 1 :";
	   for(int i = 26; i <= 50; ++i) 
	{
		cout << i << ",";
		
	}cout << endl;}
	
	if (rank == 2){
	   cout << "Process 2 :";
	   for(int i = 51; i <= 75; ++i) 
	{
		cout << i << ",";
		
	}
	cout << endl;}
	if (rank == 3){
	   cout << "Process 3 :";
	   for(int i = 76; i <= 100; ++i) 
	{
		cout << i << ",";
		
	}
}
}
