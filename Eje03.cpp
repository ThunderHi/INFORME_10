#include <iostream>
using namespace std;

// Plantilla de clase Recipiente
template <typename T>
class Recipiente {
    private:
        //Atributos
        T* elementos;      //genérico
        int n;

    public:
        //Constructor de clases
        Recipiente(T* elems, int num) : elementos(elems), n(num) {}

        //Método para mostrar datos de recipiente
        void mostrarElementos() const {
            for (int i = 0; i < n; ++i) {
                cout<<"Elemento "<<i + 1<<": "<<elementos[i]<<endl;
            }
        }
};

// Clase principal para probar la clase Recipiente
int main() {
    //Creación de arreglos de distintos tipos
    int enteros[] = {1, 2, 3, 4, 5};
    double flotantes[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    string cadenas[] = {"uno", "dos", "tres", "cuatro", "cinco"};

    //Creación de objetos de clase Recipiente
    Recipiente<int> recipiente1(enteros, 5);
    Recipiente<double> recipiente2(flotantes, 5);
    Recipiente<string> recipiente3(cadenas, 5);

    //Mostrando datos de recipientes
    cout<<"Recipiente de enteros:"<<endl;
    recipiente1.mostrarElementos();

    cout<<"\nRecipiente de flotantes:"<<endl;
    recipiente2.mostrarElementos();

    cout<<"\nRecipiente de cadenas:"<<endl;
    recipiente3.mostrarElementos();
    return 0;
}