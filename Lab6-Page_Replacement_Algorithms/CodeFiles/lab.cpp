#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <list>
#include <queue>
#include<tuple>
#include <bits/stdc++.h> // for sort
using namespace std;

vector<int> processes;


void dataFromFile()
{
    fstream newfile;
    newfile.open("./data.txt",ios::in); 
        if (newfile){   
        
            string line;       
            while(getline(newfile, line)){ 
               char *a;
               char l[line.size()+1];
               strcpy(l, line.c_str());
               
               // split the line by spaces.
               
               a = strtok(l, " ");
               
               while (a != NULL)
               {     int num = stoi(a);
                     processes.push_back(num);
                     a = strtok(NULL, " ");
                     
               }
               }
                   
}
}
void FIFO (vector<int> processes,int no_of_frames){
      int page_fault = 0;  // number of page faults
      int hit = 0;         // number of hits
      queue<int> frame;
      
      for (auto i = processes.begin(); i != processes.end(); i++ ){   // Auto deduce type to be iterator of a vector of ints.
          if (frame.size() == no_of_frames){
		   bool found = false;
		   queue<int> copy_queue = frame;
		   while (!copy_queue.empty()){         // Check if page is already present
		       int front =  copy_queue.front();
		       if (*i == front){
			  found = true;
			  hit += 1;  
			  break;
		       } 
		       copy_queue.pop();     
		  }
		  if (found == false)  {
			frame.pop();
			frame.push(*i);      //dereferencing the iterator
			page_fault +=1;
		  }
             }
           else{
              frame.push(*i);
              page_fault += 1;
           }
      } 	
      cout << "***************** FIFO *****************" << endl; 
      cout << "No of page faults = " << page_fault << endl;
      cout << "No of hits = " << hit << endl;  
}

void LRU (vector<int> processes,int no_of_frames){
      int page_fault = 0;  // number of page faults
      int hit = 0;         // number of hits
      queue<int> frame;      
      
      for (int i = 0 ; i < processes.size() ; i++ ){   // Auto deduce type to be iterator of a vector of ints.
 
          if (frame.size() == no_of_frames){
		   bool found = false;
		   queue<int> copy_queue = frame;
		   while (!copy_queue.empty()){         // Check if page is already present
		       int front =  copy_queue.front();
		       if (processes[i] == front){
			  found = true;
			  hit += 1;  
			  break;
		       } 
		       copy_queue.pop();     
		  }
		  if (found == false)  {
			for (int k = 0; k<i;k++);{
			    queue<int> copy_queue2 = frame;
			     while(!copy_queue2.empty()){
			          if (copy_queue2.front() == processes[k]){
			              frame[l] = processes[i];
			              page_fault+=1;
			              break;
			              
			          }
			     }
			
		}
		  }
             }
           else{
              frame.push(processes[i]);
              page_fault += 1;
           }
      } 	
      cout << "***************** LRU *****************" << endl; 
      cout << "No of page faults = " << page_fault << endl;
      cout << "No of hits = " << hit << endl;  
}

int main(){
   int no_of_frames;
   dataFromFile();
   cout << "Enter the number of frames:" ;
   cin >> no_of_frames;
   cout << endl;      
   FIFO (processes,no_of_frames);
   LRU (processes,no_of_frames);
 
   return 0;
}
