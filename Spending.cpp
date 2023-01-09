//
// Created by ritte on 10/10/2022.
//

#include <fstream>
#include "Spending.h"
using namespace std;



Spending::Spending() {
    budget = 0.0;
    bank = 500.0;
    food_budget = 0.0;
    toy_budget = 0.0;
    accessory_budget = 0.0;
    ideal_budget = 500.0;
}


//GETTERS
double Spending::get_food_budget()const{
    return food_budget;
}
double Spending::get_accessories_budget()const{
    return accessory_budget;
}
double Spending::get_toy_budget()const{
    return toy_budget;
}

vector<double> Spending::get_expenses() const {
    return expenses;
}

double Spending::get_budget() const {
    return budget;
}

double Spending::get_bank() const {
    return bank;
}

//This method is the 'fake' bank and subtracts budgets from it
double Spending::get_ideal_budget() const {
    return ideal_budget;
}

//SETTERS
void Spending::set_food_budget(){
    food_budget = Spending::set_budget("food");
}
void Spending::set_accessories_budget(){
    accessory_budget = Spending::set_budget("accessory");
}
void Spending::set_toys_budget(){
    toy_budget = Spending::set_budget("toys");
}

void Spending::set_bank(double b) {
    bank = b;
}

bool Spending::set_ideal_budget(double b){
    if(ideal_budget-b < 0){
        cout << "Sorry there is no more money in the budget, please lower your price" << endl;
        return false;
    }
    else{
        ideal_budget -= b;
        return true;
    }

}


int Spending::set_budget(string type) {
    int decimalCount = 0;
    string f;
    char floater;
    double input_budget;

    cout << "What is your " << type << " budget? (ex. 5.00)" << endl;
    cin >> f;

    while(decimalCount != 1 ){
        for (int i = 0; i < f.length(); i++) {
            if ((isdigit(f[i]) != true and f[i] != '.') or f.empty() ) {
                i = -1;
                decimalCount = 0;
                cout << "Input was not correct, try again" << endl;
                cin.clear();
                getline(cin, f);
            }
            if (f[i] == '.') {
                decimalCount++;
            }
            if (decimalCount > 1) {
                i = -1;
                decimalCount = 0;
                cout << "Input was not a float number, try again" << endl;
                cin.clear();
                getline(cin, f);
            }
        }
        if(decimalCount == 0){
            cout << "Input was not a float number, try again" << endl;
            cin.clear();
            getline(cin, f);
        }
    }
    input_budget = stod(f);
    return input_budget;
}

void Spending::set_all_budget(){
    cout << "Welcome to your budget maker, you currently have: $" << get_bank();
    cout << "\nBefore setting your budget make sure to account for animals\n you would like to buy in the future." << "\n" << endl;
    cout << "These budget recommendations are only recommendations, however, if you go over or under \nthen money will be deducted from you bank account" << endl;
    cout << "Let's set your accessory budget!" << endl;
    set_accessories_budget();
    while(!set_ideal_budget(get_accessories_budget())){
        set_accessories_budget();
    }
    cout << "You have $" << get_ideal_budget() << " left to budget." << endl;
    if(ideal_budget > 0){
        cout << "Let's set your food budget!" << endl;
        set_food_budget();
        while(!set_ideal_budget(get_food_budget())){
            set_food_budget();
        }
        cout << "You have $" << get_ideal_budget() << " left to budget." << endl;
    }
    if(ideal_budget > 0){
        cout << "Let's set your toy budget!" << endl;
        set_toys_budget();
        while(!set_ideal_budget(get_toy_budget())){
            set_toys_budget();
        }
        cout << "You have $" << get_ideal_budget() << " left to budget." << endl;
    }
    else{
        cout << "Looks like you have no more money left to budget" << endl;
    }
}

void Spending::check_balance(string type, double expense){
    if(type == "food"){
        food_budget = get_food_budget()-expense;
    }
    else if(type == "toy"){
        toy_budget = get_toy_budget()-expense;
    }
    else if(type == "accessory"){
        accessory_budget = get_accessories_budget()-expense;
    }
}

void Spending::print_budgets(){
    cout << "Accessory Budget: " << get_accessories_budget() << endl;
    cout << "Food Budget: " << get_food_budget() << endl;
    cout << "Toy Budget: " << get_toy_budget() << endl;
}

