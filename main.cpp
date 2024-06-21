#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct structclientes {             
  int idCliente[1000];         
  string razonSocial[1000];  
  string domicilio[1000]; 
  string localidad[1000];
  short codigoPostal[1000];
  struct sFec{
    short dia[1000];
    short mes[1000];
    short agno[1000];
  };
  sFec fecha;
  float saldo[1000];
};    

struct structarticulos {
    short idArticulo[100];
    string descripcion[100];
    short stockActual[100];
    float precioUnitario[100];
};



structclientes clientes;
structarticulos articulos;


int importarClientes(){
    const char* ruta_clientes = R"(C:\Users\Stormfacha\Desktop\tp facturas a clientes\clientes.txt)";
    ifstream clientestexto; // Objeto ifstream para lectura de archivos
    clientestexto.open(ruta_clientes);
    string linea;

    if (clientestexto.is_open()) {
        short line_number=0;
        while (getline(clientestexto, linea)) {
            line_number++;
            clientes.idCliente[line_number]    = stoi(linea.substr(1-1,8));
            clientes.razonSocial[line_number]  = linea.substr(14-1,20);
            clientes.domicilio[line_number]    = linea.substr(34-1,20);
            clientes.localidad[line_number]    = linea.substr(54-1,20);
            clientes.codigoPostal[line_number] = stoi(linea.substr(70-1,20));
            clientes.fecha.agno[line_number]   = stoi(linea.substr(94-1,4));
            clientes.fecha.mes[line_number]    = stoi(linea.substr(99-1,2));
            clientes.fecha.dia[line_number]    = stoi(linea.substr(102-1,2));   
            clientes.saldo[line_number]        = stof(linea.substr(106-1,20));
        }
        clientestexto.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return 0;
}

int importarArticulos(){
    const char* ruta_articulos = R"(C:\Users\Stormfacha\Desktop\tp facturas a clientes\articulos.txt)";
    ifstream articulostexto; // Objeto ifstream para lectura de archivos
    articulostexto.open(ruta_articulos);
    string linea;

    if (articulostexto.is_open()) {
        int line_number=0;
        while (getline(articulostexto, linea)) {
            line_number++;
            articulos.idArticulo[line_number]        = stoi(linea.substr(1-1,3));
            articulos.descripcion[line_number]       = linea.substr(6-1,20);
            articulos.stockActual[line_number]       = stoi(linea.substr(28-1,3));
            articulos.precioUnitario[line_number]    = stof(linea.substr(33-1,10));  
        }
        articulostexto.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return 0;
}


int main() {
    importarClientes();
    importarArticulos();
    short clienteseleccionado;
    cout << "Seleccione un Cliente:";
    cin  >> clienteseleccionado;
    
    cout << clientes.idCliente[clienteseleccionado] << endl;
    cout << clientes.razonSocial[clienteseleccionado] << endl;
    cout << clientes.domicilio[clienteseleccionado] << endl;
    cout << clientes.localidad[clienteseleccionado] << endl;
    cout << clientes.codigoPostal[clienteseleccionado] << endl;
    cout << clientes.fecha.agno[clienteseleccionado] << endl;
    cout << clientes.fecha.mes[clienteseleccionado] << endl;
    cout << clientes.fecha.dia[clienteseleccionado] << endl;
    cout << clientes.saldo[clienteseleccionado] << endl;
    /*
    cout << articulos.idArticulo[clienteseleccionado] << endl;
    cout << articulos.descripcion[clienteseleccionado] << endl;
    cout << articulos.stockActual[clienteseleccionado] << endl;
    cout << articulos.precioUnitario[clienteseleccionado] << endl;
    */
    return 0;
}
