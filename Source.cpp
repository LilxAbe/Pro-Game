#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <conio.h>
#pragma comment(lib, "winmm.lib")
#include <mmsystem.h>
#include <RtMidi.h>

using namespace std;

class IJuegos
{
public:
    virtual void jugar() = 0;
};

void IJugar(IJuegos* juegos)
{
    juegos->jugar();
}

class Control
{
public:
    HANDLE pantalla = GetStdHandle(STD_OUTPUT_HANDLE);

    Control()
    {

    }
    //Colores
    void rojo()
    {
        SetConsoleTextAttribute(pantalla, 0x000C);
    }
    void azul()
    {
        SetConsoleTextAttribute(pantalla, 0x0009);
    }
    void cyan()
    {
        SetConsoleTextAttribute(pantalla, 0x000B);
    }
    void verde()
    {
        SetConsoleTextAttribute(pantalla, 0x000A);
    }
    void amarillo()
    {
        SetConsoleTextAttribute(pantalla, 0x000E);
    }
    void magenta()
    {
        SetConsoleTextAttribute(pantalla, 0x000D);
    }
    void cafe()
    {
        SetConsoleTextAttribute(pantalla, FOREGROUND_RED | FOREGROUND_GREEN);
    }
    void rosa()
    {
        SetConsoleTextAttribute(pantalla, FOREGROUND_RED | FOREGROUND_BLUE);
    }
    void purpura()
    {
        SetConsoleTextAttribute(pantalla, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    }
    void defect()
    {
        SetConsoleTextAttribute(pantalla, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }

    //Elementos visuales
    void cargaNormal()
    {
        cout << "\t\t\t\tCargando por favor espere...\n\t\t\t\t\t\t";
        for (size_t i = 0; i < 30; i++)
        {
            cout << (char)219;
            Sleep(70);
        }
    }
    void cargaLenta()
    {
        cout << "\t\t\t\tCargando por favor espere...\n\t\t\t\t\t\t";
        for (size_t i = 0; i < 30; i++)
        {
            cout << (char)219;
            Sleep(70);
            if (i == 15)
            {
                Sleep(350);
            }
            if (i == 22)
            {
                Sleep(700);
            }
        }
    }
    void cargaIntro()
    {
        char estados[] = { '-', '\\', '|', '/' };
        int numEstados = sizeof(estados) / sizeof(estados[0]);
        cout << endl;
        c.cyan();
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < numEstados; j++)
            {
                cout << "\r\t\t\t\t\t\t" << estados[j] << " \tCargando... ";
                Sleep(90);
                cout.flush();
            }
        }
        c.defect();
    }
    void cargaIntro(int vez)
    {
        char estados[] = { '-', '\\', '|', '/' };
        int numEstados = sizeof(estados) / sizeof(estados[0]);
        cout << endl;
        c.cyan();
        for (int i = 0; i < vez; i++)
        {
            for (int j = 0; j < numEstados; j++)
            {
                cout << "\r\t\t\t\t\t\t" << estados[j] << " \tCargando... ";
                Sleep(90);
                cout.flush();
            }
        }
        c.defect();
    }
    void cargaAcciones()
    {
        char estados[] = { '-', '\\', '|', '/' };
        int numEstados = sizeof(estados) / sizeof(estados[0]);
        cout << endl;
        c.cyan();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < numEstados; j++)
            {
                cout << "\r\t\t\t\t\t" << estados[j] << " \tCargando... ";
                Sleep(90);
                cout.flush();
            }
        }
        c.defect();
        cout << "\r\t\t\t\t\t\t\t\t\t\r";
    }
    void cargaPalabras(string& opcionCPU)
    {
        srand(time(0));
        int nRand = 11;
        string palabras[] = { "Pied", "Pape", "Tija", "Laga", "Espoa", "Spok", "Robo", "Humo", "Fueo", "Plano", "Agua" };
        for (int i = 0; i < nRand + 20; i++)
        {
            int numRand = rand() % nRand;
            string pal = palabras[numRand];
            const char* pala = pal.c_str();
            int aux = strlen(pala);
            cout << "\t\t\t\t\t\t\t     " << left << pal << setw(20 - aux) << "" << "\r";
            Sleep(50);
            cout << "\r" << setw(45) << "" << "\r";
        }
        c.rojo();
        cout << "\t\t\t\t\t\t\t     " << opcionCPU; c.defect(); cout << endl;
    }
    void intro(const char* audio4)
    {
        srand(time(0));
        c.amarillo();
        cout << "\n";
        c.cyan();
        cout << "\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        c.rojo();
        cout << "\t\t\t\t\t   x = x  "; c.defect(); cout << "P  R  O  C  R  E  A"; c.rojo(); cout << "   x = x  \n";
        c.cyan();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        Sleep(1250);
        c.cyan();
        cout << "\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        c.rojo();
        cout << "\t\t\t\t         x = x  "; c.defect(); cout << " P  R  O  J  U  E  G  A"; c.rojo(); cout << "   x = x  \n";
        c.cyan();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        Sleep(1000);
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        Sleep(3000);
        cout << "\t\t\t\t    ";
        cout << "\n\n\t\t\t";
        int i = 0;
        int auxR = 0;
        int nRandS = 0;
        int vez = 0;
        PlaySoundA(audio4, NULL, SND_FILENAME | SND_ASYNC);
        while (i < 4)
        {
            nRandS = rand() % 9;
            while (auxR == nRandS)
            {
                nRandS = rand() % 9;

                
            }
            auxR = nRandS;

            if (nRandS == 0)
            {
                nRandS += 1;
            }

            switch (nRandS)
            {
            case 1:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.verde();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t   ";
                c.verde();
                cout << "\tRecolecta puntos y desbloquea contenido\n\n\n\n\n\n\n\n";
                i++;
                vez = 5;
                c.cargaIntro(vez);
                break;
            case 2:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.amarillo();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t    ";
                c.amarillo();
                cout << "\tUtiliza el piano para desestresarte un rato. It's free!\n\n\n\n\n\n\n\n";
                i++;
                vez = 7;
                c.cargaIntro(vez);
                break;
            case 3:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.azul();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t    ";
                c.azul();
                cout << "\tCompite contra el puntaje de otros jugadores\n\n\n\n\n\n\n\n";
                i++;
                vez = 6;
                c.cargaIntro(vez);
                break;
            case 4:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.rojo();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t    ";
                c.rojo();
                cout << "\tSolo tenias que seguir el maldito Tren, Cj!\n\n\n\n\n\n\n\n";
                i++;
                vez = 5;
                c.cargaIntro(vez);
                break;
            case 5:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.cafe();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t ";
                c.cafe();
                cout << "Encuentra el Easter Egg para conseguir el Millon de puntos\n\n\n\n\n\n\n\n";
                i++;
                vez = 7;
                c.cargaIntro(vez);
                break;
            case 6:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.rosa();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t    ";
                c.rosa();
                cout << "\tEPIC jamas te pedira tu contraseña de FORTNITE\n\n\n\n\n\n\n\n";
                i++;
                vez = 6;
                c.cargaIntro(vez);
                break;
            case 7:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.magenta();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t";
                c.magenta();
                cout << "\tSi pasas tus codigos, Fernando te amonestara :(\n\n\n\n\n\n\n\n";
                i++;
                vez = 6;
                c.cargaIntro(vez);
                break;
            case 8:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.defect();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t  ";
                c.defect();
                cout << "Recuerda realizar los desafios para conseguir mas puntos\n\n\n\n\n\n\n\n";
                i++;
                vez = 7;
                c.cargaIntro(vez);
                break;
            case 9:
                system("CLS");
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.purpura();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                cout << "\n\n";
                cout << "\n\n\t\t\t\t";
                cout << "\n\t\t\t\t    ";
                c.purpura();
                cout << "\t\t\tHola mundo!\n\n\n\n\n\n\n\n";
                i++;
                vez = 4;
                c.cargaIntro(vez);
                break;
            default: break;
            }
        }
    }

    //Cont Extra
    void escogeme()
    {

    }

    void acercaDe()
    {
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t\t  -Creditos-" << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(1300);
        c.rojo();
        cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t       -Desarrolladores-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tEmilio Enrique Cesena M." << endl;
        cout << "\t\t\t\t\t\tReni Sebastian Altamirano C." << endl;
        cout << "\t\t\t\t\t\tJosue Ezequiel Colin P." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=\n" << endl;
        Sleep(750);
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t         -Produccion-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLenguaje: C++" << endl;
        cout << "\t\t\t\t\t\tIDLE: Visual Basic Studio" << endl;
        cout << "\t\t\t\t\t\tFilmora 12 Audio" << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(5000);
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t    -Contenido Desarrollado-" << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(1300);        
        c.rojo();
        cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.verde();
        cout << "\t\t\t\t\t\t         -TicTacToe-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tEmilio Enrique Cesena M." << endl;
        Sleep(750);
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.azul(); 
        cout << "\t\t\t\t\t\t       -Adivina Numeros-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tReni Sebastian Altamirano C." << endl;
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        Sleep(750);
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.rosa(); 
        cout << "\t\t\t\t\t\t    -Piedra Papel Tijeras-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tEmilio Enrique Cesena M." << endl;
        cout << "\t\t\t\t\t\tJosue Ezequiel Colin P." << endl;
        cout << "\t\t\t\t\t\tReni Sebastian Altamirano C." << endl;
        Sleep(750);
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.defect(); 
        cout << "\t\t\t\t\t\t         -Ahorcado--" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tReni Sebastian Altamirano C." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(7000);
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t    -Contenido Desarrollado-" << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(1300);
        c.rojo();
        cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.verde(); 
        cout << "\t\t\t\t\t\t         -BlackJack-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;        
        Sleep(750);
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.azul(); 
        cout << "\t\t\t\t\t\t          -Piano-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tJosue Ezequiel Colin P." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(750);
        c.rojo();
        c.rosa(); 
        cout << "\t\t\t\t\t\t        -Ruleta Rusa-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(750);
        c.defect(); 
        cout << "\t\t\t\t\t\t          -Volado-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tReni Sebastian Altamirano C." << endl;
        cout << "\t\t\t\t\t\tEmilio Enrique Cesena M." << endl;
        cout << "\t\t\t\t\t\tJosue Ezequiel Colin P." << endl;
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(6000);
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";

        c.rojo();
        cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t      -Ideas de la musica-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tJosue Ezequiel Colin P." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(750);
        c.rojo();
        cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t          -Dise" << (char)164 << "o-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tLuis Abraham Rios R." << endl;
        cout << "\t\t\t\t\t\tEmilio Enrique Cesena M." << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(750);
        c.rojo();
        cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.cyan();
        cout << "\t\t\t\t\t\t      -Agradecimientos-" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\tFamilia, Amigos y Profesores" << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        Sleep(3000);
        c.rojo();
        cout << "\n\n\n\n\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        c.defect();
        cout << "\t\t\t\t\t        Persione 'ENTER' para regresar" << endl;
        c.rojo();
        cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
        _getch();
    }

}c;

class Jugador
{
public:
    string usuario;
    int puntaje;
    int partidas;
    bool des1 = false;
    bool des2 = false;
    bool des3 = false;
    bool des4 = false;
    bool des5 = false;
    bool des6 = false;
    int partV, partAN, partPPT, partTTT, partAHO;
    int piedra;
    int cExt;

    vector <Jugador> jugadores;

    Jugador()
    {
        puntaje = 0;
        partidas = 0;
        partV = 0;
        partAN = 0;
        partPPT = 0;
        cExt = 0;
        partTTT = 0;
        partAHO = 0;
        piedra = 0;
    }

    Jugador(string usuario, int puntaje)
    {
        this->usuario = usuario;
        this->puntaje = puntaje;
    }

    string getUsuario()
    {
        return usuario;
    }

    void setUsuario(string us)
    {
        usuario = us;
    }

    int getPuntaje()
    {
        return puntaje;
    }

    void setPuntaje(int punt)
    {
        puntaje = punt;
    }

    int getPartidas()
    {
        return partidas;
    }

    void setPartidas(int part)
    {
        partidas = part;
    }

    int getPartV()
    {
        return partV;
    }

    void setPartV(int pv)
    {
        partV = pv;
    }

    int getPartAN()
    {
        return partAN;
    }

    void setPartAN(int pan)
    {
        partAN = pan;
    }

    int getPartPPT()
    {
        return partPPT;
    }

    void setPartPPT(int pppt)
    {
        partPPT = pppt;
    }

    int getPartTTT()
    {
        return partTTT;
    }

    void setPartTTT(int pttt)
    {
        partTTT = pttt;
    }

    int getPartAHO()
    {
        return partAHO;
    }

    void setPartAHO(int paho)
    {
        partAHO = paho;
    }

    int getPiedra()
    {
        return piedra;
    }

    void setPiedra(int pie)
    {
        piedra = pie;
    }

    int getCExt()
    {
        return cExt;
    }

    void setCExt(int cextra)
    {
        cExt = cextra;
    }

    void registro(vector<Jugador>& jugadores)
    {
        system("CLS");
        string us = "";
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";
        c.amarillo();
        cout << "\t\t\t\t\t\t  Registro de usuario\n"; c.defect();
        c.magenta();
        cout << "\t\t\t\t\t*****************************************\n";
        c.cyan();
        cout << "\t\t\t\t\t\t!Bienvenido nuevo jugador!"; c.rojo(); cout << "\n\t\t\t\t\t      Wow. Primero debes registrarte";
        c.magenta();
        cout << "\n\t\t\t\t\t*****************************************\n";
        c.cyan();
        cout << "\n\t\t\t\t\t          Ventajas de usuarios:\n";
        c.magenta();
        cout << "\t\t\t\t\t*****************************************\n";
        
        c.verde();
        cout << "\t\t\t\t\t*-Recoleccion de puntos\n"; 
        c.azul(); cout << "\t\t\t\t\t*-Tablero de puntaje\n"; 
        c.rojo(); cout << "\t\t\t\t\t*-Desbloquear contenido oculto\n"; 
        c.cafe(); cout << "\t\t\t\t\t*-Desafios y logros\n"; 
        c.amarillo(); cout << "\t\t\t\t\t*-Canjeo codigos\n"; 
        c.magenta();
        cout << "\t\t\t\t\t*****************************************";
        c.cyan();
        cout << "\n\t\t\t\t\t\t\tRegistro";
        c.magenta();
        cout << "\n\t\t\t\t\t*****************************************";
        c.amarillo();
        cout << "\n\t\t\t\t\tIngrese el nickname que desee utilizar"; c.rojo(); cout << "\n\t\t\t\t\t- No debe superar los 15 caracteres -\n\t\t\t\t\t- Podra modificarlo mas tarde -";
        c.magenta();
        cout << "\n\t\t\t\t\t*****************************************";
        c.amarillo();
        cout << "\n\t\t\t\t\tNickname: "; c.cyan(); cin >> us;
        if (us.length() > 15)
        {
            c.rojo();
            cout << "\n\t\t\t\tHaz ingresado un exceso de caracteres! (15). Vuelve a intentarlo.";
            c.defect();
            _getch();
            j.registro(j.jugadores);
        }
        else
        {
        Jugador jug(us, 0); jugadores.push_back(jug);
        c.magenta();
        cout << "\t\t\t\t\t*****************************************\n";
        c.defect();
        cout << "\t\t\t\t\t-----------------------------------------\n";
        c.amarillo();
        cout << "\t\t\t\t\tUsuario registrado correctamente con el\n\t\t\t\t\tnickname: "; c.cyan(); cout << us; c.defect(); cout << ".\n";
        c.defect();
        cout << "\t\t\t\t\t-----------------------------------------\n";
        c.amarillo();
        cout << "\t\t\t\t\tPresione ENTER para ir al menu principal"; c.defect(); _getch();
        }        
    }

