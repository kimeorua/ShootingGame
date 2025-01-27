#pragma once

UENUM()
enum class EShootingGameConfirmType : uint8
{
	Yes,
	No
};

UENUM(BlueprintType)
enum class EAimOffsetType : uint8
{
	None,
	SMG11,
	AR4
};