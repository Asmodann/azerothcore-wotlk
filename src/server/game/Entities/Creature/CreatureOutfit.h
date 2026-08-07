/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Affero General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CREATURE_OUTFIT_H
#define CREATURE_OUTFIT_H

#include "Define.h"
#include "Player.h" // EquipmentSlots
#include "SharedDefines.h" // Gender
#include <memory>

class Creature;

// Gives a Creature the full visual appearance of a Player (race/gender/skin/face/hair
// plus every visible equipment slot) by piggybacking on the Mirror Image protocol
// (SMSG_MIRRORIMAGE_DATA). The client only renders those fields for a real Player,
// so a "fake" displayId (> max_real_modelid) is used as a marker: whenever such an id
// is set on a Creature, ObjectMgr resolves it to this outfit instead of a DBC model.
class AC_GAME_API CreatureOutfit
{
public:
    friend class ObjectMgr;

    // Remember to change the DB query too if this changes!
    static constexpr uint32 invisible_model = 11686;
    static constexpr uint32 max_real_modelid = 0x7FFFFFFF;
    static constexpr EquipmentSlots item_slots[] =
    {
        EQUIPMENT_SLOT_HEAD,
        EQUIPMENT_SLOT_SHOULDERS,
        EQUIPMENT_SLOT_BODY,
        EQUIPMENT_SLOT_CHEST,
        EQUIPMENT_SLOT_WAIST,
        EQUIPMENT_SLOT_LEGS,
        EQUIPMENT_SLOT_FEET,
        EQUIPMENT_SLOT_WRISTS,
        EQUIPMENT_SLOT_HANDS,
        EQUIPMENT_SLOT_BACK,
        EQUIPMENT_SLOT_TABARD,
    };

    static bool IsFake(uint32 modelId) { return modelId > max_real_modelid; }

    CreatureOutfit(uint8 race, Gender gender);

    uint8 Class = 1;
    uint8 face = 0;
    uint8 skin = 0;
    uint8 hair = 0;
    uint8 facialhair = 0;
    uint8 haircolor = 0;
    uint32 outfitdisplays[EQUIPMENT_SLOT_END] = { 0 };
    uint32 npcsoundsid = 0;
    uint32 guild = 0;

    uint32 GetId() const { return id; }
    uint8 GetGender() const { return gender; }
    uint8 GetRace() const { return race; }
    uint32 GetDisplayId() const { return displayId; }

    CreatureOutfit& SetItemEntry(EquipmentSlots slot, uint32 itemEntry);
    CreatureOutfit& SetItemDisplay(EquipmentSlots slot, uint32 displayId)
    {
        outfitdisplays[slot] = displayId;
        return *this;
    }

private:
    CreatureOutfit() {}
    uint32 id = 0;
    uint8 race = 0;
    uint8 gender = 0;
    uint32 displayId = 0;
};

#endif
