//
// Created by ritte on 10/10/2022.
//

#ifndef M3OEP_ROBOT_DRAGON_H
#define M3OEP_ROBOT_DRAGON_H
#include "Pet.h"

class Robot_Dragon : public Pet{
private:
    int battery_level;
public:

    //constructor
    Robot_Dragon();

    //setter
    void set_battery_level(int);

    //getter
    int get_battery_level();

    /*
     * This method subtracts battery usage
     * Requires: amount of battery to subtract
     * Modifies: battery levels
     * Effects: changes battery amount as robot dragon is being used
     */
    void use_battery(int);

    /*
     * This method charges the dragon and brings it up to 100%
     * Requires: nothing
     * Modifies: battery level and return battery level when fully charged
     * Effects: waits a few minutes for robot dragon to be fully charged
     */
    int charge_battery();
};


#endif //M3OEP_ROBOT_DRAGON_H
