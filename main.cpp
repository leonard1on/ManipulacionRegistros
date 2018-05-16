#include "Persona.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
int menu();
Persona* agregar();
void list(string);
int main() {
  vector<Persona*> buffer;
  int opcion=0;
  string archivo = "./Registro.sota";

  while (opcion!=4) {
    opcion=menu();

    if (opcion==1) {
      /*for (int i = 0; i < 10; i++) {
      Persona* temp = new Persona("Leonardo"+to_string(i),"Borjas","0801199804812","Colonia America","50495105400",'M','B');
      temp->fill();
      buffer.push_back(temp);
    }*/
      buffer.push_back(agregar());
      if (buffer.size()==10) {
        ofstream file(archivo, ios::out);
        if (file.is_open()) {
          for (size_t i = 0; i < buffer.size(); i++) {
            file<<buffer.at(i)->toString();
          }
          file.close();
        }
        buffer.clear();
      }
    }

    if (opcion==2) {
      int opcion;
      list(archivo);
      cout<<"Cual registro desea eliminar: ";
      cin>>opcion;
    }
    if (opcion==3) {
      list(archivo);
    }
  }
  return 0;
}

int menu(){
  cout<<"1)Agregar \n2)Eliminar \n3)Listar\n";
  int opcion;
  cin>>opcion;
  return opcion;
}

Persona* agregar(){
  string nombre, apellido, identidad, direccion, telefono;
  char sexo, raza;
  cout<<"Nombre: ";
  cin.get();
  getline(cin,nombre);
  cout<<"\nApellido: ";
  getline(cin,apellido);
  cout<<"\nIdentidad: ";
  getline(cin,identidad);
  cout<<"\nDireccion: ";
  getline(cin,direccion);
  cout<<"\nTelefono: ";
  getline(cin,telefono);
  cout<<"\nSexo (M/F): ";
  cin>>sexo;
  cout<<"\nRaza: ";
  cin>>raza;
  Persona* temp = new Persona(nombre,apellido,identidad,direccion,telefono,sexo,raza);
  temp->fill();
  return temp;
}

void list(string archivo){
  ifstream file(archivo, ios::in);
  if (file.is_open()) {
    string line;
    int cont=0;
    while (getline(file, line)) {
      cout << to_string(cont)+") " + line;
      cont++;
    }
  }
  file.close();
}