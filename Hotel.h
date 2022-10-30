#pragma once
#include <string>
#include <vector>
#include <map>

class Room								// гостиничный номер/комната
{
	enum RoomType						// типы номеров
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

	int number;							// номер комнаты
	RoomType type;						// тип номера/комнаты
	bool isFree;						// свободен для заселения
	bool isNeedCleaning;				// требует уборки

public:
	void PutTheGuest();					// заселить гостя в номер
	void Release();						// освободить номер от гостей
};

class Restaurant
{
	RestaurantAdministrator admin;		// контакты администратора

public:
	std::vector<bool> tableIsFreeBase;	// база столов в формате "i-ый стол cвободен - true, занят - false"
};

class Person							// человек/личность
{
	std::string fullName;				// ФИО
	std::string phoneNumber;			// номер телефона
};

class Guest : public Person				// гость
{
	Room room;							// номер, в котором проживает гость
	Manager admin;						// контакты администратора

public:
	void Complain(Employee employee);	// пожаловаться на сотрудника
	void Encourage(Employee employee);	// поощрить сотрудника
};

class Employee : public Person			// сотрудник
{
	int experience;						// опыт работы/стаж
	int salary;							// зарплата

public:
	void Quit();						// уволиться
};

class Manager : public Employee			// управляющий
{
	std::vector<Employee> employeeBase;	// база сотрудников

public:
	void Fire(Employee employee);		// уволить сотрудника
	void IncreaseSalary(Employee employee);	// повысить зарплату
};

class HotelAdministrator : public Employee	// администратор гостиницы
{
	std::map<Guest, int> guestBase;		//база гостей "гость - номер в гостинице"

public:
	void CheckInAGuest(Guest guest);	// заселить гостя
	void CheckOutAGuest(Guest guest);	// выселить гостя
};

class RestaurantAdministrator : public Employee	// администратор ресторана
{
	std::map<Guest, int> visitorBase;	// база посетителей в соотвествии Гость отеля - заказанный стол в ресторане

public:
	void BookATable(Guest visitor);		// забронировать столик за гостем
};

class Housemaid : public Employee		// горничная
{
	std::vector<Room> rooms;			// база гостиничных номеров

public:
	void CleanUp(Room room);			// убрать в номере
};

class Accountant : public Employee		// бухгалтер
{
	std::map<Room, int> roomPrice;		// прайс номеров отеля
	std::map<int, int> tablePrice;		// прайс столиков ресторана

public:
	int СalculateProfit();				// посчитать прибыль
};