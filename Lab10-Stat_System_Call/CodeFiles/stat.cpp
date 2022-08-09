#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include <time.h> 
using namespace std;
  
vector<string> files;
int Total_files = 0;
int main(int argc, char** argv)
{
    fstream newfile;
    cout << "You have entered " << argc-1
         << " files:" << "\n";
    for (int i = 1; i < argc; ++i){
        newfile.open(argv[i],ios::in); 
        if (newfile){  
            files.push_back(argv[i]); 
            Total_files +=1;
            cout <<" ****************** "<< argv[i] 
            <<" ****************** " << "\n";
            //pointer to stat struct
            struct stat sfile;

            //stat system call
            //int stat(const char *path, struct stat *buf)
            if(stat(argv[i],&sfile)==-1){
    		printf("Error Occurred\n");
             }

  	    //Accessing data members of stat struct
  	    cout << " File st_uid: " << sfile.st_uid << endl;   // user ID
 	    cout << " File st_gid: " << sfile.st_gid << endl;   // group ID
 	    cout << " File st_blksize: " << sfile.st_blksize << endl;   // preferred block size for I/O file system
 	    cout << " File st_blocks: " << sfile.st_blocks << endl;     // total number of blocks in multiples of 512 bytes
 	    cout << " File st_size: " << sfile.st_size << endl;         // size of the file in bytes
 	    cout << " File st_nlink: " << sfile.st_nlink << endl;       // total number of hard links
 	    // last time or the recent time at which the file was accessed
 	    cout << " File st_atime: " << ctime(&sfile.st_atime) ;   // c_time-- Convert time to character string 
 	    // recent time at which the file was modified
 	    cout << " File st_mtime: " << ctime(&sfile.st_mtime) << endl;  
 	    
 	    cout << " File Permission User: "  ;
 	    cout << ((sfile.st_mode & S_IRUSR)? "r":"-");
 	    cout << ((sfile.st_mode & S_IWUSR)? "w":"-");
 	    cout << ((sfile.st_mode & S_IXUSR)? "x":"-");
 	    cout << endl;
 	    
 	    cout << " File Permission Group: "  ;
 	    cout << ((sfile.st_mode & S_IRGRP)? "r":"-");
 	    cout << ((sfile.st_mode & S_IWGRP)? "w":"-");
 	    cout << ((sfile.st_mode & S_IXGRP)? "x":"-");
 	    cout << endl;
 	    
 	    cout << " File Permission Other: "  ;
 	    cout << ((sfile.st_mode & S_IROTH)? "r":"-");
 	    cout << ((sfile.st_mode & S_IWOTH)? "w":"-");
 	    cout << ((sfile.st_mode & S_IXOTH)? "x":"-");
 	    cout << endl;
 	    
            newfile.close();  
            cout << endl;}  
        else{
            cout <<" ************ "<< argv[i] <<" does'nt exist." 
            << " ************ "<<"\n";
            cout << endl;
        }  
    }
    
    // Same file size
    for (int i = 0 ; i < Total_files-1; i++ ){
    	for (int j = i+1 ; j < Total_files; j++ ){
    	    if (files[i] != files[j]){
    		struct stat sfile1;
    		const char* f1 = files[i].c_str();
           	stat(f1,&sfile1);
           	struct stat sfile2;
           	const char* f2 = files[j].c_str();
              	stat(f2,&sfile2);
              	if (sfile1.st_size == sfile2.st_size){
              	    cout << files[i] <<" and " << files[j] << " have same size." << endl;
              	}
    	     }
    	
    	}}
    return 0;
}
