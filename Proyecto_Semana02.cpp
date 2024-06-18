#include <iostream>
#include <string>
using namespace std;

// Interfaz para mostrar información de empleados
class Interfaz {
    public:
        virtual void mostrarInformacion() const = 0; // Método virtual puro
        virtual double calcularSalario() const = 0;  // Método virtual puro
        virtual ~Interfaz() {} // Destructor virtual
};

// Clase Base para empleados
class Empleado : public Interfaz {
    protected:
        string nombre;
        double salarioBase;     // salario base acorde a su rol
        string fechaContratacion;
        static double tarifaHora; // Atributo estático
    public:
        // Constructor de clase base
        Empleado(string nom, double salario, string fecha) : 
        nombre(nom), salarioBase(salario), fechaContratacion(fecha) {}
        // Método estático para establecer la tarifa por hora
        static void setTarifaHora(double tarifa) {
            tarifaHora = tarifa;
        }
        // Método para mostrar información básica del empleado
        void mostrarInformacion() const override {
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Salario Base: "<<salarioBase<<endl;
            cout<<"Fecha de Contratacion: "<<fechaContratacion<<endl;
        }
        virtual ~Empleado() {} // Destructor virtual
};

// Inicialización del atributo estático
double Empleado::tarifaHora = 0.0;

// Clase derivada Gerente
class Gerente : public Empleado {
    private:
        double bono; // Adicional a su sueldo
    public:
        // Constructor de clase Gerente
        Gerente(string nom, double salario, string fecha, double b) : 
        Empleado(nom, salario, fecha), bono(b) {}
        // Sobreescritura de método
        double calcularSalario() const override {
            return salarioBase + bono;
        }
        // Sobreescritura y refinamiento de método
        void mostrarInformacion() const override {
            Empleado::mostrarInformacion();
            cout<<"Bono: "<<bono<<endl;
        }
        // Método getNombre() para la búsqueda
        string getNombre() const {
            return nombre;
        }
};

// Clase derivada Desarrollador
class Desarrollador : public Empleado {
    private:
        int horasExtras; // Hora fuera de horario normal
    public:
        // Constructor de clase Desarrollador
        Desarrollador(string nom, double salario, string fecha, int horas) : 
        Empleado(nom, salario, fecha), horasExtras(horas) {}
        // Sobreescritura de método
        double calcularSalario() const override {
            return salarioBase + (horasExtras * tarifaHora);
        }
        // Sobreescritura y refinamiento de método
        void mostrarInformacion() const override {
            Empleado::mostrarInformacion();
            cout<<"Horas Extras: " << horasExtras << endl;
            cout<<"Tarifa por Hora Extra: "<<tarifaHora<<endl;
        }
        // Método getNombre() para la búsqueda
        string getNombre() const {
            return nombre;
        }
};

// Clase derivada Diseñador
class Disenador : public Empleado {
    private:
        double porcentajeComision; // Ganancia por ventas
        double ventasTotales; // Ventas realizadas en soles

    public:
        // Constructor de Diseñador
        Disenador(string nom, double salario, string fecha, double comision, double ventas) : 
        Empleado(nom, salario, fecha), porcentajeComision(comision), ventasTotales(ventas) {}
        // Sobreescritura de método
        double calcularSalario() const override {
            return salarioBase + (ventasTotales * porcentajeComision);
        }
        // Sobreescritura y refinamiento de método
        void mostrarInformacion() const override {
            Empleado::mostrarInformacion();
            cout<<"Porcentaje de Comision: "<< porcentajeComision<<endl;
            cout<<"Ventas Totales: "<<ventasTotales<<endl;
        }
        // Método getNombre() para la búsqueda
        string getNombre() const {
        return nombre;
        }
};

// Plantilla de clase Departamento
template <typename T>
class Departamento {
private:    //Atributos de clase
    T** empleados;  //Se agregaran de tipo empleados
    int capacidad;
    int contador;

public:
    //Constructor de clase
    Departamento(int capInicial = 10) : capacidad(capInicial), contador(0) {
        empleados = new T*[capacidad];
    }

    //Destructor de clase
    ~Departamento() {
        for (int i = 0; i < contador; ++i) {
            delete empleados[i];
        }
        delete[] empleados;
    }

