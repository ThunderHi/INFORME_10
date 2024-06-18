#include <iostream>
#include <string>
using namespace std;

//Plantilla de clase Punto que representa un punto en un plano 2D
template <typename T>
class Punto {
public:
    T x, y;
    //Constructor de clase
    Punto(T _x = 0, T _y = 0) : x(_x), y(_y) {}
};

//Función para calcular el valor absoluto
template <typename T>
T abs(T value) {
    //Devuelve valor positivo en cualquier caso
    return (value < 0) ? -value : value;
}

// Función para calcular la raíz cuadrada
template <typename T>
T sqrt(T value) {
    T guess = value / 2;
    T epsilon = 0.00001; // precisión
    while (abs(guess * guess - value) >= epsilon) {
        guess = (guess + value / guess) / 2;
    }
    //Retorna raiz cuadrada
    return guess;
}

//Función para calcular la distancia entre dos puntos
template <typename T>
T calcularDistancia(const Punto<T>& p1, const Punto<T>& p2) {
    T dx = p2.x - p1.x;
    T dy = p2.y - p1.y;
    return sqrt<T>(dx * dx + dy * dy);
}

//Plantilla de clase Ruta
template <typename T>
class Ruta {
private:
    //Atributos con tipos genericos
    Punto<T> origen;
    Punto<T> destino;
    T distancia; // en kilómetros

public:
    //Constructor de clase
    Ruta(Punto<T> o, Punto<T> d) : origen(o), destino(d) {
        distancia = calcularDistancia<T>(origen, destino);
    }
    //Asignación de vehiculo
    template <typename V>
    void asignarVehiculo(V vehiculo) {
        cout<<"Vehiculo "<<vehiculo<<" asignado a la ruta de ("<<origen.x<<", "<<origen.y<<") a ("<<destino.x<<", "<<destino.y<<")"<< endl;
    }
    //Método genérico para tiempo
    T calcularTiempoEstimado(T velocidad) {
        return distancia / velocidad;
    }
    //Muestra detalles de Ruta
    void mostrarRuta() {
        cout<<"Ruta de ("<<origen.x<<", "<<origen.y<<") a ("<<destino.x<<", "<<destino.y<<") con una distancia de "<<distancia<<" km"<<endl;
    }
};

// Plantilla de clase Entrega
template <typename T>
class Entrega {
private:    //Atributos de  clase
    string id;
    string direccion;
    string fecha;

public:
    //Constructor de clase
    Entrega(string i, string dir, string f) : id(i), direccion(dir), fecha(f) {}
    
    //Método generico para asignar estado de entrega
    template <typename E>
    void asignarEstado(E estado) {
        cout<<"Entrega "<<id<<" tiene el estado: "<<estado<<endl;
    }

    //Método generico para asignar dias de entrega
    template <typename D>
    void calcularFechaEstimada(D diasTransito) {
        cout<<"La entrega "<<id<<" llegara en aproximadamente "<<diasTransito<<" dias a "<<direccion<<endl;
    }
    //Muestra detalles de entrega
    void mostrarEntrega() {
        cout<<"Entrega "<<id<<" a "<<direccion<<" programada para la fecha "<<fecha<<endl;
    }
};

//Plantilla de clase SistemaGestionRutas
template <typename T>
class SistemaGestionRutas {
private:    //Atributos genéricos
    Ruta<T>* ruta;
    Entrega<T>* entrega;

public:
    //Constructor de clase
    SistemaGestionRutas(Ruta<T>* r, Entrega<T>* e) : ruta(r), entrega(e) {}

    //Apunta a método de clase entrega y ruta
    void mostrarDetalles() {
        ruta->mostrarRuta();
        entrega->mostrarEntrega();
    }

    //Apunta a método de clase ruta
    template <typename V>
    void asignarVehiculoARuta(V vehiculo) {
        ruta->asignarVehiculo(vehiculo);
    }

    //Apunta a método de clase entrega para estado de entrega
    template <typename E>
    void asignarEstadoAEntrega(E estado) {
        entrega->asignarEstado(estado);
    }
    //calcula estado de tiempo
    void calcularTiempoEstimadoRuta(T velocidad) {
        cout<<"Tiempo estimado: "<<ruta->calcularTiempoEstimado(velocidad)<<" horas"<<endl;
    }

    //Apunta a método de clase entrega para calcular fecha de entrega
    template <typename D>
    void calcularFechaEstimadaEntrega(D diasTransito) {
        entrega->calcularFechaEstimada(diasTransito);
    }
};

// Rutina Principal
int main() {
    //Creación de puntos
    Punto<double> p1(0, 0);
    Punto<double> p2(4, 6);
    //Creación de rutas y entrega
    Ruta<double> ruta1(p1, p2);
    Entrega<double> entrega1("E123", "Av. Ejercito 1047", "2024-06-20");
    //Creación de sistema
    SistemaGestionRutas<double> sistema(&ruta1, &entrega1);
    //Muestra detalles de entrega y ruta
    sistema.mostrarDetalles();

    //Métodos con tipos distitos de datos
    sistema.asignarVehiculoARuta("Camion A1");
    sistema.asignarVehiculoARuta(101); // Ejemplo con un tipo de dato diferente
    
    //Métodos con tipos distitos de datos
    sistema.calcularTiempoEstimadoRuta(80); // int
    sistema.calcularTiempoEstimadoRuta(80.5); // double

    //Métodos con tipos distitos de datos
    sistema.asignarEstadoAEntrega("En camino");
    sistema.asignarEstadoAEntrega(2); // Ejemplo con un tipo de dato diferente
    
    //Métodos con tipos distitos de datos
    sistema.calcularFechaEstimadaEntrega(5); // int
    sistema.calcularFechaEstimadaEntrega(3.5); // double
    return 0;
}
