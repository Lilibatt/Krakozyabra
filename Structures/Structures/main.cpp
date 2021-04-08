#include <iostream>
#define str_len 30
#define size 30
int choice;
int panel = 0;
using namespace std;


struct Flight
{
	
	int FlightNumber;
	string Destination;
	char StartTime[str_len];
	string StartDate;
	int TicketCost;
	int PlacesCount;
};

struct Flight flights[size];
struct Flight bad;
int current_size;


void enter_new() { 
	setlocale(LC_CTYPE, "Russian");
	cout << "Ввод информации" << endl; 
	if (current_size < size) 
	{ 
		cout << "Строка номер "; 
		cout << current_size + 1; 
		cout << endl << "Номер рейса " << endl; 
		cin >> flights[current_size].FlightNumber; 
		cout << "Пункт назначения " << endl; 
		cin >> flights[current_size].Destination;
		cout << "Время вылета " << endl; 
		cin >> flights[current_size].StartTime;
		cout << "Дата вылета " << endl; 
		cin >> flights[current_size].StartDate;
		cout << "Стоимость билета " << endl;
		cin >> flights[current_size].TicketCost;
		cout << "Кол-во посадочных мест " << endl; 
		cin >> flights[current_size].PlacesCount; 
		current_size++; 
	} else 
		cout << "Введено максимальное кол-во строк"; 
	cout << "Что дальше?" << endl; 
	cin >> choice; 
} 

void del() { 
	setlocale(LC_CTYPE, "Russian");
	int d; 
	cout << "\nНомер строки, которую надо удалить (для удаления всех строк набрать 10)" << endl; 
	cin >> d;
	if (d != 10) 
	{ 
		for (int de1 = (d - 1); de1 < current_size; de1++) 
			flights[de1] = flights[de1 + 1]; 
		current_size = current_size - 1; 
	} 
	if (d == 10) 
	for (int i = 0; i < size; i++) 
	flights[i] = bad; 
	cout << "Что дальше?" << endl; 
	cin >> choice; 
} 

void change() { 
	setlocale(LC_CTYPE, "Russian");
	int n, per; 
	cout << "\nВведите номер строки" << endl; 
	cin >> n; 
	do { 
		cout << "Введите: " << endl; 
		cout << "1-для изменения номера рейса" << endl; 
		cout << "2-для изменения пункта назначения" << endl; 
		cout << "3-для изменения время вылета" << endl; 
		cout << "4-для изменения даты вылета" << endl; 
		cout << "5-для изменения стоимости билета" << endl; 
		cout << "6-для изменения кол-ва мест" << endl; 
		cout << "7-конец\n"; 
		cin >> per; 
		switch (per) 
		{ 
			case 1: cout << "Новый номер рейса"; 
			cin >> flights[n - 1].FlightNumber; 
			break; 
			case 2: cout << "Новый пункт назначения"; 
			cin >> flights[n - 1].Destination; 
			break; 
			case 3: cout << "Новое время вылета"; 
			cin >> flights[n - 1].StartTime; 
			break; 
			case 4: cout << "Новая дата вылета"; 
			cin >> flights[n - 1].StartDate;
			break; 
			case 5: cout << "Новая стоимость билета"; 
			cin >> flights[n - 1].TicketCost; 
			break; 
			case 6: cout << "Новое кол-во мест"; 
			cin >> flights[n - 1].PlacesCount; 
			break; 
		} 
	} while (per != 7); 
	cout << "Что дальше?" << endl;
	cin >> choice; 
}

