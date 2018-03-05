#pragma once
/// This sample has not yet been fully assimiliated into the framework
/// and also the GL support is not quite fully there yet, hence the VR
/// is not that great!

// Include the Oculus SDK
#include "OVR_CAPI_GL.h"

#if defined(_WIN32)
#include <dxgi.h> // for GetDefaultAdapterLuid
#pragma comment(lib, "dxgi.lib")
#endif


typedef void* RenderFunc(const float* viewMat3x3, const float* projMat3x3);
struct TextureBuffer;
struct DepthBuffer;
class HMD_Framework
{
private:
	TextureBuffer*		eyeRenderTexture[2];
	DepthBuffer*		eyeDepthBuffer[2];
	ovrSizei			mirrorWindowSize;
	ovrMirrorTexture	mirrorTexture;
	unsigned int		mirrorFBO;
	long long			frameIndex;

	ovrSession session;
	ovrGraphicsLuid luid;
	bool isRunning;
public:
	int Main(HINSTANCE hinst);
	bool Initialize(ovrErrorType& error);
	void Shutdown();
	void Frame(ovrErrorType& error, RenderFunc sceneRenderFunction);
	bool IsRunning() { return isRunning; }

	HMD_Framework();
	~HMD_Framework();
};