#ifndef MODAPI_DLL_EXPORT
#include <Spore\Graphics\GeneratedMesh.h>

namespace Graphics
{
	using namespace RenderWare;

	const RenderWare::VertexElement PosNormalVertex::ELEMENTS[2] = {
		{0, offsetof(PosNormalVertex, pos), D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0, RWDECL_VERTEX_POSITION},
		{0, offsetof(PosNormalVertex, normal), D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0, RWDECL_VERTEX_NORMAL}
	};

	const RenderWare::VertexElement StandardVertex::ELEMENTS[4] = {
		{0, offsetof(StandardVertex, pos), D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0, RWDECL_VERTEX_POSITION},
		{0, offsetof(StandardVertex, uv), D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0, RWDECL_VERTEX_TEXCOORD0},
		{0, offsetof(StandardVertex, normal), D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0, RWDECL_VERTEX_NORMAL},
		{0, offsetof(StandardVertex, tangent), D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0, RWDECL_VERTEX_TANGENT}
	};
}
#endif