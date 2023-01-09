//
// Created by ritte on 10/10/2022.
//

#include "Chicken_Hamster.h"

Chicken_Hamster::Chicken_Hamster(){

}
Chicken_Hamster::Chicken_Hamster(string name, double price, double reward, int energy){
    name = "";
    price = 10.00;
    reward = 50.00;
    energy = 70;
}


//getters
int Chicken_Hamster::get_energy_levels(){
    return energy_levels;
}


//setters
void Chicken_Hamster::set_energy_levels(int energy){
    energy_levels = energy;
}