#pragma once
class GameBase {
public:
	int Pointer_Origin;
protected:
};
class Gameinstance : public GameBase {
public:
	char Fname; // Game instance name , initalise for an array of Fname[ncharacters_max];
	int Veiwport_x; // Current resolution x
	int Veiwport_y; // Current resolution y
protected:
	int Gnameid;

};
class Uworld : public GameBase {
public:
	char gameid; // instance of the game id (used to identify users and current game version)
	int relativeorigin_x; // The origin vecotor to offset from. "Center of the world spawn"
	int relativeorigin_y;
	int relativeorigin_z;
protected:
	int initGamestate() {}
};
class GameState :public Uworld {
public:
	double x, y, z; // Exit State Game relative vector position

};
class LocalPlayer : public Uworld {
public:
	double x, y, z; //Current local player position relative to origin/ 0 vecotor
	int health;
	int stam;
	int team;
	// initalise properties here of each character 
protected:
	int look_movement() {} // Looks for key state to determine if to move
	double Player_move() {} // Returns new vect 3 if movement occurs
	double Relative_Position(double x, double y, double z) {} // Returned from player move with new x,y,z
	bool Player_State(int Relative_Pos) {} // 
	double Camera_Angle() {} // returns the vector of the relative camera angle in vect 3 and direction to current local player 
	double Player_Angle() {} // rotates the player relative to look_movement returned values
};

class Player_World : public LocalPlayer {

public: 
	int Veiw_y; // is the relative position to the screen of your x and y
	int Veiw_x;
};
class Actor : public Uworld {
public:
	int Nactors; // number of people in public lobby
	double actors_pos[999][3];
	//reinit properties for each actor in 999 array ie: int health[999]; is for each actor
protected:
	// Same functions as the local player ie:
	// int Actor_Camera_Angle(){}
};
class Items : Actor {

public:
	int dropped_item_count;
	int itemid[999]; // each dropped item has a id
	int item_name[999];// is the name / assigned properties of that item.
	int itempos[999][3]; // position of the item in the relative 3D world 
	// is called in the other game instance, such that a class inherits items 
	// and will be able to assign preset properties of that item given a id and name
protected:
	void OnItemDrop() {}
	int GenerateItemID() {}
};