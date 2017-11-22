#include <string>
#pragma once

class Pokemon{
  private :

  int m_hp;
  int m_attackLevel;
  int m_defenseLevel;
  std::string m_name;

  public:

  Pokemon();

  void reduceHP(int &amount);

  void setHP(int &newHP);
  int getHP() const;

  void setAttackLevel(int &newAttackLevel);
  int getAttackLevel() const;

  void setDefenseLevel(int &newDefenseLevel);
  int getDefenseLevel() const;

  void setName(std::string &newName);
  std::string getName() const;
};
