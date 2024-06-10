#include <iostream>
#include <string>
class ClapTrap {
public:
  ClapTrap(const std::string &name)
      : m_name(name), m_hp(initial_hp), m_energy(initial_energy),
        m_damage(initial_damage) {
    std::cout << "CTOR CLAPTRAP\n";
  }
  // Destructor should be virtual
  // See ISO CPP core guidelines item C.127
  virtual ~ClapTrap() { std::cout << "DTOR CLAPTRAP\n"; }

  virtual void attack(const std::string &target) {
    if (!canAct()) {
      std::cout << "ClapTrap " << name() << " is unable to attack " << target
                << "!\n";
      return;
    }
    std::cout << "ClapTrap " << name() << " attacks " << target << ", causing "
              << damage() << " points of damage!\n";
    reduceEnergy();
  }

  void takeDamage(unsigned int amount) {
    if (amount > m_hp) {
      m_hp = 0;
    } else {
      m_hp -= amount;
    }
    std::cout << "ClapTrap " << m_name << " takes " << amount << " damage!\n";
  }

  void beRepaired(unsigned int amount) {
    if (!canAct()) {
      std::cout << "ClapTrap " << m_name << " is unable to repair itself!\n";
      return;
    }
    m_hp += amount;
    std::cout << "ClapTrap " << m_name << " repairs itself for " << amount
              << " points!\n";
    reduceEnergy();
  }

protected:
  const std::string &name() { return m_name; }

  void setName(const std::string &name) { m_name = name; }

  unsigned int hp() { return m_hp; }

  void setHp(unsigned int hp) { m_hp = hp; }

  unsigned int energy() { return m_energy; }

  void setEnergy(unsigned int energy) { m_energy = energy; }

  unsigned int damage() { return m_damage; }

  void setDamage(unsigned int damage) { m_damage = damage; }

  ClapTrap(const std::string &name, unsigned int hp, unsigned int energy,
           unsigned int damage)
      : m_name(name), m_hp(hp), m_energy(energy), m_damage(damage) {
    std::cout << "CTOR CLAPTRAP\n";
  }

  void reduceEnergy()
  {
      --m_energy;
  }

  bool canAct()
  {
      return m_hp != 0 && m_energy != 0;
  }

  static const unsigned int initial_hp = 10;
  static const unsigned int initial_energy = 10;
  static const unsigned int initial_damage = 0;

private:
  // Explicitly disabled, counts as OCF
  // See ISO CPP core guidelines item C.67
  ClapTrap(const ClapTrap &);
  ClapTrap &operator=(const ClapTrap &);

  std::string m_name;
  unsigned int m_hp;
  unsigned int m_energy;
  unsigned int m_damage;

};

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(const std::string &name)
      : ClapTrap(name, initial_hp, initial_energy, initial_damage) {
    std::cout << "CTOR SCAVTRAP\n";
  }

  // Destructor should be virtual
  // See ISO CPP core guidelines item C.127
  virtual ~ScavTrap() { std::cout << "DTOR SCAVTRAP\n"; }

  virtual void attack(const std::string &target) {
    if (energy() == 0 || hp() == 0) {
      std::cout << "ScavTrap " << name() << " is unable to attack " << target
                << "!\n";
      return;
    }
    std::cout << "ScavTrap " << name() << " attacks " << target << ", causing "
              << damage() << " points of damage!\n";
    setEnergy(energy() - 1);
  }

  void guardGate() {
    std::cout << "ScavTrap " << name() << " is now in Gatekeeper mode!\n";
  }

protected:
  static const unsigned int initial_hp = 100;
  static const unsigned int initial_energy = 50;
  static const unsigned int initial_damage = 20;

private:
  // Explicitly disabled, counts as OCF
  // See ISO CPP core guidelines item C.67
  ScavTrap(const ScavTrap &);
  ScavTrap &operator=(const ScavTrap &);
};

class FragTrap : virtual public ClapTrap {
public:
  FragTrap(const std::string &name)
      : ClapTrap(name, initial_hp, initial_energy, initial_damage) {
    std::cout << "CTOR FRAGTRAP\n";
  }
  // Destructor should be virtual
  // See ISO CPP core guidelines item C.127
  virtual ~FragTrap() { std::cout << "DTOR FRAGTRAP\n"; }

  virtual void attack(const std::string &target) {
    if (energy() == 0 || hp() == 0) {
      std::cout << "FragTrap " << name() << " is unable to attack " << target
                << "!\n";
      return;
    }
    std::cout << "FragTrap " << name() << " attacks " << target << ", causing "
              << damage() << " points of damage!\n";
    setEnergy(energy() - 1);
  }

  void highFivesGuys() {
    std::cout << "FragTrap " << name() << " requests a high fives!\n";
  }

protected:
  static const unsigned int initial_hp = 100;
  static const unsigned int initial_energy = 100;
  static const unsigned int initial_damage = 30;

private:
  // Explicitly disabled, counts as OCF
  // See ISO CPP core guidelines item C.67
  FragTrap(const FragTrap &);
  FragTrap &operator=(const FragTrap &);
};

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap(const std::string &name)
      : ClapTrap(name + "_clap_name", initial_hp, initial_energy,
                 initial_damage),
        FragTrap(name), ScavTrap(name), m_name(name) {
    std::cout << "CTOR DIAMONDTRAP\n";
  }

  virtual void attack(const std::string &target) { ScavTrap::attack(target); }

  void whoAmI() {
    std::cout << "name: " << m_name << ", claptrap name: " << name() << "\n";
    std::cout << "hp: " << hp() << "\n";
    std::cout << "energy: " << energy() << "\n";
    std::cout << "damage: " << damage() << "\n";
  }

protected:
  static const unsigned int initial_hp = FragTrap::initial_hp;
  static const unsigned int initial_energy = ScavTrap::initial_energy;
  static const unsigned int initial_damage = FragTrap::initial_damage;

private:
  std::string m_name;
};

int main() {
  // ClapTrap c1("Jean-Michel");
  // ClapTrap c2("Hubert");
  //
  // c1.attack("Hubert");
  // c2.takeDamage(10);
  // c1.beRepaired(5);
  //
  // for (int i = 0; i < 15; ++i) {
  //   c1.beRepaired(10);
  // }
  //
  // ScavTrap s1("Paul");
  // s1.attack("Michou");
  // s1.guardGate();
  //
  // FragTrap f1("Bite");
  // f1.highFivesGuys();

  DiamondTrap d1("chatte");
  d1.whoAmI();
  return 0;
}
