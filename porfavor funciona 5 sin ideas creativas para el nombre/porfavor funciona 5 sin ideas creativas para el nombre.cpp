#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <ctype.h>

using namespace std;
int opcion = 0, a = 0, i = 0, entero = 0;

struct opciones {

	string nombre = "", edad = "", tratamiento = "", descripcion = "", fecha = "";
	double precio = 0, hora = 0;

}dentista[100];

void Menu();
void modificar();

void Menu() {

	system("cls");
	cout << "Bienvenido a nuestra pagina" << endl;

	cout << "1.agendar cita" << endl;
	cout << "2.modificar cita" << endl;
	cout << "3.eliminar cita" << endl;
	cout << "4,lista de citas" << endl;
	cout << "5.limpiar pantalla" << endl;
	cout << "6. salir" << endl;


}

int main() {


	while (a != 4) {

		Menu();
		cin >> opcion;

		switch (opcion) {

		case 1:

			system("cls");
			do {

				cout << "\nnombre de la persona que desea la cita ";
				cin.ignore();
				getline(cin, dentista[i].nombre);
				cout << "\nfavor de escribir su edad ";
				cin.ignore();
				getline(cin, dentista[i].edad);

				cout << "\nokay, ahora porfavor diga que tipo de tratamiento desea ";
				cin.ignore();
				getline(cin, dentista[i].tratamiento);

				cout << "\n favor de describir el tratamiento ";
				cin.ignore();
				getline(cin, dentista[i].descripcion);
				cout << "\nya casi terminamos, ahora introduzca su fecha deseada de la siguiente forma dd/mm/aaaa ";
				cin.ignore();
				getline(cin, dentista[i].fecha);
				cout << "\n para finalizar favor de introducir la hora a la que desea la cita en un fomato de 24hr ";
				cin >> dentista[i].hora;
				cout << "\n introduzca el precio unitario del tratamiento ";
				cin >> dentista[i].precio;

				cout << "¡listo!, su fecha ha sido agendada";
				i++;
			} while (entero == 1);

			system("pause");
			break;

		case 2:
			modificar();

			break;

		case 3:
			system("cls");
			int l;
			cout << "ingrese el registro a eliminar";
			cin >> l;
			l = l - 1;
			for (int j = l; j < i - 1; j++)
			{
				dentista[j].nombre = dentista[j + 1].nombre;
				dentista[j].edad = dentista[j + 1].edad;
				dentista[j].tratamiento = dentista[j + 1].tratamiento;
				dentista[j].descripcion = dentista[j + 1].descripcion;
				dentista[j].fecha = dentista[j + 1].fecha;
				dentista[j].hora = dentista[j + 1].hora;
				dentista[j].precio = dentista[j + 1].precio;

			}
			i--;
			break;

		case 4:
			for (int j = 0; j < i; j++) {
				cout << "numero de cita" << j + 1 << endl;
				cout << "nombre completo: " << dentista[j].nombre << endl;
				cout << "su edad es " << dentista[j].edad << endl;
				cout << "eligio el tratamiento " << dentista[j].tratamiento << endl;
				cout << "la descripcion del tratamiento es " << dentista[j].descripcion << endl;
				cout << "su cita sera el dia " << dentista[j].fecha << endl;
				cout << "a la hora " << dentista[j].hora << endl;
				cout << "el precio total es " << dentista[j].precio << endl;
				j++;

			}
			system("pause");
			break;
		case 5:
			system("cls");

			break;
		case 6:
			ofstream archivo("cosultoriocitas", ios_base::out);

			for (int j = 0; j < i; j++) {

				archivo << "cantidad de citas" << j + 1 << endl;
				archivo << "Nombre del paciente:\n" << dentista[j].nombre << endl;
				archivo << "edad del paciente:\n" << dentista[j].edad << endl;
				archivo << "tratamiento deseado:\n" << dentista[j].tratamiento << endl;
				archivo << "Descripcion del tratamiento:\n" << dentista[j].descripcion << endl;
				archivo << "fecha:\n" << dentista[j].fecha << endl;
				archivo << "hora a la que se llevara a cabo:\n" << dentista[j].hora << endl;
				archivo << "precio:\n" << dentista[j].precio << endl;
				archivo << "\n" << endl;
				j++;
			}

			cout << "hasta luego, gracias por su visita" << endl;
			exit(0);
			break;

		default:

			cout << "Esta opcion no esta disponible..." << endl;
			system("pause");
			system("cls");
			break;

		}

	}

}
}
void modificar()
{
	int i, opcion;
	bool correcto = false;
	cout << "Ingrese el numero de cita que desea cambiar";
	cin >> i;
	i = i - 1;
	cout << "Digite el numero que contenga el dato a modificar" << endl << "1.-Nombre" << endl << "2.- edad" << endl << "3.- tratamiento" << endl << "4.- descrpcion" << endl << "5.- fecha" << endl << "6.-hora" << endl << "7.-precio" << endl;
	cin >> opcion;

	switch (opcion)
	{
	case 1:
		while (!correcto)
		{
			cout << "porfavor introduzca el nuevo nombre: " << endl;
			cin.ignore();
			getline(cin, dentista[i].nombre);
			for (int j = 0; j < dentista[i].nombre; j++) {
				if (!isalpha(dentista[i].nombre[j]) && dentista[i].nombre[j] != ' ') {
					correcto = false;
					break;
				}
				else {
					correcto = true;
				}
			}
		}

		break;

	case 2:
		while (!correcto)
		{
			cout << "porfavor introduzca la nueva edad: " << endl;
			cin.ignore();
			getline(cin, dentista[i].edad);
			for (int j = 0; j < dentista[i].edad; j++) {
				if (!isalpha(dentista[i].edad[j]) && dentista[i].edad[j] != ' ') {
					correcto = false;
					break;
				}
				else {
					correcto = true;
				}
			}

		}

	case 3:
		while (!correcto)
		{
			cout << "porfavor mencione el tratamiento deseado" << endl;
			cin.ignore();
			getline(cin, dentista[i].tratamiento);
			for (int j = 0; j < dentista[i].tratamiento; j++) {
				if (!isalpha(dentista[i].tratamiento[j]) && dentista[i].tratamiento[j] != ' ') {
					correcto = false;
					break;
				}
				else {
					correcto = true;
				}

			}
		}

	case 4:
		while (!correcto)
		{
			cout << "porfavor describa su nuevo tratamiento" << endl;
			cin.ignore();
			getline(cin, dentista[i].descripcion);
			for (int j = 0; j < dentista[i].descripcion; j++) {
				if (!isalpha(dentista[i].descripcion[j]) && dentista[i].descripcion[j] != ' ') {
					correcto = false;
					break;
				}
			}
			else {
			correcto = true;
		   }
		}

	case 5:
		while (!correcto)
		{
			cout << "porfavor introduzca la nueva fecha en la que desea la cita" << endl;
			cin.ignore();
			getline(cin, dentista[i].fecha);
			for (int j = 0; j < dentista[i].fecha; j++) {
				if (!isalpha(dentista[i].fecha[j]) && dentista[i].fecha[j] != ' ') {
					correcto = false;
					break;
				}
				else {
					correcto = true;
				}
			}
		}
	case 6:
		while (!correcto)
		{
			cout << "favor de introducir la nueva hora a la que desea la cita" << endl;
			cin.ignore();
			getline(cin, dentista[i].hora);
			for (int j = 0; j < dentista[i].hora; j++) {
				if (!isalpha(dentista[i].hora[j]) && dentista[i].hora[j] != ' ') {
					correcto = false;
					break;
				}
				else {
					correcto = true;
				}
			}

		}
	case 7:
		while (!correcto)
		{
			cout << "introduzca el precio corregido" << endl;
			cin.ignore();
			getline(cin, dentista[i].precio);
			for (int j = 0; j < dentista[i].precio; j++) {
				if (!isalpha(dentista[i].precio[j]) && dentista[i].precio[j] != ' ') {
					correcto = false;
					break;
				}
				else {
					correcto = true;
				}
			}



		}




	}
}