//
// Created by ritte on 10/10/2022.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Spending.h"
#include "Home.h"
#include "Chicken_Hamster.h"
#include "Robot_Dragon.h"
#include "Pet.h"

//gets user information
using namespace std;

int main(int argc, char* argv[]) {

    struct home {
        string user_name;
        string pet_name;
        string home_name;
    };
    home user_home;

    int const WEEK = 6;
    int days = 0;
    int hunger_value = 100;
    string rescue;
    string choice;
    string sleep;
    Home home;
    Pet pet;
    Spending pet_expenses;
    cout << "Congratulations! You have inherited quite a large sum of mysterious money, meant to be put towards mysterious things. "
            "This is a very rare opportunity, " << endl;
    // you inherited $500
    pet_expenses.set_bank(500);
    cout << "a path of wonder and adventure lies ahead of you." << endl;
    cout << "What is your name, friend?: " << endl;
    cin >> user_home.user_name;
    cout << "What will you name your new home?: " << endl;
    getline(cin, user_home.home_name);
    getline(cin, user_home.home_name);
    cout << "Hello, " << user_home.user_name << ". " << user_home.home_name << " is a wonderful name for your home!" << "\n" << endl;
    cout << user_home.user_name << " would you like to see your bank account?" << endl;
    getline(cin, choice);
    while(!(choice == "yes" or choice == "no" or choice == "Yes" or choice == "No")){
        cout << "Please enter either yes or no" << endl;
        getline(cin, choice);
    }
    if(choice == "yes" or choice == "Yes"){
        cout << "You have $" << pet_expenses.get_bank() << endl;
    }
    else if(choice == "no" or choice == "No"){
        cout << "That's okay we can check another time!" << endl;
    }

    fstream expenses("../Pet_Expenses.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    //assign crop details
    //end of day!
    while (days < WEEK) {
        days++;

        if(days == 1){
            cout << "Before we get started there are a few money things we need to go over first." << endl;
            cout << "You will be taking care of this pet for 10 days! \nIn those 10 days you need to make sure you feed it, ";
            cout << "socialize it, and help it grow." << endl;
            cout << "For all of these you will have 3 different budgets. A food budget, a toy budget, and an accessory budget.\n" << endl;
            pet_expenses.set_all_budget();
        }
        else{
            home.show_growing();
            pet.show_hunger();
            pet.decrement_hunger();
            pet_expenses.get_report(expenses, days);
        }

        cout << "--------Day " << (days) << " in " << user_home.home_name << "--------" << endl;

        expenses << "Day" << days << endl;
        expenses << "0" << endl;

        if (days%2 == 1) {
            cout << "Would you like to rescue an animal today? (you can only rescue every other day): " << endl;
            cin >> rescue;
            while (!(rescue == "Yes" or rescue == "yes" or rescue == "YES" or rescue == "y" or rescue == "No" or
                     rescue == "no" or rescue == "NO" or rescue == "n")) {
                cout << "Please enter yes or no: " << endl;
                cin >> rescue;
            }


            if (rescue == "Yes" or rescue == "yes" or rescue == "YES" or rescue == "y") {
                Home::vendor(pet_expenses,expenses);
                home.add_to_progress(days);
                pet.add_to_hunger(hunger_value);
                home.show_growing();
            }
            if (rescue == "No" or rescue == "no" or rescue == "NO" or rescue == "n") {
                cout << "Okay! Maybe next time." << endl;
            }
        }
        int option;

        cout << "On today's menu: " << endl;
        cout << "Option 1: Feed my animals" << endl;
        cout << "Option 2: Play with my animals!" << endl;
        cout << "Option 3: Check on my animals!" << endl;
        cout << "Option 4: Check your bank!" << endl;
        cout << "Option 5: Read the Bestiary" << endl;
        cin >> option;

        if (option == 1) {
            double money;
            int choice;
            int vecIndex;
            cout << "How many dollars worth of food would you like to feed your pet?" << endl;
            cout << "On average $1 equals about 5 hunger points" << endl;
            cin >> money;
            pet_expenses.update_bank(money);
            pet_expenses.update_food(money);
            expenses << "food" << endl;
            expenses << money << endl;
            cout << "Which Pet would you like to feed?" << endl;
            home.show_growing();
            cout << "Enter the number of the pet you want to feed" << endl;
            cin >> choice;
            vecIndex  = choice - 1;
            pet.feed_animal(vecIndex, money);
        }
        if (option == 2){
            Home::buy_toys(pet_expenses,expenses);
        }
        if (option == 3) {
            home.show_growing();
            cout << "Which pet would you like to check on?" << endl;
        }
        if (option == 4) {
            cout << "You can see your budget after you move to the next day" << endl;
            pet_expenses.get_money_info();
        }
        if (option == 5) {
            home.read_bestiary();
        }

        cout << "Would you like to move to the next day? yes or no: " << endl;
        cin >> sleep;
        while (sleep != "Yes" and sleep != "yes" and sleep != "No" and sleep != "no" and sleep != "YES" and sleep != "NO") {
            cout << "Please choose Yes or No: " << endl;
            cin >> sleep;
        }

        while (sleep == "no" or sleep == "No" or sleep == "NO") {
            cout << "You can't adopt any animals right now."<< endl;
            cout <<  "But you can view your current pets (G), check up on your released pets (H), check your balance (B), or to sleep (S)" << endl;
            while (sleep != "G" and sleep != "H" and sleep != "B" and sleep != "S") {
                cout << "Please choose an option!" << endl;
                cin >> sleep;
            }
            if (sleep == "G") {
                home.show_growing();
            }
            if (sleep == "H") {
                home.show_released();
            }
            if (sleep == "B") {
                pet_expenses.get_money_info();
            }
            if(sleep == "S"){
                sleep = "yes";
            }
            //put show balance here
            cout << "Would you like to sleep now?: " << endl;
            cin >> sleep;
        }
        //harvesting vector
        home.release_animal(days);
        pet_expenses.make_day_table(days);
    }
    expenses.close();
    cout << "Welcome to the last day! Congrats! You now have the choice be compensated for your work regarding animal rehabilitation" << endl;
    cout << "or! you can donate your earnings to the community" << endl;
    cout << "Here is a list of the animals you have released: " << endl;
    home.show_released();
    cin >> choice;
    if (choice == "S") {
        home.show_prices_rescued();
    }
    if (choice == "G") {
        cout << "You have been recognized as a the Most Outstanding Citizen of the town where "
             << user_home.home_name << " is stationed." << endl;
    }
    cout << "Congratulations! Thank you, " << user_home.user_name  << ", for using our Pet Simulator. Bye!" << endl;



    return 0;
};
