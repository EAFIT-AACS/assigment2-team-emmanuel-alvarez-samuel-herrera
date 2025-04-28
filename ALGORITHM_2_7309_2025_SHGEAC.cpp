/*
    Descripción: Implementa un Autómata de Pila (PDA) que reconoce cadenas generadas por la gramática:
    S -> aSb | ε
 */

 #include <iostream>
 #include <stack>
 #include <string>
 #include <fstream>

 using namespace std;
 
 // Función que implementa el PDA
 bool pdaRecognizeString(const string& input) {
     stack<char> pdaStack;
     
     for (char c : input) {
         if (c == 'a') {
             pdaStack.push('a'); // Empujar 'a' en la pila
         } else if (c == 'b') {
             if (pdaStack.empty() || pdaStack.top() != 'a') {
                 return false; // No hay 'a' correspondiente en la pila
             }
             pdaStack.pop(); // Hacer match con 'a'
         } else {
             return false; // Caracter inválido en el alfabeto
         }
     }
     
     return pdaStack.empty(); // La pila debe estar vacía al final
 }
 
 int main() {

    ifstream inputFile("cadenas_generadas.txt");
    if (!inputFile) {
        cerr << "Error al abrir cadenas_generadas.txt" << endl;
        cerr <<"Por favor ejecute el algoritmo 1 antes de ejecutar este algoritmo"<<endl;
        return 1;
    }
     
    // Abrimos el archivo de salida
    ofstream outputFile("cadenas_aceptadas.txt");
    if (!outputFile) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    cout << "Resultados del Automata de pila:" << endl;
    int i=0;
    while (getline(inputFile, line)) {
        cout <<"cadena "<<i+1<<": "<< (line=="" ? "ε" : line) << " -> " << (pdaRecognizeString(line) ? "Aceptada" : "Rechazada") << endl;
        if (pdaRecognizeString(line)==1) {
            outputFile << line << endl;
        }
        i++;
    }

    // Cerramos los archivos
    outputFile.close();
    inputFile.close();
     
     return 0;
 }
 