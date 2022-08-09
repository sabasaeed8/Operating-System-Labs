#include <iostream>
#include <fstream>
#include <pthread.h>
#include <vector>
#include <cstring>
using namespace std;
vector<int> processes;

bool check_duplicate(int num){
   bool found = false;
   for (auto i = processes.begin(); i != processes.end(); i++ ){
        if (*i == num){
	      found = true;
	      break;} 
   }
   return found;

}
void* read_files(void* file_name){
   string file = *((string*) file_name);
   fstream newfile;
    newfile.open("./"+file,ios::in); 
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
                     if (num >= 0){
                        if (check_duplicate(num)==false){
                              processes.push_back(num);    }
                     a = strtok(NULL, " ");
                     }
                     else{
                        break;
                     }
               }
               }
                   
}
   else{ 
       cout << "File does'nt exist. Please Enter correct file name." << endl;
   }
   
   return 0;
}
int main(){
    // Enter File names.
    string f1,f2;
    cout << "Enter name of first file: ";
    cin >> f1;
    cout << "Enter name of secod file: ";
    cin >> f2;
    // Creating Threads
    pthread_t t1,t2;
   
    pthread_create(&t1,NULL, read_files, &f1);
    pthread_create(&t2,NULL, read_files, &f2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    int sum=0;
    int total=0;
    for (auto j = processes.begin(); j != processes.end(); j++ ){
         sum+= *j;
         total +=1;
    }
    int avg = sum/total;
    cout << "Average: " << avg << endl;
    return 0;

}
