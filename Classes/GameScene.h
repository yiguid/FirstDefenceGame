#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class GameScene : public cocos2d::CCLayer
{
public:
	GameScene();
	~GameScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();

    // implement the "static node()" method manually
    CREATE_FUNC(GameScene);

	void loadTowerPositions();
	bool canBuyTower();
	void addWaypoints();
	bool collisionWithCircle(cocos2d::CCPoint circlePoint, float radius, cocos2d::CCPoint circlePointTwo, float radiusTwo);
	bool loadWave();
	void enemyGotKilled();
	void getHpDamage();
	void doGameOver();
	void awardGold(int gold);

	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

	CC_SYNTHESIZE_RETAIN(cocos2d::CCArray*, _towers, Towers);
	CC_SYNTHESIZE_RETAIN(cocos2d::CCArray*, _waypoints, Waypoints);
	CC_SYNTHESIZE_RETAIN(cocos2d::CCArray*, _enemies, Enemies);

private:
	cocos2d::CCArray* towerBases;
	int wave;
	cocos2d::CCLabelBMFont* ui_wave_lbl;
	int playerHp;
	cocos2d::CCLabelBMFont *ui_hp_lbl;
	bool gameEnded;
	int playerGold;
	cocos2d::CCLabelBMFont *ui_gold_lbl;
};

#endif  // __GAME_SCENE_H__