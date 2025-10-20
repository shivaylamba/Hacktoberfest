#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <condition_variable>

template<typename T>

class ThreadSafeQueue {
private:
    std::queue<T> queueData;
    mutable std::mutex mtx;
    std::condition_variable cv;
public:
    void push (const T& value) {
        std::lock_guard<std::mutex> lock(mtx);
        queueData.push(value);
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]{ return !queueData.empty(); });
        T value = queueData.front();
        queueData.pop();
        return value;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return queueData.empty();
    }
};

ThreadSafeQueue<int> tsQueue;

void producer() {
    for (int i=0; i<10; i++) {
        tsQueue.push(i);
        std::cout<< "Produced: " << i << std::endl;
    }
}

void consumer() {
    for (int i=0; i<10; i++) {
        int value = tsQueue.pop();
        std::cout<< "Consumed: " << value << std::endl;
    }
}


int main() {
    std::thread prodThread(producer);
    std::thread consThread(consumer);

    prodThread.join();
    consThread.join();

    return 0;
}
