#include <iostream>
#include <string>

using namespace std;

// Clase Punto que representa un punto en un plano 2D
class Punto {
public:
    double x, y;
    Punto(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

// Función para calcular el valor absoluto
template <typename T>
T abs(T value) {
    return (value < 0) ? -value : value;
}

// Template de función para calcular la raíz cuadrada
template <typename T>
T sqrt(T value) {
    T guess = value / 2;
    T epsilon = 0.00001; // Precisión
    while (abs(guess * guess - value) >= epsilon) {
        guess = (guess + value / guess) / 2;
    }
    return guess;
}

// Template de función para calcular la distancia entre dos puntos
template <typename T>
T calcularDistancia(const Punto& p1, const Punto& p2) {
    T dx = p2.x - p1.x;
    T dy = p2.y - p1.y;
    return sqrt<T>(dx * dx + dy * dy);
}

// Template de función para calcular el tiempo estimado de entrega
template <typename T>
T tiempoEstimadoEntrega(const Punto& p1, const Punto& p2, T velocidad) {
    T distancia = calcularDistancia<T>(p1, p2);
    return distancia / velocidad;
}

// Template de función para generar un informe de distancias entre puntos
template <typename T, size_t N>
void generarInforme(Punto (&puntos)[N]) {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = i + 1; j < N; ++j) {
            std::cout << "Distancia entre Punto " << i + 1 << " y Punto " << j + 1 << ": "
                      << calcularDistancia<T>(puntos[i], puntos[j]) << std::endl;
        }
    }
}

// Función principal que prueba todas las funcionalidades
int main() {
    Punto p1(1, 2);
    Punto p2(4, 6);
    double velocidad = 50.0; // km/h
    
    // Calcular y mostrar la distancia entre dos puntos
    cout<<"Distancia entre p1 y p2: "<<calcularDistancia<double>(p1, p2)<<endl;
    
    // Calcular y mostrar el tiempo estimado de entrega
    cout<<"Tiempo Estimado de Entrega: "<<tiempoEstimadoEntrega<double>(p1, p2, velocidad)<<" horas"<<endl;
    
    // Array de puntos para generar el informe
    Punto puntos[] = {Punto(1, 2), Punto(4, 6), Punto(7, 8)};
    
    // Generar y mostrar el informe de distancias
    generarInforme<double>(puntos);
    
    return 0;
}
