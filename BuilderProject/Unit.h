#pragma once
#include <iostream>
#include <vector>

enum class UnitID {
	Infantry,
	Archer,
	Cavalery,
	Special,
	Elephant,
	Catapult,
	Tank,
	Saper
};

class Unit
{
protected:
	UnitID id;
	std::string title;

	int attack;
	int defends;
	int health;

	std::vector<std::string> equipment;

public:
	Unit(UnitID id) : id{ id } {}
	virtual std::string Info() = 0;
	void SetEquipment(std::string equip)
	{
		equipment.push_back(equip);
	}

	void PrintEquipment()
	{
		for (std::string equip : equipment)
			std::cout << equip << "\n";
	}
};

std::string UnitName[]{ "Infantry", "Archer", "Cavalery" };

class Infantry : public Unit
{
public:
	Infantry() : Unit(UnitID::Infantry)
	{
		attack = 50;
		defends = 30;
		health = 100;
		title = UnitName[(int)id];
	}
	std::string Info() override
	{
		return title;
	}
};

class Archer : public Unit
{
public:
	Archer() : Unit(UnitID::Archer)
	{
		attack = 60;
		defends = 20;
		health = 100;
		title = UnitName[(int)id];
	}
	std::string Info() override
	{
		return title;
	}
};

class Cavalery : public Unit
{
public:
	Cavalery() : Unit(UnitID::Cavalery)
	{
		attack = 70;
		defends = 40;
		health = 100;
		title = UnitName[(int)id];
	}
	std::string Info() override
	{
		return title;
	}
};

