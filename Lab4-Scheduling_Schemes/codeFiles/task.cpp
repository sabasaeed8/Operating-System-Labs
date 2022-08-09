#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <list>
#include <climits>
using namespace std;

vector<int> processes_FCFS;
vector<int> burst_FCFS;
vector<int> arrival_FCFS;
vector<int> processes_SJFN;
vector<int> burst_SJFN;
vector<int> arrival_SJFN;
vector<int> processes_SJFP;
vector<int> burst_SJFP;
vector<int> arrival_SJFP;
int temp;




void dataFromFileFCFS(int n)
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
               int i = 0;
               while (a != NULL)
               {   
                   if(i == 0){
                     int num = stoi(a);
                     processes_FCFS.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}
                   if(i == 1){
                     int num = stoi(a);
                     burst_FCFS.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}
                   if(i == 2){
                     int num = stoi(a);
                     arrival_FCFS.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}  
               } 
               
              
               } 
              
             }   
       for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(arrival_FCFS[i]>arrival_FCFS[j])
			{
				temp  = arrival_FCFS[i];
				arrival_FCFS[i]=arrival_FCFS[j];
				arrival_FCFS[j]=temp;
				
				temp  = burst_FCFS[i];
				burst_FCFS[i]=burst_FCFS[j];
				burst_FCFS[j]=temp;
				
				temp  = processes_FCFS[i];
				processes_FCFS[i]=processes_FCFS[j];
				processes_FCFS[j]=temp;
				
			}
		}
	}
}

void dataFromFileSJFN(int n)
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
               int i = 0;
               while (a != NULL)
               {   
                   if(i == 0){
                     int num = stoi(a);
                     processes_SJFN.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}
                   if(i == 1){
                     int num = stoi(a);
                     burst_SJFN.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}
                   if(i == 2){
                     int num = stoi(a);
                     arrival_SJFN.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}  
               } 
               
              
               } 
              
             }
       //  Sort according to arrival time
       for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(arrival_SJFN[i]>arrival_SJFN[j])
			{
				temp  = arrival_SJFN[i];
				arrival_SJFN[i]=arrival_SJFN[j];
				arrival_SJFN[j]=temp;
				
				temp  = burst_SJFN[i];
				burst_SJFN[i]=burst_SJFN[j];
				burst_SJFN[j]=temp;
				
				temp  = processes_SJFN[i];
				processes_SJFN[i]=processes_SJFN[j];
				processes_SJFN[j]=temp;
				
			}
		}
	}
	
     // Compare second process BT with the rest ones. If any one of them is shorter, Compare its arrival time.
     // If it has been arrivad swap. 	
      for(int i=0;i<n-1;i++)
	{      
		for(int j=i+1;j<n-1;j++)
		{
		  if(i==0){
		   if(burst_SJFN[i+1] > burst_SJFN[j+1]){
		      if (burst_SJFN[i] > arrival_SJFN[j+1]){
		            temp  = arrival_SJFN[i+1];
					arrival_SJFN[i+1]=arrival_SJFN[j+1];
					arrival_SJFN[j+1]=temp;
				
					temp  = burst_SJFN[i+1];
					burst_SJFN[i+1]=burst_SJFN[j+1];
					burst_SJFN[j+1]=temp;
				
					temp  = processes_SJFN[i+1];
					processes_SJFN[i+1]=processes_SJFN[j+1];
					processes_SJFN[j+1]=temp;
		          
		      }
		   }
		   }
		  else{
		    if(burst_SJFN[i+1] > burst_SJFN[j+1]){
		      if (burst_SJFN[i]+burst_SJFN[i-1] > arrival_SJFN[j+1]){
		            temp  = arrival_SJFN[i+1];
					arrival_SJFN[i+1]=arrival_SJFN[j+1];
					arrival_SJFN[j+1]=temp;
				
					temp  = burst_SJFN[i+1];
					burst_SJFN[i+1]=burst_SJFN[j+1];
					burst_SJFN[j+1]=temp;
				
					temp  = processes_SJFN[i+1];
					processes_SJFN[i+1]=processes_SJFN[j+1];
					processes_SJFN[j+1]=temp;
		          
		      }
		   }
		     
		  }
		   
		      
		}
		
	
	}
}

void dataFromFileSJFP(int n)
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
               int i = 0;
               while (a != NULL)
               {   
                   if(i == 0){
                     int num = stoi(a);
                     processes_SJFP.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}
                   if(i == 1){
                     int num = stoi(a);
                     burst_SJFP.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}
                   if(i == 2){
                     int num = stoi(a);
                     arrival_SJFP.push_back(num);
                     a = strtok(NULL, " ");
                     i+=1;}  
               } 
               
              
               } 
              
             }   
       // Sort the processes according to their arrival time
       for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(arrival_SJFP[i]>arrival_SJFP[j])
			{
				temp  = arrival_SJFP[i];
				arrival_SJFP[i]=arrival_SJFP[j];
				arrival_SJFP[j]=temp;
				
				temp  = burst_SJFP[i];
				burst_SJFP[i]=burst_SJFP[j];
				burst_SJFP[j]=temp;
				
				temp  = processes_SJFP[i];
				processes_SJFP[i]=processes_SJFP[j];
				processes_SJFP[j]=temp;
				
			}
		}
	}	
}


void WaitingTimeFCFS(vector<int> processes_FCFS, int n, vector<int> burst_FCFS, int wt_FCFS[], vector<int> arrival_FCFS)
{
    
    int CPU_time[n];
    CPU_time[0] = arrival_FCFS[0];
    wt_FCFS[0] = 0;

    for (int i = 1; i < n ; i++)
    {
        // Add burst time of previous processes
        CPU_time[i] = CPU_time[i-1] + burst_FCFS[i-1];
 
        // Find waiting time for current process =
        // sum - at[i]
        wt_FCFS[i] = CPU_time[i] - arrival_FCFS[i];
 
    }
}

