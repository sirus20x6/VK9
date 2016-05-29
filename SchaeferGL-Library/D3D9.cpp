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
in a product, an acknowledgement in the product documentation would be
appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/
 
#include "D3D9.h"
#include <vulkan/vulkan.h>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include "C9.h"

IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
	boost::log::add_file_log("SchaeferGL.log");
	return new C9();
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, IDirect3D9Ex** out)
{
	out = NULL;

	//TODO: Implement, maybe.

	return E_NOTIMPL;
}

/* Other things to possibly implement.

D3DPERF_BeginEvent
D3DPERF_EndEvent
D3DPERF_SetMarker
D3DPERF_SetRegion
D3DPERF_QueryRepeatFrame
D3DPERF_SetOptions
D3DPERF_GetStatus
DXVA2CreateDirect3DDeviceManager9
DXVA2CreateVideoService
*/