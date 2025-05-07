/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   Triangulo.h
 * Author: kille
 *
 * Created on 7 de mayo de 2025, 15:52
 */

#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iomanip>
#include <iostream>

    using namespace std;

    //Clase Madre Triángulo

    class Triangulo {
    protected:
        int **M;
        int N;
        //Método para liberar memoria si está ocupada

        void Borrar() {
            if (N != 0) {
                for (int i = 0; i < N; i++) {
                    delete []M[i];
                }
                delete []M;
                N = 0;
                M = NULL;
            }
        }
    public:
        //Constructor

        Triangulo() {
            N = 0;
            M = NULL;
            return;
        }

        //Constructor con parámetros

        Triangulo(int n) {
            N = 0;
            M = NULL;
            if (n > 0) { //Si el tamaño no es nulo, creamos la matriz triangular
                N = n;
                M = new int *[N];
                for (int i = 0; i < N; i++) {
                    M[i] = new int [N - i];
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - i; j++) { //Disminuimos en uno el número de columnas pora cada fila
                        M[i][j] = abs(rand() % 10);
                    }
                }
            }
            return;
        }

        //Constructor copia

        Triangulo(const Triangulo &otro) {
            N = 0;
            M = NULL;
            if (otro.N > 0) {
                N = otro.N;
                M = new int *[N];
                for (int i = 0; i < N; i++) {
                    M[i] = new int [N - i];
                }

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - i; j++) {
                        M[i][j] = otro.M[i][j];
                    }
                }
            }
            return;
        }

        //Destructor

        ~Triangulo() {
            Borrar();
            return;
        }

        //Operador de asignación

        Triangulo operator=(Triangulo otro) {
            Borrar();
            N = 0;
            M = NULL;

            if (otro.N != 0) {
                N = otro.N;
                M = new int *[N];
                for (int i = 0; i < N; i++) {
                    M[i] = new int [N - i];
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - i; j++) {
                        M[i][j] = otro.M[i][j];
                    }
                }
            }
            return *this;
        }

        //Operadores algebraicos entre Triangulos elemento a elemento

        Triangulo operator*(Triangulo otro) {
            Triangulo res;
            if (N == otro.N) {
                res = *this;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - i; j++) {
                        res.M[i][j] = res.M[i][j] * otro.M[i][j];
                    }
                }
            }
            return res;
        }

        Triangulo operator+(Triangulo otro) {
            Triangulo res;
            if (N == otro.N) {
                res = *this;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N - i; j++) {
                        res.M[i][j] = res.M[i][j] + otro.M[i][j];
                    }
                }
            }
            return res;
        }

        Triangulo operator+=(Triangulo otro) {
            *this = *this +otro;
            return *this;
        }

        Triangulo operator-(Triangulo otro) { //Suma del opuesto
            Triangulo res;
            res = *this;
            res = res + -otro;
            return res;
        }

        Triangulo operator-=(Triangulo otro) {
            *this = *this -otro;
            return *this;
        }

        Triangulo operator*=(Triangulo otro) {
            *this = *this * otro;
            return *this;
        }

        //Operador de igualdad

        bool operator==(Triangulo otro) {
            bool iguales = true;
            if (N == otro.N) {//Si el tamaño es igual, comprueba todos los elementos
                for (int i = 0; i < N && iguales; i++) {
                    for (int j = 0; j < N - i && iguales; j++) {
                        if (M[i][j] != otro.M[i][j]) {
                            iguales = false; //Si algún elemento es distinto, pone el marcador a falso
                        }
                    }
                }
            } else {
                iguales = false; //Si el tamaño es diferente, pone el marcador a falso
            }
            return iguales;
        }

        bool operator!=(Triangulo otro) {
            return !(*this == otro);
        }

        //Operador cambio signo

        friend Triangulo operator-(Triangulo otro) {
            for (int i = 0; i < otro.N; i++) {
                for (int j = 0; j < otro.N - i; j++) {
                    otro.M[i][j] = -otro.M[i][j];
                }
            }
            return otro;
        }

        //Operador para mostrar un objeto de tipo triangulo por pantalla

        friend ostream& operator<<(ostream &os, Triangulo otro) {
            if (otro.M != NULL) { //Si el puntero no es nulo, imprime el triangulo
                for (int i = 0; i < otro.N; i++) {
                    for (int j = 0; j < otro.N - i; j++) {
                        if (otro.M[i][j] == 0) {
                            os << setw(4) << 0 << " ";
                        } else {
                            os << setw(4) << otro.M[i][j] << " ";
                        }
                    }
                    os << endl;
                }
            } else { //Si el puntero es nulo, muestra el siguiente mensaje
                cout << "TRIANGULO NULO" << endl;
            }
            return os;
        }
    };
    
    //Faltan todas las clases heredadas

#endif /* TRIANGULO_H */