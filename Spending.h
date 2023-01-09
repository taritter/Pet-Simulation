//
// Created by ritte on 10/10/2022.
//

#ifndef M3OEP_SPENDING_H
#define M3OEP_SPENDING_H


/*
     * Tess Ritter and Freyja Feeney CS120 M3OEP
     * This program calculates your pet's budget and reports how much you spent
     * It uses getters and setters
     * Has many methods to go through the file, and get the money
     */

#include <iostream>
#include <vector>
using namespace std;


class Spending {
private:
    vector<double> expenses;
    double budget;
    double bank;
    double food_budget;
    double toy_budget;
    double accessory_budget;
    double ideal_budget;

public:
    /*
     * Default Constructor
     * Requires: vector of expenses, budget, and vector of months
     * Modifies: nothing
     * Effects: calls the variables needed for the class
     */
    Spending();

    //setter
    void set_expenses();
    int set_budget(string);
    void set_bank(double);
    void set_food_budget();
    void set_accessories_budget();
    void set_toys_budget();
    bool set_ideal_budget(double);

    //getter
    vector<double> get_expenses()const;
    double get_budget()const;
    double get_bank()const;
    double get_food_budget()const;
    double get_accessories_budget()const;
    double get_toy_budget()const;
    double get_ideal_budget()const;



    /*
     * This method gets the difference between the users set budget and actual spent during that month
     * Requires: set budget and total spent for the month
     * Modifies: nothing
     * Effects: prints out how much you went over or under
     */
    static void budget_difference (double, double);

    /*
     * This method returns how much was spent for 1 day and what was purchased, also how much is left in each budget
     * Requires: int for the day number
     * Modifies: nothing
     * Effects: adds up all the values in the vector
     */
    double get_report (fstream& a, int);

    /*
     * This method returns how much money you have left
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints money left
     */
    void get_money_info();

    /*
     * This method prints the budgets for the categories
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints money left
     */
    void print_budgets();


    /*
     * This method sets food, toy, and accessory budget
     * Requires: nothing
     * Modifies: food, toy, and accessory budget, and bank
     * Effects: gets category budgets and subtracts that from bank total.
     */
    void set_all_budget();

    /*
     * This method updates balances based on spending
     * Requires: a string, the category of the item bought, and a double, the amount
     * Modifies: the category budgets
     * Effects: subtracts from the category budgets
     */
    void check_balance(string, double);

    /*
     * This method adds or subtracts money from your account
     * Requires: a double with the amount to subtract or add
     * Modifies: bank
     * Effects: adds or subtracts bank
     */
    double update_bank(double);

    /*
     * This method adds or subtracts money from the food budget
     * Requires: a double with the amount to subtract
     * Modifies: food budget
     * Effects: subtracts from food budget
     */
    double update_food(double);

    /*
     * This method adds or subtracts money from the accessory budget
     * Requires: a double with the amount to subtract
     * Modifies: accessory budget
     * Effects: subtracts from accessory budget
     */
    double update_accessory(double);

    /*
     * This method adds or subtracts money from the toy budget
     * Requires: a double with the amount to subtract
     * Modifies: toy budget
     * Effects: subtracts from toy budget
     */
    double update_toy(double);

    /*
     * This method makes the table in html for a specific day
     * Requires: integer which is the day number
     * Modifies: creates html doc
     * Effects: creates html doc
     */
    void make_day_table(int);

};


#endif //M3OEP_SPENDING_H
