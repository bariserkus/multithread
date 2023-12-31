// spinLock.cpp
#include <iostream>
#include <atomic>
#include <thread>

class Spinlock{
    std::atomic_flag flag;
public:
    Spinlock(): flag(ATOMIC_FLAG_INIT){
        std::cout << ATOMIC_FLAG_INIT<< std::endl;
    }

    void lock(){
        while( flag.test_and_set() );
    }

    void unlock(){
        flag.clear();
    }
};

Spinlock spin;

void workOnResource(){
    spin.lock();
    // shared resource
    spin.unlock();
    std::cout << "Work done" << std::endl;
}


int main(){
    std::thread t(workOnResource);
    std::thread t2(workOnResource);

    t.join();
    t2.join();

}