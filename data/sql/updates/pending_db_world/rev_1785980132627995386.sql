--
-- Admin-only label to help identify what an outfit entry is meant to look like.
-- Not read by the server, purely a DB note.
--
ALTER TABLE `creature_template_outfits`
ADD COLUMN `name` varchar(100) DEFAULT NULL COMMENT 'admin note, not used by the server' AFTER `entry`;
