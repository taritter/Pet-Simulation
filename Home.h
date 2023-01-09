//
// Created by ritte on 10/10/2022.
//

#ifndef M3OEP_HOME_H
#define M3OEP_HOME_H

#include <vector>
#include <string>
#include <fstream>
#include "Pet.h"
#include "Spending.h"

using namespace std;

class Home {

private:
    vector<int> released;
    vector<int> babyAnimal;
    vector<int> progress;
    vector<Pet> pet_vector;
    Spending money;
    int balance = 100;
    fstream expenses;
public:
    /**
     * Default Constructor
     * Creates garden
     */
    Home();
    /**
    * vendor dialog
     * Takes in a spending object
    * this method reads the vendors dialog and allows the user to pick and choice
     * returns int choice
    */
    static int vendor(Spending&, fstream&);
    /**
    * displays bestiary
    * this method displays the text describing the animals
    * returns int choice
    */
    static void read_bestiary();
    /**
    * add to progress
    * this method marks down the day that a plant was harvested and stores it in a separate vector
    * adds date to vector progress
    */
    void add_to_progress(int date);

    /**
    * add to harvest
    * this method adds crop to harvest vector when it has grown its set amount of days
    * adds mature crop to harvested vector
    */
    void add_to_released(int releasedPet);
    /**
    * add to growing
    * this method takes choice and adds chosen crop to vector growing
    */
    void add_to_growing(int add);
    /**
    * show released vector
    * displays the contents of the released vector to user
    */
    void show_released();
    /**
    * show growing vector
    * displays the contents of the growing vector to user
    */
    void show_growing();
    /**
    * show released prices
    * counts number of crops in released vector by their corresponding number and sells them adding value
     * to balance
    */
    void show_prices_rescued();
    /**
    * release animal
    * searches through growing vector and subtracts progress value from corresponding index to see if the crop is mature
     * moves mature crops into released vector
    */
    void release_animal(int days);
    /**
     * feed animal
     * int hunger level is added to
     */
     //?

     /**
      * release animal
      * searches through growing vector and subtracts progress value from corresponding index to see if the crop is mature
      * moves mature crops into released vector
      */
    static void buy_toys(Spending&, fstream&);
};


#endif //M3OEP_HOME_H
