#pragma once
#include <string>
#include <vector>
#include <map>

class Room								// ����������� �����/�������
{
	enum RoomType						// ���� �������
	{
		Single,
		Double,
		Standart,
		Apartment,
		Suite,
		FamilyRoom,
		DeLuxe,
		President
	};

	int number;							// ����� �������
	RoomType type;						// ��� ������/�������
	bool isFree;						// �������� ��� ���������
	bool isNeedCleaning;				// ������� ������

public:
	void PutTheGuest();					// �������� ����� � �����
	void Release();						// ���������� ����� �� ������
};

class Restaurant
{
	RestaurantAdministrator admin;		// �������� ��������������

public:
	std::vector<bool> tableIsFreeBase;	// ���� ������ � ������� "i-�� ���� c������� - true, ����� - false"
};

class Person							// �������/��������
{
	std::string fullName;				// ���
	std::string phoneNumber;			// ����� ��������
};

class Guest : public Person				// �����
{
	Room room;							// �����, � ������� ��������� �����
	Manager admin;						// �������� ��������������

public:
	void Complain(Employee employee);	// ������������ �� ����������
	void Encourage(Employee employee);	// �������� ����������
};

class Employee : public Person			// ���������
{
	int experience;						// ���� ������/����
	int salary;							// ��������

public:
	void Quit();						// ���������
};

class Manager : public Employee			// �����������
{
	std::vector<Employee> employeeBase;	// ���� �����������

public:
	void Fire(Employee employee);		// ������� ����������
	void IncreaseSalary(Employee employee);	// �������� ��������
};

class HotelAdministrator : public Employee	// ������������� ���������
{
	std::map<Guest, int> guestBase;		//���� ������ "����� - ����� � ���������"

public:
	void CheckInAGuest(Guest guest);	// �������� �����
	void CheckOutAGuest(Guest guest);	// �������� �����
};

class RestaurantAdministrator : public Employee	// ������������� ���������
{
	std::map<Guest, int> visitorBase;	// ���� ����������� � ����������� ����� ����� - ���������� ���� � ���������

public:
	void BookATable(Guest visitor);		// ������������� ������ �� ������
};

class Housemaid : public Employee		// ���������
{
	std::vector<Room> rooms;			// ���� ����������� �������

public:
	void CleanUp(Room room);			// ������ � ������
};

class Accountant : public Employee		// ���������
{
	std::map<Room, int> roomPrice;		// ����� ������� �����
	std::map<int, int> tablePrice;		// ����� �������� ���������

public:
	int �alculateProfit();				// ��������� �������
};