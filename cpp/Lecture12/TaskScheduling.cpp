/**
 * Greedy strategy for task scheduling problem.
 * 
 * Author: Guoxi Liu
 * Clemson University
 * Date: 03/06/2023
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

/**
 * Task structure. 
*/
struct Task
{
    int tid;        // task id
    int start;      // start time
    int finish;     // finish time

    // Constructor
    Task(int id, int s, int f) : tid(id), start(s), finish(f) {}

    // Define the less-than operator to order elements by finish time
    bool operator<(const Task &other) const {
        return this->finish > other.finish;
    }
};

/**
 * Use greedy strategy to schedule the tasks on a single machine.
 * The functions returns the list of maximum tasks can be scheduled. 
*/
std::vector<int> greedy_task_schedule(std::vector<Task> &tasks) {
    std::vector<int> scheduledTasks;

    // create a priority queue 
    std::priority_queue<Task> pq;
    for (auto t : tasks) {
        pq.push(t);
    }
    int time = 0;
    while (!pq.empty()) {
        Task frontTask = pq.top();
        pq.pop();
        if (frontTask.start >= time) {
            scheduledTasks.push_back(frontTask.tid);
            time = frontTask.finish;
        }
    }

    return scheduledTasks;
}

/**
 * Sort the task in ascending order based on the start time. 
 */
bool compare(const Task &a, const Task &b) {
    if (a.start == b.start) {
        return a.finish < b.finish;
    }
    return a.start < b.start;
}

/**
 * Use greedy strategy to schedule all the tasks on multiple machines.
 * The functions returns the minimum number of machines needed. 
*/
int greedy_machine_schedule(std::vector<Task> &tasks) {
    std::sort(tasks.begin(), tasks.end(), compare);
    // for (auto &t : tasks) {
    //     std::cout << t.tid << " ";
    // }
    // std::cout << std::endl;

    // create a priority queue 
    int n = tasks.size();
    std::priority_queue<Task> pq;
    for (int i = 0; i < n; ++i) {
        if (pq.empty()) {
            pq.push(tasks[i]);
        }
        else {
            Task lastTask = pq.top();
            if (tasks[i].start >= lastTask.finish) {
                std::cout << lastTask.tid << ", " << lastTask.start << ", " << lastTask.finish << std::endl;
                pq.pop();
            }
            pq.push(tasks[i]);
        }
    }
    return pq.size();
}

/**
 * Main entry of the program. 
*/
int main()
{
    // Use the example in the exercise
    std::vector<Task> tasks;
    tasks.emplace_back(3, 0, 6);
    tasks.emplace_back(7, 6, 10); 
    tasks.emplace_back(5, 3, 8); 
    tasks.emplace_back(10, 2, 13); 
    tasks.emplace_back(1, 1, 4); 
    tasks.emplace_back(9, 8, 12); 
    tasks.emplace_back(4, 5, 7); 
    tasks.emplace_back(6, 5, 9); 
    tasks.emplace_back(2, 3, 5); 
    tasks.emplace_back(8, 8, 11); 
    tasks.emplace_back(11, 12, 14); 

    std::vector<int> taskList = greedy_task_schedule(tasks);
    std::cout << "Maximum tasks scheduled: { ";
    for (int &t : taskList) {
        std::cout << t << " ";
    }
    std::cout << "}" << std::endl;
    
    std::cout << "Minimum number of machines: " << greedy_machine_schedule(tasks) << std::endl;

    // std::vector<Task> times;
    // times.emplace_back(3, 900, 1030);
    // times.emplace_back(7, 900, 1230); 
    // times.emplace_back(5, 900, 1030); 
    // times.emplace_back(10, 1100, 1230); 
    // times.emplace_back(1, 1100, 1400); 
    // times.emplace_back(9, 1300, 1430); 
    // times.emplace_back(4, 1300, 1430); 
    // times.emplace_back(6, 1400, 1630); 
    // times.emplace_back(2, 1500, 1630); 
    // times.emplace_back(8, 1500, 1630); 
    // std::cout << "Minimum number of machines: " << greedy_machine_schedule(times) << std::endl;

    return 0;
}