void Spending::budget_difference(double setBudget, double spentBudget) {
    double difference = setBudget - spentBudget;
    if(difference > 0){
        cout << "You spent " << difference << " less than you set for your pet" << endl;
    }
    else if(difference < 0){
        difference = difference * -1;
        cout << "You spent " << difference << " more than you set for your pet" << endl;
    }
}

double Spending::get_report(fstream& filename, int day) {
    string day_num =  "Day_Expense/0" + to_string(day) + "day.txt";
    ofstream days(day_num);
    string line;
    int day_number;
    double daily_total = 0.0;
    double daily_food = 0.0;
    double daily_toy = 0.0;
    double daily_accessory = 0.0;

    cout << "You have a food, toy, and accessory budget" << endl;
    cout << "Your food budget is $" << get_food_budget() << endl;
    cout << "Your toy budget is $" << get_toy_budget() << endl;
    cout << "Your accessory budget is $" << get_accessories_budget() << endl;
    if (filename.is_open())
    {
        while (getline(filename,line))
        {
            if(line.substr(0,3) == "Day"){
                day_number = stoi(line.substr(3,4));
                if(day_number == day){
                    if(line == "food"){
                        getline(filename,line);
                        daily_food += stod(line);
                        daily_total += daily_food;
                    }
                    else if(line == "toy"){
                        getline(filename,line);
                        daily_toy += stod(line);
                        daily_total += daily_toy;
                    }
                    else if(line == "accessory"){
                        getline(filename,line);
                        daily_accessory += stod(line);
                        daily_total += daily_accessory;
                    }
                }
            }
        }
        cout << "Today you spent: " << daily_total << endl;
        cout << "Food was $" << daily_food << endl;
        cout << "Toys were $" << daily_toy << endl;
        cout << "Accessories were $" << daily_accessory << endl;
        days << "food," << daily_food << endl;
        days << "toys," << daily_toy << endl;
        days << "accessory," << daily_accessory << endl;
    }
    double dub = 0;

    for(double c: expenses){
        dub += c;
    }
    cout << dub << "\n" << endl;
    return dub;
}

//UPDATES
double Spending::update_bank(double money){
    if(bank-=money < 1){
        bank -= money;
        cout << "Nice purchase! You have $" << bank << " left" << endl;
    }
    else{
        cout << "Oh no! You ran out of money!" << endl;
    }
    return bank;
}

double Spending::update_food(double money){
    food_budget -= money;
    return bank;
}

double Spending::update_accessory(double money){
    accessory_budget -= money;
    return bank;
}

double Spending::update_toy(double money){
    toy_budget -= money;
    return bank;
}

void Spending::get_money_info() {
    cout << "You currently have $" << Spending::get_bank() << " in your bank" << endl;
}

void Spending::make_day_table(int day_num){
    string day = to_string(day_num);

    // Declare variables
    vector<int> letterCounts(26);
    string line;

    // Open the Lyrics file
    ifstream inFile("Day" + day + ".txt");

    // Print the lyrics to an article html element
    cout << "<article><h3>Expenses</h3>" << endl;
    vector<int> food_costs;
    vector<int> toy_costs;
    vector<int> accessory_costs;
    vector<int> total;
    while (inFile) {
        int spending = 0;
        string category;

        while(inFile) {
            getline(inFile, line);
            // Print the line to the article and put a break tag to go to the next line
            cout << line << "<br>";
            if (category == "food") {
                try {
                    spending = stoi(line);
                    food_costs.push_back(spending);
                }
                catch (int param) {
                    throw;
                };
            }
            if (category == "toy") {
                try {
                    spending = stoi(line);
                    food_costs.push_back(spending);
                }
                catch (int param) {
                    throw;
                };
            }
            if (category == "accessory") {
                try {
                    spending = stoi(line);
                    food_costs.push_back(spending);
                }
                catch (int param) {
                    throw;
                };
            }
        }
    }
    cout << "</article>" << endl;

    // Write an html table to display the expense
    cout << "<table>\n<tr><th>Category</th><th>Costs</th></tr>" << endl;
    int total_money;
    for (int cost: food_costs) {
        total_money += cost;
    }
    cout << "<tr><td>Food</td><td>" << total_money << "</td></tr>" << endl;
    total_money = 0;
    for (int access: accessory_costs) {
        total_money += access;
    }
    cout << "<tr><td>Accessories</td><td>" << total_money << "</td></tr>" << endl;
    total_money = 0;
    for (int toy: toy_costs) {
        total_money += toy;
    }
    cout << "<tr><td>Toys</td><td>" << total_money << "</td></tr>" << endl;
    cout << "</table>" << endl;
}