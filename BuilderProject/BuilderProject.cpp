#include <iostream>
#include "Builder.h"

class DirectorSword
{
    Builder* builder;
public:
    DirectorSword()
    {
        builder = new BuilderInfantry();
    }
    Unit* GetUnit()
    {
        builder->SetShild();
        builder->SetSword();
        return builder->GetUnit();
    }

    Unit* operator()()
    {
        builder->SetShild();
        builder->SetSword();
        return builder->GetUnit();
    }
};

int main()
{
    Builder* builder;

    builder = new BuilderInfantry();

    Unit* unitInfantry = builder->SetShild()->SetSpear()->GetUnit();
    std::cout << "spearman:\n";
    unitInfantry->PrintEquipment();

    Unit* unitSuper = builder->SetShild()->SetSpear()->SetSword()->GetUnit();
    std::cout << "\nsuper:\n";
    unitSuper->PrintEquipment();

    std::cout << "\nswordman:\n";
    DirectorSword directorSword;
    Unit* swordman = directorSword();
    swordman->PrintEquipment();

    return 0;
}
