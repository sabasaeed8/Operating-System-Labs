#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <queue>
using namespace std;

sem_t sem_empty;
sem_t sem_full;
queue<int> buffer;
int buffer_size;

void * producer(void *arg) {  
   while(buffer.size() != buffer_size){
      sem_wait(&sem_empty);
      int num = rand() % 6 + 1; // Produce an random item
      buffer.push(num);
      cout << "Thread1 Produce " << num <<endl;
      sem_post(&sem_full);
   }
   return 0;	
}

void * consumer(void *arg) {  
   while(buffer.size() != buffer_size){      
      sem_wait(&sem_full);
      int num2 = buffer.front();
      buffer.pop();
      cout << "Thread2 Consume " << num2 << endl;
      sem_post(&sem_empty);
   }
   return 0;	
}

int main(){

    int size;
    cout << "Enter the size of Array: ";
    cin >> size;
    buffer_size = size;
    
    sem_init(&sem_empty, 0, buffer_size);
    sem_init(&sem_full, 0, 0);

    pthread_t pro,con; 
    pthread_create(&pro,NULL, producer, NULL);
    pthread_create(&con,NULL, consumer, NULL);
    
    pthread_join(pro, NULL);
    pthread_join(con, NULL);
    
   

}
