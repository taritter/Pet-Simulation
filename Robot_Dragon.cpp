//
// Created by ritte on 10/10/2022.
//

#include "Robot_Dragon.h"
#include <chrono>
#include <thread>
using namespace std;

Robot_Dragon::Robot_Dragon(){
    battery_level = 100;
}
int Robot_Dragon::get_battery_level() {
    return battery_level;
}

void Robot_Dragon::set_battery_level(int battery) {
    battery_level = battery;
}

int Robot_Dragon::charge_battery() {
    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(60));
    battery_level = 100;
    return battery_level;
}