    //Método para agregar un empleado
    void agregarEmpleado(T* empleado) {
        if (contador >= capacidad) {
            capacidad *= 2;
            T** nuevosEmpleados = new T*[capacidad];
            for (int i = 0; i < contador; ++i) {
                nuevosEmpleados[i] = empleados[i];
            }
            delete[] empleados;
            empleados = nuevosEmpleados;
        }
        empleados[contador++] = empleado;
    }

    //Método para eliminar un empleado por índice
    void eliminarEmpleado(int indice) {
        //en caso de encontrar fuera de indice
        if (indice < 0 or indice >= contador) {
            cout<<"Indice fuera de rango"<<endl;
            return;
        }
        //elimina empleado por indice
        delete empleados[indice];


        for (int i = indice; i < contador - 1; ++i) {
            empleados[i] = empleados[i + 1];
        }
        //se actualiza contador
        --contador;
    }

    //Método para buscar un empleado por nombre
    T* buscarEmpleado(const string& nombre) const {
        for (int i = 0; i < contador; ++i) {
            if (empleados[i]->getNombre() == nombre) {
                //retorna al empleado
                return empleados[i];
            }
        }
        //en caso de que no encuentre empleado buscado
        return nullptr;
    }

    //Método para listar todos los empleados
    void listarEmpleados() const {
        for (int i = 0; i < contador; ++i) {
            cout<<"Indice: "<<i+1<<endl;
            //Polimorfismo, muestra información de empleados
            empleados[i]->mostrarInformacion();
            //Polimorfismo, calcula salario de empleados
            cout<<"Salario Calculado: "<<empleados[i]->calcularSalario()<<endl<<endl;
        }
    }
};

int main() {
    //Establecer tarifa estática
    double Thora;
    cout<<"Ingrese tarifa en soles de hora: ";
    cin>>Thora;
    Empleado::setTarifaHora(Thora);

    //Crear departamento de gerentes
    Departamento<Gerente> deptoGerentes;
    deptoGerentes.agregarEmpleado(new Gerente("Carlos", 5000, "2022-01-01", 1000));
    deptoGerentes.agregarEmpleado(new Gerente("Ana", 6000, "2021-05-01", 1200));

    //Crear departamento de desarrolladores
    Departamento<Desarrollador> deptoDesarrolladores;
    deptoDesarrolladores.agregarEmpleado(new Desarrollador("Pedro", 4000, "2020-07-01", 10));
    deptoDesarrolladores.agregarEmpleado(new Desarrollador("Lucia", 4500, "2019-10-01", 20));

    //Crear departamento de diseñadores
    Departamento<Disenador> deptoDisenadores;
    deptoDisenadores.agregarEmpleado(new Disenador("Juan", 3500, "2021-03-01", 0.10, 50000));
    deptoDisenadores.agregarEmpleado(new Disenador("Marta", 4000, "2020-11-01", 0.15, 40000));

    //Listar empleados en cada departamento
    cout<<"================Gerentes================"<<endl;
    deptoGerentes.listarEmpleados();

    cout<<"================Desarrolladores================"<<endl;
    deptoDesarrolladores.listarEmpleados();

    cout<<"================Disenadores================"<<endl;
    deptoDisenadores.listarEmpleados();

    //Buscar un empleado
    string nombreBusqueda;
    cout<<"Ingrese el nombre del empleado que desea buscar en el departamento de gerentes: ";
    cin>>nombreBusqueda;
    Gerente* gerenteEncontrado = deptoGerentes.buscarEmpleado(nombreBusqueda);
    if (gerenteEncontrado) {
        cout<<"Gerente encontrado:"<<endl;
        gerenteEncontrado->mostrarInformacion();
        cout<<"Salario Calculado: "<<gerenteEncontrado->calcularSalario()<<endl;
    } else {
        cout<<"Gerente no encontrado."<<endl;
    }

    //Eliminar un empleado
    int indiceEliminar;
    cout<<"Ingrese el indice del empleado que desea eliminar del departamento de desarrolladores: ";
    cin>>indiceEliminar;
    deptoDesarrolladores.eliminarEmpleado(indiceEliminar-1);

    //Listar empleados nuevamente para verificar eliminación
    cout<<"Desarrolladores despues de la eliminacion:"<<endl;
    deptoDesarrolladores.listarEmpleados();

    return 0;
}
