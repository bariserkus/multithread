// mutex.cpp
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mut;

void workOnResource(){
    mut.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    mut.unlock();
    std::cout << "Work done" << std::endl;
}

int main(){

    std::thread t(workOnResource);
    std::thread t2(workOnResource);

    t.join();
    t2.join();

}