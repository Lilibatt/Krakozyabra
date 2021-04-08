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
	cout << "���� ����������" << endl; 
	if (current_size < size) 
	{ 
		cout << "������ ����� "; 
		cout << current_size + 1; 
		cout << endl << "����� ����� " << endl; 
		cin >> flights[current_size].FlightNumber; 
		cout << "����� ���������� " << endl; 
		cin >> flights[current_size].Destination;
		cout << "����� ������ " << endl; 
		cin >> flights[current_size].StartTime;
		cout << "���� ������ " << endl; 
		cin >> flights[current_size].StartDate;
		cout << "��������� ������ " << endl;
		cin >> flights[current_size].TicketCost;
		cout << "���-�� ���������� ���� " << endl; 
		cin >> flights[current_size].PlacesCount; 
		current_size++; 
	} else 
		cout << "������� ������������ ���-�� �����"; 
	cout << "��� ������?" << endl; 
	cin >> choice; 
} 

void del() { 
	setlocale(LC_CTYPE, "Russian");
	int d; 
	cout << "\n����� ������, ������� ���� ������� (��� �������� ���� ����� ������� 10)" << endl; 
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
	cout << "��� ������?" << endl; 
	cin >> choice; 
} 

void change() { 
	setlocale(LC_CTYPE, "Russian");
	int n, per; 
	cout << "\n������� ����� ������" << endl; 
	cin >> n; 
	do { 
		cout << "�������: " << endl; 
		cout << "1-��� ��������� ������ �����" << endl; 
		cout << "2-��� ��������� ������ ����������" << endl; 
		cout << "3-��� ��������� ����� ������" << endl; 
		cout << "4-��� ��������� ���� ������" << endl; 
		cout << "5-��� ��������� ��������� ������" << endl; 
		cout << "6-��� ��������� ���-�� ����" << endl; 
		cout << "7-�����\n"; 
		cin >> per; 
		switch (per) 
		{ 
			case 1: cout << "����� ����� �����"; 
			cin >> flights[n - 1].FlightNumber; 
			break; 
			case 2: cout << "����� ����� ����������"; 
			cin >> flights[n - 1].Destination; 
			break; 
			case 3: cout << "����� ����� ������"; 
			cin >> flights[n - 1].StartTime; 
			break; 
			case 4: cout << "����� ���� ������"; 
			cin >> flights[n - 1].StartDate;
			break; 
			case 5: cout << "����� ��������� ������"; 
			cin >> flights[n - 1].TicketCost; 
			break; 
			case 6: cout << "����� ���-�� ����"; 
			cin >> flights[n - 1].PlacesCount; 
			break; 
		} 
	} while (per != 7); 
	cout << "��� ������?" << endl;
	cin >> choice; 
}

void out() { 
	setlocale(LC_CTYPE, "Russian");
	int sw, n; 
	int FlightNumber;
	cout << "1-����� ������ �� ������ �����" << endl; 
	cout << "2-����� ���� �����" << endl; 
	cin >> sw; 
	if (sw == 1) { 
		cout << "������� ����� �����: " << endl;
		cin >> FlightNumber;
		cout << endl;
		for (n = 0; n < panel; n++)
		{
			if (flights[n].FlightNumber == FlightNumber){
				cout << "\n ������ �����: " << n + 1;
				cout << "����� ����� ";
				cout << flights[n].FlightNumber << endl;
				cout << "����� ���������� ";
				cout << flights[n].Destination << endl;
				cout << "����� ������ ";
				cout << flights[n].StartTime << endl;
				cout << "���� ������ ";
				cout << flights[n].StartDate << endl;
				cout << "��������� ������ ";
				cout << flights[n].TicketCost << endl;
				cout << "���-�� ���� ";
				cout << flights[n].PlacesCount << endl;
			}
		}
	
	} 
	if (sw == 2) { 
		for (int i = 0; i < current_size; i++) { 
			cout << "����� ����� "; 
			cout << flights[i].FlightNumber << endl; 
			cout << "����� ���������� "; 
			cout << flights[i].Destination << endl;
			cout << "����� ������ "; 
			cout << flights[i].StartTime << endl;
			cout << "���� ������ "; 
			cout << flights[i].StartDate << endl;
			cout << "��������� ������ "; 
			cout << flights[i].TicketCost << endl;
			cout << "���-�� ���� "; 
			cout << flights[i].PlacesCount << endl;
		} 
	} 
	cout << "��� ������?" << endl; 
	cin >> choice;

} 

void findBy()
{
	setlocale(LC_CTYPE, "Russian");
	int forFind;
	string forFindDestination;
	string forFindDate;
	cout << "�������� �� ������ ���� ������������ �����" << std::endl;
	cout << "1-����� ����������" << endl;
	cout << "2-���� ������" << endl;
	cin >> forFind;
	if (forFind == 1)
	{
		cout << "������� ����� ����������" << std::endl;
		cin >> forFindDestination;
		for (int i = 0; i < current_size; i++)
		{
			if (forFindDestination == flights[i].Destination)
			{
				cout << "����� ����� "; 
				cout << flights[i].FlightNumber << endl; 
				cout << "����� ���������� "; 
				cout << flights[i].Destination << endl;
				cout << "����� ������ "; 
				cout << flights[i].StartTime << endl;
				cout << "���� ������ "; 
				cout << flights[i].StartDate << endl;
				cout << "��������� ������"; 
				cout << flights[i].TicketCost << endl;
				cout << "���-�� ���� "; 
				cout << flights[i].PlacesCount << endl;
			}
		}
	}
	if (forFind == 2)
	{
		cout << "������� ���� ������" << endl;
		cin >> forFindDate;
		for (int i = 0; i < current_size; i++)
		{
			if (forFindDate == flights[i].StartDate)
			{
				cout << "����� ����� "; 
				cout << flights[i].FlightNumber << endl; 
				cout << "����� ���������� "; 
				cout << flights[i].Destination << endl;
				cout << "����� ������ "; 
				cout << flights[i].StartTime << endl;
				cout << "���� ������ "; 
				cout << flights[i].StartDate << endl;
				cout << "��������� ������"; 
				cout << flights[i].TicketCost << endl;
				cout << "���-�� ���� "; 
				cout << flights[i].PlacesCount << endl;
			}
		}
	}
	cout << "��� ������?" << endl; 
	cin >> choice;
}

int main() { 
	setlocale(LC_CTYPE, "Russian"); 
	cout << "������ ���" << endl; 
	cout << "�������:" << endl; 
	cout << "1-��� �������� ������" << endl; 
	cout << "2-��� ����� ����� ������" << endl; 
	cout << "3-��� ��������� ������" << endl; 
	cout << "4-��� ������ ������(��)" << endl; 
	cout << "5-��� ������ ������" << endl;
	cout << "6-��� ������" << endl; 
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