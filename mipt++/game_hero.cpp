#include <iostream>

class Game_Hero{
    public:
    Game_Hero(int health_ = 10, bool isZomb_ = 0): health(health_), isZomb(isZomb_) {}
    bool isDead() {
        return !isAlive;
    }
    int livePoints() {
        return health;
    }
    void damage(int damage = 5) {
        health -= damage;
        if (health <= 0) {
            isAlive = 0;
        }
    }
    void heal(int healHealth = 3) {
        health += healHealth;
        if (health > 0 && isZomb == 1) {
            isAlive = 1;
        }
    }
    private:
    int health;
    bool isAlive = 1;
    bool isZomb;
};