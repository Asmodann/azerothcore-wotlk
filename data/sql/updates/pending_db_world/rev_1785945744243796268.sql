--
-- Dress NPC outfit system: lets a creature use a full Player-style appearance
-- (race/gender/skin/face/hair + every visible equipment slot) via the Mirror
-- Image protocol. Referenced by `creature`.`modelid1` / `creature_template_model`
-- using a "fake" display id, i.e. `entry` here, which must be > 2147483647
-- (0x7FFFFFFF) so it can never collide with a real CreatureDisplayInfo.dbc id.
--
DROP TABLE IF EXISTS `creature_template_outfits`;
CREATE TABLE `creature_template_outfits` (
  `entry` int unsigned NOT NULL COMMENT 'fake display id, must be > 2147483647',
  `npcsoundsid` int unsigned NOT NULL DEFAULT '0' COMMENT 'NPCSounds.dbc id, 0 for none',
  `race` tinyint unsigned NOT NULL DEFAULT '1',
  `class` tinyint unsigned NOT NULL DEFAULT '1',
  `gender` tinyint unsigned NOT NULL DEFAULT '0',
  `skin` tinyint unsigned NOT NULL DEFAULT '0',
  `face` tinyint unsigned NOT NULL DEFAULT '0',
  `hair` tinyint unsigned NOT NULL DEFAULT '0',
  `haircolor` tinyint unsigned NOT NULL DEFAULT '0',
  `facialhair` tinyint unsigned NOT NULL DEFAULT '0',
  `head` int NOT NULL DEFAULT '0' COMMENT 'item entry, or negative raw ItemDisplayInfo id',
  `shoulders` int NOT NULL DEFAULT '0',
  `body` int NOT NULL DEFAULT '0',
  `chest` int NOT NULL DEFAULT '0',
  `waist` int NOT NULL DEFAULT '0',
  `legs` int NOT NULL DEFAULT '0',
  `feet` int NOT NULL DEFAULT '0',
  `wrists` int NOT NULL DEFAULT '0',
  `hands` int NOT NULL DEFAULT '0',
  `back` int NOT NULL DEFAULT '0',
  `tabard` int NOT NULL DEFAULT '0',
  `guildid` int unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Optional DB overrides for NPCSounds.dbc, following the same convention as
-- the other `*_dbc` tables (e.g. `namesreserved_dbc`). Left empty by default.
--
DROP TABLE IF EXISTS `npcsounds_dbc`;
CREATE TABLE `npcsounds_dbc` (
  `ID` int unsigned NOT NULL,
  `hello` int unsigned NOT NULL DEFAULT '0',
  `goodbye` int unsigned NOT NULL DEFAULT '0',
  `pissed` int unsigned NOT NULL DEFAULT '0',
  `ack` int unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
