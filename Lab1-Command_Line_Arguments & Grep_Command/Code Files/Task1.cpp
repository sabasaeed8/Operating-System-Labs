#include <iostream>
#include <fstream>
using namespace std;
  
int main(int argc, char** argv)
{
    fstream newfile;
    cout << "You have entered " << argc
         << " arguments." << "\n";
    cout << "You have entered " << argc-1
         << " files:" << "\n";
    for (int i = 1; i < argc; ++i){
        newfile.open(argv[i],ios::in); 
        if (newfile){   
            cout <<" ****************** "<< argv[i] 
            <<" ****************** " << "\n";
            string line;
            while(getline(newfile, line)){ 
               cout << line << "\n";
           }
            newfile.close();  }  
        else{
            cout <<" ************ "<< argv[i] <<" does'nt exist." 
            << " ************ "<<"\n";
        }  
    }
    return 0;
}
