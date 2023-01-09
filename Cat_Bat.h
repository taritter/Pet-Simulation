//
// Created by ritte on 10/10/2022.
//

#ifndef M3OEP_CAT_BAT_H
#define M3OEP_CAT_BAT_H
#include "Pet.h"

class Cat_Bat : public Pet{
private:
    bool fly;
public:
    //A cat bat can fly, however, it takes a few days for it to learn to fly
    bool get_fly();
    void set_fly(bool);
};

#endif //M3OEP_CAT_BAT_H
