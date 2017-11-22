#include "Pokemon.h"
#include <string>

Pokemon::Pokemon(){
  m_hp = 0;
  m_attackLevel = 0;
  m_defenseLevel = 0;
  m_name = "";
}

void Pokemon::reduceHP(int &amount){
  m_hp = m_hp - amount;
  if (m_hp < 0){
      m_hp = 0;
  }
}

void Pokemon::setHP(int &newHP){
  m_hp = newHP;
}

void Pokemon::setAttackLevel(int &newAttackLevel){
  m_attackLevel = newAttackLevel;
}

void Pokemon::setDefenseLevel(int &newDefenseLevel){
  m_defenseLevel = newDefenseLevel;
}

void Pokemon::setName(std::string &newName){
  m_name = newName;
}

int Pokemon::getHP() const{
  return(m_hp);
}

int Pokemon::getAttackLevel() const{
  return(m_attackLevel);
}

int Pokemon::getDefenseLevel() const{
  return(m_defenseLevel);
}

std::string Pokemon::getName() const{
  return(m_name);
}
