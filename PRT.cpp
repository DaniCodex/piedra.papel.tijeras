#include <iostream>
#include <ctime>
#include <cctype>

using namespace std;

char eleccionUsuario();
void mostrarEleccion (char eleccion);
char eleccionPC ();
void ganador (char jugador, char pc);

int main () {
    char jugador, pc, seguirJugando;

    do {
        jugador = eleccionUsuario();
        cout << "Jugador: ";
         mostrarEleccion(jugador);

        pc = eleccionPC();
        cout << "PC: ";
        mostrarEleccion(pc);

        ganador(jugador, pc);

        cout << "Quieres seguir jugando?  (S/N) "; cin >> seguirJugando;

    } while (seguirJugando == 's' || seguirJugando == 'S');
    

    return 0;
}

char eleccionUsuario () {
    char jugador;
    cout << "--------------------------- \n";
    cout << "    Roca-Papel-Tijera \n";
    cout << "--------------------------- \n";

    do {
        cout << "Elige una opcion (R/T/P): "; cin >> jugador;
        cout << "--------------------------- \n";

        jugador = tolower(jugador);

    } while (jugador != 'r' && jugador != 'p' && jugador != 't');
    
    return jugador;

}

void mostrarEleccion (char eleccion) {
    switch (eleccion) {
        case 'r':
            cout << "Roca \n";
            break;
        case 'p':
            cout << "Papel \n";
         break;
        case 't':
            cout << "Tijera \n";
         break;
            default:
        break;
    }
}

char eleccionPC () {
    srand(time(0));

    int num = rand() % 3 + 1;

    switch (num) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 't';

    }

    return 0;
}

void ganador (char jugador, char pc) {
    cout << "RESULTADO: ";
    switch (jugador) {
        case 'r':
            if (pc == 'r') {
                cout << "Empate \n ";
            } else if (pc == 'p') {
                cout << "Perdiste \n";
            } else {
                cout << "Ganaste!!! \n";
            }
        break;
        case 't':
            if (pc == 'r') {
                cout << "Perdiste \n ";
            } else if (pc == 'p') {
                cout << "Ganaste!!! \n";
            } else {
                cout << "Empate \n";
            }
            break;

        case 'p':
            if (pc == 'r') {
                cout << "Ganaste!!! \n ";
            } else if (pc == 'p') {
                cout << "Empate \n";
            } else {
                cout << "Perdiste \n";
            }
            break;
         default:
            break;
    }
}