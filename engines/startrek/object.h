/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARTREK_OBJECT_H
#define STARTREK_OBJECT_H

#include "startrek/common.h"
#include "startrek/fixedint.h"
#include "startrek/items.h"
#include "startrek/sprite.h"

#include "common/scummsys.h"

namespace StarTrek {

class StarTrekEngine;
class FileStream;
class Room;


// Objects 0-31 are "actors" that are drawn to the screen, are animated, etc.
// Objects 32-63 are "hotspots" corresponding to specific regions in the screen.
// Objects 64+ are "items".
// All interactions in the game consist of specific object indices interacting with each
// other, ie. object 0 (kirk) interacts with object 32 (a hotspot) via ACTION_LOOK.

const int ACTORS_START = 0;
const int SCALED_ACTORS_END = 8; // Only first 8 actors have room scaling applied?
const int ACTORS_END = 32;
const int NUM_ACTORS = ACTORS_END - ACTORS_START;

const int HOTSPOTS_START = 32;
const int HOTSPOTS_END = 64;
const int NUM_HOTSPOTS = HOTSPOTS_END - HOTSPOTS_START;

const int ITEMS_START = 64;
const int ITEMS_END = ITEMS_START + NUM_ITEMS; // See items.h

const int NUM_OBJECTS = ITEMS_END;


enum Directions {
	DIR_N = 0,
	DIR_S = 1,
	DIR_E = 2,
	DIR_W = 3
};

// Some object indices are reserved (see items.h for item objects)
enum Objects {
	OBJECT_KIRK = 0,
	OBJECT_SPOCK = 1,
	OBJECT_MCCOY = 2,
	OBJECT_REDSHIRT = 3,
	OBJECT_INVENTORY_ICON = 31
};


struct Actor {
	bool spriteDrawn;
	char animFilename[16];
	uint16 animType;
	Sprite sprite;
	char bitmapFilename[10];
	Fixed16 scale;
	SharedPtr<FileStream> animFile;
	uint16 numAnimFrames;
	uint16 animFrame;
	uint32 frameToStartNextAnim;
	Common::Point pos;
	uint16 field60;
	uint16 field62;

	// When an object finished walking somewhere or finishes an animation, if
	// "triggerActionWhenAnimFinished" is true, it will create an action of type
	// "ACTION_FINISHED_WALKING" or "ACTION_FINISHED_ANIMATION", with the integer value
	// "finishedAnimActionParam".
	bool triggerActionWhenAnimFinished;
	uint16 finishedAnimActionParam;

	char animationString2[8];
	uint16 field70;
	uint16 field72;
	uint16 field74;
	uint16 field76;
	int16 iwSrcPosition;
	int16 iwDestPosition;

	// Fixed-point position values (16.16) used while walking.
	Fixed32 granularPosX;
	Fixed32 granularPosY;

	// Fixed-point speed values (16.16).
	Fixed32 speedX;
	Fixed32 speedY;

	Common::Point dest; // Position object is walking toward
	uint16 field90;
	byte field92;

	// Can 'n', 's', 'e', 'w', or 0 for uninitialized?
	// Can also be capitalized?
	char direction;

	uint16 field94;
	uint16 field96;

	char animationString[10];

	// These might be part of "animationString"?
	uint16 fielda2;
	uint16 fielda4;
	uint16 fielda6;

public:
	Actor() :
		spriteDrawn(),
		//animFilename[16],
		animType(),
		sprite(),
		//bitmapFilename[10],
		scale(),
		animFile(),
		numAnimFrames(),
		animFrame(),
		frameToStartNextAnim(),
		pos(),
		field60(),
		field62(),
		triggerActionWhenAnimFinished(),
		finishedAnimActionParam(),
		//animationString2[8](),
		field70(),
		field72(),
		field74(),
		field76(),
		iwSrcPosition(),
		iwDestPosition(),
		granularPosX(),
		granularPosY(),
		speedX(),
		speedY(),

		dest(),
		field90(),
		field92(),

		direction(),
		field94(),
		field96(),
		//char animationString[10];

		fielda2(),
		fielda4(),
		fielda6()
		{
			memset(animFilename, 0, sizeof(animFilename));
			memset(bitmapFilename, 0, sizeof(bitmapFilename));
			memset(animationString2, 0, sizeof(animationString2));
			memset(animationString, 0, sizeof(animationString));
		}

};

}

#endif

