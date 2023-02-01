#include <iostream>
#include <string>

int* champSelect(int x);


std::string champList[] = { "Master Yi", "Shyvana", "Garen" };
int MasterYi[] = { 500, 68 };
int Shyvana[] = { 670, 80 };
int Garen[] = { 550, 72 };

class Player {
private:
	std::string name;
	//std::string status;
	int id;
	int hp;
	int dmg;
public:
	Player(std::string x) {
		std::string name = x;
		//std::string status;
		int id;
		int hp;
		int dmg;
	}
	void setId(int x) {
		id = x;
	}
	void setStats(int x[]) {
		hp = x[0];
		dmg = x[1];
	}
	int getHp() {
		return hp;
	}
	int getDamage() {
		return dmg;
	}
	int getId() {
		return id;
	}
	std::string getName() {
		return name;
	}

	//interaction functions
	
	void takeDamage(int x) { 
		hp -= x;
	}
	
	int doMove(int hero, char move) { //hero = getid
		switch (move) {
		case 'a':
			return dmg;
		}
	}

	
};

void moveset(Player x);


int main() {
	
	Player p1("p1");
	Player p2("p2");
	

	int p1CInput;
	int p2CInput;
	
	char p1MInput;
	char p2MInput;
	
	// displaying champ picks
	
	std::cout << "P1 choose:\n";
	for (int i = 0; i < 3; ++i) {										//idk
		std::cout << i << ": " << champList[i] << "\n";
	}
	std::cin >> p1CInput;
	std::cout << "P1: " << champList[p1CInput]<<"\n\n";
	
	std::cout << "P2 choose:\n";
	for (int i = 0; i < 3; ++i) {										//idk
		std::cout << i << ": " << champList[i] << "\n";
	}
	std::cin >> p2CInput;
	std::cout << "P2: " << champList[p2CInput] << "\n\n";

	//setup

	p1.setStats(champSelect(p1CInput));
	p1.setId(p1CInput);
	p2.setStats(champSelect(p2CInput));
	p2.setId(p2CInput);

	//display and input moves

	moveset(p1);
	std::cin >> p1MInput;
	moveset(p2);
	std::cin >> p2MInput;
	
	p2.takeDamage(p1.doMove(p1.getId(),p1MInput));
	p1.takeDamage(p2.doMove(p2.getId(), p2MInput));

	std::cout << p2.getHp();
}

int* champSelect(int x) { //the player object's id
	
	switch (x) {
	case 0:
		return MasterYi;
	case 1:
		return Shyvana;
	case 2:
		return Garen;
	}
}

void moveset(Player x) { //the player object
	
	std::cout << x.getName() << champList[x.getId()] << " (HP: " << x.getHp() << ")" << "'s turn:\n";
	std::cout << "a. Attack (" << x.getDamage() << ")\n\n";
}

