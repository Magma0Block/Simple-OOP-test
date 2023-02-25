#include <iostream>
#include <string>
using namespace std;

class Point {
 public:
  int x, y;
};

class Character {
 private:
  string name;
  int max_hp, hp;
  int damage;
  int defence;
  bool isalive = 1;
  Point position;

 public:
  void setname(string s) { name = s; }

  void setmaxhp(int h) {
    if (h <= 0) h = 1;
    max_hp = h;
  }
  void sethp(int h) {
    if (h < 0) {
      h = 0;
      isalive = 0;
    }
    if (h > max_hp) h = max_hp;
    hp = h;
  }

  void setdefence(int x) {
    if (x < 0) x = 0;
    defence = x;
  }
  void setdamage(int x) {
    if (x < 1) x = 0;
    damage = x;
  }
  void setposition(Point a) {
    position.x = a.x;
    position.y = a.y;
  }

  Point getposition() { return position; }
  string getname() { return name; }
  int getmaxhp() { return max_hp; }
  int gethp() { return hp; }
  int getdefence() { return defence; }
  int getdamage() { return damage; }
  bool getdeadorlive() { return isalive; }
  void getstatus() {
    cout << "Name: " << name << endl << "Status: ";
    if (isalive)
      cout << "alive" << endl;
    else
      cout << "died" << endl;
    cout << "HP: " << hp << "/" << max_hp << endl
         << "Damage: " << damage << endl
         << "Defence: " << defence << endl
         << "Position: (" << position.x << ", " << position.y << ")" << endl;
  }
  void update() {
    if (position.x == 0 && position.y == 0) {
      sethp(max_hp);
    } else if (position.x < 0 && position.y > 0) {
      sethp(hp - 5);
      setdamage(damage - 1);
    } else if (position.x < 0 && position.y < 0) {
      if (defence > 100) sethp(hp - 2);
    }
    if (position.x > 0 && position.y < 0) {
      setdefence(defence + 1);
    }
  }
};

int main() {
  Character Oleg;
  Point os;
  int maxhp_input, hp_input, damage_input, defence_input, x, y;
  string name_input;
  cin >> name_input >> maxhp_input >> hp_input >> damage_input >>
      defence_input >> os.x >> os.y;
  Oleg.setmaxhp(maxhp_input);
  Oleg.sethp(hp_input);
  Oleg.setname(name_input);
  Oleg.setdamage(damage_input);
  Oleg.setdefence(defence_input);
  Oleg.setposition(os);

  //Фаза работы

  string cmd;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cmd;
    if (cmd == "status") {
      Oleg.getstatus();
    } else if (cmd == "move") {
      int x1, y1;
      cin >> x1 >> y1;
      if (Oleg.getdeadorlive()) {
        os.x = x1;
        os.y = y1;
        Oleg.setposition(os);
        Oleg.update();
      }
    }
  }
  return 0;
}
