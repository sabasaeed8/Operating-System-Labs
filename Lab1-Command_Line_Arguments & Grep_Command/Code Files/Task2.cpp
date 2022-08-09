#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;
  
int main(int argc, char** argv)
{
    fstream newfile;
    cout << "You want to search " << argv[1]
         << " in " << argv[2] << "\n";         

    int count = 0;
    
    newfile.open(argv[argc-1],ios::in); 
        if (newfile){   
            cout <<" ****************** "<< argv[2] 
            <<" ****************** " << "\n";
            
            string line;
            while(getline(newfile, line)){ 
               char *p;
               char l[line.size()+1];
               strcpy(l, line.c_str());
               
               // split the line by spaces.
               vector<string> w;
               p = strtok(l, " ");
               
               while (p != NULL)
               {
                   w.push_back(p);
                   p = strtok(NULL, " ");
               } 
               
              // search for word in a line.          
              for (int i = 0; i < w.size(); i++){
                   if (argv[argc-2] == w[i]){
                      cout << line << "\n"; 
                      count+=1;
                   
                    }}
           }
            newfile.close();  }  
         
        // If a file does'nt exist.    
        else{
            cout <<" ************ "<< argv[2] <<" does'nt exist." 
            << " ************ "<<"\n";
            return 0;
        }  
        
        // If a word does'nt exist in a given file. 
        if (count == 0){
            cout <<" The word '"<< argv[argc-2] <<"' does'nt exist" 
            << " in " << argv[argc-1] <<"\n";
        }
    }
