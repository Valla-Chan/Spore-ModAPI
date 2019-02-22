// The IO namespace has been copied (mostly only the headers) from the open source EA WebKit

/*
Copyright (C) 2009-2010 Electronic Arts, Inc.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

1.  Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2.  Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3.  Neither the name of Electronic Arts, Inc. ("EA") nor the names of
its contributors may be used to endorse or promote products derived
from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY ELECTRONIC ARTS AND ITS CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ELECTRONIC ARTS OR ITS CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/////////////////////////////////////////////////////////////////////////////
// EAStreamMemory.h
//
// Copyright (c) 2007, Electronic Arts Inc. All rights reserved.
// Written by Paul Pedriana
//
// Implements a IO stream that reads and writes to a block of memory.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "IStream.h"

namespace IO
{
	///
	/// Implements a 'bit bucket' stream, whereby all writes to the stream
	/// succeed but do nothing and all reads from the stream succeed but write
	/// nothing to the user-supplied buffer.
	///
	class StreamNull : public IStream
	{
	public:
		StreamNull();

		/* 04h */	virtual int	AddRef() override;
		/* 08h */	virtual int	Release() override;

		/* 0Ch */	virtual uint32_t	GetType() const override;
		/* 10h */	virtual int			GetAccessFlags() const override;
		/* 14h */	virtual FileError	GetState() const override;
		/* 18h */	virtual bool		Close() override;

		/* 1Ch */	virtual size_type	GetSize() const override;
		/* 20h */	virtual bool		SetSize(size_type size) override;
		/* 24h */	virtual int			GetPosition(PositionType positionType = kPositionTypeBegin) const override;
		/* 28h */	virtual bool		SetPosition(int distance, PositionType positionType = kPositionTypeBegin) override;
		/* 2Ch */	virtual int			GetAvailable() const override;

		/* 30h */	virtual int		Read(void* pData, size_t nSize) override;
		/* 34h */	virtual bool	Flush() override;
		/* 38h */	virtual int		Write(const void* pData, size_t nSize) override;

		static const uint32_t kType = 0x025C9BB3;

	protected:
		/* 04h */	int mnRefCount;
	};

	///////////////////////////////////
	//// INTERNAL IMPLEMENENTATION ////
	///////////////////////////////////

	static_assert(sizeof(StreamNull) == 0x8, "sizeof(StreamNull) != 08h");

	namespace InternalAddressList(StreamNull)
	{
		DefineAddress(AddRef, GetAddress(0x93BB60, 0x93C350, 0x93C350));
		DefineAddress(Release, GetAddress(0x93BB70, 0x93C360, 0x93C360));
		DefineAddress(GetType, GetAddress(0x93C920, 0x93C340, 0x93C340));
		DefineAddress(GetAccessFlags, GetAddress(0x5D6800, 0x10E87E0, 0x10E87E0));
		DefineAddress(GetState, GetAddress(0x1065680, 0xE31100, 0xE310C0));
		DefineAddress(Close, GetAddress(0xA37650, 0xB1FB00, 0xB1FB30));
		DefineAddress(GetSize, GetAddress(0x1065680, 0xE31100, 0xE310C0));
		DefineAddress(SetSize, GetAddress(0xB5E030, 0xB7D4D0, 0xB7D550));
		DefineAddress(GetPosition, GetAddress(0x108DD90, 0x111CD70, 0x111CD70));
		DefineAddress(SetPosition, GetAddress(0xDDFB10, 0x88A5D0, 0x88A610));
		DefineAddress(GetAvailable, GetAddress(0x93C930, 0x93C380, 0x93C380));
		DefineAddress(Read, GetAddress(0x93C940, 0x93C390, 0x93C390));
		DefineAddress(Flush, GetAddress(0xA37650, 0xB1FB00, 0xB1FB30));
		DefineAddress(Write, GetAddress(0xDDFB10, 0x88A5D0, 0x88A610));
	}

}