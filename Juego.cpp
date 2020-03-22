#pragma once
#include "Jugador.cpp"
#include "Nivel.cpp"
#include "Puntuacion.cpp"

#include <iostream>

class Game {
    private:
    Level nivel;
    Player jugador;
	Record record;
    double efectividad;

    public:
    void run_game();
	Player get_jugador();
    Game(Level, Player);
    Game(); 
};

Player Game::get_jugador() {
	return this->jugador;
}

Game::Game(Level nivel, Player jugador): nivel(nivel), jugador(jugador) { }

Game::Game() {}

void Game::run_game() {
    unsigned int n1, n2, p, r = 0;
    int num_of_questions = 5, fails = 0, limit_number = nivel.max_number;
	for (size_t i = 0; i < num_of_questions; i++) {
		n1 = rand() % limit_number;
		n2 = rand() % limit_number;
		p = n1 * n2;
		std::cout << n1 << " multiplicado por " << n2 << " es:" << std::endl;
		std::cin >> r;
		size_t cont = 0;
		while (r != p && cont < 2) {
			cont++;
			std::cout << "You failed! (remaining attempts: " << 3 - cont << ")" << std::endl;
			std::cin >> r;
		}
		if (cont == 2) {
			std::cout << "FAIL!" <<std::endl;
			fails++;
		}
		else std::cout << "GOOD!" << std::endl;
	}
	this->efectividad = (num_of_questions - fails) * 100 / num_of_questions;
	this->record.level = this->nivel.name_level;
	this->record.record = this->efectividad;
	this->jugador.add_record(this->record);
}
