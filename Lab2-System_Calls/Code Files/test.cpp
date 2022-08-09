#include <iostream>
#include <fstream>
using namespace std;
  
int main(int argc, char** argv)
{
    fstream newfile;
    newfile.open("./data.txt",ios::in); 
        if (newfile){   
           cout << "\n" <<"*********** "<< "Data.txt"
           <<" ***********" << "\n";
            string line;
            while(getline(newfile, line)){ 
               cout << line << "\n";
           }
            newfile.close();  }  
 
    
    return 0;
}
