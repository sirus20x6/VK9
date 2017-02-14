/*
Copyright(c) 2016 Christopher Joseph Dean Schaefer

This software is provided 'as-is', without any express or implied
warranty.In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions :

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software.If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
 
#ifndef CPIXELSHADER9_H
#define CPIXELSHADER9_H

#include "d3d9.h" // Base class: IDirect3DPixelShader9
#include <vulkan/vulkan.h>
#include "CResource9.h"
#include "ShaderConverter.h"

class CPixelShader9 : public IDirect3DPixelShader9
{
public:
	CPixelShader9(CDevice9* device,const DWORD* pFunction);
	~CPixelShader9();

	CDevice9* mDevice = nullptr;
	DWORD* mFunction = nullptr;

	ShaderConverter mShaderConverter;
	ConvertedShader mConvertedShader;

	ULONG mReferenceCount = 1;
	VkResult mResult = VK_SUCCESS;
public:
	//IUnknown
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid,void  **ppv);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);	
	virtual ULONG STDMETHODCALLTYPE Release(void);

	//IDirect3DResource9
	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice9** ppDevice);
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid);
	virtual DWORD STDMETHODCALLTYPE GetPriority();
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData);
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType();
	virtual void STDMETHODCALLTYPE PreLoad();
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew);
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void* pData, DWORD SizeOfData, DWORD Flags);

	//IDirect3DPixelShader9
	//virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice9** ppDevice);
	virtual HRESULT STDMETHODCALLTYPE GetFunction(void* pData, UINT* pSizeOfData);
};

#endif // CPIXELSHADER9_H
