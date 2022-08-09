#include <iostream> 
#include <unistd.h>    //include this header for fork()
using namespace std;

       bool isPrime(int num){
	if (num == 1)
	{
		return true;
	}
	else
	{
		double result;
		int divisor = num - 1;
		while (num != -1)
		{
			result = num % divisor;
			if (result == 0)
			{
				num = -1;
			}
			else
			{
				divisor = divisor - 1;
			}
		}

		if (divisor == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}   } 
	  
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
	   int count;
	   for(int i = 2; i <= 25001; ++i) 
	{       if (isPrime(i)==true){
		   count+=1;
		}
	} 
	cout << count <<endl;}
	
	if (rank == 1){
	   cout << "Process 1 :";
	   int count;
	   for(int i = 25002; i <= 50001; ++i) 
	{       if (isPrime(i)){
		   count+=1;
		}
	} 
	cout << count <<endl;}
	
	if (rank == 2){
	   cout << "Process 2 :";
	   int count;
	   for(int i = 50002; i <= 75001; ++i) 
	{       if (isPrime(i)){
		   count+=1;
		}
	} 
	cout << count <<endl;}
	if (rank == 3){
	   cout << "Process 3 :";
	   int count;
	   for(int i = 75002; i <= 100001; ++i) 
	{       if (isPrime(i)){
		   count+=1;
		}
	} 
	cout << count <<endl;}
}
	
	
	