void WaitingTimeSJFN(vector<int> processes_SJFN, int n, vector<int> burst_SJFN, int wt_SJFN[], vector<int> arrival_SJFN)
{
    
    int CPU_time[n];
    CPU_time[0] = arrival_SJFN[0];
    wt_SJFN[0] = 0;

    for (int i = 1; i < n ; i++)
    {
        // Add burst time of previous processes
        CPU_time[i] = CPU_time[i-1] + burst_SJFN[i-1];
 
        // Find waiting time for current process =
        // sum - at[i]
        wt_SJFN[i] = CPU_time[i] - arrival_SJFN[i];
 
    }
}
void WaitingTimeSJFP(vector<int> processes_SJFP, int n, vector<int> burst_SJFP,int wt_SJFP[], vector<int> arrival_SJFP) {
   int response[n];
   for (int i = 0; i < n; i++)
   response[i] = burst_SJFP[i];
   int complete = 0, t = 0, minm = INT_MAX;
   int shortest = 0, finish_time;
   bool check = false;
   while (complete != n) {
      for (int j = 0; j < n; j++) {
         if ((arrival_SJFP[j] <= t) && (response[j] < minm) && response[j] > 0) {
            minm = response[j];
            shortest = j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      // decrementing the remaining time
      response[shortest]--;
      minm = response[shortest];
      if (minm == 0)
         minm = INT_MAX;
         // If a process gets completely
         // executed
         if (response[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            // Calculate waiting time
            wt_SJFP[shortest] = finish_time -
            burst_SJFP[shortest] -
            arrival_SJFP[shortest];
            if (wt_SJFP[shortest] < 0)
               wt_SJFP[shortest] = 0;
         }
         // Increment time
         t++;
   }
}

void avgTime(vector<int> processes_FCFS, int n, vector<int> burst_FCFS, vector<int> arrival_FCFS,vector<int> processes_SJFN,vector<int> burst_SJFN, vector<int> arrival_SJFN,vector<int> processes_SJFP,vector<int> burst_SJFP, vector<int> arrival_SJFP)
{
    int wt_FCFS[n];
    int wt_SJFN[n];
    int wt_SJFP[n];
    
    // Function to find waiting time of all processes
    WaitingTimeFCFS(processes_FCFS, n, burst_FCFS, wt_FCFS, arrival_FCFS);
    WaitingTimeSJFN(processes_SJFN, n, burst_SJFN, wt_SJFN, arrival_SJFN);
    WaitingTimeSJFP(processes_SJFP, n, burst_SJFP, wt_SJFP, arrival_SJFP);
   
    for(int i=0;i<n;i++)
	{		
		for(int j=i+1;j<n;j++)
		{
			if(processes_SJFN[i]>processes_SJFN[j])
			{
				temp  =arrival_SJFN[i];
				arrival_SJFN[i]=arrival_SJFN[j];
				arrival_SJFN[j]=temp;
				
				temp  =burst_SJFN[i];
				burst_SJFN[i]=burst_SJFN[j];
				burst_SJFN[j]=temp;
				
				temp  = processes_SJFN[i];
				processes_SJFN[i]=processes_SJFN[j];
				processes_SJFN[j]=temp;
				
				temp  = wt_FCFS[i];
				wt_FCFS[i]=wt_FCFS[j];
				wt_FCFS[j]=temp;
				
				temp  = wt_SJFN[i];
				wt_SJFN[i]=wt_SJFN[j];
				wt_SJFN[j]=temp;
					
				temp  = wt_SJFP[i];
				wt_SJFP[i]=wt_SJFP[j];
				wt_SJFP[j]=temp;
				
			}
		}
	}
    
    // Display processes along with all details
    cout << "Processes " << " Burst Time " << " Arrival Time "
         << " Waiting Time FCFS " << " Waiting Time SJF_N " << " Waiting Time SJF_P\n";
    int total_wt_FCFS = 0;
    int total_wt_SJFN = 0;
    int total_wt_SJFP = 0;
    for (int i = 0 ; i < n ; i++)
    {
        total_wt_FCFS = total_wt_FCFS + wt_FCFS[i];
        total_wt_SJFN = total_wt_SJFN + wt_SJFN[i];
        total_wt_SJFP = total_wt_SJFP + wt_SJFP[i];
        cout << " " << "P"<<processes_SJFN[i] << "\t\t" << burst_SJFN[i] << "\t\t"
             << arrival_SJFN[i] << "\t\t" << wt_FCFS[i] << "\t\t " << wt_SJFN[i] << "\t\t " << wt_SJFP[i] << "\t\t "
             << endl;
    }
 
    cout << "Average waiting time FCFS = "
         << (float)total_wt_FCFS / (float)n << endl;
    cout << "Average waiting time SJFN = "
         << (float)total_wt_SJFN / (float)n << endl;
    cout << "Average waiting time SJFP = "
         << (float)total_wt_SJFP / (float)n << endl;
}

int main(){
   int n = 4;
   dataFromFileFCFS(n);
   dataFromFileSJFN(n);
   dataFromFileSJFP(n);
   avgTime(processes_FCFS, n, burst_FCFS, arrival_FCFS,processes_SJFN, burst_SJFN, arrival_SJFN,processes_SJFP,burst_SJFP,arrival_SJFP);
   return 0;
}