    void usuarios(vector<Jugador>& jugadores)
    {
        int op;
        string us;
        do
        {
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.azul();
            cout << "\n\t\t\t\tBienvenido al sistema de usuarios\n"; c.defect();
            cout << "\t\t\t\t-----------------------------------------\n";
            c.azul();
            cout << "\t\t\t\t\tBeneficio de usuarios:\n";
            c.magenta();
            cout << "\t\t\t\t*****************************************\n";
            c.defect();
            cout << "\t\t\t\t-----------------------------------------\n";
            c.verde();
            cout << "\t\t\t\t*-Recoleccion de puntos\n"; c.azul(); cout << "\t\t\t\t*-Registro de puntaje\n"; c.rojo(); cout << "\t\t\t\t*-Desbloquear contenido oculto\n"; c.rosa(); cout << "\t\t\t\t*-Canjeo codigos\n"; c.defect();
            cout << "\t\t\t\t-----------------------------------------\n";
            c.magenta();
            cout << "\t\t\t\t*****************************************";
            c.cafe();
            cout << "\n\t\t\t\tSelecciona la opcion que deseas:\n"; c.amarillo(); cout << "\t\t\t\t1.-Modificar nombre de usuario\n\t\t\t\t2.-Consultar datos completos de usuario\n\t\t\t\t3.-Guardar Score\n\t\t\t\t4.-Salir\n"; c.defect(); cout << "\t\t\t\tOpcion: "; cin >> op;


            switch (op)
            {
            case 1:
                system("CLS");
                c.amarillo();
                cout << "\t\t\t\t\t\tUsuarios\n\n"; c.defect();
                c.cafe();
                cout << "\n\n\t\t\t\tEL usuario en esta partida es: "; c.azul(); cout << j.jugadores[0].getUsuario() << endl; c.defect();
                cout << "\t\t\t\t---------------------------------\n";
                c.cafe();
                cout << "\t\t\t\tIngrese el nuevo nombre de usuario: ";
                c.defect();
                cin >> us;
                cout << "\t\t\t\t--------------------------\n";
                j.jugadores[0].setUsuario(us);
                c.verde();
                cout << "\t\t\t\tEL nuevo usuario es: "; c.azul(); cout << j.jugadores[0].getUsuario() << endl; c.defect();
                c.magenta();
                cout << "\t\t\t\t"; system("PAUSE");
                break;

            case 2:
                system("CLS");
                c.amarillo();
                cout << "\t\t\t\t\t\tUsuarios\n\n"; c.defect();
                c.cafe();
                cout << "\t\t\t\tEL usuario en esta partida es: "; c.azul(); cout << j.jugadores[0].getUsuario() << endl; c.defect();
                cout << "\t\t\t\t--------------------------\n";
                c.verde();
                cout << "\t\t\t\tEl total de puntos del usuario es: "; c.azul(); cout << j.jugadores[0].getPuntaje() << endl; c.defect();
                cout << "\t\t\t\t--------------------------\n";
                c.magenta();
                cout << "\t\t\t\t"; system("PAUSE");
                break;
            case 3: cout << "\n\n\t\t\t\tSe ha guardado correctamente el Score. Regresara al menu anterior..."; _getch(); usuarios(jugadores); break;
            case 4: break;
            default: cout << "\n\n\t\t\t\tOpcion incorrecta, intente de nuevo."; _getch(); usuarios(jugadores);
            }

        } while (op < 4);
    }

    void guardarPuntaje(Jugador usuario) {
        ofstream archivo_guardar("score.txt", ios_base::app);
        if (archivo_guardar.good())
        {
            if (!archivo_guardar.is_open())
            {
                archivo_guardar.open("score.txt", ios_base::app);
            }
            archivo_guardar << usuario.getUsuario() << "\t\t" << usuario.getPuntaje() << "\n";
            archivo_guardar.close();
            cout << "\t\t\t\t\t\tSe guardo su record correctamente.\n";
        }
        else
        {
            cout << "\t\t\t\t\t\tNo se pudo abrir el archivo.\n";
        }
    }

    void mostrarPuntaje()
    {
        string linea;
        ifstream cargar_archivo("score.txt");
        system("CLS");
        int i;
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n\n";        
        c.rosa();
        cout << "\t\t\t\t\tScore: Tablero de puntos\n\n";
        cout << "\t\t\t\t****************************\n";
        c.amarillo();

        if (cargar_archivo.is_open())
        {
            int i = 1;
            while (getline(cargar_archivo, linea))
            {
                cout << "\t\t\t\t" << i << setw(3) << ".-" << setw(25) << left << linea << endl;
                i++;
            }
        }
        else
        {
            ifstream cargar_archivo("score.txt");

            if (cargar_archivo.is_open())
            {
                while (getline(cargar_archivo, linea))
                {
                    cout << linea << "\n";
                }
                cargar_archivo.close();
            }
            else
            {
                cout << "No se pudo abrir el archivo";
                system("PAUSE");
            }
        }
        c.rosa();
        cout << "\t\t\t\t****************************\n";
        cout << "\n\n\t\t\t\t"; system("PAUSE");
        system("CLS");
    }

    void desafios(vector <Jugador> jugadores)
    {

        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.rosa();
        cout << "\n\t\t\t\t****************************************************\n";
        c.amarillo();
        cout << "\t\t\t\t\tCompleta los desafios y consigue puntos\n";
        cout << "\t\t\t\t!Consigue puntos de manera rapida con estos desafios!\n";
        c.rosa();
        cout << "\n\t\t\t\t****************************************************\n";

        //Desafio 1
        c.azul();
        if (j.getPartAN() < 3)
        {
            cout << "\t\t\t\t1.-Gana 3 veces consecutivas en 'Adivinar el numero' | +25 puntos\n";
        }
        else
        {
            c.verde();
            cout << "\t\t\t\t1.-!Ganaste 3 veces consecutivas en 'Adivinar el numero'!       | Conseguido +25 puntos\n";
            if (des1 == false)
            {
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 25);
                des1 = true;
            }
            c.azul();
        }
        //Desafio 2
        if (j.jugadores[0].getPuntaje() != 36)
        {
            cout << "\t\t\t\t2.-Consigue una puntuacion exacta de 36 puntos       | +15 puntos\n";
        }
        else
        {
            c.verde();
            cout << "\t\t\t\t2.-!Conseguiste una puntuacion exacta de 36 puntos!       | Conseguido +15 puntos\n";
            if (des2 == false)
            {
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 15);
                des2 = true;
            }
            c.azul();
        }
        //Desafio 3
        c.azul();
        if (j.jugadores[0].getPiedra() == 0)
        {
            cout << "\t\t\t\t3.-Gana con Piedra en 'Piedra, papel o tijera'       | +10 puntos\n";
        }
        else
        {
            c.verde();
            cout << "\t\t\t\t3.-!Ganaste con Piedra en 'Piedra, papel o tijera'   | Conseguido +10 puntos\n";
            if (des3 == false)
            {
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                des3 = true;
            }
            c.azul();
        }
        //Desafio 4
        c.azul();
        if (j.cExt == 0)
        {
            cout << "\t\t\t\t4.-Consigue canjear un codigo en 'Contenido Extra'   | +20 puntos\n";
        }
        else
        {
            c.verde();
            cout << "\t\t\t\t4.-Canjeaste un codigo de acceso!   | Conseguido +10 puntos\n";
            if (des4 == false)
            {
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                des4 = true;
            }
            c.azul();
        }
        //Desafio 5
        c.azul();
        if (j.getPartV() < 3)
        {
            cout << "\t\t\t\t5.-Consigue 'cara' en el 'Volado' 3 veces seguidas   | +25 puntos\n";
        }
        else
        {
            c.verde();
            cout << "\t\t\t\t5.-Conseguiste 'cara' en el 'Volado' 3 veces seguidas!         | Conseguido +50 puntos\n";
            if (des5 == false)
            {
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                des5 = true;
            }
            c.azul();
        }
        c.rosa();
        cout << "\n\t\t\t\t****************************************************\n";
        cout << "\n\t\t\t\t"; system("PAUSE");

    }

}j;

class TicTacToe : public IJuegos
{
public:
    string jugador;
    vector<int> x;
    vector<int> o;
    vector<string> tablero;
    vector<string> tablero2;
    vector<string> tablero3;

