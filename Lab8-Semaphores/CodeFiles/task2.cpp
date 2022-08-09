#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>
using namespace std;

sem_t sem_empty;
sem_t sem_full;
queue<int> buffer;

void * producer(void *arg) {  
   while(buffer.size() != 100){
      sem_wait(&sem_empty);
      int num = rand() % 6 + 1; // Produce an random item
      buffer.push(num);
      cout << "Number " << num <<endl;
      sem_post(&sem_full);
   }
   return 0;	
}

void * consumer(void *arg) {  
      int sum = 0;
   while(buffer.size() != 100){      
      sem_wait(&sem_full);
      sum = sum + buffer.front();
      buffer.pop();
      cout << "Sum " << sum << endl;
      sem_post(&sem_empty);
   }
   return 0;	
}

int main(){

    
    sem_init(&sem_empty, 0, 100);
    sem_init(&sem_full, 0, 0);

    pthread_t pro,con; 
    pthread_create(&pro,NULL, producer, NULL);
    pthread_create(&con,NULL, consumer, NULL);
    
    pthread_join(pro, NULL);
    pthread_join(con, NULL);
    
   

}
