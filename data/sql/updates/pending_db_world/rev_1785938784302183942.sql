--
ALTER TABLE `creature` ADD COLUMN `faction` smallint unsigned NOT NULL DEFAULT '0' AFTER `dynamicflags`;
