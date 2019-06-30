#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <mutex>
#include<algorithm>
#include <sstream>

class Vehicle
{
public:
    Vehicle(int id) : _id(id) {}

private:
    int _id;
};

class WaitingVehicles
{
public:
    WaitingVehicles() {}

    // getters / setters
    void printSize()
    {
        _mutex.lock();
        std::cout << "#vehicles = " << _vehicles.size() << std::endl;
        _mutex.unlock();
    }

    // typical behaviour methods
    void pushBack(Vehicle &&v)
    {
        using Ms = std::chrono::milliseconds;
        std::ostringstream stream;
        for (int i = 0; i < 3; ++i) {
        if (tMutex.try_lock_for(Ms(100))) {
            //stream << "success ";
            std::cout << "success "<< std::endl;

        //_mutex.lock();
        _vehicles.emplace_back(std::move(v)); // data race would cause an exception
        //_mutex.unlock(); 
        //std::this_thread::sleep_for(Ms(10));  // hang on to the lock before releasing
        tMutex.unlock();
        break;
        } else {
            //stream << "failed ";
            std::cout << "failed "<< std::endl;

        }
        //std::this_thread::sleep_for(Ms(100));
    }
   
 
    }

private:
    std::vector<Vehicle> _vehicles; // list of all vehicles waiting to enter this intersection
    std::mutex _mutex;
    std::timed_mutex tMutex;
    };

int main()
{
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles); 
    std::vector<std::future<void>> futures;
    for (int i = 0; i < 1000; ++i)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicles::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr) {
        ftr.wait();
    });

    queue->printSize();

    return 0;
}
