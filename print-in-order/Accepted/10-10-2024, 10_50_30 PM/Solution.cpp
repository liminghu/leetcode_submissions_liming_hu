// https://leetcode.com/problems/print-in-order

/*
Suppose we have a class:
public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
The same instance of Foo will be passed to three different threads. Thread A will call first(), thread B will call second(), and 
thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and 
third() is executed after second().

Note:
We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seem to imply the ordering. 
The input format you see is mainly to ensure our tests' comprehensiveness.

Example 1:
Input: nums = [1,2,3]
Output: "firstsecondthird"
Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), 
and thread C calls third(). "firstsecondthird" is the correct output.

Example 2:
Input: nums = [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
 
Constraints:
nums is a permutation of [1, 2, 3].
*/
#include <semaphore.h>
class Foo {
protected:
    sem_t firstJobDone;
    sem_t secondJobDone;
public:
    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();

    }
};