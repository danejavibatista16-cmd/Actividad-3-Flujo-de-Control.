#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Estructura para almacenar los datos de cada estudiante
struct Estudiante {
    string nombre;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    string estatus;
};

int main() {
    int cantidadEstudiantes;
    vector<Estudiante> listaEstudiantes;

    cout << "====================================================\n";
    cout << "   SISTEMA DE CALIFICACIONES - FLUJO DE CONTROL     \n";
    cout << "====================================================\n\n";

    cout << "A cuantos estudiantes desea registrar?: ";
    cin >> cantidadEstudiantes;
    cin.ignore(); // Limpia el bufer para poder usar getline

    // Bucle para capturar los datos de los estudiantes
    for (int i = 0; i < cantidadEstudiantes; i++) {
        Estudiante est;
        
        cout << "\n--- Datos del Estudiante #" << i + 1 << " ---\n";
        cout << "Nombre completo: ";
        getline(cin, est.nombre);

        cout << "Nota 1: ";
        cin >> est.nota1;
        cout << "Nota 2: ";
        cin >> est.nota2;
        cout << "Nota 3: ";
        cin >> est.nota3;
        cout << "Nota 4: ";
        cin >> est.nota4;
        cin.ignore(); // Limpia el bufer para el siguiente estudiante

        // Calculo del promedio
        est.promedio = (est.nota1 + est.nota2 + est.nota3 + est.nota4) / 4.0;

        // Condicional para evaluar el estatus
        if (est.promedio >= 70.0) {
            est.estatus = "Aprobado";
        } else {
            est.estatus = "Reprobado";
        }

        listaEstudiantes.push_back(est);
    }

    // --- IMPRESION DE RESULTADOS EN FORMATO TABLA ---
    cout << "\n\n=========================================================================================\n";
    cout << left << setw(25) << "Estudiante"
         << right << setw(8) << "Nota 1"
         << setw(8) << "Nota 2"
         << setw(8) << "Nota 3"
         << setw(8) << "Nota 4"
         << setw(12) << "Promedio"
         << setw(15) << "Estatus" << endl;
    cout << "=========================================================================================\n";

    // Configura la consola para mostrar siempre 2 decimales
    cout << fixed << setprecision(2);

    // Recorrer la lista e imprimir las filas alineadas
    for (const auto& estudiante : listaEstudiantes) {
        cout << left << setw(25) << estudiante.nombre
             << right << setw(8) << estudiante.nota1
             << setw(8) << estudiante.nota2
             << setw(8) << estudiante.nota3
             << setw(8) << estudiante.nota4
             << setw(12) << estudiante.promedio
             << setw(15) << estudiante.estatus << endl;
    }
    
    cout << "=========================================================================================\n";

    return 0;
}
