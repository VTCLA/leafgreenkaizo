.set LOCALID_BROCK, 2

Route2_MapScripts:: @ 8167F64
	.byte 0

Route2_EventScript_RouteSign:: @ 8167F65
	msgbox Route2_Text_RouteSign, MSGBOX_SIGN
	end

Route2_EventScript_DiglettsCaveSign:: @ 8167F6E
	msgbox Route2_Text_DiglettsCave, MSGBOX_SIGN
	end

Route2_EventScript_Brock::
	lock
	faceplayer
	msgbox Route2_Text_SeeYouAtTheGym
	applymovement LOCALID_BROCK, Route2_Movement_BrockReturns
	waitmovement 0
	removeobject LOCALID_BROCK
	setvar VAR_MAP_SCENE_PEWTER_CITY, 1
	release
	end
	
Route2_Movement_BrockReturns::
	jump_2_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
