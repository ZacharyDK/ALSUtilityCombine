# ALSUtilityCombine
ALSUtilityCombine

by Zach Kolansky

ALS Community Version: https://github.com/dyanikoglu/ALS-Community

My Standalone UtilityAI System: https://www.unrealengine.com/marketplace/en-US/product/utilityai-with-replicated-weapon-stat-and-status-effect-systems

Standalone Github for my UtilityAI System: https://github.com/ZacharyDK/UtilityCombatSample 

My Standalone UtilityAI System Documentation: https://docs.google.com/document/d/1XkaUs4PwrAyDM_PV1cD-ulRLw5Ykb_6LmlaFsxnZIcQ/edit?usp=sharing 

Documentation: https://docs.google.com/document/d/1XkaUs4PwrAyDM_PV1cD-ulRLw5Ykb_6LmlaFsxnZIcQ/edit#

# Installation

You need to have git LFS set up to download this repo properly. 

1. Install Homebrew
2. brew install git-lfs 
3. Create a folder to hold the repo
4. change your current directory to said folder
5. git clone https://github.com/ZacharyDK/ALSUtilityCombine 

# Notes:

This sample project combines my UtilityAI system with the community version of the ALS plugin. 
Reasoning: ALS offers a robust animation system, with mantle, camera shake, aim, overlay system, and a very good movement system.
All of which are great, and done much better than I could ever do. 

I wanted to make it easy to drag and drop into your project (i.e drag stuff into Plugins folder), even if it already uses ALS. See the content combined folder to find
classes that I edited. I wanted to keep each system as pure as possible, with minimal changes. For example, the RangeAndMelee
anim BP in the UtilityAI system is not changed, the ALS Anim BP is unchanged, and I made a copy of the ALS Anim BP named
*ALS_Combined_AnimBP*. That is where I made my changes. The character that implements the numerous interfaces from the
UtilityAI system named *ALS_Combined_BP*. I handled that part for you and left *MannequinCharacter_BP* unchanged. 

# API changes to ALS

1. ALVS4_CPP.uplugin now dependent on UtilityCombatPlugin. ALSV4_CPP.Build.cs also dependent on UtilityCombatPlugin
2. UtilityCombatPlugin now loads PreDefault, see .uplugin. This ensures I can make ALS dependent on UtilityCombat
3. AALSAIController is now a AUtilityAIController .
4. AALSPlayerController is a AUtilityPlayerController .
5. UALSMantleComponent has OnMantleStart and OnMantleEnd Delegates
6. UALSMantleComponent remembers the LastMantleHitResult, new BlueprintReadOnly variable
7. UALSMantleComponent has a TArray called ForbiddenMontages, if any of these montages is playing, the character will not be able to mantle.
8. UALSMantleComponent now has a variable that lets you toggle binding to the jump key. 
9. Exposed some action events in AALSBaseCharacter to Blueprint
10. UALSCharacterAnimInstance has a new variable called *bIsHumanCharacter* = true. If this is false, the animation instance will terminate 
NativeUpdateAnimation() early, skipping the calls UpdateAimingValues(DeltaSeconds); UpdateLayerValues(); UpdateFootIK(DeltaSeconds); and all other update functions. Set bIsHumanCharacter to false if you want to possess a non human character (like a car) but still use the ALS controller framework.

11. Added three new overlay states. EALSOverlayState::MeleeOneHand, EALSOverlayState::MeleeAndShield, EALSOverlayState::MeleeTwoHand


12. Edited FALSOverlayState to account for the new overlay states. *ALS_Combined_BP* handles my changes.  

13. Modified GetMantleAsset() in the BP child of UALSMantleComponent to account for the new overlay states. 

14. *ALS_Combined_AnimBP* has an upperbody slot, for montages that you only want to play on the upperbody.

15. I was messing around with the *UINavigationPlugin* (Link: https://www.unrealengine.com/marketplace/en-US/product/uinavigation) There shouldn't
be any dependencies YET, BUT I will add working menus in the future. Install this in the Plugins folder if I accidently left a dependency. 

# TODO:

Look, the major integration steps are done, so you can use this plugin with ALS. But there are some finishing touches I want to put on.

1. Finish status effects testing (i.e make sure integration complete and working as intended)
2. Making the AI AIM (using the Anims from ALS )
3. Making the AI Sprint ()
4. HUD integration. (UtilityAI hud should be mostly fine)
5. Full menus. (Main menu, pause menu, maybe server select. )
6. Make/include .cs files for server builds. For ease of use.
7. Video show case. 

# EULA:

This plugin is subject to same EULA as Epic's Paragon assets, the general UE4 EULA, and the EULA from using assets downloaded from the Unreal Engine Marketplace.

This plugin is only for Unreal Engine users. If you don't use Unreal, the most you can do read the source code. 

This plugin contains animations from Paragon assets retargeted to the manniquin. Do not use these animations for anything other than an Unreal project. 

This plugin contains animations from Advanced Locomotion System. This are subject to Ue4's EULA and Epic's EULA. 

Free, have fun.

License: MIT license. 