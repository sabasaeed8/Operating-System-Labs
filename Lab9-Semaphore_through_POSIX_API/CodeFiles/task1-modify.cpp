#include <iostream>
#include <pthread.h>
#include <semaphore.h>

using namespace std;
sem_t sem1;
sem_t sem2;
sem_t sem3;
sem_t sem4;

void * child1(void *arg) {  
   int i =0;
   while(i<4){
      sem_wait(&sem1);
      for (int i=0; i<3; i++){
         cout << 'a' ;
      }
      sem_post(&sem4);
      i++;
    }
   return 0;	
}
void * child2(void *arg) {  
    int i =0;
   while(i<4){
      sem_wait(&sem2);
      cout << 'b';
      sem_post(&sem1);
      i++;
  }
   return 0;	
}
void * child3(void *arg) {  
   int i =0;
   while(i<4){
      sem_wait(&sem3);
      cout << 'c';
      sem_post(&sem2);
      i++;
  }
   return 0;	
}
void * child4(void *arg) {  
   int i =0;
   while(i<4){
      sem_wait(&sem4);
      for (int i=0; i<2; i++){
         cout << 'd' ;
      }
      sem_post(&sem3);
      i++;
  }
   return 0;	
}
int main(){

    
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 1);
    sem_init(&sem4, 0, 0);
    

    pthread_t t1,t2,t3,t4; 
    pthread_create(&t1,NULL, child1, NULL);
    pthread_create(&t2,NULL, child2, NULL);
    pthread_create(&t3,NULL, child3, NULL);
    pthread_create(&t4,NULL, child4, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    
   

}
