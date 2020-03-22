#include "Juego.cpp"
#include "Jugador.cpp"
#include "Nivel.cpp"

#include<iostream>
#include <vector>
#include<iomanip>
#include<conio.h>

using namespace std;

Level NIVEL1 = Level{9, "facil"};
Level NIVEL2 = Level{99, "medio"};
Level NIVEL3 = Level{999, "dificil"};
vector<Player> jugadores;
Player jugador;
Game partida;

void menu_principal();
void crea_nuevo_jugador();
void display_jugadores();
bool back_pregunta();
void menu_usuarios();
void sesion_usuario();
void menu_partida();
bool existe_jugador(char);
void seleccionar_usuario();
void display_records();
void cambia_nombre();
void update_user();

int main(int argc, char const *argv[])
{   
    menu_principal();
    return 0;
}

void menu_principal() {
    system("cls");
    char op;
    do{   
        cout<<"\t\t.::GaXme::."<<endl;
        cout<<"\t 1. Usuarios dispobibles"<<endl;
        cout<<"\t 2. Nuevo usuario"<<endl;
        cout<<"\t 3. Salir"<<endl;
        cin>>op;
        switch(op) {
        case '1': 
            menu_usuarios();
            break;
        case '2': 
            crea_nuevo_jugador();
            break;
        case '3':
            exit(0);
            break;
        default:
            system("cls");
            cout<<"\t** '"<<op<<"'"<<" no es una opcion valida **\n"<<endl;
            break;
        }
        
    } while(true);
}

void menu_usuarios() {
    system("cls");
    char r;
    do {
        cout<<"\t\t.::USUARIOS::."<<endl;
        display_jugadores();
        cout<<"\t1. Escoger usuario"<<endl;
        cout<<"\t2. Volver atras"<<endl;
        cin>>r;
        switch (r)
        {
        case '1':
            seleccionar_usuario();
            sesion_usuario();
            break;
        case '2':
            system("cls");
            return;
            break;
        default:
            system("cls");
            cout<<"\t** '"<<r<<"'"<<" no es una opcion valida **\n"<<endl;
            break;
        }
    } while(true);
}

void sesion_usuario() {
    system("cls");
    char r;
    do {
        cout<<"\t..::Bienvenido "<<jugador.get_username()<<"::.."<<endl;
        cout<<"\t 1. Jugar"<<endl;
        cout<<"\t 2. Records"<<endl;
        cout<<"\t 3. Cambiar nombre"<<endl;
        cout<<"\t 4. Cerrar sesion"<<endl;
        cin>>r;
     
        switch(r) {
        case '1':
            menu_partida();
            system("cls");
            cout<<"\t** puntuacion guardada, vea Records **\n"<<endl;
            break;
        case '2':
            display_records();
            system("cls");
            break;
        case '3':
            cambia_nombre();
            break;
        case '4':
            system("cls");
            update_user();
            return;
            break;
        default:
            system("cls");
            cout<<"\t** '"<<r<<"'"<<" no es una opcion valida **\n"<<endl;
            break;
        }
    } while(true);
}

void menu_partida() {
    char r;
    do {
        cout<<" 1.Facil"<<endl;
        cout<<" 2.Medio"<<endl;
        cout<<" 3.Dificil"<<endl;
        cin>>r;
    } while (r!= '1' && r!='2' && r!='3');
    switch (r)
    {
    case '1':
        partida = Game(NIVEL1, jugador);
        break;
    case '2':
        partida = Game(NIVEL2, jugador);
        break;
    case '3':
        partida = Game(NIVEL2, jugador);
        break;
    }
    partida.run_game();
    jugador = partida.get_jugador();
}


void seleccionar_usuario() {
    system("cls");
    char r;
    do {
        cout<<"\t\t::Seleccionar Usuario::"<<endl;
        display_jugadores();
        cout<<"numero de jugador: "<<endl;
        cin>>r;
        if (!existe_jugador(r)){
            system("cls");
            cout<<"\t** jugador numero "<<r<<" no existe **\n"<<endl;
        }
        else
            break;
    }while(true);
    jugador = jugadores[atoi(&r)];
}

void crea_nuevo_jugador() {
    string name;
    cout<<"username :";
    cin>>name;
    jugadores.push_back(Player(name));
    system("cls");
    cout<<"\t** jugador "<<name<<" creado **\n"<<endl;
}



void display_jugadores() {
    // for (int i=0; i<int(jugadores.size()); i++) {
    //     cout<<"Jugador "<<i
    //     <<": "<<jugadores[i].get_username()<<endl;
    // }

    cout<<"\t ---------------------------"<<endl;

    cout<<"\t|";
    cout.setf(ios::left);
    cout<<setw(7)<<"Numero "<<setw(15)<<"|Nombre "<<setw(4)<<"|ID ";
    cout<<"|"<<endl;

    
    // cout.setf(ios::left);
    cout<<"\t|";
    cout.fill('-');
    cout<<setw(7)<<""<<setw(15)<<"|"<<setw(4)<<"|";
    cout<<"|"<<endl;
    
    cout.fill(' ');
    for (int i=0; i<int(jugadores.size()); i++) {
        cout<<"\t|";
        // cout.fill('-');
        cout<<setw(7)<<i<<"";
        // cout.fill('-');
        cout<<"|"<<setw(14)<<jugadores[i].get_username()<<"";
        // cout.fill('-');
        cout<<"|"<<setw(3)<<jugadores[i].get_ID()<<"";
        cout<<"|"<<endl;
    }
    cout<<"\t ---------------------------"<<endl;

}

bool existe_jugador(char i) {
    if (isdigit(i) && atoi(&i)<jugadores.size())
        return true;
    return false;
}

bool back_pregunta() {
    cout<<"¿Volver a atras? (S/N)"<<endl;
    char r;
    while(r!='S' && r!='N') 
        cin>>r;
    if (r == 'S') return true;
    return false;
}

void display_records() {
    cout<<"\t\t::RECORDS::\t"<<endl;
    for (int i=0 ; i<jugador.get_best_records().size(); i++) {
        Record r = jugador.get_best_records()[i];
        string nivel = r.level;
        int record = r.record;
        cout<<"\tNivel: "<<nivel<<" Efectividad: "<<record<<"%"<<endl;
    }
    cout<<"presione una tecla para volver...";
    getch();
}

void cambia_nombre() {
    string new_name;
    cout<<"\t\t::Cambia Nombre::\n"<<endl;
    cout<<"\t Nombre anterior: "<<jugador.get_username()<<endl;
    cout<<"\t Nuevo nombre: "; cin>>new_name;
    jugador.set_username(new_name);
    system("cls");
    cout<<"\t** Nombre cambiado con exito **\n"<<endl;

}

void update_user() {
    for (int i=0; i<jugadores.size();i++) {
        if (jugadores[i].get_ID() == jugador.get_ID())
            jugadores[i] = jugador;
    }
    return;
}
