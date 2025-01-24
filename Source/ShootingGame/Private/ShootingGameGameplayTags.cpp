// Fill out your copyright notice in the Description page of Project Settings.


#include "ShootingGameGameplayTags.h"

namespace ShootingGameTags
{
	// Input Tag
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Lock");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipSMG11, "InputTag.EquipSMG11");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_EquipAR4, "InputTag.EquipAR4");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipSMG11, "InputTag.UnequipSMG11");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_UnequipAR4, "InputTag.UnequipAR4");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_HoldAction, "InputTag.HoldAction");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HoldAction_Dash, "InputTag.HoldAction.Dash");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_HoldAction_Zoom, "InputTag.HoldAction.Zoom");

	// Player Tag
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_SMG11, "Player.Ability.Equip.SMG11");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_SMG11, "Player.Ability.Unequip.SMG11");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_AR4, "Player.Ability.Equip.AR4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_AR4, "Player.Ability.Unequip.AR4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Dash, "Player.Ability.Dash");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Zoom, "Player.Ability.Zoom");

	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_SMG11, "Player.Weapon.SMG11");
	UE_DEFINE_GAMEPLAY_TAG(Player_Weapon_AR4, "Player.Weapon.AR4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_SMG11, "Player.Event.Equip.SMG11");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_SMG11, "Player.Event.Unequip.SMG11");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_AR4, "Player.Event.Equip.AR4");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_AR4, "Player.Event.Unequip.AR4");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Dash, "Player.Status.Dash");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_Zoom, "Player.Status.Zoom");
}