    TicTacToe()
    {
        tablero = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
        tablero2 = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };
        tablero3 = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25" };
        jugador = "X";

    }

    void jugar()
    {
        int op;
        do
        {
            bool empate = true;
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.cafe();
            cout << "\n\n\t\t\t\t\tSeleccione la dificultad de partida";
            c.rosa();
            cout << "\n\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.cyan();
            cout << "\n\t\t\t\t\t\t   1.-Tablero 3x3\n";
            c.rojo();
            cout << "\t\t\t\t\t\t   2.-Tablero 4x4(dificil)\n";
            c.cafe();
            cout << "\t\t\t\t\t\t   3.-Regresar\n";
            c.rosa();
            cout << "\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=xA2=x=x=x";
            c.defect();
            cout << "\n\t\t\t\t\t\t      Opcion: "; c.defect(); cin >> op;

            switch (op)
            {
            case 1:
                tablero3x3();
                while (!victoria3x3(empate))
                {
                    opcionJugador3x3();
                    tablero3x3();

                    if (victoria3x3(empate))
                    {
                        break;
                    }

                    if (jugador == "X")
                    {
                        jugador = "O";
                    }
                    else
                    {
                        jugador = "X";
                    }

                }
                if (!empate)
                {
                    c.amarillo();
                    cout << "\n\t\t\t\t\t\tFelicidades jugador "; c.cyan(); cout << jugador; c.verde(); cout << "\n\n\t\t\t\t\t\t\t! Ganaste !\n"; c.rojo();
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 5);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartTTT(j.jugadores[0].getPartTTT() + 1);
                    cout << "\n\t\t\t\t"; system("PAUSE");
                }
                else
                {
                    j.setPartidas(j.getPartidas() + 1);
                }

                if (op == 1 || op == 2)
                {
                    tablero = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
                }
                break;

            case 2:
                tablero4x4();
                while (!victoria4x4(empate))
                {
                    opcionJugador4x4();
                    tablero4x4();

                    if (victoria4x4(empate))
                    {

                        break;
                    }
                    if (jugador == "X")
                    {
                        jugador = "O";
                    }
                    else
                    {
                        jugador = "X";
                    }
                }

                if (!empate)
                {
                    c.cyan();
                    cout << "\t\t\t\t\t\tFelicidades jugador "; c.cyan(); cout << jugador; c.verde(); cout << "\n\t\t\t\t\t\t! Ganaste !\n"; c.rojo();
                    if (jugador != "O")
                    {
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 5);
                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                        j.jugadores[0].setPartTTT(j.jugadores[0].getPartTTT() + 1);
                    }
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    cout << "\n\t\t\t\t"; system("PAUSE");
                }
                else
                {
                    j.setPartidas(j.getPartidas() + 1);
                }

                if (op == 1 || op == 2)
                {
                    tablero2 = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16" };
                }
                break;

            case 3: op == 2;
                break;

            default: c.rojo(); cout << "\n\t\t\t\tIngreso una opcion no valida, vuelva a intentarlo.\n"; c.defect(); _getch(); t.jugar();
                break;
            }

            

        } while (op < 3);

    };

    void tablero3x3()
    {
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.azul();
        cout << "\n\t\t\t\t\t!Bienvenido al juego del gato y el raton!\n";
        c.cafe();
        cout << "\n\t\t\t\t\t\t     Instrucciones:";
        c.defect();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.amarillo();
        cout << "\n\t\t\t\t1.-Cada jugador debe colocar su sello en diferentes posiciones"
            << "\n\t\t\t\t2.-Se debe formar una fila, columna o diagonal del mismo sello"
            << "\n\t\t\t\t3.-El primero en lograr esto sera el ganador";
        c.defect();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.azul();
        cout << "\n\n\t\t\t\t\t\t         !A Jugar!";
        cout << "\n" << endl;
        c.defect();
        cout << "\t\t\t\t\t\t" << (char)218 << "-------------------------" << (char)191 << "\n";
        cout << "\t\t\t\t\t\t|\t "; if (tablero[0] == "1") { c.cyan(); } else { c.rosa(); } cout << tablero[0]; c.defect(); cout << " | "; if (tablero[1] == "2") { c.cyan(); } else { c.rosa(); } cout << tablero[1]; c.defect(); cout << " | "; if (tablero[2] == "3") { c.cyan(); } else { c.rosa(); } cout << tablero[2]; c.defect(); cout << "\t  |" << endl;
        cout << "\t\t\t\t\t\t|\t---+---+---" << "\t  |" << endl;
        cout << "\t\t\t\t\t\t|\t "; if (tablero[3] == "4") { c.cyan(); } else { c.rosa(); } cout << tablero[3]; c.defect(); cout << " | "; if (tablero[4] == "5") { c.cyan(); } else { c.rosa(); } cout << tablero[4]; c.defect(); cout << " | "; if (tablero[5] == "6") { c.cyan(); } else { c.rosa(); } cout << tablero[5]; c.defect(); cout << "\t  |" << endl;
        cout << "\t\t\t\t\t\t|\t---+---+---" << "\t  |" << endl;
        cout << "\t\t\t\t\t\t|\t "; if (tablero[6] == "7") { c.cyan(); } else { c.rosa(); } cout << tablero[6]; c.defect(); cout << " | "; if (tablero[7] == "8") { c.cyan(); } else { c.rosa(); } cout << tablero[7]; c.defect(); cout << " | "; if (tablero[8] == "9") { c.cyan(); } else { c.rosa(); } cout << tablero[8]; c.defect(); cout << "\t  |" << endl;
        cout << "\t\t\t\t\t\t" << (char)192 << "-------------------------" << (char)217 << "\n";

        c.defect();
    }

    void tablero4x4()
    {
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.azul();
        cout << "\n\t\t\t\t\t!Bienvenido al juego del gato y el raton!\n";
        c.cafe();
        cout << "\n\t\t\t\t\t\t     Instrucciones:";
        c.defect();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.amarillo();
        cout << "\n\t\t\t\t1.-Cada jugador debe colocar su sello en diferentes posiciones"
            << "\n\t\t\t\t2.-Se debe formar una fila, columna o diagonal del mismo sello"
            << "\n\t\t\t\t3.-El primero en lograr esto sera el ganador";
        c.defect();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.azul();
        cout << "\n\n\t\t\t\t\t\t         !A Jugar!";
        cout << "\n" << endl;
        c.defect();
        cout << "\t\t\t\t\t" << (char)218 << "-------------------------------" << (char)191 << "\n";
        cout << "\t\t\t\t\t\t|\t" << " " << tablero2[0] << " | " << " " << tablero2[1] << " | " << " " << tablero2[2] << " | " << " " << tablero2[3] << "\t|" << endl;
        cout << "\t\t\t\t\t\t|\t---+----+----+----" << "\t|" << endl;
        cout << "\t\t\t\t\t\t|\t" << " " << tablero2[4] << " | " << " " << tablero2[5] << " | " << " " << tablero2[6] << " | " << " " << tablero2[7] << "\t|" << endl;
        cout << "\t\t\t\t\t\t|\t---+----+----+----" << "\t|" << endl;
        cout << "\t\t\t\t\t\t|\t" << " " << tablero2[8] << " | " << tablero2[9] << " | " << tablero2[10] << " | " << tablero2[11] << "\t|" << endl;
        cout << "\t\t\t\t\t\t|\t---+----+----+----" << "\t|" << endl;
        cout << "\t\t\t\t\t\t|\t" << tablero2[12] << " | " << tablero2[13] << " | " << tablero2[14] << " | " << tablero2[15] << "\t|" << endl;
        cout << "\t\t\t\t\t\t" << (char)192 << "-------------------------------" << (char)217 << "\n";
        c.defect();
    }

    bool victoria3x3(bool& empate)
    {
        for (int i = 0; i < 9; i += 3)
        {
            if (tablero[i] == tablero[i + 1] && tablero[i + 1] == tablero[i + 2])
            {
                return true;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            if (tablero[i] == tablero[i + 3] && tablero[i + 3] == tablero[i + 6])
            {
                return true;
            }
        }

        if (tablero[0] == tablero[4] && tablero[4] == tablero[8])
        {
            return true;
        }

        if (tablero[2] == tablero[4] && tablero[4] == tablero[6])
        {
            return true;
        }
        empate = true;
        for (int i = 0; i < 9; i++)
        {
            if (tablero[i] != "X" && tablero[i] != "O")
            {
                empate = false;
                break;
            }
        }
        if (empate)
        {
            cout << "\t\t\t\tHa habido un empate!" << endl;
            return true;
        }

        return false;
    }

    bool victoria4x4(bool& empate)
    {
        for (int i = 0; i < tablero2.size(); i += 4)
        {
            if (tablero2[i] == tablero2[i + 1] && tablero2[i + 1] == tablero2[i + 2] && tablero2[i + 1] == tablero2[i + 3])
            {
                return true;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (tablero2[i] == tablero2[i + 4] && tablero2[i + 4] == tablero2[i + 8] && tablero2[i + 4] == tablero2[i + 12])
            {
                return true;
            }
        }

        if (tablero2[0] == tablero2[5] && tablero2[5] == tablero2[10] && tablero2[5] == tablero2[15])
        {
            return true;
        }

        if (tablero2[3] == tablero2[6] && tablero2[6] == tablero2[9] && tablero2[6] == tablero2[12])
        {
            return true;
        }
        empate = true;
        for (int i = 0; i < tablero2.size(); i++)
        {
            if (tablero2[i] != "X" && tablero2[i] != "O")
            {
                empate = false;
                break;
            }
        }
        if (empate)
        {
            cout << "\t\t\t\tHa habido un empate!" << endl;
            return true;
        }

        return false;
    }

    void opcionJugador3x3()
    {
        string choice;
        c.defect();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=B3x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.amarillo();
        cout << "\n\n\t\t\t\t\t\tEs turno del jugador "; c.rosa(); cout << jugador; 
        c.amarillo(); 
        cout << "\n\t\t\t\t\tIngresa el numero donde colocaras '"; c.rosa(); cout << jugador; c.amarillo(); cout << "': "; c.cyan();
        cin >> choice;
        c.defect();
        for (int i = 0; i < tablero.size(); i++)
        {
            if (tablero[i] == choice)
            {
                tablero[i] = jugador;
                return;
            }
        }
        c.rojo();
        cout << "\t\t\t\t\tOpcion invalida, intentalo de nuevo..." << endl; _getch();
        opcionJugador3x3();
    }

    void opcionJugador4x4()
    {
        string choice;
        c.defect();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=B3x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.amarillo();
        cout << "\n\n\t\t\t\t\t\tEs turno del jugador "; c.rosa(); cout << jugador;
        c.amarillo();
        cout << "\n\t\t\t\t\tIngresa el numero donde colocaras '"; c.rosa(); cout << jugador; c.amarillo(); cout << "': "; c.cyan();
        cin >> choice;
        for (int i = 0; i < tablero2.size(); i++)
        {
            if (tablero2[i] == choice)
            {
                tablero2[i] = jugador;
                return;
            }
        }
        c.rojo();
        cout << "\t\t\t\t\tOpcion invalida, intentalo de nuevo..." << endl; _getch();
        opcionJugador4x4();
    }

}t;

class Numeros : public IJuegos
{
public:
    int intentos;

    void jugar()
    {        
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;

        int numRandom = 0;
        int op = 0;
        int adivina = 0;
        srand(time(NULL));

        c.cafe();
        cout << "\n\n\t\t\t\tA continuacion debera adivinar el numero secreto para ganar";
        c.rosa();
        cout << "\n\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.amarillo();
        cout << "\t\t\t\tElige la dificultad que desees:\n";
        c.rosa();
        cout << "\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=H5x=x=x=x\n";
        //Mensaje dificultades
        c.verde();
        cout << "\t\t\t\t1.-Facil (1-50 | 5 intentos | Asiss)\n";
        c.amarillo();
        cout << "\t\t\t\t2.-Normal (1-100 | 7 intentos | Asiss)\n";
        c.azul();
        cout << "\t\t\t\t3.-Dificil (1-100 | 5 intentos | Asiss)\n";
        c.cafe();
        cout << "\t\t\t\t4.-Extremo (1-50 | 5 intentos | Asiss limitada)\n";
        c.rojo();
        cout << "\t\t\t\t5.-Modo Dios (1-10 | 1 intento | +200 Ganas -200 Pierdes)\n";
        c.amarillo();
        cout << "\t\t\t\t6.-regresar\n";
        c.rosa();
        cout << "\t\t\t\tx=x=x=x=x=C7x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t\t\t\tOpcion: "; cin >> op;
        c.magenta();
        
        //Dependiendo de la dificultad elegida se modifican los intentos, etc.
        switch (op)
        {
        case 1:
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.cafe();
            cout << "\n\t\t\t\tHa elegido la dificultad:  "; c.verde(); cout << "| Facil |"; c.defect();
            c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.cafe();
            cout << "\n\t\t\t\t\t\tInstruccuiones:"; c.amarillo(); cout << "\n\t\t\t\t-Tienes que adivinar el numero del 1 al 50\n\t\t\t\t-Cada que respondas incorrecto recibiras una pista\n\t\t\t\t-Tienes solo 5 intentos disponibles\n\t\t\t\t\t\t"; c.cafe(); cout << "Suerte!\n";
            numRandom = rand() % 50 + 1; intentos = 5; break;
        case 2:
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.cafe();
            cout << "\n\t\t\t\tHa elegido la dificultad:  "; c.amarillo(); cout << "| Normal |"; c.defect();
            c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.cafe();
            cout << "\n\t\t\t\t\t\tInstruccuiones:"; c.amarillo(); cout << "\n\t\t\t\t-Tienes que adivinar el numero del 1 al 100\n\t\t\t\t-Cada que respondas incorrecto recibiras una pista\n\t\t\t\t-Tienes solo 7 intentos disponibles\n\t\t\t\t\t\t"; c.cafe(); cout << "   Suerte!\n";
            numRandom = rand() % 100 + 1; intentos = 7; break;
        case 3:
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.cafe();
            cout << "\n\t\t\t\tHa elegido la dificultad:  "; c.azul(); cout << "| Dificil |"; c.defect();
            c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.cafe();
            cout << "\n\t\t\t\t\t\tInstruccuiones:"; c.amarillo(); cout << "\n\t\t\t\t-Tienes que adivinar el numero del 1 al 100\n\t\t\t\t-Cada que respondas incorrecto recibiras una pista\n\t\t\t\t-Tienes solo 5 intentos disponibles\n\t\t\t\t\t\t"; c.cafe(); cout << "   Suerte!\n";
            numRandom = rand() % 100 + 1; intentos = 5; break;
        case 4:
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.cafe();
            cout << "\n\t\t\t\tHa elegido la dificultad:  "; c.cyan(); cout << "| Extremo |"; c.defect();
            c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.cafe();
            cout << "\n\t\t\t\t\t\tInstruccuiones:"; c.amarillo(); cout << "\n\t\t\t\t-Tienes que adivinar el numero del 1 al 50\n\t\t\t\t-Solo tendras una pista al tercer intento\n\t\t\t\t-Tienes solo 5 intentos disponibles\n\t\t\t\t\t\t"; c.cafe(); cout << "   Suerte!\n";
            numRandom = rand() % 50 + 1; intentos = 5; break;
        case 5:
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.cafe();
            cout << "\n\t\t\t\tHa elegido la dificultad:  "; c.rojo(); cout << "| Modo Dios |"; c.defect();
            c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.cafe();
            cout << "\n\t\t\t\t\t\tInstruccuiones:"; c.amarillo(); cout << "\n\t\t\t\t-Tienes que adivinar el numero del 1 al 10\n\t\t\t\t-Tienes solo un intento disponible\n\t\t\t\t-Si adivinas el numero obtienes 200 puntos, si no. Los pierdes\n\t\t\t\t\t\t"; c.cafe(); cout << "   Suerte!\n";
            numRandom = rand() % 10 + 1; intentos = 1; break;
        case 6: return;
        default: cout << "\n\n\t\t\t\tOpcion incorrecta, vuelve a intentarlo."; _getch(); n.jugar(); return;
            c.defect();
        }
        c.magenta(); cout << "\t\t\t\t---------------------------------------------------";
        c.rojo();
        cout << "\n\n\t\t\t\t"; system("PAUSE");
        c.defect();
        j.setPartidas(j.getPartidas() + 1);

        //El while para cuando la dificultad es menor o igual de Dificil
        if (op < 4)
        {
            while (intentos > 0) {
                system("CLS");
                c.cyan();
                cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.defect();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                c.rojo();
                cout << "\n\t\t\t\t\t\t*************************" << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                c.rojo();
                cout << "\t\t\t\t\t\t*************************" << endl;
                c.magenta(); 
                cout << "\n\t\t\t\t--------------------------------------------------"; c.defect();
                c.azul();
                if (adivina == 0)
                {
                    cout << "\n\t\t\t\tIntentos disponibles: "; c.amarillo(); cout << intentos;

                }
                else
                {
                    cout << "\n\t\t\t\tIntentos disponibles: "; c.amarillo(); cout << intentos;
                    if (adivina > numRandom)
                    {
                        c.verde(); cout << "\t\t<Num. anterior: "; c.amarillo(); cout << adivina;
                    }
                    else
                    {
                        c.rojo(); cout << "\t\t>Num. anterior: "; c.amarillo(); cout << adivina;
                    }
                }
                c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.defect();
                c.cyan();
                cout << "\n\n\t\t\t\t\t     !Intenta adivinar el numero!\n";
                c.amarillo();
                cout << "\n\t\t\t\tIngresa tu numero: "; c.defect(); cin >> adivina;
                c.magenta(); cout << "\t\t\t\t---------------------------------------------------"; c.defect();
                if (adivina == numRandom)
                {
                    c.verde();
                    cout << "\n\n\t\t\t\t\t\tFelicidades!";
                    c.amarillo();
                    cout << "\n\n\t\t\t\tAdivinaste el numero en "; c.verde(); cout << 5 - intentos + 1; c.amarillo(); cout << " intentos." << endl;
                    //Sumadores de puntos y partidas
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartAN(j.jugadores[0].getPartAN() + 1);
                    c.rojo();
                    cout << "\n\t\t\t\t"; system("PAUSE");
                    return;
                }
                else if (adivina < numRandom)
                {
                    c.rojo();
                    cout << "\n\t\t\t\t\tEl numero que buscas es mayor que "; c.defect();
                    cout << adivina;
                    c.rojo();
                    cout << ".";
                    c.cyan();
                    cout << "\n\n\t\t\t\t\t\tPierdes un intento:(" << endl;
                    c.defect();
                }
                else {
                    c.verde();
                    cout << "\n\t\t\t\t\tEl numero que buscas es menor que "; c.defect(); cout << adivina; c.verde(); cout << ".";
                    c.cyan();
                    cout << "\n\n\t\t\t\t\t\tPierdes un intento:(" << endl;
                    c.defect();
                }
                c.rojo();
                cout << "\n\t\t\t\t"; system("PAUSE");


                intentos--;
            }
        }
        else
        {
            //El while para cuando la dificultad es igual a Extremo
            if (op == 4)
            {
                while (intentos > 0)
                {
                    system("CLS");
                    c.cyan();
                    cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                    c.defect();
                    cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                    cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                    cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                    cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                    cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                    cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                    c.cyan();
                    cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.rojo();
                    cout << "\n\t\t\t\t\t\t*************************" << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                    c.rojo();
                    cout << "\t\t\t\t\t\t*************************" << endl;
                    c.magenta(); 
                    cout << "\n\t\t\t\t--------------------------------------------------"; c.defect();
                    c.azul();
                    
                        cout << "\n\t\t\t\tIntentos disponibles: "; c.amarillo(); cout << intentos;

                                        
                    c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.defect();
                    c.cyan();
                    cout << "\n\n\t\t\t\t\t     !Intenta adivinar el numero!\n";
                    c.amarillo();
                    cout << "\n\t\t\t\tIngresa tu numero: "; c.defect(); cin >> adivina;
                    if (adivina == numRandom)
                    {
                        cout << "\n\t\t\t\tFelicidades! Adivinaste el numero en " << 5 - intentos + 1 << " intentos." << endl;
                        //Sumadores de puntos
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 20);
                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                        j.jugadores[0].setPartAN(j.jugadores[0].getPartAN() + 1);
                        c.rojo();
                        cout << "\t\t\t\t"; system("PAUSE");
                        return;
                    }
                    if (intentos == 3)
                    {

                        if (adivina < numRandom)
                        {
                            c.rojo();
                            cout << "\n\t\t\t\t\tEl numero que buscas es mayor que ";  c.defect(); cout << adivina; c.rojo(); cout << ".";
                            c.cyan();
                            cout << "\n\n\t\t\t\t\t\tPierdes un intento:(" << endl;
                            c.defect();
                            c.rojo();
                            cout << "\n\t\t\t\t"; system("PAUSE");
                        }
                        else
                        {
                            c.verde();
                            cout << "\n\t\t\t\t\tEl numero que buscas es menor que "; c.defect(); cout << adivina; c.verde(); cout << ".";
                            c.cyan();
                            cout << "\n\n\t\t\t\t\t\tPierdes un intento:(\n" << endl;
                            c.amarillo();
                            cout << "\n\t\t\t\t"; system("PAUSE");
                            c.defect();
                        }
                    }

                    if (intentos > 0)
                    {
                        c.rojo();
                        cout << "\t\t\t\tTe quedan "; c.defect(); cout << intentos - 1; c.rojo(); cout << " intentos." << endl;
                        c.defect();
                    }
                    else
                    {
                        c.verde();
                        cout << "\t\t\t\tTe quedan "; c.defect(); cout << intentos - 1; c.verde(); cout << " intentos." << endl;
                        c.defect();
                    }
                    intentos--;
                }
            }
            //El while para cuando la dificultad es igual a Modo Dios
            else
            {
                system("CLS");
                c.cyan();
                cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.defect();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                c.rojo();
                cout << "\n\t\t\t\t\t\t*************************" << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                c.rojo();
                cout << "\t\t\t\t\t\t*************************" << endl;
                c.magenta(); 
                cout << "\n\t\t\t\t--------------------------------------------------"; c.defect();
                c.azul();
                if (adivina == 0)
                {
                    cout << "\n\t\t\t\tIntentos disponibles: "; c.amarillo(); cout << intentos;

                }
                else
                {
                    cout << "\n\t\t\t\tIntentos disponibles: "; c.amarillo(); cout << intentos;
                    if (adivina > numRandom)
                    {
                        c.verde(); cout << "\t\t<Num. anterior: "; c.amarillo(); cout << adivina;
                    }
                    else
                    {
                        c.rojo(); cout << "\t\t>Num. anterior: "; c.amarillo(); cout << adivina;
                    }
                }
                c.magenta(); cout << "\n\t\t\t\t---------------------------------------------------"; c.defect();
                c.cyan();
                cout << "\n\n\t\t\t\t\t     !Intenta adivinar el numero!\n";
                c.amarillo();
                cout << "\n\t\t\t\tIngresa tu numero: "; c.defect(); cin >> adivina;
                if (adivina == numRandom)
                {
                    cout << "\n\t\t\t\tFelicidades! Adivinaste el numero al primer intento.\n\n\t\t\t\tAcabas de ganar 200 puntos!" << endl;
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 200);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartAN(j.jugadores[0].getPartAN() + 1);
                    cout << "\t\t\t\t"; system("PAUSE");
                    return;
                }
                else
                {
                    cout << "\n\t\t\t\tLo siento, has perdido:(\n\t\t\t\tEl numero era "; c.azul(); cout << numRandom;  c.defect(); cout << ".\n\t\t\t\tAcabas de perder 200 puntos:(\n" << endl; cout << "\t\t\t\t";  system("PAUSE");
                    
                    if (j.jugadores[0].getPuntaje() < 200)
                    {
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() - j.jugadores[0].getPuntaje());
                    }
                    else
                    {
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() - 200);
                    }
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartAN(0);
                    return;
                }
            }
        }
        c.magenta();
        cout << "\t\t\t\t-----------------------------D4--------------------"; c.rojo();
        cout << "\n\n\t\t\t\tHaz perdido! el numero era: "; c.azul(); cout << numRandom;  c.defect(); cout << ".\n" << endl; cout << "\t\t\t\t"; c.amarillo();  system("PAUSE");
        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
        j.jugadores[0].setPartAN(0);
    }
}n;

