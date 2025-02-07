// https://leetcode.com/problems/building-h2o

/*
There are two kinds of threads: oxygen and hydrogen. Your goal is to group these threads to form water molecules.
There is a barrier where each thread has to wait until a complete molecule can be formed. Hydrogen and oxygen threads will be given 
releaseHydrogen and releaseOxygen methods respectively, which will allow them to pass the barrier. These threads should pass the barrier 
in groups of three, and they must immediately bond with each other to form a water molecule. You must guarantee that all the threads from
 one molecule bond before any other threads from the next molecule do.
In other words:
If an oxygen thread arrives at the barrier when no hydrogen threads are present, it must wait for two hydrogen threads.
If a hydrogen thread arrives at the barrier when no other threads are present, it must wait for an oxygen thread and another hydrogen thread.
We do not have to worry about matching the threads up explicitly; the threads do not necessarily know which other threads they are paired up
 with. The key is that threads pass the barriers in complete sets; thus, if we examine the sequence of threads that bind and divide them into
  groups of three, each group should contain one oxygen and two hydrogen threads.
Write synchronization code for oxygen and hydrogen molecules that enforces these constraints.

Example 1:
Input: water = "HOH"
Output: "HHO"
Explanation: "HOH" and "OHH" are also valid answers.

Example 2:
Input: water = "OOHHHH"
Output: "HHOHHO"
Explanation: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" and "OHHOHH" are also valid answers.
 
Constraints:
3 * n == water.length
1 <= n <= 20
water[i] is either 'H' or 'O'.
There will be exactly 2 * n 'H' in water.
There will be exactly n 'O' in water.
*/
#include <semaphore.h>
class H2O {
public:
    pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
    sem_t h;
    sem_t o;
    int h_count = 0;
    H2O() {
        sem_init(&h, 0, 1); //
        sem_init(&o, 0, 0); // 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h); //
        pthread_mutex_lock(&mtx);
        h_count++;
        pthread_mutex_unlock(&mtx); //

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if(h_count%2 == 0)
            sem_post(&o);
        else
            sem_post(&h);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&h);
    }
};
/*#include <semaphore.h>
class H2O {
public:
    pthread_barrier_t b;
    sem_t h;
    sem_t o;
    H2O() {
        pthread_barrier_init(&b, 0, 3); //need 3 threads to pass the barrier.
        sem_init(&h, 0, 2); //two molecules of Hydrogen
        sem_init(&o, 0, 1); //one molecule of Oxygen. 
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h); //two hudrogen threads can arrive at a time.
        pthread_barrier_wait(&b); //wait for one more thread, which must be oxygen.

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        sem_post(&h);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        pthread_barrier_wait(&b);
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&o);
    }
};*/