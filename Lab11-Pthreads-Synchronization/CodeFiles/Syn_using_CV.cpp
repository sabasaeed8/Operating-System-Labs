#include <iostream>
#include <pthread.h>
using namespace std;

int buffer_size;
int* buffer = new int[buffer_size];
int f = 0;
int use = 0;
int buffer_count = 0;

void put(int value) {
     buffer[f] = value;
     f = (f + 1) % buffer_size;
     buffer_count++; }

int get() {
     
     int tmp = buffer[use];
     use = (use + 1)%buffer_size;
     buffer_count--;
     return tmp;}
     
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty,full;

void *producer(void *arg) {
     int i;
    // int loops = *((int*)arg);
     for (i = 0; i < buffer_size; i++) {
     pthread_mutex_lock(&mutex); // p1
     while (buffer_count == buffer_size){ // p2
         pthread_cond_wait(&empty, &mutex);} // p3
     put(i); // p4
     cout<< "Thread1 produce " << i << endl;
     pthread_cond_signal(&full); // p5
     pthread_mutex_unlock(&mutex); // p6
}
     return 0;
}

void *consumer(void *arg) {
     int i;
     for (i = 0; i < buffer_size; i++) {
     pthread_mutex_lock(&mutex); // c1
     while (buffer_count == 0) // c2
         pthread_cond_wait(&full, &mutex); // c3
     int tmp = get(); // c4
     cout<< "Thread2 consume " << get() << endl;
     pthread_cond_signal(&empty); // c5
     pthread_mutex_unlock(&mutex); // c6
     
}
     return 0;
}
int main(){
    free(buffer);
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;
    buffer_size = size; 
    pthread_t pro,con; 
    pthread_create(&pro,NULL, producer, NULL);
    pthread_create(&con,NULL, consumer, NULL);
    
    pthread_join(pro, NULL);
    pthread_join(con, NULL);
    
    return 0;
}




