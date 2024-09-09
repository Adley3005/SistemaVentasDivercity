#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct Cliente {
    string nombre_nino;
    int edad_nino;
    string documento_nino;
    string nombre_padre;
    string documento_padre;
};

struct Producto {
    string codigo;
    double precio;
};

void abrirCajonDinero() {
    // ABRE CAJA REGISTRADORA
    // ...
    cout << "¡Cajón del dinero abierto!" << endl;
}

void imprimirBoleta(const Cliente& cliente, const Producto& producto) {
    // Código para imprimir la boleta
    // ...
    cout << "---------- Boleta ----------" << endl;
    cout << "Nombre del niño: " << cliente.nombre_nino << endl;
    cout << "Edad del niño: " << cliente.edad_nino << endl;
    cout << "Documento de identidad del niño: " << cliente.documento_nino << endl;
    cout << "Nombre del padre: " << cliente.nombre_padre << endl;
    cout << "Documento de identidad del padre: " << cliente.documento_padre << endl;
    cout << "Código del producto: " << producto.codigo << endl;
    cout << "Precio del producto: " << producto.precio << " soles" << endl;
    cout << "----------------------------" << endl;
}

void imprimirFactura(const Cliente& cliente, const Producto& producto, double ruc, const string& e_mail) {
    // Código para imprimir la factura
    // ...
    cout << "---------- Factura ----------" << endl;
    cout << "Nombre del niño: " << cliente.nombre_nino << endl;
    cout << "Edad del niño: " << cliente.edad_nino << endl;
    cout << "Documento de identidad del niño: " << cliente.documento_nino << endl;
    cout << "Nombre del padre: " << cliente.nombre_padre << endl;
    cout << "Documento de identidad del padre: " << cliente.documento_padre << endl;
    cout << "Código del producto: " << producto.codigo << endl;
    cout << "Precio del producto: " << producto.precio << " soles" << endl;
    cout << "RUC: " << ruc << endl;
    cout << "Correo electrónico: " << e_mail << endl;
    cout << "----------------------------" << endl;
}

int main() {
    int medio_pago = 0;
    int opcion_documento = 0;
    string codigo_producto;
    int contadorVentas = 25;
    int numProductos;

    Producto productos[] = {
        {"1010", 180.0},  // multipase
        {"4041", 69.0},   // entrada_niño
        {"4042", 45.0}    // entrada_adulto
    };

    numProductos = sizeof(productos) / sizeof(productos[0]);

    const int MAX_CLIENTES = 100;  // Tamaño máximo del arreglo de clientes
    Cliente baseDatosClientes[MAX_CLIENTES];  // Arreglo para almacenar los datos de los clientes
    int numClientes = 0;  // Contador de clientes almacenados

    int opcion = 0;

    while (opcion != 4) {
        cout << "----- Menú Principal -----" << endl;
        cout << "1. Registrar venta" << endl;
        cout << "2. Ver multipases registrados" << endl;
        cout << "3. Imprimir documentos" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { // Registrar venta
                while (true) {
                    string codigo;
                    cout << "Ingrese el código del producto: ";
                    cin >> codigo;

                    bool codigoValido = false;
                    double precio = 0.0;

                    for (int i = 0; i < numProductos; i++) {
                        if (productos[i].codigo == codigo) {
                            codigoValido = true;
                            precio = productos[i].precio;
                            break;
                        }
                    }

                    if (codigoValido) {
                        Cliente cliente; // Crear una instancia de la estructura Cliente

                        cout << "Llenar datos:\n";
                        cout << "Nombre completo del niño: ";
                        cin.ignore();
                        getline(cin, cliente.nombre_nino);

                        cout << "Edad del niño: ";
                        cin >> cliente.edad_nino;
                        while (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Edad inválida. Por favor, ingrese la edad del niño nuevamente: ";
                            cin >> cliente.edad_nino;
                        }

                        cout << "Documento de identidad del niño: ";
                        cin.ignore();
                        getline(cin, cliente.documento_nino);

                        cout << "Nombre completo del padre: ";
                        getline(cin, cliente.nombre_padre);

                        cout << "Documento de identidad del padre: ";
                        getline(cin, cliente.documento_padre);

                        baseDatosClientes[numClientes] = cliente; // Agregar el cliente al arreglo
                        numClientes++;

                        cout << "Datos almacenados correctamente." << endl;

                        contadorVentas++;
                        cout << "Numero de Multipase: " << contadorVentas << endl;
                        cout << "El monto a pagar es: " << precio << " soles" << endl;

                        while (medio_pago != 1 && medio_pago != 2 && medio_pago != 3 && medio_pago != 4) {
                            cout << "Seleccione el medio de pago (1 = Efectivo, 2 = Débito, 3 = Crédito, 4 = Mastercard): ";
                            cin >> medio_pago;
                            while (cin.fail()) {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "Opción de medio de pago inválida. Por favor, seleccione nuevamente: ";
                                cin >> medio_pago;
                            }

                            if (medio_pago == 1) {
                                cout << "Ha seleccionado: Efectivo" << endl;
                                double montopagar;
                                cout << "Ingrese la cantidad a pagar: ";
                                cin >> montopagar;

                                if (montopagar < precio) {
                                    cout << "Saldo insuficiente. El monto a pagar es mayor." << endl;
                                    break;
                                }

                                double cambio = montopagar - precio;
                                cout << "Cambio a devolver: " << cambio << " soles" << endl;
                            } else if (medio_pago == 2) {
                                cout << "Ha seleccionado: Débito" << endl;
                            } else if (medio_pago == 3) {
                                cout << "Ha seleccionado: Crédito" << endl;
                            } else if (medio_pago == 4) {
                                cout << "Ha seleccionado: Mastercard" << endl;
                            } else {
                                cout << "Opción de medio de pago inválida. Por favor, seleccione nuevamente." << endl;
                            }
                        }
                        break; // Salir del bucle al ingresar el código correcto
                    } else {
                        cout << "Código de producto incorrecto. " << endl;
                    }
                }
                break;
            }
            case 2: {
                // Ver multipases registrados
                break;
            }
            case 3: {
                while (opcion_documento != 1 && opcion_documento != 2) {
                    cout << "Seleccione el tipo de documento (1 = boleta, 2 = factura): ";
                    cin >> opcion_documento;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Opción de documento inválida. Por favor, seleccione nuevamente: ";
                        cin >> opcion_documento;
                    }
                    if (opcion_documento == 1) {
                        abrirCajonDinero();
                        // Obtener el último cliente registrado
                        Cliente cliente = baseDatosClientes[numClientes - 1];
                        // Obtener el último producto registrado (por ejemplo, el primer producto en este caso)
                        Producto producto = productos[0];
                        imprimirBoleta(cliente, producto);
                    } else if (opcion_documento == 2) {
                        double ruc;
                        string e_mail;

                        cout << "RUC: ";
                        cin >> ruc;
                        cout << "Correo electrónico: ";
                        cin >> e_mail;
                        abrirCajonDinero();
                        // Obtener el último cliente registrado
                        Cliente cliente = baseDatosClientes[numClientes - 1];
                        // Obtener el último producto registrado (por ejemplo, el primer producto en este caso)
                        Producto producto = productos[0];
                        imprimirFactura(cliente, producto, ruc, e_mail);
                    } else {
                        cout << "Opción de documento inválida. Por favor, seleccione nuevamente." << endl;
                    }
                }
                break;
            }
            case 4: {
                // Salir del programa
                cout << "¡Hasta luego!" << endl;
                return 0;
            }
            
        }
    }

    return 0;
}
