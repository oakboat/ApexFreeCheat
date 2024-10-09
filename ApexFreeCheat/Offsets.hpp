// Game Version: v3.0.81.36
#pragma once
uint64_t OFF_REGION = 0;    //[Static]->Region
constexpr uint64_t OFF_LEVEL = 0x18356c4; //[Miscellaneous]->LevelName
constexpr uint64_t OFF_LOCAL_PLAYER = 0x24342B8;//[Miscellaneous]->LocalPlayer
constexpr uint64_t OFF_ENTITY_LIST = 0x1F61048; //[Miscellaneous]->cl_entitylist
constexpr uint64_t OFF_GLOBAL_VARS = 0x18351c0; //[Miscellaneous]->GlobalVars
constexpr uint64_t OFF_NAMELIST = 0xd426160; //[Miscellaneous]->NameList

// Buttons
constexpr uint64_t OFF_IN_ATTACK = 0x76e89c0; //[Buttons]->in_attack
constexpr uint64_t OFF_IN_JUMP = 0x076e8aa8; //[Buttons]->in_jump
constexpr uint64_t OFF_IN_DUCK = 0x76e8bb0; //[Buttons]->in_duck
constexpr uint64_t OFFSET_IN_FORWARD = 0x76e88f0; //[Buttons]->in_forward
constexpr uint64_t OFFSET_TRAVERSAL_START_TIME = 0x2b70; //[RecvTable.DT_LocalPlayerExclusive]->m_traversalStartTime
constexpr uint64_t OFFSET_TRAVERSAL_PROGRESS = 0x2b6c; //[RecvTable.DT_LocalPlayerExclusive]->m_traversalProgress
constexpr uint64_t OFFSET_TRAVERSAL_RELEASE_TIME = 0x2b78; //[RecvTable.DT_LocalPlayerExclusive]->m_traversalReleaseTime
constexpr uint64_t OFFSET_WALL_RUN_START_TIME = 0x3674; //[RecvTable.DT_LocalPlayerExclusive]->m_wallRunStartTime
constexpr uint64_t OFFSET_WALL_RUN_CLEAR_TIME = 0x3678; //RecvTable.DT_LocalPlayerExclusive]->m_wallRunClearTime

