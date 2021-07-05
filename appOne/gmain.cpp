#include"libOne.h"

class CHARACTER { //classはデフォルトでprivate,structはpublic
protected:   //外で変数を変えることを禁止する(継承は〇)
    int Img = 0;
    float Px = 0, Py = 0, Angle = 0;
    float Vx = 0, Vy = 0, AngSpeed = 0;
public:    //プライベートに対しておおやけ



    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = width / 2;
        Py = height / 2;
        Angle = 0;
        Vx = 1;
        Vy = 1;
        AngSpeed = 0.01f;
    }
    virtual void move() {       //仮想クラス
        Angle += AngSpeed;
    }
    void draw() {
        rectMode(CENTER);
        image(Img, Px, Py, Angle);
    }
};
class PLAYER : public CHARACTER { //PLAYERをCHARACTERと同じにする
public:                           //継承されるクラスを基底クラス
    void move() {
        Px += Vx;
    }
};

class ENEMY_BULLET : public CHARACTER { 

};

class ENEMY : public CHARACTER {
/*
public:
    void move() {
        Py += Vy;
    }
*/
private:
    int Img;
    float Px, Py, Vx;
public:
    void setImage(int img) {
        Img = img;
    }
    void init() {
        Px = random() % (int)width;
        Py = random() % (int)height;
        Vx = random() % 5 + 1.0f;
    }
        void move() {
            Px += Vx;
        }
        void draw(){
            image(Img, Px, Py);
    }
};

void gmain() {
    window(1920, 1080, full);
    hideCursor();
    int enemyImg = loadImage("assets\\enemy.png");
    int num = 50;
    ENEMY* enemy = new ENEMY[num];
    for (int i = 0; i < num; i++) {
        enemy[i].setImage(enemyImg);
        enemy[i].init();
    }

    while (notQuit) {
        clear();
        for (int i = 0; i < num; i++) {
            enemy[i].move();
            enemy[i].draw();
        }
    }
    delete[] enemy;




  /*
    int playerImg = loadImage("assets\\player.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");

    PLAYER player;
    ENEMY enemy;
    ENEMY_BULLET eBullet;
    player.setImage(playerImg);
    enemy.setImage(enemyImg);
    eBullet.setImage(enemyBulletImg);

    const int num = 3;
    CHARACTER* chara[num];
    chara[0] = &player;
    chara[1] = &enemy;
    chara[2] = &eBullet;


    for (int i = 0; i < num; i++) {
       chara[i]->init();
    }
  
    while (notQuit) {
        for (int i = 0; i < num; i++) {
       chara[i]->move();
        }
        clear();
        for (int i = 0; i < num; i++) {
       chara[i]->draw();
        }


    }
  */ 
}
