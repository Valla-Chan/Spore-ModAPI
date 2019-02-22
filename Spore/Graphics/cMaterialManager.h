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

#include <Spore\RenderWare\RenderWareFile.h>
#include <Spore\Graphics\IMaterialManager.h>
#include <Spore\Graphics\MaterialShader.h>
#include <Spore\Object.h>
#include <Spore\Clock.h>
#include <Spore\Mutex.h>

#include <EASTL\hash_map.h>
#include <EASTL\vector.h>
#include <EASTL\string.h>

using namespace eastl;
using RenderWare::CompiledState;

namespace Graphics
{
	class UnkMatManager
	{
	protected:
		/* 00h */	int field_00;
		/* 04h */	int field_04;
		/* 08h */	hash_map<int, int> field_08;
		/* 28h */	hash_map<int, int> field_28;
		/* 48h */	hash_map<int, int> field_48;
		/* 68h */	hash_map<int, int> field_68;
		/* 88h */	vector<intrusive_ptr<MaterialShader>> mStandardShaders;
		/* 9Ch */	hash_map<int, int> field_9C;
		// They are only added here if they are outside the 0x70000000 - 0x80000000 range
		/* BCh */	hash_map<uint32_t, intrusive_ptr<MaterialShader>> mStandardShadersMap;
		/* DCh */	vector<int> field_DC;
		/* F0h */	hash_map<int, int> field_F0;
		/* 110h */	string field_110;
		/* 120h */	char field_120[0x1C];  // not initialized
		/* 13Ch */	hash_map<int, int> field_13C;

		friend class cMaterialManager;
	};


	///
	/// The implementation of IMaterialManager; this should only be used for extending and detouring.
	///
	class cMaterialManager : public IMaterialManager, public IVirtual
	{
	public:
		bool ReadCompiledShadersImpl(IO::IStream* pStream);
		bool ReadMaterialsImpl(IO::IStream* pLinkStream, RenderWare::RenderWareFile* pRenderWare);

	protected:

		/* 08h */	int mnRefCount;
		/* 0Ch */	int field_0C;
		/* 10h */	UnkMatManager field_10;
		/* 16Ch */	int field_16C;  // not initialized
		/* 170h */	int field_170;  // not initialized
		/* 174h */	hash_map<uint32_t, Material> mMaterials;
		/* 194h */	hash_map<CompiledState*, uint32_t> field_194;
		/* 1B4h */	CompiledState* mpDefaultCompiledState;

		// 200h graphics quality?
		/* 204h */	intrusive_ptr<RenderWare::RenderWareFile> mpCompiledStatesFile;
		/* 208h */	Clock field_208;
		/* 220h */	int field_220;
		/* 224h */	int field_224;
		/* 228h */	int field_228;
		/* 22Ch */	int field_22C;
		/* 230h */	int field_230;
		/* 234h */	int field_234;
		/* 238h */	int field_238;
		/* 23Ch */	bool field_23C;
		/* 240h */	int field_240;  // 0x200
		/* 244h */	vector<intrusive_ptr<Material>> mTexturedMaterials;
		/* 258h */	Mutex mMaterialsMutex;
	};
}