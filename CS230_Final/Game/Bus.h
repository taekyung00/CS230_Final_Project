#pragma once
#include "../Engine/GameObjectManager.h"
#include "../Engine/Collision.h"

#include "Constants.h"
#include "States.h"
#include "BusLine.h"

class Player;
class Bus : public CS230::GameObject {
public:
	Bus(Player* player_ptr);
	void			Update(double dt) override;
	GameObjectTypes Type() override { return GameObjectTypes::Bus; }
	std::string		TypeName() override { return "Bus"; }
	int DrawPriority() const override { return 9; }
	
	//bool			CanCollideWith(GameObjectTypes other_object_type) override;

private:
	Player* player;

	const std::vector<double> start_line = {
		0,144,288,432,576
	};

	const std::vector<double> end_line = {
		96,240,384,528,672
	};

	//const std::vector<CS230::RectCollision> can_steel_area = {
	//	{{{0,0  },	{288,96}}	,this},
	//	{{{0,144},	{288,240}}	,this},
	//	{{{0,288},	{288,384}}	,this},
	//	{{{0,432},	{288,528}}	,this},
	//	{{{0,576},	{288,672}}	,this}
	//};

	//const std::vector<CS230::RectCollision> cannot_steel_area = {
	//	{{{0,96 },	{288,144}},	this},
	//	{{{0,240},	{288,288}},	this},
	//	{{{0,384},	{288,432}},	this},
	//	{{{0,528},	{288,576}},	this},
	//	{{{0,672},	{288,720}},	this}
	//};
	
};