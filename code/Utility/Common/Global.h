#pragma once

//name constant definition
#define PLAYER 1
#define NORMALNPC 2
#define BOSSNPC 3
#define PLAYERBULLET 4
#define NPCBULLET 5
#define UNIDENTIFIED -1

//size constant values
//need to be changed according to image resources and so on
#define PLAYERWIDTH 1
#define PLAYERHEIGHT 2
#define NORMALNPCWIDTH 3
#define NORMALNPCHEIGHT 4
#define BOSSNPCWIDTH 5
#define BOSSNPCHEIGHT 6
#define PLAYERBULLETWIDTH 7
#define PLAYERBULLETHEIGHT 8
#define NPCBULLETWIDTH 9
#define NPCBULLETHEIGHT 10
#define NONEWIDTH -1
#define NONEHEIGHT -1

//scene size setting
//need further changes
#define SCENEWIDTH 1000;
#define SCENEHEIGHT 2000;

//game parameter constant values
#define NORMALNPCSPEED 1
#define BOSSNPCSPEED 2
#define PLAYERSPEED 3
#define BULLETSPEED 4
#define NONESPEED -1

#define NORMALNPCBLOOD 1
#define BOSSNPCBLOOD 2
#define PLAYERBLOOD 3
#define NONEBLOOD -1

#define NORMALNPCFIREPOWER 1
#define BOSSNPCFIREPOWER 2
#define PLAYERFIREPOWER 3
#define NONEFIREPOWER -1

//coordinate the spatial relationship between player aircraft and its bullets
#define PLAYERBULLETWIDTHOFFSET 10.0
#define PLAYERBULLETHEIGHTOFFSET 10.0
#define NORMALNPCBULLETWIDTHOFFSET 10.0
#define NORMALNPCBULLETHEIGHTOFFSET 10.0
#define BOSSNPCBULLETWIDTHOFFSET 10.0
#define BOSSNPCBULLETHEIGHTOFFSET 10.0

//Data definition
typedef enum { Pos, Neg, Neither } MOVEDIRECTION;
