#include <iostream>
#include <string>

class moveable{
    public :
        int xposition;
        int yposition;
        int hitpoint = 100;
        std::string nama;

        moveable(){
            xposition = 30;
            yposition = 50;
            hitpoint = 100;
            nama = "x";
        }

        int getHp(){
            return hitpoint;
        }

        void setDMG(int h){
            hitpoint = h;
        }

        void setnama(std::string nama){
            this->nama = nama;
            std::cout << "Nama : " << nama << std::endl;
        }

        void move(int x, int y){
            xposition += x; 
            yposition += y; 
        };
};

class attackable : virtual public moveable{
    public :
        attackable() : moveable(){}
        int attackpower = 10;
        void attack(moveable& target){
            target.setDMG(target.getHp() - attackpower);
            std::cout<< "Health sisa " << target.nama << ": " << target.getHp() << std::endl;
        }
};

class defendable : virtual public moveable{
    public :
        defendable() : moveable(){}
        int Defensepower = 2;
        int Defense() {
            return Defensepower;
        }
};

class warrior : public attackable{
    public:
        warrior(){}
        std::string nama;
        void setnama(std::string nama){
            this -> nama = nama;
            std::cout << "Nama : " << nama << std::endl;
        }
};

class healer : public defendable{
    public : 
        healer(){}
        std::string nama;
        void setnama(std::string nama){
            this->nama = nama;
            std::cout << "Nama : " << nama << std::endl;
        }
        int heal = 0;
        void healingpower(int hlt){
            this->heal += hlt;  
        }
        void xheal(moveable& target){
            target.setDMG(target.getHp() + heal);
            std::cout<< "Health sisa " << target.nama << ": " << target.getHp() << std::endl;
        }
};

class mage : public attackable , public defendable{
    public :
        mage(){}
        std::string nama;
        void setnama(std::string nama){
            this->nama = nama;
            std::cout << "Nama : " << nama << std::endl;
        }
};

int main(){
    warrior Fighter;
    healer Support;
    mage explode;
    Support.moveable::setnama("Aqua");
    Fighter.moveable::setnama("Kazuma");
    explode.moveable::setnama("Megumin");

    Fighter.attack(explode);
    Support.healingpower(8);
    Support.xheal(explode);

    while (Fighter.getHp() > 0 && explode.getHp() > 0) {
        Fighter.attack(explode);
        if (explode.getHp() > 0) {
            explode.attack(Fighter);
        }

        std::cout << "Player: " << Fighter.getHp();
        std::cout << "\nMonster: " << explode.getHp();
        std::cout << std::endl;
    }

    if (Fighter.getHp() > 0) {
        std::cout << "Fighter menang!" << std::endl;
    } else {
        std::cout << "Mage menang!" << std::endl;
    }
    return 0;
}