class PiePapTij : public IJuegos
{
public:
    string opcion;

    PiePapTij() {}

    void jugar()
    {
        int op;
        string opcionesPPT[3], opcionesLS[5], opcionesME[4], opcionesHR[5];

        do {
            string opcionCPU;
            srand(time(0));
            int numOpc1 = 3, numOpc2 = 5, numOpc4 = 4, numOpc5 = 5;
            int numAux1, numAux2, numAux4, numAux5;

            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.azul();
            cout << "\n\n\t\t\t\t\t\tSelecciona un modo de juego\n"; c.defect();
            cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.amarillo();
            cout << "\t\t\t\t\t\t1.-Clasico\n"
                << "\t\t\t\t\t\t2.-Lagarto Spock\n"
                << "\t\t\t\t\t\t3.-Regresar\n";
            c.defect();
            cout << "\t\t\t\t\t\tx=x=x=x=E6x=x=x=x=x=x=x=x=x\n";
            c.cafe();
            cout << "\t\t\t\t\t\t    Opcion: "; c.defect(); cin >> op;

            switch (op)
            {
            case 1:
                opcionesPPT[0] = "Piedra";
                opcionesPPT[1] = "Tijeras";
                opcionesPPT[2] = "Papel";
                system("CLS");
                numAux1 = rand() % numOpc1;
                opcionCPU = opcionesPPT[numAux1];
                system("CLS");
                c.cyan();
                cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.defect();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                c.rojo();
                cout << "\n\t\t\t\t\t\t*************************" << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                c.rojo();
                cout << "\t\t\t\t\t\t*************************" << endl;
                c.defect();
                cout << "\n\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.azul();
                cout << "\t\t\t\t\t\tEn este modo las reglas son simples:\n";
                c.defect();
                cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.rojo();
                cout << "\t\t\t\t\t\tPiedra >> Tijeras >> Papel >> Piedra\n";
                c.defect();
                cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.cyan();
                cout << "\t\t\t\t\t\tSelecciona tu arma, soldado:\n\t\t\t\t\t\t"; c.cafe(); cout << "(debes escribir la opcion)\n";
                c.defect();
                cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.amarillo();
                cout << "\t\t\t\t\t\t\tx=Piedra=x\n"
                    << "\t\t\t\t\t\t\tx=Papel=x\n"
                    << "\t\t\t\t\t\t\tx=Tijeras=x\n";
                c.defect();
                cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.cafe();
                cout << "\t\t\t\t\t\t        Elijes: ";
                c.defect();
                cin >> opcion;
                cout << "\t\t\t\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";

                if (opcion != "Piedra" && opcion != "Papel" && opcion != "Tijeras")
                {
                    cout << "\t\t\t\t\t\tIngresaste una opcion invalida, reintenta. "; system("PAUSE");
                    p.jugar();
                    return;
                }
                p.victoriaPPT(opcionCPU); break;

            case 2:
                opcionesLS[0] = "Piedra";
                opcionesLS[1] = "Spock";
                opcionesLS[2] = "Tijeras";
                opcionesLS[3] = "Lagarto";
                opcionesLS[4] = "Papel";
                numAux2 = rand() % numOpc2;
                opcionCPU = opcionesLS[numAux2];
                system("CLS");
                c.cyan();
                cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.defect();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                c.rojo();
                cout << "\n\t\t\t\t\t\t*************************" << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                c.rojo();
                cout << "\t\t\t\t\t\t*************************" << endl;
                c.azul();
                cout << "\n\n\t\t\t\tEn esta versión, las opciones adicionales son lagarto y Spock.\n\t\t\t\tLas reglas son las siguientes:\n\t\t\t\tEl lagarto es decapitado por las Tijerass, pero envenena al papel y este envenena a Spock.\n"
                    << "\t\t\t\tSpock vaporiza la piedra y rompe las Tijerass.";
                c.azul(); cout << "\n\t\t\t\tLas reglas quedan asi : \n"; c.defect();
                c.rojo();
                cout << "\t\t\t\tLagarto >> Papel >> Spock >> Piedra >> Tijeras >> Lagarto\n";
                c.defect();
                cout << "\n\t\t\t\tSelecciona tu arma, soldado:\n";
                c.cyan();
                cout << "\t\t\t\t-Piedra\n"
                    << "\t\t\t\t-Papel\n"
                    << "\t\t\t\t-Tijeras\n"
                    << "\t\t\t\t-Lagarto\n"
                    << "\t\t\t\t-Spock\n";
                c.defect();
                cout << "\t\t\t\tElijes: ";
                cin >> opcion;
                cout << "\t\t\t\t------------------------------\n";

                if (opcion != "Piedra" && opcion != "Papel" && opcion != "Tijeras" && opcion != "Lagarto" && opcion != "Spock")
                {
                    cout << "\t\t\t\tHaz ingresado una opcion no valida, vuelve a intentarlo. "; system("PAUSE");
                    p.jugar();
                    return;
                }
                p.victoriaLS(opcionCPU); 
                
                break;           
                
            case 3: return;

            default: 
                c.rojo();
                cout << "\n\t\t\t\tHaz ingresado una opcion incorrecta, intenta de nuevo\n\t\t\t\t"; _getch(); IJugar(&p); return;
            }

            cout << "\n\t\t\t\t\t\t"; system("PAUSE");
        } while (op < 3);
        cout << endl;
    }    

