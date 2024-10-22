.set LOCALID_DAISY, 8

Route4_MapScripts:: @ 8167F8A
	.byte 0

Route4_EventScript_Unused:: @ 8167F8B
	end

Route4_EventScript_Woman:: @ 8167F8C
	msgbox Route4_Text_TrippedOverGeodude, MSGBOX_NPC
	end

Route4_EventScript_MtMoonSign:: @ 8167F95
	msgbox Route4_Text_MtMoonEntrance, MSGBOX_SIGN
	end

Route4_EventScript_RouteSign:: @ 8167F9E
	msgbox Route4_Text_RouteSign, MSGBOX_SIGN
	end

Route4_EventScript_DaisyTriggerLeft:: @ 8168298
	lockall
	setvar VAR_TEMP_1, 0
	setobjectxyperm LOCALID_DAISY, 13, 19
	goto Route4_EventScript_Daisy
	end

Route4_EventScript_DaisyTriggerRight:: @ 81682AB
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_DAISY, 12, 19
	goto Route4_EventScript_Daisy
	end

Route4_EventScript_Daisy:: @ 81682BE
	textcolor 0
	playbgm MUS_ENCOUNTER_RIVAL, 0
	addobject LOCALID_DAISY
	compare VAR_TEMP_1, 0
	call_if_eq Route4_EventScript_DaisyApproachLeft
	compare VAR_TEMP_1, 1
	call_if_eq Route4_EventScript_DaisyApproachRight
	delay 6
	msgbox Route22_Text_EarlyRivalIntro
	trainerbattle_single TRAINER_DAISY_ROUTE4, 0, Route4_Text_DaisyDefeat
	msgbox Route4_Text_DaisyPostBattle
	closemessage
	delay 10
	playbgm MUS_RIVAL_EXIT, 0
	goto Route4_EventScript_DaisyExit
	fadedefaultbgm
	removeobject LOCALID_DAISY
	setvar VAR_MAP_SCENE_ROUTE4, 1
	releaseall
	end

Route4_EventScript_DaisyApproachLeft:: @ 8168350
	applymovement LOCALID_DAISY, Route4_Movement_DaisyApproachLeft
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_PlayerFaceDaisyLeft
	waitmovement 0
	return

Route4_EventScript_DaisyApproachRight:: @ 8168350
	applymovement LOCALID_DAISY, Route4_Movement_DaisyApproachRight
	applymovement OBJ_EVENT_ID_PLAYER, Route4_Movement_PlayerFaceDaisyRight
	waitmovement 0
	return


Route4_Movement_DaisyApproachLeft:: @ 81683D1
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

Route4_Movement_DaisyApproachRight:: @ 81683D1
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

Route4_Movement_PlayerFaceDaisyLeft:: @ 81683E3
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

Route4_Movement_PlayerFaceDaisyRight:: @ 81683E3
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

Route4_EventScript_DaisyExit:: @ 816839A
	applymovement LOCALID_DAISY, Route4_Movement_DaisyExit
	waitmovement 0
	return

Route4_Movement_DaisyExit:: @ 81683B8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
