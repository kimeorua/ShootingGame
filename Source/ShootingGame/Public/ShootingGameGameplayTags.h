//프로젝트에서 사용할 게임플레이 Tag 정의
// 규칙
// 1. 입력 제어용 태그 : Input_AAA
// 2. 플레이어 용 태그 : Player_AAA
// 3. 공용 태그 : Shard_AAA
// 4. 적용 태그 : Enemy_AAA
// 5. 상태: Status, 능력: Ability, 이벤트: Event 태그를 붙여서 사용 EX) Player_Ability_AAA

#pragma once

#include "NativeGameplayTags.h"

namespace ShootingGameTags
{
	// InputTag
	SHOOTINGGAME_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	SHOOTINGGAME_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
}