/*
    This file is part of mhw-save-editor.

    mhw-save-editor is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    mhw-save-editor is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with mhw-save-editor.  If not, see <https://www.gnu.org/licenses/>.
 * */

#ifndef _LAYOUT_BIN_H_
#define _LAYOUT_BIN_H_

#define PACKED	__attribute__((packed))

namespace layout_bin {

	struct hunterapp {
		uint32_t	makeup2color;
		float		makeup2posx;
		float     	makeup2posy;
		float     	makeup2sizex;
		float     	makeup2sizey;
		float     	makeup2glossy;
		float     	makeup2metallic;
		uint32_t     	makeup2type;
		uint32_t     	makeup1color;
		float     	makeup1posx;
		float     	makeup1posy;
		float     	makeup1sizex;
		float     	makeup1sizey;
		float     	makeup1gloss;
		float     	makeup1metallic;
		uint32_t     	makeup1type;
		uint32_t     	lefteyecolor;
		uint32_t     	righteyecolor;
		uint32_t     	eyebrowcolor;
		uint32_t     	facialhaircolor;
		uint8_t      	eyewidth;
		uint8_t      	eyeheight;
		uint8_t     	skincolorx;
		uint8_t     	skincolory;
		uint8_t     	age;
		uint8_t     	wrinkles;
		uint8_t      	noseheight;
		uint8_t      	mouthheight;
		uint32_t     	gender;
		uint8_t     	browtype;
		uint8_t     	facetype;
		uint8_t     	eyetype;
		uint8_t     	nosetype;
		uint8_t     	mouthtype;
		uint8_t     	eyebrowtype;
		uint8_t     	eyelashlength;
		uint8_t     	facialhairtype;
		uint8_t     	unused[4];
		uint32_t     	haircolor;
		uint32_t     	clothingcolor;
		uint16_t    	hairtype;
		uint8_t     	clothingtype;
		uint8_t     	voice;
		uint32_t     	expression;
	} PACKED;

	struct palicoapp {
		uint32_t	patterncolor1;
		uint32_t	patterncolor2;
		uint32_t	patterncolor3;
		uint32_t	furcolor;
		uint32_t	lefteyecolor;
		uint32_t	righteyecolor;
		uint32_t	clothingcolor;
		float		furlength;
		float		furthickness;
		uint8_t		patterntype;
		uint8_t		eyetype;
		uint8_t		eartype;
		uint8_t		tailtype;
		uint16_t	voicetype;
		uint16_t	voicepitch;
	} PACKED;

	struct charinfo {
		uint8_t		name_utf8[64];
		uint32_t	rank;
		uint32_t	zenny;
		uint32_t	res_points;
		uint32_t	xp;
		uint32_t	playtime;
		uint8_t		unknown0[4];
		hunterapp	hunter;
		palicoapp	palico;
	} PACKED;

	struct monsterqstats {
		uint16_t	captured[64]; // as of now we have 34 monsters - these are listed as appear in the chief ecologist dialogue
		uint16_t	killed[64];
	} PACKED;

	struct monsterfstats {
		uint32_t	total_captured[128]; //not sure about the indexes... for example idx 18 is Teostra, 25 is Nergi, ...
		uint32_t	total_killed[128];
		uint32_t	tempered_killed[128];
	} PACKED;

	struct itemlist {
		uint32_t	id;
		uint32_t	number;
	} PACKED;

	struct itemloadouts {
		struct loadout {
			struct       shortcuts {
				struct items {
					uint32_t	category_id;
					uint32_t	entry_id;
					uint32_t        unknown;
				} PACKED;
				uint8_t	name_utf8[32];
				items	circle[8];
			} PACKED;
			uint8_t		name_utf8[32];
			itemlist	default_pouch_items[24];
			itemlist	default_pouch_ammo[16];
			uint8_t		unknown0[264];
			shortcuts	top_left_right_bottom[4];
		} PACKED;

		loadout		list[56];
		uint8_t		sort_idx[56];
	} PACKED;

	struct itemcontainers {
		itemlist	pouch_item[24];
		itemlist	pouch_ammo[16];
		uint8_t		unknown0[288];
		itemlist	box_item[200];
		itemlist	box_ammo[200];
		itemlist	box_materials[800];
		itemlist	box_decos[200];
	} PACKED;

