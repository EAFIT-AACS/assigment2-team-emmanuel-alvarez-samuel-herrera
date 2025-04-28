/*
    Descripción: Genera cadenas que pertenecen y no pertenecen al lenguaje definido por la gramática:
    S -> aSb | ε
 */

 #include <iostream>
 #include <fstream>
 #include <vector>
 #include <string>
 #include <cstdlib>
 #include <ctime>
 
 using namespace std;
 
 // Función para generar una cadena válida siguiendo la gramática S -> aSb | ε
 string generateValidString(int depth) {
     if (depth == 0) return ""; // Caso base: ε
     return "a" + generateValidString(depth - 1) + "b";
 }
 
 // Función para generar una cadena inválida (usa 'a' y 'b' pero no sigue la gramática)
 string generateInvalidString(int length) {
    string str = "";
    int countA = 0, countB = 0;
    
    for (int i = 0; i < length; i++) {
        // Aseguramos que se rompa la estructura de la gramática
        if (countA > countB) {
            str += 'b';
            countB++;
        } else if (countA == countB) {
            // Posibilidades: agregar 'b' antes de 'a' o alternar mal los caracteres
            str += (rand() % 2 == 0) ? 'b' : 'a';
            if (str.back() == 'a') countA++;
            else countB++;
        } else {
            str += 'a';
            countA++;
        }
    }
    // Asegurar que la cadena sea realmente inválida
    if (countA == countB) {
        str += (rand() % 2 == 0) ? "aa" : "bb"; // Forzar una estructura inválida
    }
    return str;
 }
 
 int main() {
    cout<<"Bienvenido a este primer algoritmo de generación de cadenas válidas e inválidas"<<endl;
    cout<<"para una gramática libre de contexto: S -> aSb | ε"<<endl;
    srand(time(0)); // Inicializa la semilla para números aleatorios
    int i=rand()%8+2; // Genera un número aleatorio entre 2 y 10
    cout<<"A continuación se generarán: " << i*2 <<" cadenas, de las cuales "<<i<<" son cadenas válidas y "<<i<<" son cadenas inválidas"<<endl;
    int j=0;
    // Este cilo genera de 4 a 16 cadenas la mitad validas y la otra mitad invalidas

    // Abrimos el archivo de salida
    ofstream outputFile("cadenas_generadas.txt");
    if (!outputFile) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    while(i>j){
        // Generamos un numero aleatorio entre 0 y 6
        int length1 = rand() % 6;
        // Generamos un numero aleatorio entre 1 y 6
        int length2 = rand() % 5+1;
        string valid = generateValidString(length1);
        string invalid = generateInvalidString(length2);
        outputFile<< valid <<endl;
        outputFile<<invalid<<endl;
        if(valid.length()==0){
            valid="ε";
        }
        cout << "Cadena "<<j+j+1<<": " << valid << endl; // Puede ser "aabb", "aaabbb", etc.
        cout << "Cadena "<<j+j+2<<": " << invalid << endl; // Puede ser "abb", "baa", etc.
        j++;
    }
    // Cerramos el archivo
    outputFile.close();
     return 0;
 }
 