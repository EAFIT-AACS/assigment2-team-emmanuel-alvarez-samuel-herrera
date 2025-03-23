#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Función que genera las formas sentenciales en una derivación más a la izquierda
vector<string> leftmostDerivation(const string& input) {
    vector<string> derivation;
    string sententialForm = "S";
    derivation.push_back(sententialForm);

    for (char c : input) {
        if (c == 'a') {
            // Reemplaza la S más a la izquierda por "aSb"
            size_t pos = sententialForm.find('S');
            if (pos != string::npos) {
                sententialForm.replace(pos, 1, "aSb");
                derivation.push_back(sententialForm);
            }
        } else if (c == 'b') {
            // Reemplaza la S más a la izquierda por ε (elimina la S)
            size_t pos = sententialForm.find('S');
            if (pos != string::npos) {
                sententialForm.replace(pos, 1, "");
                derivation.push_back(sententialForm);
            }
        }
    }
    
    return derivation;
}

// Función para imprimir la derivación con el formato de la imagen
void printDerivation(const vector<string>& derivation, const string& acceptedString) {
    // Mostrar las reglas de producción antes de la derivación
    cout << "Production rules used in the derivation:\n";
    cout << "S → aSb | ε\n\n";

    // Mostrar la derivación en el formato solicitado
    cout << "Sentential forms in a leftmost derivation of \"" << acceptedString << "\" in G\n";
    for (const string& step : derivation) {
        cout << step << endl;
    }

    // Mostrar la cadena aceptada completa al final
    cout << "\nAccepted string: \"" << acceptedString << "\"\n";
}

int main() {
    ifstream inputFile("cadenas_aceptadas.txt");
    if (!inputFile) {
        cerr << "Error al abrir cadenas_aceptadas.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        cout << "\n=====================================\n";
        vector<string> derivation = leftmostDerivation(line);
        printDerivation(derivation, line);
    }

    inputFile.close();
    return 0;
}
