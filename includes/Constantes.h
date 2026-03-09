#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <string>
using namespace std;

//& ---- Tipografía ----
const string TEXTO_BOLD = "\033[1m";
const string TEXTO_ITALIC = "\033[3m";
const string RESET_STYLE = "\033[0m";

//& ---- Colores ----
const string COLOR_FONDO = "\033[48;2;0;112;192m";
const string TEXTO_BLANCO = "\033[97m";
const string TEXTO_NARANJA = "\033[38;5;214m";

const string TEXTO_EXITO = "\033[92m";
const string TEXTO_ERROR = "\033[91m";
const string TEXTO_ADVERTENCIA = TEXTO_ITALIC + TEXTO_NARANJA;
const string COLORES_BASE = COLOR_FONDO + TEXTO_BLANCO;
const string LIMPIAR_PANTALLA = "\033[2J\033[H";

const int ASCII_ENTER = 13;
const int ASCII_BACKSPACE = 8;

//& ---- Login ----
const string LOGIN_USER = "admin";
const string LOGIN_PASSWORD = "123456";

#endif // CONSTANTES_H