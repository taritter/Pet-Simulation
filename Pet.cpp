//
// Created by ritte on 10/10/2022.
//

#include "Pet.h"

Pet::Pet(){
    vector<int> hunger;
    hunger_levels = 25;
    happiness_levels = 20;
    hygiene_levels = 15;
    pet_reward = 100;
    pet_price = 50;
}

// Getters
int Pet::get_hunger_levels()const{
    return hunger_levels;
}

int Pet::get_happiness_levels()const{
    return happiness_levels;
}

int Pet::get_hygiene_levels()const{
    return hygiene_levels;
}

double Pet::get_price()const{
    return pet_price;
}

double Pet::get_reward()const{
    return pet_reward;
}

string Pet::get_name()const{
    return pet_name;
}

void Pet::show_hunger(){
    cout << "Here are your pet(s) hunger levels: " << endl;
    for (int i = 0; i < hunger.size(); i ++) {
        cout << hunger[i] << ", ";
    }
    cout << "\n" << endl;
}


void Pet::decrement_hunger() {
    for(int i = 0; i < hunger.size(); i ++) {
        hunger[i] = hunger[i] - 20;
    }
}

void Pet::add_to_hunger(int h){
    hunger.push_back(h);
}

void Pet::feed_animal(int choice, int money) {
    int food = 5 * money;
    hunger[choice] = hunger[choice] + food;
    // make another vector like progress but hunger levels that decrease, to boost hunger levels, boost the int in the
    // correct index corresponding to the pet by the number of foods fed

}

// Setters
void Pet::set_hunger_levels(int hunger){
    hunger_levels = hunger;
}

void Pet::set_happiness_levels(int happiness){
    happiness_levels = happiness;
}

void Pet::set_hygiene_levels(int hygiene){
    hygiene_levels = hygiene;
}

void Pet::set_price(int price){
    pet_price = price;
}

void Pet::set_reward(int reward){
    pet_reward = reward;
}

void Pet::set_name(string name){
    pet_name = name;
}

