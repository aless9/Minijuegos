#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> //esta es la libreria para el sleep
using namespace std;

int main () {
int opcion;
system ("clear");

//hundir la flota variables

int disparox, disparoy;
int Ronda = 1;
int barco1 = 2,barco2 = 3,barco3 = 4;
int x1,y1; //incognitas barco 2
    int x,y; //incognitas barco 1
    int x2,y2; //incognitas barco 3
    int posicion;
    int campo_real [6][6] ={        {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0},
                                    {0, 0, 0, 0, 0, 0}};

    string campo_teorico [6][6]={   {"-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-"}};

//cuatro en raya variables

int tablero_real [6][7] = {     {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0}};

string tablero_teorico [6][7] = {   {"-", "-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-", "-"},
                                    {"-", "-", "-", "-", "-", "-", "-"}};

int respuesta;
int contador = 0;
int random;
bool resultado = false;

system ("figlet Minijuegos");
cout<<"Hecho por Alessandro Sanchez\n";
cout<<endl;
cout<<"Le informamos de que si elige la opcion de Hundir la flota es posible que no termine de cargar el tablero, lo que tendra que hacer es cerrar y ejecutar otra vez";
cout<<endl;
cout<<endl;
cout<<"Hasta el momento tenemos a su disposicion dos juegos diferentes:\n1. Hundir la flota.\n2. El cuatro en raya.\nEscoja el juego que desee jugar: ";
cout<<endl;
cout<<endl;
cin>>opcion;

if (opcion != 1 && opcion != 2){
    cout<<endl;
    cout<<"Que haces solo hay dos opciones elige 1 o 2 no es tan dificil";
    cout<<endl;
    cout<<"Espere mientras le mandamos de vuelta...";
    cout<<endl;
    sleep (3);
    main ();
}

if (opcion == 1){

    system("clear");
    system("figlet Hundir La Flota");

    cout<<"Bienvenido a Hundir la Flota\n";
    cout<<"A continuacion te comentare las normas de este juego;\n";
    cout<<endl;
    cout<<"Hay tres barcos en el tablero generados aleatoriamente, un Balandro (dos posiciones), un Bergantin (tres posiciones), y un Portaviones (cuatro posiciones). Tienes un total de 26 intentos y con ellos deberas de darles a todos los barcos antes de que se te acaben , ademas se te iran marcando de una o en rojo los disparos que ya has efectuado pero has fallado y de azul los blancos que hayas golpeado, te mostrare por pantalla aquellos barcos los cuales ya hayas hundido (no vale disparar en el mismo sitio). Una vez discho esto mucha suerte y que te lo pases bien";
    cout<<endl;
    cout<<endl;
    srand(time (NULL));
    //hacemos el barco que tiene dos posiciones
    x = rand()%6;
    y = rand()%6;
    campo_real [x][y] = 1;

    do {
            posicion = rand ()%4;
            if (posicion == 0 && x-1 < 6 && x-1 > 0 && y < 6 && y > 0){
                    campo_real[x-1][y] = 1;
            }
            else if (posicion == 1 && x+1 < 6 && x+1 > 0 && y < 6 && y > 0){
                    campo_real[x+1][y] = 1;
            }
            else if (posicion == 2 && x < 6 && x > 0 && y+1 < 6 && y+1 > 0){
                    campo_real[x][y+1] = 1;
            }
            else if (posicion == 3 && x < 6 && x > 0 && y-1 < 6 && y-1 > 0){
                    campo_real[x][y-1] = 1;
            }
            else {
                    posicion = 5;
            }
    }while (posicion == 5);


    //acabamos primer barco 
    //empezamos con el segundo barco
    do {
            do {
                    x1 = rand()%6;
                    y1 = rand()%6;
    }while (campo_real [x1-1][y1] == 1 && campo_real [x1-2][y1] == 1 && campo_real [x1][y1-1] == 1 && campo_real [x1][y1-2] == 1 && campo_real [x1+1][y1] == 1 && campo_real [x1+2][y1] ==    1 && campo_real [x1][y1+1] == 1 && campo_real [x1][y1+2] == 1);
    }while (campo_real [x1][y1] == 1);

    campo_real [x1][y1] = 2;

    do {
            posicion = rand ()%4;
            if (posicion == 0 && x1-2 < 6 && x1-2 > 0 && y1 < 6 && y1 > 0 && campo_real[x1-1][y1] == 0 && campo_real[x1-2][y1] == 0){
                    campo_real[x1-1][y1] = 2;
                    campo_real[x1-2][y1] = 2;

            }
            else if (posicion == 1 && x1+2 < 6 && x1+2 > 0 && y1 < 6 && y1 > 0 && campo_real[x1+1][y1] == 0 && campo_real[x1+2][y1] == 0){
                    campo_real[x1+1][y1] = 2;
                    campo_real[x1+2][y1] = 2;

            }
            else if (posicion == 2 && x1 < 6 && x1 > 0 && y1+2 < 6 && y1+2 > 0 && campo_real[x1][y1+1] == 0 && campo_real[x1][y1+2] == 0){
                    campo_real[x1][y1+1] = 2;
                    campo_real[x1][y1+2] = 2;

            }
            else if (posicion == 3 && x1 < 6 && x1 > 0 && y1-2 < 6 && y1-2 > 0 && campo_real[x1][y1-1] == 0 && campo_real[x1][y1-2] == 0){
                    campo_real[x1][y1-1] = 2;
                    campo_real[x1][y1-2] = 2;

            }
            else {
                    posicion = 5;
            }
    }while (posicion == 5);


    //acabamos segundo barco 
    //empezamos con el tercer barco


    do {
            do {                                            //con esta parte le digo que spawnee la posicion cuando no haya ningun barco cerca
                    x2 = rand()%6;
                    y2 = rand()%6;
    }while (campo_real [x2-1][y2] == 1 && campo_real [x2-2][y2] == 1 && campo_real [x2][y2-1] == 1 && campo_real [x2][y2-2] == 1 && campo_real [x2+1][y2] == 1 && campo_real [x2+2][y2] == 1 && campo_real [x2][y2+1] == 1 && campo_real [x2][y2+2] == 1 && campo_real [x2-1][y2] == 2 && campo_real [x2-2][y2] == 2 && campo_real [x2][y2-1] == 2 && campo_real [x2][y2-2] == 2 && campo_real [x2+1][y2] == 2 && campo_real [x2+2][y2] == 2 && campo_real [x2][y2+1] == 2 && campo_real [x2][y2+2] == 2 && campo_real [x2-3][y2] == 2 && campo_real [x2-3][y2] == 2 && campo_real [x2][y2-3] == 2 && campo_real [x2][y2-3] == 2 && campo_real [x2+3][y2] == 2 && campo_real [x2+3][y2] == 2 && campo_real [x2][y2+3] == 2 && campo_real [x2][y2+3] == 2 && campo_real [x2-3][y2] == 1 && campo_real [x2-3][y2] == 1 && campo_real [x2][y2-3] == 1 && campo_real [x2][y2-3] == 1 && campo_real [x2+3][y2] == 1 && campo_real [x2+3][y2] == 1 && campo_real [x2][y2+3] == 1 && campo_real [x2][y2+3] == 1 );
    }while (x2 == x1 and y2 == y1 and x2 == x and y2 == y or campo_real[x2][y2] == 1 or campo_real[x2][y2] == 2 );

    campo_real [x2][y2] = 3;

    do {
            posicion = rand ()%4;
            if (posicion == 0 && x2-3 < 6 && x2-3 > 0 && y2 < 6 && y2 > 0 && campo_real[x2-1][y2] == 0 && campo_real[x2-2][y2] == 0 &&  campo_real [x2-3][y2] == 0){
                    campo_real[x2-1][y2] = 3;
                    campo_real[x2-2][y2] = 3;
                    campo_real[x2-3][y2] = 3;
            }
            else if (posicion == 1 && x2+3 < 6 && x2+3 > 0 && y2 < 6 && y2 > 0 && campo_real[x2+1][y2] == 0 && campo_real[x2+2][y2] == 0 &&  campo_real [x2+3][y2] == 0){
                    campo_real[x2+1][y2] = 3;
                    campo_real[x2+2][y2] = 3;
                    campo_real[x2+3][y2] = 3;
            }
            else if (posicion == 2 && x1 < 6 && x2 > 0 && y2+3 < 6 && y2+3 > 0 && campo_real[x2][y2+1] == 0 && campo_real[x2][y2+2] == 0 &&  campo_real [x2][y2+3] == 0){
                    campo_real[x2][y2+1] = 3;
                    campo_real[x2][y2+2] = 3;
                    campo_real[x2][y2+3] = 3;
            }
            else if (posicion == 3 && x2 < 6 && x2 > 0 && y2-3 < 6 && y2-3 > 0 && campo_real[x2][y2-1] == 0 && campo_real[x2][y2-2] == 0 &&  campo_real [x2][y2-3] == 0){
                    campo_real[x2][y2-1] = 3;
                    campo_real[x2][y2-2] = 3;
                    campo_real[x2][y2-3] = 3;
            }
            else {
                    posicion = 5;
            }
    }while (posicion == 5);


    // aqui hacemos el tema de disparos del juego
    
    cout<<endl;

    for (int t = 0; t < 27; t++){
            cout<<"Ronda "<<Ronda;
            Ronda++;
            cout<<endl;
            cout << "\n  | 0 1 2 3 4 5\n";
            cout << "--+-------------\n";
            for (int i = 0; i < 6; i++) {
                    cout << i << " | ";
                    for (int j = 0; j < 6; j++) {
                            cout << campo_teorico[i][j] << " ";
                    }
            cout << endl;
            }
            do {
                    cout << endl;
                    cout<<"Indica la coordenada del eje x: ";cin>>disparox;
                    cout<<"Indica la coordenada del eje y: ";cin>>disparoy;
                    cout<<endl;
                    if (disparox > 6 || disparox < 0 || disparoy > 6 || disparoy < 0){
                            cout<<"Los numeros que sean entre 0 y 6 si puede ser.";
                            cout<<endl;
                    }
            } while (disparox > 6 || disparox < 0 || disparoy > 6 || disparoy < 0);
            if (disparox >= 0 && disparox <= 6 && disparoy >= 0 && disparoy <= 6 ){
                    if (campo_real [disparox][disparoy] == 1 || campo_real [disparox][disparoy] == 2 || campo_real [disparox][disparoy] == 3 ){
                            cout<<"Le has dado!";
                            cout<<endl;                     //si acierta el diparo es un 4
                            if (campo_real [disparox][disparoy] == 1 ){
                                    barco1--;
                            }
                            if (campo_real [disparox][disparoy] == 2 ){
                                    barco2--;
                            }
                            if (campo_real [disparox][disparoy] == 3 ){
                                    barco3--;
                            }
                            cout<<endl;
                            campo_teorico [disparox][disparoy] = "\033[34mo\033[0m"; //con esto hago que se vea de color azul la letra
                    }
                    if (barco1 == 0){
                            cout<<"Balandro Hundido";
                            cout<<endl;
                            cout<<endl;
                    }
                    if (barco2 == 0){
                            cout<<"Bergantin Hundido";
                            cout<<endl;
                            cout<<endl;
                    }
                    if (barco3 == 0){
                            cout<<"Portaviones Hundido";
                            cout<<endl;
                            cout<<endl;
                    }

                    if (campo_real [disparox][disparoy] == 0){
                            cout<<"agua parguela";  
                            cout<<endl;        //si falla el disparo es un 5
                            campo_teorico [disparox][disparoy] = "\033[31mo\033[0m";  // con esto hago que se vea de color rojo cuando falle
                            cout<<endl;
                    }
                    if (campo_real [disparox][disparoy] == 7){
                            cout<<"Que intentas juanma que te he dicho que no vale disparar al mismo sitio no te enteras\n";
                            cout<<endl;
                            Ronda--;   
                    }
                    if (barco1 == 0 && barco2 == 0 && barco3 == 0){
                            cout<<"Ganaste maquina, enhorabuena";
                            cout<<endl;
                            cout<<endl;
                            cout<<"Programa made por Alessandro Sanchez";
                            cout<<endl;
                            return 0;
                    }
                    if (Ronda == 27){
                            cout<<"Te has quedado sin municion, has perdido.";
                            cout<<endl;
                            cout<<endl;
                            cout<<"Programa made por Alessandro Sanchez";
                            cout<<endl;
                            return 0;
                    }
                    campo_real [disparox][disparoy] = 7;
            }


    }    

    cout<<endl;
    cout<<endl;
}

else if (opcion == 2){
    system ("clear");
    srand(time(NULL));

    system ("figlet Cuatro en Raya");
    cout<<endl;
    cout<<"Bienvenido al Cuatro en raya, este juego consta como su nombre indica, intentar de conectar cuatro fichas colocadas por columnas de forma vertical, horizontal u oblicua antes de que lo haga la maquina, tus fichas se mostraran de color azul y la de la maquina de rojo, tienes un maximo de 42 turnos asi que usa bien tus movimientos y recuerda de que si una columna esta llena de fichas no puedes colocar una ahi!.\nUna vez dicho esto, buena suerte y que te lo pases bien";
    cout<<endl;                                                     //con esta parte creamos el tablero de 6 filas por 7 columnas
    cout << "\n| 0    1    2    3    4    5    6 |\n";
            cout << "----------------------------------";
            cout<<endl;
    for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7 ; j++) {
                cout<<" |";
                cout << tablero_teorico[i][j];
                cout<<"| ";
            }
            cout << endl;
            }

    //empezamos con la colocacion de las fichas del usuario y del bot
    cout<<endl;
    cout<<endl;
    for (int turno = 0 ; turno < 42 ; turno++){
        contador = 0;
        cout<<endl;
        cout<<"Turno "<<turno+1<<endl;
        cout<<endl;
        do {
        cout<<"Digame la columna en la que quiera colocar su ficha: ";cin>>respuesta;
        cout<<endl;
            for (int k = 5; k >= 0; k--) {
                if (tablero_real[k][respuesta] == 0) {
                    contador++;
                }
            }

            if (contador != 0) {
                for (int k = 5; k >= 0; k--) {
                    if (tablero_real[k][respuesta] == 0) {
                        tablero_real[k][respuesta] = 1;
                        break;
                    }
                }
            }
            else {
                cout << "La fila esta completa, repite posición. (Juanma no vale poner mas fichas de las que el tablero puede soportar, tramposo\n" << endl;
                }
        }while (contador == 0);
        contador = 0;
        do {
        random = rand ()%7; 
        for (int k = 5; k >= 0; k--) {
            if (tablero_real[k][random] == 0) {
                contador++;
            }
        }

        if (contador != 0) {
            for (int k = 5; k >= 0; k--) {
                if (tablero_real[k][random] == 0) {
                    tablero_real[k][random] = -1;
                    break;
                }
            }
        }
        }while (contador == 0);


            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 7 ; j++) {
                    if (tablero_real[i][j] == -1){
                        tablero_teorico [i][j] = "\033[31mx\033[0m";
                    }
                    if (tablero_real[i][j] == 1){
                        tablero_teorico [i][j] = "\033[34mo\033[0m";
                    }
                }
            }

        //COMPROBACIONES

        //1 Vertical
        for (int j = 0; j < 7 ; j++) {
            for (int i = 0; i < 3 ; i++){
                if (tablero_real [i][j] + tablero_real [i+1][j] + tablero_real [i+2][j] + tablero_real [i+3][j] == 4){
                    cout<<"has ganao, tenias 4 fichas seguidas de forma Vertical";
                    resultado = true;
                    cout<<endl;
                    break;
                }
                if (tablero_real [i][j] + tablero_real [i+1][j] + tablero_real [i+2][j] + tablero_real [i+3][j] == -4){
                    cout<<"has perdio, te han metio una palisa";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
            }
        }  

        //2 Horizontal

        for (int i = 0; i < 7 ; i++) {
            for (int j = 0; j < 4 ; j++){
                if (tablero_real [i][j] + tablero_real [i][j+1] + tablero_real [i][j+2] + tablero_real [i][j+3] == 4){
                    cout<<"has ganao, tenias 4 fichas seguidas de forma Horizontal";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
                if (tablero_real [i][j] + tablero_real [i][j+1] + tablero_real [i][j+2] + tablero_real [i][j+3] == -4){
                    cout<<"has perdio, te han metio una palisa";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
            }
        } 
        //3 Oblicuo
        for (int j = 0; j < 4 ; j++) {
            for (int i = 2 ; i >= 0 ; i--){
                if (tablero_real [i][j] + tablero_real [i+1][j+1] + tablero_real [i+2][j+2] + tablero_real [i+3][j+3] == 4){
                    cout<<"has ganao, tenias 4 fichas unidas oblicuamente";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
                if (tablero_real [i][j] + tablero_real [i+1][j+1] + tablero_real [i+2][j+2] + tablero_real [i+3][j+3] == -4){
                    cout<<"has perdio, te han metio una palisa";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
            }
        } 
        for (int j = 6 ; j > 2 ; j--) {
            for (int i = 0 ; i <= 2 ; i++){
                if (tablero_real [i][j] + tablero_real [i+1][j-1] + tablero_real [i+2][j-2] + tablero_real [i+3][j-3] == 4){
                    cout<<"has ganao, tenias 4 fichas unidas oblicuamente";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
                if (tablero_real [i][j] + tablero_real [i+1][j-1] + tablero_real [i+2][j-2] + tablero_real [i+3][j-3] == -4){
                    cout<<"has perdio, te han metio una palisa";
                    cout<<endl;
                    resultado = true;
                    cout<<endl;
                    break;
                }
            }
        } 

        cout << "\n| 0    1    2    3    4    5    6 |\n";
            cout << "----------------------------------";
            cout<<endl;
        for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 7 ; j++) {
                        cout<<" |";
                        cout << tablero_teorico[i][j];
                        cout<<"| ";
                    }
            cout << endl;
            }
        if (resultado == true){
            return 0;
        }

    }

    cout<<endl;
    cout<<endl;
}
cout<<"Espero que te haya gustado";
cout<<endl;

return 0;
}