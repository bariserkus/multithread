// calculateWithLoop.cpp

#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <vector>

constexpr long long size = 100000000;

int main(){

    std::cout << std::endl;

    std::vector<int> randValues;
    randValues.reserve(size);

    // random values
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<> uniformDist(1, 10);
    for (long long i = 0 ; i < size ; ++i)
        randValues.push_back(uniformDist(engine));


    unsigned long long sum = {};
    std::cout << " For Loop Results:" << std::endl;
    auto sta = std::chrono::steady_clock::now();

    for (auto const n: randValues) sum += n;

    std::chrono::duration<double> dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for mySummation " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;
    std::cout << std::endl;


    std::cout << " Accumulate Results:" << std::endl;
    sum = {};
    sta = std::chrono::steady_clock::now();

    sum = std::accumulate(randValues.begin(), randValues.end(), 0);

    dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for mySummation " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;
    std::cout << std::endl;


    std::cout << " Locks Results:" << std::endl;
    sum = {};
    std::mutex myMutex;
    sta = std::chrono::steady_clock::now();

    for (auto const i: randValues){
        std::lock_guard<std::mutex> myLockGuard(myMutex);
        sum += i;
    }

    dur = std::chrono::steady_clock::now() - sta;
    std::cout << "Time for mySummation " << dur.count()
              << " seconds" << std::endl;
    std::cout << "Result: " << sum << std::endl;
    std::cout << std::endl;

}