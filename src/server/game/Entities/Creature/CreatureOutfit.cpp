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

#include "CreatureOutfit.h"
#include "DBCStores.h" // sChrRacesStore
#include "DBCStructure.h" // ChrRacesEntry
#include "ItemTemplate.h"
#include "ObjectMgr.h"

constexpr uint32 CreatureOutfit::invisible_model;
constexpr uint32 CreatureOutfit::max_real_modelid;
constexpr EquipmentSlots CreatureOutfit::item_slots[];

CreatureOutfit::CreatureOutfit(uint8 race, Gender gender) : race(race), gender(gender)
{
    ChrRacesEntry const* rEntry = sChrRacesStore.LookupEntry(race);
    if (!rEntry)
        rEntry = sChrRacesStore.LookupEntry(RACE_HUMAN);

    displayId = (gender == GENDER_FEMALE) ? rEntry->model_f : rEntry->model_m;
}

CreatureOutfit& CreatureOutfit::SetItemEntry(EquipmentSlots slot, uint32 itemEntry)
{
    if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry))
        outfitdisplays[slot] = proto->DisplayInfoID;
    else
        outfitdisplays[slot] = 0;
    return *this;
}
