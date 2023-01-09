//
// Created by ritte on 10/10/2022.
//

#ifndef M3OEP_CHICKEN_HAMSTER_H
#define M3OEP_CHICKEN_HAMSTER_H
#include "Pet.h"

class Chicken_Hamster : public Pet {
private:
    int energy_levels;
public:
    Chicken_Hamster();
    Chicken_Hamster(string name, double price, double reward, int energy);

    //getters
    int get_energy_levels();

    //setters
    void set_energy_levels(int energy);

};


#endif //M3OEP_CHICKEN_HAMSTER_H
