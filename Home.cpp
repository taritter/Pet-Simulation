//
// Created by ritte on 10/10/2022.
//

#include "Home.h"
#include "Pet.h"
#include "Spending.h"
#include "Robot_Dragon.h"
#include "Chicken_Hamster.h"
#include <iostream>
#include <fstream>

using namespace std;

Chicken_Hamster chicken_hamster;
Robot_Dragon robot_dragon;
Pet cat_bat;

Home::Home() {

}

//outputs the vendor dialog/displays menu
int Home::vendor(Spending &money, fstream& expenses) {
    int choice;
    chicken_hamster.set_price(10);
    robot_dragon.set_price(8);
    cat_bat.set_price(5);
    chicken_hamster.set_reward(40);
    robot_dragon.set_reward(35);
    cat_bat.set_reward(15);
    cout << "Welcome to Tess and Freyja's Pet Shelter. Here are the animals available for fostering." << endl;
    cout << "Adoption fees (cover immunizations, ointments, and mysterious items) are listed to the right. You may choose one pet every other day" << endl;
    cout << "Chicken-Hamster --- buy " << chicken_hamster.get_price() << "$ ---sell " << chicken_hamster.get_reward() << "-- 4 days" << endl;
    cout << "Robot-Dragon --- buy " << robot_dragon.get_price() << "$ ---sell " << robot_dragon.get_reward() << "-- 4 days" << endl;
    cout << "Cat-bat --- buy " << cat_bat.get_price() << "$ ---sell " << cat_bat.get_reward() << "-- 4 days" << endl;
    cout << "Enter 1 for a Chicken-Hamster, 2 for Robot-Dragon, 3 for a Cat-Bat: " << endl;
    cin >> choice;
    while(!(choice == 1 or choice == 2 or choice == 3)){
        cout << "Please enter a valid choice" << endl;
        cin >> choice;
    }
    if(choice == 1){
        money.update_bank(chicken_hamster.get_price());
        expenses << "pet" << endl;
        expenses << chicken_hamster.get_price() << endl;
    }
    else if(choice == 2){
        money.update_bank(robot_dragon.get_price());
        expenses << "pet" << endl;
        expenses << robot_dragon.get_price() << endl;
    }
    else if(choice == 3){
        money.update_bank(cat_bat.get_price());
        expenses << "pet" << endl;
        expenses << cat_bat.get_price() << endl;
    }
    return choice;
}
//outputs link to website
void Home::read_bestiary() {
    cout << "Here is the link to our extensive beastiary on your favorite creatures: https://ffeeney.w3.uvm.edu/ffeeney-taritter-oep3/beastiary.php" << endl;
}

void Home::add_to_progress (int date){
    progress.push_back(date);
}

void Home::add_to_released(int releasedPet) {
    released.push_back(releasedPet);
}
/**
void Home::add_to_growing(int add) {
    if (balance > 0) {
        babyAnimal.push_back(add);
        update_balance(add);
    }
    else {
        cout << "sorry, you have no money left!" << endl;
    }
}**/

void Home::show_released() {
    string list = "Your Released Animals: ";
    for (int i : released) {
        if (i == 1){
            list+="--Chicken Hamster--";
        }
        if (i == 2){
            list+="--Robot Dragon--";
        }
        if (i == 3){
            list+="--Cat Bat--";
        }
    }
    cout << list << endl;
}
void Home::show_growing(){
    string list = "Growing in your Home: ";
    for (int i : babyAnimal) {
        if (i == 1){
            list+= "--Chicken-Hamster--";
        }
        if (i == 2){
            list+= "--Robot-Dragon--";
        }
        if (i == 3){
            list+= "--Cat-Bat--";
        }
        if (i == 0) {
            list += "---this pet has been released!---";
        }
    }
    cout << list << endl;
}

void Home::show_prices_rescued() {
    int carrot = 0;
    int tomato = 0;
    int daisy = 0;

    string choice;
    for (int i : released) {
        if (i == 1) {
            carrot++;
        }
        if (i == 2) {
            tomato++;
        }
        if (i == 3) {
            daisy++;
        }
    }
    cout << "You have " << carrot << " carrot(s) that are worth 40$ each." << endl;
    cout << "You have " << tomato << " tomato(es) that are worth 35$ each." << endl;
    cout << "You have " << daisy << " daisy(ies) that are worth 15$ each." << endl;
    cout << "Your previous balance was " << balance << " gold pieces." << endl;
    //i was going to use the struct here for the math
    balance = balance + (daisy * 15) + (carrot * 40) + (tomato * 35);
    cout << "Your balance now is " << balance << " gold pieces" << endl;
}

void Home::release_animal(int days) {
    for (int i = 0; i < babyAnimal.size(); i++) {

        if (babyAnimal[i] == 1) {
            if ((days + 1) - progress[i] == 4) {
                add_to_released(1);
                //sets growing crop and its corresponding progress value to zero
                babyAnimal[i] = (0);
                progress[i] = (0);
            }
        }
        if (babyAnimal[i] == 2) {
            if ((days + 1) - progress[i] == 2) {
                add_to_released(2);
                babyAnimal[i] = (0);
                progress[i] = (0);
            }
        }
        if (babyAnimal[i] == 3) {
            if ((days + 1) - progress[i] == 2) {
                add_to_released(3);
                babyAnimal[i] = (0);
                progress[i] = (0);
            }
        }
    }
}

void Home::buy_toys(Spending &money, fstream& expenses){
    int option;
    cout << "Welcome to the toy shop!" << endl;
    cout << "We have many toys in stock! Choose from the list below" << endl;
    cout << "1) Ball---$4" << endl;
    cout << "2) Chicken Hamster doll---$15" << endl;
    cout << "3) Hamster wheel---$60" << endl;
    cout << "4) Puzzle---$10" << endl;
    cout << "5) Mini treehouse---$150" << endl;
    cout << "Enter the number for the toy you'd like" << endl;
    cin >> option;
    if(option == 1){
        money.update_bank(4);
        money.update_food(4);
        expenses << "toy" << endl;
        expenses << "4" << endl;
    }
    else if(option == 2){
        money.update_bank(15);
        money.update_food(15);
        expenses << "toy" << endl;
        expenses << "15" << endl;
    }
    else if(option == 3){
        money.update_bank(60);
        money.update_food(60);
        expenses << "toy" << endl;
        expenses << "60" << endl;
    }
    else if(option == 4){
        money.update_bank(10);
        money.update_food(10);
        expenses << "toy" << endl;
        expenses << "10" << endl;
    }
    else if(option == 5){
        money.update_bank(150);
        money.update_food(150);
        expenses << "toy" << endl;
        expenses << "150" << endl;
    }
}
