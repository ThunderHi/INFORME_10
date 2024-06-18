#include <iostream>
using namespace std;
//Clase Ruta
class Ruta {
    private:    //Atributos de clase
        string origen;
        string destino;
        int distancia; // en kilómetros

    public:
        //Constructor de la clase
        Ruta(string o, string d, int dist) : origen(o), destino(d), distancia(dist) {}

        //Método template para asignar vehículo a la ruta
        template <typename T>
        void asignarVehiculo(T vehiculo) {
            cout<<"Vehiculo "<<vehiculo<<" asignado a la ruta de "<<origen<<" a "<<destino<<endl;
        }

        //Método template para calcular tiempo estimado basado en diferentes velocidades
        template <typename T>
        T calcularTiempoEstimado(T velocidad) {
            return (distancia)/velocidad;
        }
        //Método que muestra detalles de Ruta
        void mostrarRuta() {
            cout<<"Ruta de "<<origen<<" a "<<destino<<" con una distancia de "<<distancia<<" km"<<endl;
        }
};
//CLase entrega
class Entrega {
    private:
        string id;  //Atributos
        string direccion;
        string fecha;

    public:
        //Constructor de clase
        Entrega(string i, string dir, string f) : id(i), direccion(dir), fecha(f) {}

        //Método template para asignar estado a la entrega
        template <typename T>
        void asignarEstado(T estado) {
            cout<<"Entrega "<<id<<" tiene el estado: "<<estado<< endl;
        }

        //Método template para calcular la fecha estimada de llegada basada en diferentes tiempos de tránsito
        template <typename T>
        void calcularFechaEstimada(T diasTransito) {
            cout<<"La entrega "<<id<<" llegara en aproximadamente "<<diasTransito<<" dias a "<<direccion<<endl;
        }
        //Método que muestra entrega
        void mostrarEntrega() {
            cout<<"Entrega "<<id<<" a "<<direccion<<" programada para la fecha "<<fecha<< endl;
        }
};
//Rutina Principal
int main() {
    //Pruebas para la clase Ruta
    Ruta ruta1("Arequipa", "Lima", 1000);
    ruta1.mostrarRuta();
    ruta1.asignarVehiculo("Camion A1");
    ruta1.asignarVehiculo(101); // Ejemplo con un tipo de dato diferente
    cout<<"Tiempo estimado (int): "<<ruta1.calcularTiempoEstimado(80)<<" horas"<< endl;
    cout<<"Tiempo estimado (double): "<<ruta1.calcularTiempoEstimado(80.5)<<" horas"<<endl;

    //Pruebas para la clase Entrega
    Entrega entrega1("E123", "Av. Ejercito 1047", "2024-06-20");
    entrega1.mostrarEntrega();
    entrega1.asignarEstado("En camino");
    entrega1.asignarEstado(2); // Ejemplo con un tipo de dato diferente
    entrega1.calcularFechaEstimada(5);
    entrega1.calcularFechaEstimada(3.5);
    return 0;
}