// Player
constexpr uint64_t OFF_VIEW_MATRIX = 0x11a350; //[RecvTable.DT_Player]->ViewMatrix
constexpr uint64_t OFF_VIEW_RENDER = 0x76e88b8; //[RecvTable.DT_Player]->ViewRender
constexpr uint64_t OFF_VIEW_MODELS = 0x2d98; //[RecvTable.DT_Player]->m_hViewModels
constexpr uint64_t OFF_ZOOMING = 0x1be1; //[RecvTable.DT_Player]->m_bZooming
constexpr uint64_t OFF_LOCAL_ORIGIN = 0x017c; //[DataMap.CBaseViewModel]->m_vecAbsOrigin
constexpr uint64_t OFF_ABSVELOCITY = 0x0170; //[DataMap.C_BaseEntity]->m_vecAbsVelocity
constexpr uint64_t OFF_TEAM_NUMBER = 0x0338; //[RecvTable.DT_BaseEntity]->m_iTeamNum
constexpr uint64_t OFF_CURRENT_HEALTH = 0x0328; //[RecvTable.DT_BaseEntity]->m_iHealth
constexpr uint64_t OFF_MAXHEALTH = 0x0470; //[RecvTable.DT_Player]->m_iMaxHealth
constexpr uint64_t OFF_CURRENT_SHIELDS = 0x01a0; //[RecvTable.DT_BaseEntity]->m_shieldHealth
constexpr uint64_t OFF_MAXSHIELD = 0x01a4; //[RecvTable.DT_TitanSoul]->m_shieldHealthMax
constexpr uint64_t OFF_NAME = 0x0481; //[RecvTable.DT_BaseEntity]->m_iName
constexpr uint64_t OFF_SIGNIFIER_NAME = 0x0478; //[RecvTable.DT_BaseEntity]->m_iSignifierName
constexpr uint64_t OFF_LIFE_STATE = 0x0690; //[RecvTable.DT_Player]->m_lifeState
constexpr uint64_t OFF_BLEEDOUT_STATE = 0x2760; //[RecvTable.DT_Player]->m_bleedoutState
constexpr uint64_t OFF_LAST_VISIBLE_TIME = 0x19a0; //[RecvTable.DT_BaseCombatCharacter]->CPlayer!lastVisibleTime // m_hudInfo_visibilityTestAlwaysPasses + 0x2
constexpr uint64_t OFF_LAST_AIMEDAT_TIME = 0x19a8; //[RecvTable.DT_BaseCombatCharacter]->OFF_LAST_VISIBLE_TIME + 0x8 // m_hudInfo_visibilityTestAlwaysPasses + 0x2 + 0x8
constexpr uint64_t OFF_VIEW_ANGLES = 0x2534 - 0x14; //[DataMap.C_Player]->m_ammoPoolCapacity - 0x14
constexpr uint64_t OFF_PUNCH_ANGLES = 0x2438; //[DataMap.C_Player]->m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
constexpr uint64_t OFF_BREATH_ANGLES = OFF_VIEW_ANGLES - 0x10; //(OFF_VIEW_ANGLES - 0x10)
constexpr uint64_t OFF_STUDIOHDR = 0x1000; //[Miscellaneous]->CBaseAnimating!m_pStudioHdr
constexpr uint64_t OFF_BONES = 0x0db0 + 0x48; //[RecvTable.DT_BaseAnimating]->m_nForceBone + 0x48
constexpr uint64_t OFF_CAMERAORIGIN = 0x1ee0; //[Miscellaneous]->CPlayer!camera_origin
constexpr uint64_t OFF_MODELNAME = 0x0030; //[DataMap.C_BaseEntity]->m_ModelName
constexpr uint64_t OFF_YAW = 0x223c - 0x8;; //[DataMap.C_Player]=>m_currentFramePlayer.m_ammoPoolCount - 0x8
constexpr uint64_t OFF_NAMEINDEX = 0x38; //[RecvTable.DT_BaseEntity]
constexpr uint64_t OFF_XPLEVEL = 0x3724; //m_xp
constexpr uint64_t OFF_SQUAD_ID = 0x0344; //m_squadID
constexpr uint64_t OFF_GAMEMODE = 0x0246c460; //mp_gamemode
constexpr uint64_t OFF_SPECTATOR_LIST = 0x1f63068; //IDA signtature -> [48 8B 0D ? ? ? ? 48 85 C9 74 ? 48 8B 01 FF ? ? 48 85 C0 74 ? 48 63 4E 38]
constexpr uint64_t OFF_SPECTATOR_LIST_ARRAY = 0x974;

// Weapon
constexpr uint64_t OFF_WEAPON_HANDLE = 0x1944; //[RecvTable.DT_BaseCombatCharacter]->m_latestPrimaryWeapons
constexpr uint64_t OFF_WEAPON_INDEX = 0x1788; //[RecvTable.DT_WeaponX]->m_weaponNameIndex
constexpr uint64_t OFFSET_AMMO = 0x1564; //[DT_WeaponX_LocalWeaponData]->m_ammoInClip
constexpr uint64_t OFF_GRENADE_HANDLE = 0x1954; //[RecvTable.DT_Player]->m_latestNonOffhandWeapons
constexpr uint64_t OFF_SKIN = 0x0d68; //[RecvTable.DT_BaseAnimating]->m_nSkin
constexpr uint64_t OFF_WEAPON_DISCARDED = 0x15a9;//[RecvTable.DT_WeaponX]->m_discarded
constexpr uint64_t OFFSET_TIME_BASE = 0x2088; //[RecvTable.DT_Player]->m_currentFramePlayer.timeBase


constexpr uint64_t OFF_PROJECTILESPEED = 0x04ec + 0x19d8; //CWeaponX!m_flProjectileSpeed //[WeaponSettings]->projectile_launch_speed + [WeaponSettingsMeta].base
constexpr uint64_t OFF_PROJECTILESCALE = OFF_PROJECTILESPEED + 0x8; //CWeaponX!m_flProjectileScale //[WeaponSettings]->projectile_gravity_scale + [WeaponSettingsMeta].base
// Glow
constexpr uint64_t HIGHLIGHT_TYPE_SIZE = 0x34;
constexpr uint64_t OFF_GLOW_THROUGH_WALL = 0x26c; //[DT_HighlightSettings].?
constexpr uint64_t OFF_GLOW_FIX = 0x278;
constexpr uint64_t OFF_GLOW_HIGHLIGHT_ID = 0x29C; //[DT_HighlightSettings].m_highlightServerActiveStates
constexpr uint64_t OFF_GLOW_HIGHLIGHTS = 0xb1da3a0;
constexpr uint64_t OFF_GLOW_ENABLE = 0x27c;