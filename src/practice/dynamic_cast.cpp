//
// Created by 14771 on 2024/10/9.
//

class Entity{
    //dynamic——cast转换需要虚函数
public:
    virtual void Print(){}
};
class Player: public Entity {

};
class Enemy: public Entity{

};

int main(){
    Player* player = new Player();
    Entity* e = player;
    Entity* e1 = new Enemy();

    Player* p1 = dynamic_cast<Player*>(e);
    Player* p = dynamic_cast<Player*>(e1);
}
