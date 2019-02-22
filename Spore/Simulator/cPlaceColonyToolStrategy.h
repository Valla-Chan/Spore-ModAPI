/****************************************************************************
* Copyright (C) 2019 Eric Mor
*
* This file is part of Spore ModAPI.
*
* Spore ModAPI is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
****************************************************************************/
#pragma once

#include <Spore\Simulator\cDefaultProjectileWeapon.h>

namespace Simulator
{
	class cPlaceColonyToolStrategy
		: public cDefaultProjectileWeapon
	{
	public:
		static const uint32_t STRATEGY_ID = 0x733B280C;

		virtual bool OnSelect(cSpaceToolData* pTool) override;
		virtual bool OnDeselect(cSpaceToolData* pTool) override;
		virtual bool Update(cSpaceToolData* pTool, bool showErrors, const char16_t** ppFailText = nullptr) override;
		virtual bool WhileAiming(cSpaceToolData* pTool, const Vector3& aimPoint, bool showErrors) override;
		virtual void SelectedUpdate(cSpaceToolData* pTool, const Vector3& position) override;
		virtual bool OnHit(cSpaceToolData* pTool, const Vector3& position, cSpaceToolData::SpaceToolHit hitType) override;
	};

	namespace InternalAddressList(cPlaceColonyToolStrategy)
	{
		DefineAddress(OnSelect, GetAddress(0x1054C70, NO_ADDRESS, 0x10540C0));
		DefineAddress(OnDeselect, GetAddress(0x1054D50, NO_ADDRESS, 0x10541A0));
		DefineAddress(Update, GetAddress(0x10596D0, NO_ADDRESS, 0x1058B30));
		DefineAddress(WhileAiming, GetAddress(0x105C210, NO_ADDRESS, 0x105B670));
		DefineAddress(SelectedUpdate, GetAddress(0x1054E00, NO_ADDRESS, 0x1054300));
		DefineAddress(OnHit, GetAddress(0x105C4D0, NO_ADDRESS, 0x105B930));
	}
}