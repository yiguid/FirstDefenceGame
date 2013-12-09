#ifndef __WAYPOINT_H__
#define __WAYPOINT_H__

#include "cocos2d.h"
#include "GameScene.h"

class Waypoint : public cocos2d::CCNode
{
public:
	Waypoint(void);
	~Waypoint(void);

	static Waypoint* nodeWithTheGame(GameScene* game, cocos2d::CCPoint location);
	bool initWithTheGame(GameScene* game, cocos2d::CCPoint location);

	void draw(void);

	CC_SYNTHESIZE(cocos2d::CCPoint, _myPosition, MyPosition);
	CC_SYNTHESIZE(Waypoint*, _nextWaypoint, NextWaypoint);

private:
	GameScene* theGame;
};

#endif  // __WAYPOINT_H__