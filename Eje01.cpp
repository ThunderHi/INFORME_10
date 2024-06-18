#include <iostream>
#include <string>
using namespace std;

// Clase Entrega
class Entrega {
private:   //Atributos
    string id;
    string direccion;
    string fecha;

public:
    //Constructor de clase
    Entrega(string i, string dir, string f) : id(i), direccion(dir), fecha(f) {}

    //Obtiene fecha
    string getFecha() const {
        return fecha;
    }
    //Muestra datos de entrega
    void mostrarEntrega() const {
        cout<<"Entrega "<<id<<" a "<<direccion<<" programada para la fecha "<<fecha<< endl;
    }
};

// Función plantilla para ordenar arreglo de Entrega por fecha
template <typename T>
T* ordenarPorFecha(T* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Comparar las fechas como cadenas directamente
            if (arr[j].getFecha() > arr[j + 1].getFecha()) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int main() {
    //Creación de arreglo con objetos predeterminados
    Entrega entregas[] = {
        Entrega("E123", "Av. Ejercito 1047", "2024-06-20"),
        Entrega("E124", "Av. Ejercito 1048", "2024-05-20"),
        Entrega("E125", "Av. Ejercito 1049", "2024-07-20")
    };
    //Cantidad de objetos del arreglo anterior
    int n = 3;

    //Mostramos arreglo antes de ordenas
    cout<<"Entregas antes de ordenar:"<<endl;
    for (int i = 0; i < n; ++i) {
        entregas[i].mostrarEntrega();
    }
    //Creamos otro arreglo para las entregas ya ordenadas
    Entrega* entregasOrdenadas = ordenarPorFecha(entregas, n);

    //Mostramos el arreglo ordenado
    cout<<"\nEntregas después de ordenar por fecha:"<<endl;
    for (int i = 0; i < n; ++i) {
        entregasOrdenadas[i].mostrarEntrega();
    }
    return 0;
}
