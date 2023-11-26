/* The program simuates an elevator. It runs infinitely, just like a real elevator.
   Only one agent is allowed at a time is allowed in the elevator. Different security level agents can
   visit different levels of the building. If an agent doesn't hold the required security level, the
   elevator doors will not open.
*/

#include <algorithm>
#include <condition_variable>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

enum SecurityLevel {
    CONFIDENTIAL,
    SECRET,
    TOP_SECRET
};

class Elevator {
public:
    Elevator() : currentFloor("G"), doorOpen(false) {}
 
    // Call the elevator from a floor
    void callElevator(const std::string& floor, SecurityLevel agentSecurityLevel) {
        std::unique_lock<std::mutex> lock(mutex);
        if (floor != currentFloor) {
            // Wait for the elevator to arrive at the current floor
            cv.wait(lock, [this, &floor] {
                return currentFloor == floor && !doorOpen;
            });
        }
    }
 
    // Move the elevator to a target floor
    void moveElevator(const std::string& target_floor, SecurityLevel agentSecurityLevel) {
        std::unique_lock<std::mutex> lock(mutex);
        std::cout << "Elevator is moving from floor " << currentFloor << " to floor " << target_floor << "." << std::endl;
        
        // Simulate travel time
        std::this_thread::sleep_for(std::chrono::seconds(1));
        currentFloor = target_floor;
 
        // Simulate elevator stop
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Elevator arrived at floor " << currentFloor << "." << std::endl;
        doorOpen = true;
        
        // Check agent security level
        if (agentSecurityLevel >= getRequiredSecurityLevel(currentFloor)) {
            std::cout << "Security check passed. Agent allowed to exit." << std::endl;
        } else {
            std::cout << "Security check failed! Agent does not have required credentials." << std::endl;
            doorOpen = false;
            return;
        }
 
        // Simulate time for the agent to enter/exit
        std::this_thread::sleep_for(std::chrono::seconds(2));
 
        doorOpen = false;
        std::cout << "Elevator door closed." << std::endl;

        // Notify waiting threads that the elevator has arrived
        cv.notify_all();
    }
 
private:
    std::string currentFloor;
    bool doorOpen;
    std::mutex mutex;
    std::condition_variable cv;
 
    // Get required security level for a given floor
    SecurityLevel getRequiredSecurityLevel(const std::string& floor) const {
        if (floor == "S") {
            return SECRET;
        } else if (floor == "T1" || floor == "T2") {
            return TOP_SECRET;
        } else {
            return CONFIDENTIAL;
        }
    }
};
 
class Agent {
public:
    Agent(const std::string& name, const std::string& initialFloor, SecurityLevel securityLevel, Elevator& elevator)
        : name(name), currentFloor(initialFloor), securityLevel(securityLevel), elevator(elevator) {}
 
    // Make the agent object callable
    void operator()() {
        while (true) {
            // Simulate random time before calling the elevator
            std::this_thread::sleep_for(std::chrono::seconds(rand() % 10 + 1));
 
            elevator.callElevator(currentFloor, securityLevel);
 
            // Randomly choose next floor
            std::vector<std::string> floors = {"G", "S", "T1", "T2"};
            std::random_shuffle(floors.begin(), floors.end());
 
            for (const auto& floor : floors) {
                if (floor != currentFloor) {
                    elevator.moveElevator(floor, securityLevel);
                    currentFloor = floor;
                    break;
                }
            }
        }
    }
 
private:
    std::string name;
    std::string currentFloor;
    SecurityLevel securityLevel;
    Elevator& elevator;
};
 
int main() {
    srand(static_cast<unsigned>(time(nullptr)));
 
    Elevator elevator;
 
    std::thread elevatorThread(&Elevator::moveElevator, std::ref(elevator), "G", CONFIDENTIAL);
 
    // Create an agent with random security level
    Agent agent1("Agent1", "G", static_cast<SecurityLevel>(rand() % 3), elevator);
    Agent agent2("Agent2", "G", static_cast<SecurityLevel>(rand() % 3), elevator);
 
    std::thread agentThread1(std::ref(agent1));
    std::thread agentThread2(std::ref(agent2));
 
    // Wait for the threads to finish. (They never will..)
    elevatorThread.join();
    agentThread1.join();
    agentThread2.join();
 
    return 0;
}
