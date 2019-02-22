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

#include <stdint.h>
#include <EASTL\functional.h>

///
/// Class similar to ResourceKey, but this one is only formed up by an instanceID and a groupID.
/// The groupID is used when hashing and comparing, allowing this class to be used in containers such as hash_map
/// or sorted vectors.
///
class ResourceID
{
public:
	ResourceID();
	ResourceID(uint32_t instanceID, uint32_t groupID);

	uint32_t mnGroupID;
	uint32_t mnInstanceID;

	bool ResourceID::operator ==(const ResourceID &b) const;

};


///////////////////////////////////
//// INTERNAL IMPLEMENENTATION ////
///////////////////////////////////

static_assert(sizeof(ResourceID) == 0x8, "sizeof(ResourceID) must be 8h");


inline ResourceID::ResourceID(uint32_t _instanceID, uint32_t _groupID)
	: mnInstanceID(_instanceID)
	, mnGroupID(_groupID)
{
};

inline ResourceID::ResourceID()
	: mnInstanceID(0)  // maybe use -1?
	, mnGroupID(0)  // maybe use -1?
{
}

inline bool ResourceID::operator ==(const ResourceID &b) const
{
	return mnGroupID == b.mnGroupID && mnInstanceID == b.mnInstanceID;
}

namespace eastl
{
	/// A necessary structure to be able to use ResourceID on containers such as hash_map.
	template <> struct hash<ResourceID>
	{
		size_t operator()(const ResourceID& val) const { return static_cast<size_t>(val.mnGroupID); }
	};
}