#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

using namespace std::chrono_literals;

void refreshInventory(std::map<std::string, int> bloodInventory) {
  while(true) {
     for(auto& item: bloodInventory) {
        item.second++;
        std::cout<< item.first << ": " << item.second << std::endl;
     }
     std::this_thread::sleep_for(2000ms);
  }
} 

int main() {
   std::map<std::string, int> bloodInventory = {
     {"Type O", 23},
     {"Type B", 36},
     {"Type A", 54}
   };
   std::thread bgWorker(refreshInventory, bloodInventory);
   bgWorker.join();
}