	struct investigation {
		uint8_t		filled[4];
		uint8_t 	selected;
		int32_t		attempts;
		int32_t		seen; // is the first byte which matters (0x03 to be seen)
		uint8_t		locale;
		uint8_t		rank;
		uint32_t	mon1;
		uint32_t	mon2;
		uint32_t	mon3; //27 bytes so far
		uint8_t		mon1_temper;
		uint8_t		mon2_temper;
		uint8_t		mon3_temper;
		uint8_t		hp; // ???
		uint8_t		attack; // ???
		uint8_t		defense; // ??? = 33 bytes so far
		uint8_t		X3; // ???
		uint8_t		Y0; // ???
		uint8_t		flourish_idx;
		uint8_t		time_amount;
		uint8_t		Y3; // ???
		uint8_t		faints_limits;
		uint8_t		max_players;
		uint8_t		mon_rewards; // ???
		uint8_t		zenny_multiplier;
	} PACKED;

	struct equiploadout {
		uint32_t	slotid;
		uint8_t		name_utf8[256];
		uint32_t	weapon_idx;
		uint32_t	helmet_idx;
		uint32_t	torso_idx;
		uint32_t	arms_idx;
		uint32_t	coil_idx;
		uint32_t	feet_idx;
		uint32_t	charm_idx;
		uint32_t	mantle1_idx;
		uint32_t	mantel2_idx;
		uint32_t	weapondecos_id1;
		uint32_t	weapondecos_id2;
		uint32_t	weapondecos_id3;
		uint32_t	helmetdecos_id1;
		uint32_t	helmetdecos_id2;
		uint32_t	helmetdecos_id3;
		uint32_t	torsodecos_id1;
		uint32_t	torsodecos_id2;
		uint32_t	torsodecos_id3;
		uint32_t	armsdecos_id1;
		uint32_t	armsdecos_id2;
		uint32_t	armsdecos_id3;
		uint32_t	coildecos_id1;
		uint32_t	coildecos_id2;
		uint32_t	coildecos_id3;
		uint32_t	feetdecos_id1;
		uint32_t	feetdecos_id2;
		uint32_t	feetdecos_id3;
		uint32_t	unknown0[27];
		uint32_t	charmdecos_idx1;
		uint32_t	charmdecos_idx2;
		uint32_t	charmdecos_idx3;
		uint32_t	mantle1decos_idx1;
		uint32_t	mantle1decos_idx2;
		uint32_t	mantle1decos_idx3;
		uint32_t	mantle2decos_idx1;
		uint32_t	mantle2decos_idx2;
		uint32_t	mantle2decos_idx3;
		uint32_t	bitmask_customcolours;
		uint32_t	bitmask_rainbow;
		uint32_t	rgb_head;
		uint32_t	rgb_torso;
		uint32_t	rgb_arms;
		uint32_t	rgb_coil;
		uint32_t	rgb_wholeset;
		uint32_t	unknown_[1];
	} PACKED;

	struct inventoryitem {
		uint32_t	type;	// 0 armor, 1 weapon, 2 charm
		uint32_t	slot;	// 0 head, 1 chest, 2 arms, 3 waist, 4 legs, ... if armor
					// otherwise weapon type
		uint32_t	id;	// item id
		uint8_t		unknown[56];
	} PACKED;

	struct harvestdata {
		itemlist	harvestable_items[3]; 	// the quantity are the turns harvested for (increasing)
		itemlist	active_fertilizers[5];	// id and how many turns is going to be on (decreasing)
		itemlist	harvestbox[30];
	} PACKED;

	struct saveslot {
		charinfo	info;
		uint8_t		unknown0[4347];
		monsterqstats	qstats; //quick summary monster stats
		uint8_t		unknown1[592084];
		monsterfstats	fstats; //full monster stats
		uint8_t		unknown2[5038];
		itemloadouts	item_loadouts;
		uint8_t		unknown3[8];
		itemcontainers	items;
		uint8_t		unknown4[4];
		inventoryitem	inventory[1000];
		uint8_t		unknown5[102676];
		uint32_t	inventory_idx[1000];
		uint8_t		unknown6[41956];
		investigation	invs[250];
		uint8_t		unknown7[4025];
		equiploadout	equip_loadouts[112];
		uint8_t		unknown8[7008];
		harvestdata	harvestbox;
		uint8_t		unknown9[32];
		uint8_t		harvest_flag; // set to 1 when fertilizer has been used
		uint8_t		unknown_[29901];
	} PACKED;

	struct savefile {
		uint32_t	magicnum;
		uint8_t		unknown0[8];
		uint8_t		sha1[20];
		uint8_t		unknown1[8];
		int64_t		steamid;
		uint8_t		unknown_[3146924];
		saveslot	slots[3];
	} PACKED;

	static_assert(sizeof(layout_bin::investigation) == (42), "Investigation structure size not as expected");
	static_assert(sizeof(layout_bin::savefile) == (0x3004dc + (3*0xf6110)), "Savefile structure size not as expected");
}

#endif //_LAYOUT_BIN_H_

