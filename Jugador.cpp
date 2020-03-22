#pragma once

#include "Puntuacion.cpp"

#include<string>
#include<vector>

class Player
{
private:
    int ID;
    std::string username;
    std::vector<Record> best_records;
public:
    static int nextID;

    int get_ID();
    std::string get_username();
    std::vector<Record> get_best_records();
    void add_record(Record);
    void set_username(std::string);
    Player(std::string);
    Player();
    ~Player();
};

int Player::nextID = 0; 

Player::Player(std::string name): username(name), ID(Player::nextID)
{
    nextID++;
}

Player::Player(): username("default") {
}

Player::~Player()
{
}

int Player::get_ID() { 
    return this->ID;
}

std::string Player::get_username() {
    return this->username;
}

std::vector<Record> Player::get_best_records() {
    return this->best_records;
}

void Player::set_username(std::string name) {
    this->username = name;
}

void Player::add_record(Record r) {
    this->best_records.push_back(r);
}
    