    void victoriaPPT(string& opcionCPU)
    {
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.defect();
        cout << "\t\t";
        c.cargaLenta();
        c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.amarillo();
        cout << "\t\t\t\t\t\tSoldado elegiste "; c.cyan(); cout << opcion;
        c.rosa();
        cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.verde(); cout << "\t\t\t\t\t\t\t BUENA SUERTE!";
        cout << endl;
        Sleep(2000);
        c.rosa(); cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.amarillo(); cout << "\t\t\t\t\t\t      Tu oponente eligio:\n"; c.amarillo(); cout << "\t"; c.cargaPalabras(opcionCPU);  c.defect();
        c.rosa(); cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.defect();
        if (opcionCPU == opcion)
        {
            c.amarillo();
            cout << "\t\t\t\t\t\tAmbos eligieron "; c.cyan(); cout << opcionCPU; c.rojo(); cout << "\n\n\t\t\t\t\t\t\tNO HAY GANADOR"; c.rojo(); c.verde(); cout << "\n\t\t\t\t\t\t\tIntente de Nuevo."; c.defect();
            c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);

        }
        else
        {
            if (opcionCPU == "Tijeras" && opcion == "Papel")
            {
                c.rojo();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X AUCH! X=X=X=X=X=X=X\n";
                c.rosa();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                c.defect(); cout << "\t\t\t\t\t\tLas "; c.rojo(); cout << opcionCPU; c.defect(); cout << " cortan el "; c.verde(); cout << opcion; c.defect();
                c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
            }
            else
            {
                if (opcionCPU == "Papel" && opcion == "Piedra")
                {
                    c.rojo();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X Oops! X=X=X=X=X=X=X\n";
                    c.rosa();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                    c.defect(); cout << "\t\t\t\t\t\tEl "; c.rojo(); cout << opcionCPU; c.defect(); cout << " cubre a la "; c.verde(); cout << opcion; c.defect();
                    c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);

                }
                else
                {
                    if (opcionCPU == "Piedra" && opcion == "Tijeras")
                    {
                        c.rojo();
                        cout << "\t\t\t\t\t\tX=X=X=X=X Perdiste! X=X=X=X=X=X\n";
                        c.rosa();
                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                        c.defect(); 
                        cout << "\t\t\t\t\t\t\t\tLa "; c.rojo(); cout << opcionCPU; c.defect(); cout << " rompe a las "; c.verde(); cout << opcion; c.defect();
                        c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);

                    }
                }
            }

            if (opcionCPU == "Papel" && opcion == "Tijeras")
            {
                c.cyan();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X BUENA! X=X=X=X=X=X=\n";
                c.rosa();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                c.defect(); cout << "\t\t\t\tLas "; c.verde(); cout << opcion; c.defect(); cout << " cortan el "; c.rojo(); cout << opcionCPU;
                c.rosa();
                cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                c.cyan();
                cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                c.rosa();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
            }
            else
            {
                if (opcionCPU == "Piedra" && opcion == "Papel")
                {
                    c.cyan();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X GANASTE! X=X=X=X=X=\n";
                    c.rosa();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                    c.defect(); cout << "\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " cubre a la "; c.rojo(); cout << opcionCPU;
                    c.rosa();
                    cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                    c.cyan();
                    cout << "\n\t\t\t\t\t\tX=X=X=X=X Eres un Pro! X=X=X=X=\n";
                    c.rosa();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                }
                else
                {
                    if (opcionCPU == "Tijeras" && opcion == "Piedra")
                    {
                        c.cyan();
                        cout << "\t\t\t\t\t\tX=X=X=X=X=X CAMPEON! X=X=X=X=X=\n";
                        c.rosa();
                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                        c.defect(); cout << "\t\t\t\tLa "; c.verde(); cout << opcion; c.defect(); cout << " rompe a las "; c.rojo(); cout << opcionCPU;
                        c.rosa();
                        cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                        c.cyan();
                        cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                        c.rosa();
                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                        j.jugadores[0].setPiedra(j.jugadores[0].getPiedra() + 1);
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                    }
                }
            }
        }
    }        

    void victoriaLS(string& opcionCPU)
    {
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.defect();
        cout << "\t\t";
        c.cargaLenta();
        c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.amarillo();
        cout << "\t\t\t\t\t\tSoldado elegiste "; c.cyan(); cout << opcion;
        c.rosa();
        cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.verde(); cout << "\t\t\t\t\t\t\t BUENA SUERTE!";
        cout << endl;
        Sleep(2000);
        c.rosa(); cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.amarillo(); cout << "\t\t\t\t\t\t      Tu oponente eligio:\n"; c.amarillo(); cout << "\t"; c.cargaPalabras(opcionCPU);  c.defect();
        c.rosa(); cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
        c.defect();
        if (opcionCPU == opcion)
        {
            c.amarillo();
            cout << "\t\t\t\t\t\tAmbos eligieron "; c.cyan(); cout << opcionCPU; c.rojo(); cout << "\n\n\t\t\t\t\t\t\tNO HAY GANADOR"; c.rojo(); c.verde(); cout << "\n\t\t\t\t\t\t\tIntente de Nuevo."; c.defect();
            c.rosa(); cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
        }
        else
        {
            if (opcionCPU == "Tijeras" && opcion == "Lagarto")
            {
                c.rojo();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X AUCH! X=X=X=X=X=X=X\n";
                c.rosa();
                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                c.defect(); cout << "\t\t\t\t\t\tLas "; c.rojo(); cout << opcionCPU; c.defect(); cout << " cortan el cuello del\n "; c.verde(); cout << opcion; c.defect();
                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);

            }
            else
            {
                if (opcionCPU == "Papel" && opcion == "Spock")
                {
                    c.rojo();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X Oops! X=X=X=X=X=X=X\n";
                    c.rosa();
                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                    c.defect(); cout << "\t\t\t\t\t\tEl "; c.rojo(); cout << opcionCPU; c.defect(); cout << " enveneno a "; c.verde(); cout << opcion; c.defect();
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                }
                else
                {
                    if (opcionCPU == "Piedra" && opcion == "Tijeras")
                    {
                        c.rojo();
                        cout << "\t\t\t\t\t\tX=X=X=X=X=X Perdiste! X=X=X=X=X\n";
                        c.rosa();
                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                        c.defect(); cout << "\t\t\t\t\t\tLa "; c.rojo(); cout << opcionCPU; c.defect(); cout << " rompe a las "; c.verde(); cout << opcion; c.defect();
                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                    }
                    else
                    {
                        if (opcionCPU == "Lagarto" && opcion == "Papel")
                        {
                            c.rojo();
                            cout << "\t\t\t\t\t\tX=X=X=X=X=X Animo! X=X=X=X=X=X=\n";
                            c.rosa();
                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                            c.defect(); cout << "\t\t\t\t\t\tEl "; c.rojo(); cout << opcionCPU; c.defect(); cout << " mastica el "; c.verde(); cout << opcion; c.defect();
                            j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                            j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                        }
                        else
                        {
                            if (opcionCPU == "Spock" && opcion == "Piedra")
                            {
                                c.rojo();
                                cout << "\t\t\t\t\t\tX=X=X=X=X No Te Rindas! X=X=X=X\n";
                                c.rosa();
                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                                c.defect(); cout << "\t\t\t\t\t\tEl ";  c.rojo(); cout << opcionCPU; c.defect(); cout << " arroja a la "; c.verde(); cout << opcion; c.defect();
                                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                            }
                            else {
                                if (opcionCPU == "Papel" && opcion == "Tijeras")
                                {
                                    c.rojo();
                                    cout << "\t\t\t\t\t\tX=X=X=X Sigue Intentando! =X=X=\n";
                                    c.rosa();
                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                                    c.defect(); cout << "\t\t\t\t\t\tEl ";  c.rojo(); cout << opcionCPU; c.defect(); cout << " es cortado por las "; c.verde(); cout << opcion; c.defect();
                                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                }
                                else {
                                    if (opcion == "Spock" && opcionCPU == "Lagarto")
                                    {
                                        c.rojo();
                                        cout << "\t\t\t\t\t\tX=X=X Volveras Mas Fuerte! =X=X\n";
                                        c.rosa();
                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                        c.defect(); cout << "\t\t\t\t\t\tEl "; c.rojo(); cout << opcion; c.defect(); cout << " fue envenenado por "; c.verde(); cout << opcionCPU; c.defect();
                                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                    }
                                    else {
                                        if (opcion == "Lagarto" && opcionCPU == "Piedra")
                                        {
                                            c.rojo();
                                            cout << "\t\t\t\t\t\tX=X= Date Otra Oportunidad! X=X\n";
                                            c.rosa();
                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                            c.defect(); cout << "\t\t\t\t\t\tEl "; c.rojo(); cout << opcion; c.defect(); cout << " fue aplastado por la\n "; c.verde(); cout << opcionCPU; c.defect();
                                            j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                                            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                            j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                        }
                                        else {
                                            if (opcion == "Piedra" && opcionCPU == "Papel")
                                            {
                                                c.rojo();
                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X Animo! X=X=X=X=X=X=\n";
                                                c.rosa();
                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                                                c.defect(); cout << "\t\t\t\t\t\tLa "; c.rojo(); cout << opcion; c.defect(); cout << " fue envuelta por el "; c.verde(); cout << opcionCPU; c.defect();
                                                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                                                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                            }
                                            else {
                                                if (opcion == "Papel" && opcionCPU == "Tijeras")
                                                {
                                                    c.rojo();
                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X Oops! X=X=X=X=X=X=X\n";
                                                    c.rosa();
                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";
                                                    c.defect(); cout << "\t\t\t\t\t\tEl "; c.rojo(); cout << opcion; c.defect(); cout << " fue cortado por las\n "; c.verde(); cout << opcionCPU; c.defect();
                                                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 3);
                                                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                }
                                                else {
                                                    if (opcion == "Lagarto" && opcionCPU == "Papel")
                                                    {
                                                        c.cyan();
                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X BUENA! X=X=X=X=X=X=\n";
                                                        c.rosa();
                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                        c.defect(); cout << "\t\t\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " se come al "; c.rojo(); cout << opcionCPU; c.defect();
                                                        c.rosa();
                                                        cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                        c.cyan();
                                                        cout << "\n\t\t\t\t\t\tX=X=X= Eres un crack! X=X=X=X=X\n";
                                                        c.rosa();
                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                    }
                                                    else
                                                    {
                                                        if (opcion == "Lagarto" && opcionCPU == "Spock")
                                                        {
                                                            c.cyan();
                                                            cout << "\t\t\t\t\t\tX=X=X=X=X VICTORIA! X=X=X=X=X=X\n";
                                                            c.rosa();
                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                            c.defect(); cout << "\t\t\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " Envenena a "; c.rojo(); cout << opcionCPU; c.defect();
                                                            c.rosa();
                                                            cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                            c.cyan();
                                                            cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                            c.rosa();
                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                            j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                            j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                        }
                                                        else
                                                        {
                                                            if (opcion == "Papel" && opcionCPU == "Piedra")
                                                            {
                                                                c.cyan();
                                                                cout << "\t\t\t\t\t\tX=X=X=X=X= GANASTE! X=X=X=X=X=X\n";
                                                                c.rosa();
                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                c.defect(); cout << "\t\t\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " cubre a la "; c.rojo(); cout << opcionCPU; c.defect();
                                                                c.rosa();
                                                                cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                c.cyan();
                                                                cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                c.rosa();
                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                j.jugadores[0].setPiedra(j.jugadores[0].getPiedra() + 1);

                                                            }
                                                            else
                                                            {
                                                                if (opcion == "Papel" && opcionCPU == "Spock")
                                                                {
                                                                    c.cyan();
                                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X CAMPEON! X=X=X=X=X=\n";
                                                                    c.rosa();
                                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                    c.defect(); cout << "\t\t\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " Desaprueba a "; c.rojo(); cout << opcionCPU; c.defect();
                                                                    c.rosa();
                                                                    cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                    c.cyan();
                                                                    cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                    c.rosa();
                                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                }
                                                                else
                                                                {
                                                                    if (opcion == "Spock" && opcionCPU == "Tijeras")
                                                                    {
                                                                        c.cyan();
                                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X GENIAL! X=X=X=X=X=X\n";
                                                                        c.rosa();
                                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                        c.defect(); cout << "\t\t\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " rompe a las "; c.rojo(); cout << opcionCPU; c.defect();
                                                                        c.rosa();
                                                                        cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                        c.cyan();
                                                                        cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                        c.rosa();
                                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (opcion == "Spock" && opcionCPU == "Piedra")
                                                                        {
                                                                            c.cyan();
                                                                            cout << "\t\t\t\t\t\tX=X=X=X=X= GANADOR! X=X=X=X=X=X\n";
                                                                            c.rosa();
                                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                            c.defect(); cout << "\t\t\t\t\t\tEl "; c.verde(); cout << opcion; c.defect(); cout << " Evaporizo a la "; c.rojo(); cout << opcionCPU; c.defect();
                                                                            c.rosa();
                                                                            cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                            c.cyan();
                                                                            cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                            c.rosa();
                                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                            j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                            j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (opcion == "Piedra" && opcionCPU == "Lagarto")
                                                                            {
                                                                                c.cyan();
                                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X EXITO! X=X=X=X=X=X=\n";
                                                                                c.rosa();
                                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                                c.defect(); cout << "\t\t\t\t\t\tLa "; c.verde(); cout << opcion; c.defect(); cout << " aplasta al "; c.rojo(); cout << opcionCPU; c.defect();
                                                                                c.rosa();
                                                                                cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                                c.cyan();
                                                                                cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                                c.rosa();
                                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (opcion == "Piedra" && opcionCPU == "Tijeras")
                                                                                {
                                                                                    c.cyan();
                                                                                    cout << "\t\t\t\t\t\tX=X=X=X IMPRESIONANTE! X=X=X=X=\n";
                                                                                    c.rosa();
                                                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                                    c.defect(); cout << "\t\t\t\t\t\tLa "; c.verde(); cout << opcion; c.defect(); cout << " aplasta a las "; c.rojo(); cout << opcionCPU; c.defect();
                                                                                    c.rosa();
                                                                                    cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                                    c.cyan();
                                                                                    cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                                    c.rosa();
                                                                                    cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                                    j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (opcion == "Tijeras" && opcionCPU == "Papel")
                                                                                    {
                                                                                        c.cyan();
                                                                                        cout << "\t\t\t\t\t\tX=X=X=X=X BRILLANTE! X=X=X=X=X=\n";
                                                                                        c.rosa();
                                                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                                        c.defect(); cout << "\t\t\t\t\t\tLas "; c.verde(); cout << opcion; c.defect(); cout << " cortan al "; c.rojo(); cout << opcionCPU; c.defect();
                                                                                        c.rosa();
                                                                                        cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                                        c.cyan();
                                                                                        cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                                        c.rosa();
                                                                                        cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                                        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                                        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                                        j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (opcion == "Tijeras" && opcionCPU == "Lagarto")
                                                                                        {
                                                                                            c.cyan();
                                                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X GANASTE! X=X=X=X=X=\n";
                                                                                            c.rosa();
                                                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                                            c.defect(); cout << "\t\t\t\t\t\tLas "; c.verde(); cout << opcion; c.defect(); cout << " Decapitan al "; c.rojo(); cout << opcionCPU; c.defect();
                                                                                            c.rosa();
                                                                                            cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                                            c.cyan();
                                                                                            cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                                            c.rosa();
                                                                                            cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                                            j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                                            j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                                            j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                                        }
                                                                                        else {
                                                                                            if (opcion == "Tijeras" && opcionCPU == "Spock")
                                                                                            {
                                                                                                c.cyan();
                                                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X CAMPEON! X=X=X=X=X=\n";
                                                                                                c.rosa();
                                                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n";

                                                                                                c.defect(); cout << "\t\t\t\t\t\tLas "; c.verde(); cout << opcion; c.defect(); cout << " cortan el cuello de \n"; cout << "\t\t\t\t"; c.rojo(); cout << opcionCPU; c.defect();
                                                                                                c.rosa();
                                                                                                cout << "\n\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X";
                                                                                                c.cyan();
                                                                                                cout << "\n\t\t\t\t\t\tX=X=X=X Eres un crack! X=X=X=X=\n";
                                                                                                c.rosa();
                                                                                                cout << "\t\t\t\t\t\tX=X=X=X=X=X=X=X=X=X=X=X=X=X=X=X\n"; c.defect();
                                                                                                j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 10);
                                                                                                j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                                                                                                j.jugadores[0].setPartPPT(j.jugadores[0].getPartPPT() + 1);
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}p;

class Ahorcado : public IJuegos
{
public:
    string palSeleccion;
    string palOculta;
    int intentos;
    vector <string> palabras;

    Ahorcado()
    {
        palabras = { "Perro", "Vaca", "Rinoceronte", "Elefante", "Caballo", "Mantis", "Ornitorrinco", "Koala", "Gato", "Cienpies",
            "León", "Tigre", "Jirafa", "Cebra", "Mono", "Lobo", "Pájaro", "Delfín", "Ballena", "Pingüino", "Elefante",
            "Gorila", "Hipopótamo", "Rana", "Gallina", "Cocodrilo", "Hormiga", "Tortuga", "Camello", "Cangrejo",
            "Mariposa", "Búho", "Escorpión", "Pulpo", "Tiburón", "Langosta", "Araña", "Pez", "Ciervo", "Panda",
            "Cebú", "Jaguar", "Ratón", "Nutria", "Kangaroo", "Guepardo", "Murciélago", "Chimpancé", "Zorro" };
        intentos = 5;
        srand(time(0));
    }

    void jugar()
    {
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.azul();
        cout << "\n\n\t\t\t\t\tBienvenido al juego del Ahorcado!\n";
        c.rosa(); 
        cout << "\n\t\t\t\t***********************************************\n";
        c.amarillo();
        cout << "\t\t\t\t-Tienes que adivinar la palabra oculta\n\t\t\t\t-Ingresa cada letra hasta descubrir la palabra\n\t\t\t\t-Tienes 5 intentos para adivinar la palabra\n\t\t\t\t\t\tSuerte!";
        c.rosa();
        cout << "\n\t\t\t\t***********************************************\n";

        c.rojo();
        cout << "\n\n\t\t\t\t"; system("PAUSE");

        
        int selRand = rand() % 10;
        palSeleccion = palabras[selRand];
        palOculta = string(palSeleccion.length(), '_');
        char letra = ' ';
        char letraMay;
        letraMay = palSeleccion[0];
        letraMay = tolower(letraMay);
        while (intentos > 0 && palSeleccion != palOculta)
        {
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.azul();
            cout << "\n\n\t\t\t    Palabra Secreta: ";
            c.defect();
            for (int i = 0; i < palOculta.length(); i++)
            {
                cout << "  " << palOculta[i];
            }
            c.rojo(); cout << "\t\t\tIntentos: "; c.defect(); cout << intentos;
            c.amarillo();
            cout << "\n\n\n\t\t\t\tIngrese una letra: ";
            c.defect();
            cin >> letra;
            cout << endl;
            c.cargaAcciones();

            if (verificaLetra(letra, letraMay))
            {
                c.cyan();
                cout << "\n\n\t\t\t\t\t\tLetra encontrada!";
                c.rosa();
                if (verificaVitoria())
                {
                    c.verde();
                    cout << "\n\t\t\t\tFelicidades, adivinaste la palabra correctamente!";
                    c.amarillo();
                    cout << "\n\n\t\t\t\tLa palabra era: "; c.cyan(); cout << palSeleccion;
                    c.rosa();
                    cout << "\n\n\t\t\t\t"; system("PAUSE");
                    j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 12);
                    j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
                    j.jugadores[0].setPartAHO(j.jugadores[0].getPartAHO() + 1);
                    return;

                }
                cout << "\n\n\t\t\t\t"; system("PAUSE");
            }
            else
            {
                c.rojo();
                cout << "\n\n\t\t\t\t\t\tLetra NO encontrada.";
                intentos--;
                c.rosa();
                cout << "\n\n\t\t\t\t"; system("PAUSE");
            }

            
        }
        c.rojo();
        cout << "\n\t\t\t\t\t\t!Has perdido!";
        c.amarillo();
        cout << "\n\n\t\t\t\tLa palabra correcta era: "; c.cyan(); cout << palSeleccion;
        j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 5);
        j.jugadores[0].setPartidas(j.jugadores[0].getPartidas() + 1);
        j.jugadores[0].setPartAHO(j.jugadores[0].getPartAHO() + 1);
        c.rosa();
        cout << "\n\n\t\t\t\t"; system("PAUSE");

    }

    bool verificaLetra(char letra, char letraMay)
    {
        bool letraEncontrada = false;
        char letraMin;
        for (int i = 0; i < palSeleccion.length(); i++)
        {
            letraMin = tolower(palSeleccion[i]);
            if (letra == palSeleccion[i] || letra == letraMin)
            {
                palOculta[i] = palSeleccion[i];
                letraEncontrada = true;
            }
        }
        return letraEncontrada;
    }

    bool verificaVitoria()
    {
        if (palOculta == palSeleccion)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}ahorcado;

class BlackJack : public IJuegos, public Jugador
{
public:
    vector <string> baraja;
    vector<string> cartas;
    vector<string> cartasCPU;

    BlackJack()
    {
        baraja = { "As de Picas","02 de Picas","03 de Picas", "04 de Picas", "05 de Picas", "06 de Picas", "07 de Picas", "08 de Picas", "09 de Picas", "10 de Picas", "J de Picas", "Q de Picas", "K de Picas",
                   "As de Corazones","02 de Corazones","03 de Corazones","04 de Corazones","05 de Corazones","06 de Corazones","07 de Corazones","08 de Corazones","09 de Corazones","10 de Corazones","J de Corazones","Q de Corazones","K de Corazones",
                   "As de Diamantes","02 de Diamantes","03 de Diamantes","04 de Diamantes","05 de Diamantes","06 de Diamantes","07 de Diamantes","08 de Diamantes","09 de Diamantes","10 de Diamantes","J de Diamantes","Q de Diamantes","K de Diamantes",
                   "As de Treboles","02 de Treboles","03 de Treboles","04 de Treboles","05 de Treboles","06 de Treboles","07 de Treboles","08 de Treboles","09 de Treboles","10 de Treboles","J de Treboles","Q de Treboles","K de Treboles", };
    }

    void jugar()
    {
        int repar = 0;
        int valorM = 0;
        int valorMCPU = 0;
        int nRepar = 0;
        int op = 0;
        int cReCpu = 0;
        vector <int>Crepar;
        cartas.clear();
        cartasCPU.clear();
        srand(time(0));
        Crepar.push_back(0);
        do
        {
            cReCpu = 0;
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl << endl;
            c.cafe();

            if (cartas.empty())
            {
                nRepar = 2;
                repartir(repar, Crepar, nRepar);
            }
            if (op == 1)
            {
                cout << "\t\t\t\t\t\tVolviste a pedir!\n\t\t\t\tA continuacion se repartira otra carta a tu mazo.\n\n";
                nRepar = 1;
                repartir(repar, Crepar, nRepar);
            }
            else
            {
                cout << "\t\t\t\tA continuacion se repartiran tus primeras 2 cartas.\n";
            }
            Sleep(1000);
            if (cReCpu == 1)
            {
                c.rojo();
                cout << "\n\n\t\t\t\tTu contrincante pidio otra carta!\n\n";
            }
            if (cartasCPU.size() == 0)
            {
                int nReparCPU = 2;
                repartirCPU(repar, Crepar, nReparCPU);
            }
            c.amarillo();
            cout << "\t\t\t\tEstas son tus cartas:\n";
            c.azul();
            verBaraja();
            c.rojo();
            cout << "\n\t\t\t\tTu contrincante tiene " << cartasCPU.size() << " en su mano.\n";
            c.amarillo();
            cout << "\t\t\t\tEste es el valor de tu mano: ";
            c.verde();
            conteo(valorM);
            cout << valorM << ".";
            c.cyan();

            if (cartas.size() < 5)
            {
                cout << "\n\n\t\t\t\tQuieres otra carta?\n\t\t\t\t1.-Si\n\t\t\t\t2.-No\n\t\t\t\tOpcion: "; c.defect();
                cin >> op;
            }
            else
            {
                cout << "\n\n\t\t\t\tYa no puedes pedir mas cartas, sabras tu resultado a continuacion:\n"; Sleep(2000);
                op = 2;
            }

            if (op != 1 && op != 2)
            {
                cout << "\t\t\t\tOpcion incorrecta. Recibiras carta.\n";
            }

            conteoCPU(valorMCPU);
            if (valorMCPU < 17 && cartasCPU.size() < 5)
            {
                cReCpu = 0;
                int nReparCPU = 1;
                repartirCPU(repar, Crepar, nReparCPU);
                cReCpu++;
            }


        } while (op < 2);

        int ccpu = 0;
        while (valorMCPU < 12)
        {
            cReCpu = 0;
            int nReparCPU = 1;
            repartirCPU(repar, Crepar, nReparCPU);
            conteoCPU(valorMCPU);
            ccpu++;
        }
        if (ccpu > 0)
        {
            cout << "\t\t\t\tTu contrincante pidio " << ccpu << " cartas mas.\n";
        }

        victoria21(valorM, valorMCPU);
        j.setPartidas(j.getPartidas() + 1);
        cout << "\n\t\t\t\t"; system("PAUSE");
    }

    void repartir(int& repar, vector <int>& Crepar, int& nRepar)
    {
        int j;
        for (int i = 0; i < nRepar; i++)
        {
            repar = rand() % 52;
            j = 0;
            for (int k = 0; k < Crepar.size(); k++)
            {
                while (Crepar[j] == repar)
                {
                    repar = rand() % 52;
                }
                j++;
            }
            cartas.push_back(baraja[repar]);
            Crepar.push_back(repar);
        }
    }

    void repartirCPU(int& repar, vector<int>& Crepar, int& nReparCPU)
    {
        int j;
        for (int i = 0; i < nReparCPU; i++)
        {
            repar = rand() % 52;
            j = 0;
            for (int k = 0; k < Crepar.size(); k++)
            {
                while (Crepar[j] == repar)
                {
                    repar = rand() % 52;
                }
                j++;
            }
            cartasCPU.push_back(baraja[repar]);
            Crepar.push_back(repar);
        }
    }

    void conteo(int& valorM)
    {
        int aux = cartas.size();
        valorM = 0;
        for (int i = 0; i < aux; i++)
        {
            if (cartas[i] == "As de Picas" || cartas[i] == "As de Corazones" || cartas[i] == "As de Diamantes" || cartas[i] == "As de Treboles")
            {
                valorM += 1;
            }
            else
            {
                if (cartas[i] == "J de Picas" || cartas[i] == "J de Corazones" || cartas[i] == "J de Diamantes" || cartas[i] == "J de Treboles")
                {
                    valorM += 10;
                }
                else if (cartas[i] == "Q de Picas" || cartas[i] == "Q de Corazones" || cartas[i] == "Q de Diamantes" || cartas[i] == "Q de Treboles")
                {
                    valorM += 10;
                }
                else if (cartas[i] == "K de Picas" || cartas[i] == "K de Corazones" || cartas[i] == "K de Diamantes" || cartas[i] == "K de Treboles")
                {
                    valorM += 10;
                }
                else
                {
                    string sub = cartas[i].substr(0, 2);
                    int num = stoi(sub);
                    valorM += num;
                }
            }
        }
    }

    void conteoCPU(int& valorMCPU)
    {
        int aux = cartasCPU.size();
        valorMCPU = 0;
        for (int i = 0; i < aux; i++)
        {
            if (cartasCPU[i] == "As de Picas" || cartasCPU[i] == "As de Corazones" || cartasCPU[i] == "As de Diamantes" || cartasCPU[i] == "As de Treboles")
            {
                valorMCPU += 1;
            }
            else
            {
                if (cartasCPU[i] == "J de Picas" || cartasCPU[i] == "J de Corazones" || cartasCPU[i] == "J de Diamantes" || cartasCPU[i] == "J de Treboles")
                {
                    valorMCPU += 10;
                }
                else if (cartasCPU[i] == "Q de Picas" || cartasCPU[i] == "Q de Corazones" || cartasCPU[i] == "Q de Diamantes" || cartasCPU[i] == "Q de Treboles")
                {
                    valorMCPU += 10;
                }
                else if (cartasCPU[i] == "K de Picas" || cartasCPU[i] == "K de Corazones" || cartasCPU[i] == "K de Diamantes" || cartasCPU[i] == "K de Treboles")
                {
                    valorMCPU += 10;
                }
                else
                {
                    string sub = cartasCPU[i].substr(0, 2);
                    int num = stoi(sub);
                    valorMCPU += num;
                }
            }
        }
    }

    void verBaraja()
    {
        int aux = size(cartas);
        for (int i = 0; i < aux; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ".-" << cartas[i] << endl;
            Sleep(800);
        }
    }

    void verBarajaCPU()
    {
        int aux = cartasCPU.size();
        for (int i = 0; i < aux; i++)
        {
            cout << "\t\t\t\t" << i + 1 << ".-" << cartasCPU[i] << endl;
            Sleep(500);
        }
    }

    void victoria21(int& valorM, int& valorMCPU)
    {
        conteo(valorM);
        conteoCPU(valorMCPU);

        if (valorM < valorMCPU && valorMCPU <= 21)
        {
            c.magenta();
            cout << "\n\t\t\t\tPerdiste!";
            c.amarillo();
            cout << "\n\t\t\t\tObtuviste "; c.cyan(); cout << valorM; c.amarillo(); cout << " puntos.";
            cout << "\n\t\t\t\tTu cartas fueron:\n";
            c.verde();
            verBaraja();
            c.defect();
            cout << "\t\t\t\t--------------------------------------\n";
            c.amarillo();
            cout << "\t\t\t\tTu contrincante obtuvo "; c.cyan(); cout << valorMCPU; c.amarillo(); cout << " puntos.";
            cout << "\n\t\t\t\tSus cartas fueron:\n";
            c.rojo();
            verBarajaCPU();
            c.defect();
        }
        else
        {
            if (valorM > valorMCPU && valorM <= 21)
            {
                c.magenta();
                cout << "\n\t\t\t\tGanaste!";
                c.amarillo();
                cout << "\n\t\t\t\tObtuviste "; c.cyan(); cout << valorM; c.amarillo(); cout << " puntos.";
                cout << "\n\t\t\t\tTu cartas fueron:\n";
                c.verde();
                verBaraja();
                c.defect();
                cout << "\t\t\t\t--------------------------------------\n";
                c.amarillo();
                cout << "\t\t\t\tTu contrincante obtuvo "; c.cyan(); cout << valorMCPU; c.amarillo(); cout << " puntos.";
                cout << "\n\t\t\t\tSus cartas fueron:\n";
                c.rojo();
                verBarajaCPU();
                c.defect();
            }
            else
            {
                if (valorM > valorMCPU && valorM > 21)
                {
                    c.magenta();
                    cout << "\n\t\t\t\tPerdiste!";
                    c.amarillo();
                    cout << "\n\t\t\t\tObtuviste "; c.cyan(); cout << valorM; c.amarillo(); cout << " puntos.";
                    cout << "\n\t\t\t\tTu cartas fueron:\n";
                    c.verde();
                    verBaraja();
                    c.defect();
                    cout << "\t\t\t\t--------------------------------------\n";
                    c.amarillo();
                    cout << "\t\t\t\tTu contrincante obtuvo "; c.cyan(); cout << valorMCPU; c.amarillo(); cout << " puntos.";
                    cout << "\n\t\t\t\tSus cartas fueron:\n";
                    c.rojo();
                    verBarajaCPU();
                    c.defect();
                }
                else
                {
                    if (valorMCPU > 21 && valorM < 21)
                    {
                        c.magenta();
                        cout << "\n\t\t\t\tGanaste!";
                        c.amarillo();
                        cout << "\n\t\t\t\tObtuviste "; c.cyan(); cout << valorM; c.amarillo(); cout << " puntos.";
                        cout << "\n\t\t\t\tTu cartas fueron:\n";
                        c.verde();
                        verBaraja();
                        c.defect();
                        cout << "\t\t\t\t--------------------------------------\n";
                        c.amarillo();
                        cout << "\t\t\t\tTu contrincante obtuvo "; c.cyan(); cout << valorMCPU; c.amarillo(); cout << " puntos.";
                        cout << "\n\t\t\t\tSus cartas fueron:\n";
                        c.rojo();
                        verBarajaCPU();
                        c.defect();
                    }
                    else
                    {
                        if (valorM > 21)
                        {
                            c.magenta();
                            cout << "\n\t\t\t\tPerdiste!";
                            c.amarillo();
                            cout << "\n\t\t\t\tObtuviste "; c.cyan(); cout << valorM; c.amarillo(); cout << " puntos.";
                            cout << "\n\t\t\t\tTu cartas fueron:\n";
                            c.verde();
                            verBaraja();
                            c.defect();
                            cout << "\t\t\t\t--------------------------------------\n";
                            c.amarillo();
                            cout << "\t\t\t\tTu contrincante obtuvo "; c.cyan(); cout << valorMCPU; c.amarillo(); cout << " puntos.";
                            cout << "\n\t\t\t\tSus cartas fueron:\n";
                            c.rojo();
                            verBarajaCPU();
                            c.defect();
                        }
                        else
                        {
                            if (valorM < 21 && cartas.size() < 5 && valorM < valorMCPU)
                            {
                                c.magenta();
                                cout << "\n\t\t\t\tGanaste!";
                                c.amarillo();
                                cout << "\n\t\t\t\tObtuviste "; c.cyan(); cout << valorM; c.amarillo(); cout << " puntos.";
                                cout << "\n\t\t\t\tTu cartas fueron:\n";
                                c.verde();
                                verBaraja();
                                c.defect();
                                cout << "\t\t\t\t--------------------------------------\n";
                                c.amarillo();
                                cout << "\n\t\t\t\tTu contrincante obtuvo "; c.cyan(); cout << valorMCPU; c.amarillo(); cout << " puntos.";
                                cout << "\n\t\t\t\tSus cartas fueron:\n";
                                c.rojo();
                                verBarajaCPU();
                                c.defect();
                            }
                        }
                    }
                }
            }
        }

    }
}black;

class Piano : public IJuegos
{
public:
    char tecla;

    void jugar()
    {
        HMIDIOUT hMidiOut;

        if (midiOutOpen(&hMidiOut, MIDI_MAPPER, 0, 0, CALLBACK_NULL) != MMSYSERR_NOERROR)
        {
            cout << "\t\t\t\tError al abrir el dispositivo MIDI de salida. Intenta de nuevo" << endl;
            _getch();
            return;
        }
        tecla = ' ';
        while (true)
        {
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;
            c.defect();
            cout << "\n\n\t\t\t\t******************************************************\n";
            c.rojo();
            cout << "\t\t\t\tx=x Presiona las teclas disponibles para tocar el piano x=x";
            c.defect();
            cout << "\n\t\t\t\t******************************************************";
            c.azul();
            cout << "\n\t\t\t\tx=x Presiona ESPACIO para regresar al menu principal x=x\n";
            c.defect();
            cout << "\t\t\t\t******************************************************\n\n";
            if (tecla != ' ')
            {
                cout << "\t\t\t\t\tx=x Tecla presionada x=x\n\t\t\t\t\t\t"; c.cyan(); cout << tecla << "\n\n";
            }
            c.defect();
            teclado();
            tecla = _getch();

            switch (tecla)
            {
            case 'q':
                midiOutShortMsg(hMidiOut, 0x00403C90);
                break;

            case 'w':
                midiOutShortMsg(hMidiOut, 0x00413E90);
                break;

            case 'e':
                midiOutShortMsg(hMidiOut, 0x00423F90);
                break;

            case 'r':
                midiOutShortMsg(hMidiOut, 0x00434190);
                break;

            case 't':
                midiOutShortMsg(hMidiOut, 0x00444390);
                break;

            case 'y':
                midiOutShortMsg(hMidiOut, 0x00454690);
                break;

            case 'u':
                midiOutShortMsg(hMidiOut, 0x00464890);
                break;

            case 'i':
                midiOutShortMsg(hMidiOut, 0x00474A90);
                break;

            case 'o':
                midiOutShortMsg(hMidiOut, 0x00484C90);
                break;

            case 'p':
                midiOutShortMsg(hMidiOut, 0x00494E90);
                break;

            case 'a':
                midiOutShortMsg(hMidiOut, 0x004A5090);
                break;

            case 's':
                midiOutShortMsg(hMidiOut, 0x004B5190);
                break;

            case 'd':
                midiOutShortMsg(hMidiOut, 0x004C5390);
                break;

            case 'f':
                midiOutShortMsg(hMidiOut, 0x004D5590);
                break;

            case 'g':
                midiOutShortMsg(hMidiOut, 0x004E5790);
                break;

            case 'h':
                midiOutShortMsg(hMidiOut, 0x004F5990);
                break;

            case 'j':
                midiOutShortMsg(hMidiOut, 0x00505B90);
                break;

            case 'k':
                midiOutShortMsg(hMidiOut, 0x00515D90);
                break;

            case 'l':
                midiOutShortMsg(hMidiOut, 0x00525F90);
                break;

            case 'z':
                midiOutShortMsg(hMidiOut, 0x00536190);
                break;

            case 'x':
                midiOutShortMsg(hMidiOut, 0x00546390);
                break;

            case 'c':
                midiOutShortMsg(hMidiOut, 0x00556590);
                break;

            case 'v':
                midiOutShortMsg(hMidiOut, 0x00566790);
                break;

            case 'b':
                midiOutShortMsg(hMidiOut, 0x00576990);
                break;

            case 'n':
                midiOutShortMsg(hMidiOut, 0x00586B90);
                break;

            case 'm':
                midiOutShortMsg(hMidiOut, 0x00596D90);
                break;
            case ',':
                midiOutShortMsg(hMidiOut, 0x005A6F90);
                break;
            case ' ': midiOutClose(hMidiOut);
                return; break;
            default: break;
            }
        }
    }

    void teclado()
    {
        c.azul();
        cout << "\t ____________________________________________________________________________________________\n";
        cout << "\t|        |  "; c.rojo(); cout << "1"; c.azul(); cout << "  |  "; c.rojo(); cout << "2"; c.azul(); cout << "  |  "; c.rojo(); cout << "3"; c.azul(); cout << "  |  "; c.rojo(); cout << "4"; c.azul(); cout << "  |  "; c.rojo(); cout << "5"; c.azul(); cout << "  |  "; c.rojo(); cout << "6"; c.azul(); cout << "  |  "; c.rojo(); cout << "7"; c.azul(); cout << "  |  "; c.rojo(); cout << "8"; c.azul(); cout << "  |  "; c.rojo(); cout << "9"; c.azul(); cout << "  |  "; c.rojo(); cout << "0"; c.azul(); cout << "  |  "; c.rojo(); cout << "-"; c.azul(); cout << "  |  "; c.rojo(); cout << "="; c.azul(); cout << "  |  "; c.rojo(); cout << "Retroceso"; c.azul(); cout << "| \n";
        cout << "\t|________|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|___________|\n";
        cout << "\t|        | Q   | W   | E   | R   | T   | Y   | U   | I   | O   | P   | [   | ]   |   \\    __|\n";
        cout << "\t|________|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|________|__|\n";
        cout << "\t|         | A   | S   | D   | F   | G   | H   | J   | K   | L   | ;   | '   | Enter       ___|\n";
        cout << "\t|_________|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|____________|\n";
        cout << "\t|          | Z   | X   | C   | V   | B   | N   | M   | ,   | .   | /   |                |\n";
        cout << "\t|__________|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______________|\n";
        c.defect();
    }        

}piano;

class Ruleta : public IJuegos
{
public:
    string jugadorCPU;

    void jugar()
    {
        bool tur;
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.azul();
        cout << "\n\t\t\t************************************************";
        c.amarillo();
        cout << "\n\t\t\tLas reglas son simples:\n\t\t\t"; c.cafe(); cout << "1.- Se genera un 'volado' para saber quien empieza\n\t\t\t2.- El numero de la recamara sera de 6 tiros\n\t\t\t3.- Solo habra una bala, al primer jugador que le toque, pierde.\n";
        c.azul();
        cout << "\t\t\t************************************************";
        c.azul();
        cout << "\n\n\t\t\t"; system("PAUSE");
        system("CLS");
        giroMoneda(tur);
        tiro(tur);
        cout << "\n\t\t\t";  system("PAUSE");
    }

    void tiro(bool& tur)
    {
        system("CLS");
        srand(time(0));
        int pistola[] = { 0,0,0,0,0,0 };
        int balaPos = rand() % 6;
        bool juegoTerminado = false;
        pistola[balaPos] = 1;
        int inicio = 0;
        int turno = 0;
        if (tur == true)
        {
            turno = 1;
        }
        else
        {
            turno = 2;
        }


        while (!juegoTerminado) 
        {
            if (inicio == 7)
            {
                inicio = 0;
            }
            
            if (turno == 1)
            {
                system("CLS");
                c.cyan();
                cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                c.defect();
                cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                c.cyan();
                cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                c.rojo();
                cout << "\n\t\t\t\t\t\t*************************" << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                c.amarillo();
                cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                c.rojo();
                cout << "\t\t\t\t\t\t*************************" << endl;
                c.cyan();
                cout << "\n\n\t\t\t\t\t\tAtencion\n\n\t\t\t\t\t   "; c.verde(); cout << j.jugadores[0].getUsuario(); c.amarillo(); cout << " es tu turno!";
                c.defect();
                cout << "\n\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                c.rojo();
                cout << "\n\t\t\t\t  Jala el gatillo presionando una tecla";
                c.defect();
                cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                _getch();
                cout << endl << endl;
                for (int i = 2; i > 0; i--)
                {
                    c.cafe();
                    cout << "\t\t\t\t\tSe disparara en:    ";
                    c.cyan();
                    cout << i;
                    c.cafe();
                    Sleep(1000);
                    cout << "\r\t\t\t\t                                  \r";
                }

                if (pistola[inicio] == 1) 
                {                   
                    c.rojo();
                    cout << "\n\t\t\t\t\t\tBAM!\n";
                    c.defect();
                    cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.amarillo();
                    cout << "\n\t\t\t\t\t\t!El jugador "; c.cyan(); cout << j.jugadores[0].getUsuario(); c.amarillo(); cout << " ha sido eliminado!";
                    c.defect();
                    cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    juegoTerminado = true;
                }
                else 
                {
                    c.defect();
                    cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.verde();
                    cout << "\n\t\t\t\t\t !Sobreviviste "; c.cyan(); cout << j.jugadores[0].getUsuario();
                    c.defect();
                    cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.amarillo();
                    cout << "\n\n\t\t\t\tPresiona cualquier tecla" << endl;
                    _getch();
                    inicio++;
                }
                turno = 2;
            }
            else
            {
                if (turno == 2)
                {
                    system("CLS");
                    c.cyan();
                    cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                    c.defect();
                    cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                    cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                    cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                    cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                    cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                    cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                    c.cyan();
                    cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.rojo();
                    cout << "\n\t\t\t\t\t\t*************************" << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                    c.rojo();
                    cout << "\t\t\t\t\t\t*************************" << endl;
                    c.cyan();
                    cout << "\n\n\t\t\t\t\t\tAtencion\n\n\t\t\t\t\t"; c.amarillo(); cout << "!Es turno de tu contrincante!";
                    c.defect();
                    cout << "\n\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.rojo();
                    cout << "\n\t\t\t\t  Jala el gatillo presionando una tecla";
                    c.defect();
                    cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    _getch();
                    cout << "\n\n";
                    for (int i = 3; i > 0; i--)
                    {
                        c.cafe();
                        cout << "\t\t\t\t\tSe disparara en:    ";
                        c.cyan();
                        cout << i;
                        c.cafe();
                        Sleep(1000);
                        cout << "\r\t\t\t\t                                  \r";
                    }
                    if (pistola[inicio] == 1)
                    {
                        c.defect();
                        cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                        c.verde();
                        cout << "\n\t\t\t\t  !Tu contrincante ha sido eliminado!";
                        c.defect();
                        cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                        juegoTerminado = true;
                    }
                    else {
                        c.defect();
                        cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                        c.rojo();
                        cout << "\n\t\t\t\t\tTu contrincante sobrevivio.";
                        c.defect();
                        cout << "\n\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                        c.amarillo();
                        cout << "\n\n\t\t\t\tPresiona cualquier tecla" << endl;
                        _getch();
                        turno = 1;
                        inicio++;
                    }
                }
            }
        }
        c.cyan();
        cout << "\n\n\t\t\t\t\t\tFin del juego." << endl;
        c.defect();
    }

    void giroMoneda(bool &tur)
    {
        srand(time(0));
        string opciones[2] = { "Cara","Cruz" };
        int numV = 0, op = 0;
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\n\t\t\t\t\tSelecciona la opcion que desees:";
        c.defect();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x\n";
        c.azul(); cout << "\t\t\t1.-Cara\n\t\t\t2.-Cruz";
        c.defect();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x\n";
        c.amarillo(); 
        cout << "\t\t\tOpcion: "; c.defect(); cin >> op;
        cout << "\n";
        for (int i = 2; i > 0; i--)
        {
            c.cafe();
            cout << "\t\t\t\tEl tiro se lanzara en: ";
            c.cyan();
            cout << i;
            c.cafe();
            cout << " segundos.";
            Sleep(1000);
            cout << "\r\t\t\t\t                                  \r";
        }

        char estados[] = { '-', '\\', '|', '/' };
        int numEstados = sizeof(estados) / sizeof(estados[0]);
        cout << endl;
        c.cyan();
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < numEstados; j++)
            {
                if (i == 5)
                {
                    cout << "\r\t\t\t\t\t" << "__" << " \tGirando... ";
                    cout.flush();
                }
                else
                {
                    cout << "\r\t\t\t\t\t" << estados[j] << " \tGirando... ";
                    Sleep(80);
                    cout.flush();
                }
            }
        }
        cout << "\r\t\t\t\t\t\t\t\t\r";
        c.rosa();
        numV = rand() % 2;
        int winC = 0, winCr = 0;
        if (numV == 0)
        {
            cout << "\t\t\t\t\tLa moneda salio: "; c.cyan(); cout << opciones[numV];
            winC = 1;
        }
        else if (numV == 1)
        {
            cout << "\n\t\t\t\t\t\tLa moneda salio: "; c.cyan(); cout << opciones[numV];
            winCr = 2;
        }

        if (op == winC)
        {
            c.verde();
            cout << "\n\n\t\t\t\t\tEmpieza tu enemigo!";
            tur = false;
            c.defect();
        }
        else
        {
            if (op == winCr)
            {
                c.verde();
                cout << "\n\n\t\t\t\t\tEmpieza tu enemigo!";
                tur = false;
                c.defect();
            }
            else
            {
                c.rojo();
                cout << "\n\n\t\t\t\t\tEmpiezas tu!";
                tur = true;
                c.defect();
            }
        }

        cout << "\n\n";
        for (int i = 3; i > 0; i--)
        {
            c.cafe();
            cout << "\t\t\t\t\tContinuando en: ";
            c.cyan();
            cout << i;
            c.cafe();
            cout << " segundos.";
            Sleep(1000);
            cout << "\r\t\t\t\t\t                                  \r";
        }
    }

    void volado(int giros)
    {        
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
        c.rojo();
        cout << "\n\t\t\t\t\t\t*************************" << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
        c.amarillo();
        cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
        c.rojo();
        cout << "\t\t\t\t\t\t*************************" << endl;

        srand(time(0));
        string opciones[2] = { "Cara","Cruz" };
        int numV = 0, op = 0;

        c.amarillo();
        cout << "\t\t\t\tSelecciona la opcion que desees:\n"; c.rosa(); cout << "\t\t\t\t1.-Cara\n\t\t\t\t2.-Cruz"; c.amarillo(); cout << "\n\t\t\t\tOpcion: "; cin >> op;
        for (int i = 3; i > 0; i--)
        {
            c.cafe();
            cout << "\t\t\t\tEl tiro se lanzara en: ";
            c.cyan();
            cout << i;
            c.cafe();
            cout << " segundos.";
            Sleep(1000);
            cout << "\r\t\t\t\t                                  \r";
        }

        char estados[] = { '-', '\\', '|', '/' };
        int numEstados = sizeof(estados) / sizeof(estados[0]);
        cout << endl;
        c.cyan();
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < numEstados; j++)
            {
                if (i == 7)
                {
                    cout << "\r\t\t\t\t\t" << "__" << " \tGirando... ";
                    cout.flush();
                }
                else
                {
                    cout << "\r\t\t\t\t\t" << estados[j] << " \tGirando... ";
                    Sleep(80);
                    cout.flush();
                }
            }
        }
        cout << "\r\t\t\t\t\t\t\t\t\r";
        c.rosa();
        numV = rand() % 2;
        int winC = 0, winCr = 0;
        if (numV == 0)
        {
            cout << "\t\t\t\t\tLa moneda salio: "; c.cyan(); cout << opciones[numV];
            winC = 1;
        }
        else if (numV == 1)
        {
            cout << "\n\t\t\t\t\t\tLa moneda salio: "; c.cyan(); cout << opciones[numV];
            winCr = 2;
        }
        c.azul();
        if (op == winC)
        {
            cout << "\n\n\t\t\t\t\tFelicidades, ganas 1 punto!"; j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 1);
            j.jugadores[0].setPartV(1);
        }
        else
        {
            if (op == winCr)
            {
                cout << "\n\n\t\t\t\t\tFelicidades, ganas 1 punto!"; j.jugadores[0].setPuntaje(j.jugadores[0].getPuntaje() + 1);
            }
            else
            {
                cout << "\n\n\t\t\t\t\tHaz perdido, no ganas nada xd "; contExt(j.jugadores);
            }
        }

        c.rosa();
        cout << "\n\n\n\t\t\t\t"; system("PAUSE");
    }

    void contExt(vector<Jugador>& jugadores)
    {
        Ruleta r;
        int sop = 0;

        do
        {
            string cod = "";
            int op;
            system("CLS");
            c.cyan();
            cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
            c.defect();
            cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
            cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
            cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
            cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
            cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
            cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
            c.cyan();
            cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
            c.rojo();
            cout << "\n\t\t\t\t\t\t*************************" << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
            c.amarillo();
            cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
            c.rojo();
            cout << "\t\t\t\t\t\t*************************" << endl;

            int aux = j.jugadores[0].getPuntaje();

            if (aux >= 25)
            {
                c.rojo();
                cout << "\t\t\t\t******************************************\n";
                c.cyan();
                cout << "\t\t\t\tHaz desbloqueado nuevo contenido. Checalo!\n";
                c.rojo();
                cout << "\t\t\t\t******************************************\n";
            }

            c.rosa();
            cout << "\t\t\t\t(Algunos elementos estan bloqueados)\n";
            c.rojo();
            cout << "\t\t\t\t******************************************\n";
            c.amarillo();
            cout << "\t\t\t\tPuntos obtenidos hasta el momento "; c.azul(); cout << jugadores[0].getUsuario(); c.amarillo(); cout << ": "; c.azul(); cout << jugadores[0].getPuntaje() << "\n";
            c.rojo();
            cout << "\t\t\t\t******************************************\n";
            c.amarillo();
            cout << "\t\t\t\tEste es el contenido extra del juego:\n";
            c.rojo();
            cout << "\t\t\t\t******************************************\n";



            if (aux >= 0 && aux < 25)
            {

                c.cafe();
                cout << "\t\t\t\t1.-Memes"; c.defect(); cout << " | "; c.rojo(); cout << "(25 puntos necesarios)\n";
                c.rosa();
                cout << "\t\t\t\t2.-Un volado o que?"; c.defect(); cout << " | "; c.rojo(); cout << "(50 puntos necesarios)\n";
                c.azul();
                cout << "\t\t\t\t3.-Un tiro o que? (ruleta rusa)"; c.defect(); cout << " | "; c.rojo(); cout << "(75 puntos necesarios)\n";
                c.cyan();
                cout << "\t\t\t\t4.-Blackjack (21)"; c.defect(); cout << " | "; c.rojo(); cout << "(150 puntos necesarios)\n";
                c.rojo();
                cout << "\t\t\t\t******************************************\n";
                c.amarillo();
                cout << "\t\t\t\t5.-Canjear un codigo\n"
                    << "\t\t\t\t6.-Regresar\n";
                c.verde();
                c.defect();
                cout << "\t\t\t\t------------------------------------------------\n";
                cout << "\n\t\t\t\tSeleccione la opcion deseada: "; c.defect();
                cin >> op;
                if (op != 5 && op != 6)
                {
                    cout << "\n\t\t\t\t\nTe faltan puntos carnal, chambeale"; system("PAUSE"); return;
                }
            }


            if (aux >= 25 && aux < 50)
            {

                c.cafe();
                cout << "\t\t\t\t1.-Memes"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                c.rosa();
                cout << "\t\t\t\t2.-Un volado o que?"; c.defect(); cout << " | "; c.rojo(); cout << "(50 puntos necesarios)\n";
                c.azul();
                cout << "\t\t\t\t3.-Un tiro o que? (ruleta rusa)"; c.defect(); cout << " | "; c.rojo(); cout << "(75 puntos necesarios)\n";
                c.cyan();
                cout << "\t\t\t\t4.-Blackjack (21)"; c.defect(); cout << " | "; c.rojo(); cout << "(150 puntos necesarios)\n";
                c.rojo();
                cout << "\t\t\t\t******************************************\n";
                c.amarillo();
                cout << "\t\t\t\t5.-Canjear un codigo\n"
                    << "\t\t\t\t6.-Regresar\n";
                c.verde();
                cout << "\n\t\t\t\tSeleccione la opcion deseada: "; c.defect();
                cin >> op;
                if (op != 1 && op != 5 && op != 6)
                {
                    cout << "\n\t\t\t\t\nNo tienes los puntos necesarios para desbloquear el contenido. "; system("PAUSE"); return;
                }
            }
            else
            {
                if (aux >= 50 && aux < 75)
                {
                    c.cafe();
                    cout << "\t\t\t\t1.-Memes"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                    c.rosa();
                    cout << "\t\t\t\t2.-Un volado o que?"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                    c.azul();
                    cout << "\t\t\t\t3.-Un tiro o que? (ruleta rusa)"; c.defect(); cout << " | "; c.rojo(); cout << "(75 puntos necesarios)\n";
                    c.cyan();
                    cout << "\t\t\t\t4.-Blackjack (21)"; c.defect(); cout << " | "; c.rojo(); cout << "(150 puntos necesarios)\n";
                    c.rojo();
                    cout << "\t\t\t\t******************************************\n";
                    c.amarillo();
                    cout << "\t\t\t\t5.-Canjear un codigo\n"
                        << "\t\t\t\t6.-Regresar\n";
                    c.verde();
                    cout << "\n\t\t\t\tSeleccione la opcion deseada: "; c.defect();
                    cin >> op;
                    if (op != 1 && op != 2 && op != 5 && op != 6)
                    {
                        cout << "\n\t\t\t\t\nNo tienes los puntos necesarios para desbloquear el contenido. "; system("PAUSE"); return;
                    }
                }
                else
                {
                    if (aux >= 75 && aux < 150)
                    {
                        c.cafe();
                        cout << "\t\t\t\t1.-Memes"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                        c.rosa();
                        cout << "\t\t\t\t2.-Un volado o que?"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                        c.azul();
                        cout << "\t\t\t\t3.-Un tiro o que? (ruleta rusa)"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                        c.cyan();
                        cout << "\t\t\t\t4.-Blackjack (21)"; c.defect(); cout << " | "; c.rojo(); cout << "(150 puntos necesarios)\n";
                        c.rojo();
                        cout << "\t\t\t\t******************************************\n";
                        c.amarillo();
                        cout << "\t\t\t\t5.-Canjear un codigo\n"
                            << "\t\t\t\t6.-Regresar\n";
                        c.verde();
                        cout << "\n\t\t\t\tSeleccione la opcion deseada: "; c.defect();
                        cin >> op;
                        if (op != 1 && op != 2 && op != 3 && op != 5 && op != 6)
                        {
                            cout << "\n\t\t\t\t\nNo tienes los puntos necesarios para desbloquear el contenido. "; system("PAUSE"); return;
                        }
                    }
                    else
                    {
                        if (aux > 150)
                        {
                            c.cafe();
                            cout << "\t\t\t\t1.-Memes"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                            c.rosa();
                            cout << "\t\t\t\t2.-Un volado o que?"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                            c.azul();
                            cout << "\t\t\t\t3.-Un tiro o que? (ruleta rusa)"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                            c.cyan();
                            cout << "\t\t\t\t4.-Blackjack (21)"; c.defect(); cout << " | "; c.verde(); cout << "Desbloqueado\n";
                            c.rojo();
                            cout << "\t\t\t\t******************************************\n";
                            c.amarillo();
                            cout << "\t\t\t\t5.-Canjear un codigo\n"
                                << "\t\t\t\t6.-Regresar\n";
                            c.verde();
                            cout << "\n\t\t\t\tSeleccione la opcion deseada: "; c.defect();
                            cin >> op;
                        }
                    }
                }

            }


            int rep = 0;
            int inte = 0;

            switch (op)
            {
            case 1: break;
            case 2: r.volado(0);
                break;
            case 3: r.jugar();
                break;
            case 4:
                black.jugar();
                break;
            case 5:
                do
                {
                    system("CLS");
                    c.cyan();
                    cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
                    c.defect();
                    cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
                    cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
                    cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
                    cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
                    cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
                    cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
                    c.cyan();
                    cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x";
                    c.rojo();
                    cout << "\n\t\t\t\t\t\t*************************" << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario() << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Puntaje:     "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << endl;
                    c.amarillo();
                    cout << "\t\t\t\t\t\t" << left << setw(0) << "Partidas:    "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << endl;
                    c.rojo();
                    cout << "\t\t\t\t\t\t*************************" << endl;
                    c.azul();
                    cout << "\n\t\t\t\t*************************************\n";
                    c.amarillo();
                    cout << "\t\t\t\tTienes un codigo maldito hacker?\n";
                    c.azul();
                    cout << "\t\t\t\t*************************************\n";
                    c.cafe();
                    cout << "\t\t\t\tMetelo aqui crack: "; c.defect(); cin >> cod;
                    c.azul();
                    cout << "\t\t\t\t*************************************\n";
                    if (cod == "23746075")
                    {
                        c.verde();
                        cout << "\t\t\t\t\tCodigo aceptado!";
                        c.azul();
                        cout << "\n\t\t\t\t*************************************";
                        c.cafe();
                        cout << "\n\t\t\t\tEsto es lo que obtienes: "; c.cyan(); cout << " +999999 puntos\n";
                        jugadores[0].setPuntaje(999999);
                        j.cExt = 1;
                        c.azul();
                        cout << "\t\t\t\t*************************************\n";
                        c.magenta();
                        cout << "\t\t\t\t"; system("PAUSE");
                        contExt(j.jugadores);
                    }
                    else
                    {
                        if (cod == "ISC02TM")
                        {
                            c.verde();
                            cout << "\t\t\t\t\tCodigo aceptado!";
                            c.azul();
                            cout << "\n\t\t\t\t*************************************";
                            c.cafe();
                            cout << "\n\t\t\t\tObtienes: "; c.cyan(); cout << "El primer contenido desbloqueable\n";
                            j.jugadores[0].setPuntaje(25);
                            j.cExt = 1;
                            c.azul();
                            cout << "\t\t\t\t*************************************\n";
                            c.magenta();
                            cout << "\t\t\t\t"; system("PAUSE");
                            contExt(j.jugadores);
                        }
                        else
                        {
                            if (inte < 2)
                            {
                                c.rojo();
                                cout << "\t\t\t\tNo jala, intenta de nuevo. \n\t\t\t\t"; c.magenta(); system("PAUSE"); c.defect(); inte++; rep = 1;
                            }
                            else
                            {
                                c.rojo();
                                cout << "\t\t\t\tNo jalaaaaa, volveras al menu anterior. \n\t\t\t\t"; c.magenta(); system("PAUSE"); c.defect(); inte++; contExt(j.jugadores);
                            }

                        }
                    }

                } while (rep == 1);
                break;
            case 6: return;
            default: c.rojo(); cout << "\n\n\t\t\t\tHa ingresado una opcion no valida, vuelva a intentarlo"; _getch(); c.defect(); contExt(j.jugadores); break;
            }
            c.defect();
            cout << "\t\t\t\t------------------------------------------------\n";



        } while (sop == 1);
    }

}r;

int main() {
    int mop = 0;
    int audioSel = 0;
    const char* audio1 = "Sonidos\\zelda8bit.wav";
    const char* audio2 = "Sonidos\\intro.wav";
    const char* audio3 = "Sonidos\\zelda8bit_loop.wav";
    const char* audio4 = "Sonidos\\intro_carga.wav";
    const char* audio5 = "Sonidos\\creditos.wav";
    const char* audio6 = "Sonidos\\tictactoe.wav";

    //Sleep(1000);
    //PlaySoundA(audio2, NULL, SND_FILENAME | SND_ASYNC ); 
    //c.intro(audio4);
    //system("CLS");
    //Sleep(500);
    PlaySoundA(audio1, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

    j.registro(j.jugadores);    

    do
    {
        if (audioSel == 1)
        {
            PlaySoundA(audio3, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
        system("CLS");
        c.cyan();
        cout << "\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t _____    _____     ____              _____              __  __   ______" << endl;
        cout << "\t\t\t|  __ \\  |  __ \\   / __ \\            / ____|     /\\     |  \\/  | |  ____|" << endl;
        cout << "\t\t\t| |__) | | |__) | | |  | |  ______  | |  __     /  \\    | \\  / | | |__   " << endl;
        cout << "\t\t\t|  ___/  |  _  /  | |  | | |______| | | |_ |   / /\\ \\   | |\\/| | |  __|  " << endl;
        cout << "\t\t\t| |      | | \\ \\  | |__| |          | |__| |  / ____ \\  | |  | | | |____ " << endl;
        cout << "\t\t\t|_|      |_|  \\_\\  \\____/            \\_____| /_/    \\_\\ |_|  |_| |______|" << endl;
        c.cyan();
        cout << "\n\t\t\tx=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=G7x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        
        if (j.jugadores[0].getPuntaje() > 0)
        {
            c.verde();
            cout << "\n\t\t\t\t\t-------------------------------------";
            cout << "\n\t\t\t\t\t!Haz conseguido puntos recientemente!";
            cout << "\n\t\t\t\t\tEchale un vistazo al Cont. Bloqueado";
            cout << "\n\t\t\t\t\t-------------------------------------\n";
            c.rojo();
            cout << "\n\t\t\t*************************"; c.rojo(); cout << "\t\t       Juegos:\n";
            c.amarillo();
            cout << "\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario(); c.cyan(); cout << setw(3) << "x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x" << endl;
            c.amarillo();
            cout << "\t\t\t" << left << setw(0) << "Puntaje:  "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << setw(3); c.amarillo(); cout << "   1.-Tic Tac Toe" << endl;
            c.amarillo();
            cout << "\t\t\t" << left << setw(0) << "Partidas: "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << setw(3); c.azul(); cout << "   2.-Adivina el numero" << endl;
            c.rojo();
            cout << "\t\t\t*************************"; c.verde(); cout << "\t  3.-Piedra Papel o Tijeras\n";
            c.defect();
        }
        else
        {
            c.rojo();
            cout << "\n\t\t\t*************************"; c.rojo(); cout << "\t\t       Juegos:\n";
            c.amarillo();
            cout << "\t\t\t" << left << setw(0) << "Nickname: "; c.cyan(); cout << setw(24) << j.jugadores[0].getUsuario(); c.cyan(); cout << setw(3) << "x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x" << endl;
            c.amarillo();
            cout << "\t\t\t" << left << setw(0) << "Puntaje:  "; c.cyan(); cout << setw(21) << j.jugadores[0].getPuntaje() << setw(3); c.amarillo(); cout << "   1.-Tic Tac Toe" << endl;
            c.amarillo();
            cout << "\t\t\t" << left << setw(0) << "Partidas: "; c.cyan(); cout << setw(21) << j.jugadores[0].getPartidas() << setw(3); c.azul(); cout << "   2.-Adivina el numero" << endl;
            c.rojo();
            cout << "\t\t\t*************************"; c.verde(); cout << "\t  3.-Piedra Papel o Tijeras\n";
            c.defect();
        }
        c.rosa();
        cout << "\t\t\t\t\t\t\t  4.-Ahorcado\n";
        c.cyan();
        cout << "\t\t\t\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.rojo();
        cout << "\t\t\t\t\t\t\t\t   Complementos:\n";
        c.cyan();
        cout << "\t\t\t\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.amarillo();
        cout << "\t\t\t\t\t\t\t  5.-Contenido Extra\n";
        c.azul();
        cout << "\t\t\t\t\t\t\t  6.-Piano 8bits\n";
        c.verde();
        cout << "\t\t\t\t\t\t\t  7.-Desafios\n";
        c.rosa();
        cout << "\t\t\t\t\t\t\t  8.-Score local\n";
        c.cyan();
        cout << "\t\t\t\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.rojo();
        cout << "\t\t\t\t\t\t\t\t  Otras opciones:\n";
        c.cyan();
        cout << "\t\t\t\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.cafe();
        cout << "\t\t\t\t\t\t\t  9.-Ajustes de usuario\n"
            << "\t\t\t\t\t\t\t  10.-Equipo de desarrollo\n";
        c.rojo();
        cout << "\t\t\t\t\t\t\t  11.-Salir y guardar partida\n";
        c.cyan();
        cout << "\t\t\t\t\t\t\t  x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x\n";
        c.defect();
        cout << "\t\t\t\t\t\t\t  Opcion: "; cin >> mop;

        switch (mop)
        {
        case 1:            
            PlaySoundA(audio6, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            IJugar(&t);             
            PlaySoundA(NULL, NULL, SND_FILENAME | SND_ASYNC);
            audioSel = 1;
            break;
        case 2: IJugar(&n);
            audioSel = 0;
            break;
        case 3: IJugar(&p);
            audioSel = 0;
            break;
        case 4: IJugar(&ahorcado);
            audioSel = 0;
            break;
        case 5: r.contExt(j.jugadores); 
            audioSel = 0;
            break;
        case 6: 
            PlaySoundA(NULL, NULL, SND_ASYNC);
            IJugar(&piano);
            audioSel = 1;
            break;
        case 7: j.desafios(j.jugadores); 
            audioSel = 0;
            break;
        case 8: j.mostrarPuntaje();
            audioSel = 0;
            break;
        case 9: j.usuarios(j.jugadores); 
            audioSel = 0;
            break;
        case 10: 
            PlaySoundA(audio5, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
            c.acercaDe(); 
            PlaySoundA(NULL, NULL, SND_FILENAME | SND_ASYNC);
            audioSel = 1;
            break;
        case 11: c.rojo();
                 cout << "\n\t\t\t\t\t\tHa terminado. Gracias por jugar!.\n"; 
                 break;
        default: cout << "\n\t\t\t\t\t\tOpcion invalida, intente de nuevo. "; mop = 1; _getch(); break;
        }

    } while (mop < 11);
    c.verde();
    j.guardarPuntaje(j.jugadores[0]);

    c.rosa();
    cout << "\n\t\t\t\t";
    system("PAUSE");
    c.defect();
    return EXIT_SUCCESS;
}