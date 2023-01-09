//
// Created by ritte on 10/10/2022.
//

#ifndef M3OEP_PET_H
#define M3OEP_PET_H
#include "Spending.h"

class Pet {
private:
    int pet_price;
    vector<int> hunger;
    int pet_reward;
    string pet_name;
    int hunger_levels;
    int happiness_levels;
    int hygiene_levels;
    Spending money;

public:
    Pet();

    // Getters
    int get_hunger_levels()const;
    int get_happiness_levels()const;
    int get_hygiene_levels()const;
    double get_price()const;
    double get_reward()const;
    string get_name()const;
    void show_hunger();
    void decrement_hunger();
    /**
    * add to hunger vector
    * this method adds a new hunger tracker when a new animal is adopted
    */
    void add_to_hunger(int h);
    /**
    * this works to feed the animal
    * this method adds to the correct index of the hunger vector the amount of food that is fed to the animal
    */
    void feed_animal(int choice, int money);

    // Setters
    void set_hunger_levels(int hunger);
    void set_happiness_levels(int happiness);
    void set_hygiene_levels(int hygiene);
    void set_price(int price);
    void set_reward(int reward);
    void set_name(string name);

};


#endif //M3OEP_PET_H