void out() { 
	setlocale(LC_CTYPE, "Russian");
	int sw, n; 
	int FlightNumber;
	cout << "1-вывод строки по Номеру рейса" << endl; 
	cout << "2-вывод всех строк" << endl; 
	cin >> sw; 
	if (sw == 1) { 
		cout << "Введите номер рейса: " << endl;
		cin >> FlightNumber;
		cout << endl;
		for (n = 0; n < panel; n++)
		{
			if (flights[n].FlightNumber == FlightNumber){
				cout << "\n строка номер: " << n + 1;
				cout << "Номер рейса ";
				cout << flights[n].FlightNumber << endl;
				cout << "Пункт назначения ";
				cout << flights[n].Destination << endl;
				cout << "Время вылета ";
				cout << flights[n].StartTime << endl;
				cout << "Дата вылета ";
				cout << flights[n].StartDate << endl;
				cout << "Стоимость билета ";
				cout << flights[n].TicketCost << endl;
				cout << "Кол-во мест ";
				cout << flights[n].PlacesCount << endl;
			}
		}
	
	} 
	if (sw == 2) { 
		for (int i = 0; i < current_size; i++) { 
			cout << "Номер рейса "; 
			cout << flights[i].FlightNumber << endl; 
			cout << "Пункт назначения "; 
			cout << flights[i].Destination << endl;
			cout << "Время вылета "; 
			cout << flights[i].StartTime << endl;
			cout << "Дата вылета "; 
			cout << flights[i].StartDate << endl;
			cout << "Стоимость билета "; 
			cout << flights[i].TicketCost << endl;
			cout << "Кол-во мест "; 
			cout << flights[i].PlacesCount << endl;
		} 
	} 
	cout << "Что дальше?" << endl; 
	cin >> choice;

} 

void findBy()
{
	setlocale(LC_CTYPE, "Russian");
	int forFind;
	string forFindDestination;
	string forFindDate;
	cout << "Выберите по какому полю осуществлять поиск" << std::endl;
	cout << "1-Пункт назначения" << endl;
	cout << "2-Дата вылета" << endl;
	cin >> forFind;
	if (forFind == 1)
	{
		cout << "Введите пункт назначения" << std::endl;
		cin >> forFindDestination;
		for (int i = 0; i < current_size; i++)
		{
			if (forFindDestination == flights[i].Destination)
			{
				cout << "Номер рейса "; 
				cout << flights[i].FlightNumber << endl; 
				cout << "Пункт назначения "; 
				cout << flights[i].Destination << endl;
				cout << "Время вылета "; 
				cout << flights[i].StartTime << endl;
				cout << "Дата вылета "; 
				cout << flights[i].StartDate << endl;
				cout << "Стоимость билета"; 
				cout << flights[i].TicketCost << endl;
				cout << "Кол-во мест "; 
				cout << flights[i].PlacesCount << endl;
			}
		}
	}
	if (forFind == 2)
	{
		cout << "Введите дату вылета" << endl;
		cin >> forFindDate;
		for (int i = 0; i < current_size; i++)
		{
			if (forFindDate == flights[i].StartDate)
			{
				cout << "Номер рейса "; 
				cout << flights[i].FlightNumber << endl; 
				cout << "Пункт назначения "; 
				cout << flights[i].Destination << endl;
				cout << "Время вылета "; 
				cout << flights[i].StartTime << endl;
				cout << "Дата вылета "; 
				cout << flights[i].StartDate << endl;
				cout << "Стоимость билета"; 
				cout << flights[i].TicketCost << endl;
				cout << "Кол-во мест "; 
				cout << flights[i].PlacesCount << endl;
			}
		}
	}
	cout << "Что дальше?" << endl; 
	cin >> choice;
}

int main() { 
	setlocale(LC_CTYPE, "Russian"); 
	cout << "Данных нет" << endl; 
	cout << "Введите:" << endl; 
	cout << "1-для удаления записи" << endl; 
	cout << "2-для ввода новой записи" << endl; 
	cout << "3-для изменения записи" << endl; 
	cout << "4-для вывода записи(ей)" << endl; 
	cout << "5-для поиска записи" << endl;
	cout << "6-для выхода" << endl; 
	cin >> choice; 
	do 
	{ 
		switch (choice) { 
			case 1: del(); 
			break; 
			case 2: enter_new(); 
			break; 
			case 3: change(); 
			break; 
			case 4: out(); 
			break;
			case 5: findBy(); 
			break; 
		} 
	} while (choice != 6); 
}