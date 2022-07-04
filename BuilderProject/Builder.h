#pragma once
#include "Unit.h"

class Builder
{
protected:
	Unit* unit;
public:
	virtual Builder* SetSword() {};
	virtual Builder* SetSpear() {};
	virtual Builder* SetShild()
	{
		unit->SetEquipment("shild");
	};



	Unit* GetUnit()
	{
		Unit* unitResult = unit;
		unit = new Infantry();

		return unitResult;
	}

};

class BuilderInfantry : public Builder
{
public:
	BuilderInfantry()
	{
		this->unit = new Infantry();
	}

	Builder* SetSword() override
	{
		this->unit->SetEquipment("sword");
		return this;
	}

	Builder* SetSpear() override
	{
		this->unit->SetEquipment("spear");
		return this;
	}

	Builder* SetShild() override
	{
		this->unit->SetEquipment("infantry shild");
		return this;
	}
};
