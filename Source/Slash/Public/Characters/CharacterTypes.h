#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	Unarmed UMETA(DisplayName = "Unarmed"),
	OneHandedWeapon UMETA(DisplayName = "One-Handed Weapon"),
	TwoHandedWeapon UMETA(DisplayName = "Two-Handed Weapon")
};
