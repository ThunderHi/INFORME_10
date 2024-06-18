#include <iostream>
using namespace std;

//Plantilla de clase Punto
template <typename T>
class Punto {
    public:
        T x, y; //Atributos genéricos
        //Constructro de la clase
        Punto(T _x = 0, T _y = 0) : x(_x), y(_y) {}
};

//Función sqrt (raiz)
template <typename T>
T sqrt(T value) {
    T guess = value / 2;
    T epsilon = 0.00001; // Precisión
    while ((guess * guess - value) >= epsilon) {
        guess = (guess + value / guess) / 2;
    }
    //retorna valor de la raiz cuadrada
    return guess;
}

//Plantilla de clase Ruta
template <typename T>
class Ruta {
    private:    //Atributos genéricos
        Punto<T> origen;
        Punto<T> destino;
        T distancia;

    public:
        //Constructor de la clase
        Ruta(Punto<T> o, Punto<T> d) : origen(o), destino(d) {
            //Se calcula la distancia a penas son enviados los parámetros
            distancia = calcularDistancia(origen, destino);
        }

        //Función para calcular la distancia entre dos puntos
        T calcularDistancia(const Punto<T>& p1, const Punto<T>& p2) {
            T dx = p2.x - p1.x;
            T dy = p2.y - p1.y;
            return sqrt(dx * dx + dy * dy);
        }

        //Método plantilla para distancias ordenadas de menor a mayor
        T* obtenerDistanciasOrdenadas(Ruta<T>* rutas, int n) {
            //Creamos un arreglo auxiliar para almacenar las distancias
            T* distancias = new T[n];

            //Distancias antes de ser ordenadas
            cout<<"Distancias originales:"<<endl;
            for (int i = 0; i < n; ++i) {
                distancias[i] = rutas[i].distancia;
                cout << distancias[i] << " km"<<endl;
            }

            cout<<"Distancias ordenadas de menor a mayor:"<<endl;
            // Calculamos las distancias para cada ruta
            for (int i = 0; i < n; ++i) {
                distancias[i] = rutas[i].distancia;
            }

            // Ordenamos el arreglo de distancias utilizando el método de la burbuja
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (distancias[j] > distancias[j + 1]) {
                        T temp = distancias[j];
                        distancias[j] = distancias[j + 1];
                        distancias[j + 1] = temp;
                    }
                }
            }
            return distancias;
        }
};

int main() {
    //Creación de los puntos
    Punto<double> p1(0, 0);
    Punto<double> p2(3, 4);
    Punto<double> p3(1, 1);
    Punto<double> p4(6, 8);

    //Arreglo por defecto de las rutas
    Ruta<double> rutas[] = {
        Ruta<double>(p1, p2),
        Ruta<double>(p1, p3),
        Ruta<double>(p1, p4)
    };
    //Tamaño de arreglo de objetos
    int n = 3;

    //Distancias ordenadas de mayor a menor
    double* distanciasOrdenadas = rutas[0].obtenerDistanciasOrdenadas(rutas, n);
    for (int i = 0; i < n; ++i) {
        cout<<distanciasOrdenadas[i]<<" km"<< endl;
    }

    // Liberamos la memoria del arreglo dinámico
    delete[] distanciasOrdenadas;
    return 0;
}