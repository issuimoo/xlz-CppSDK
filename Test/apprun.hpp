#include "../SDK/SDK.hpp"

corn SDK;

extern "C" __declspec(dllexport) 文本型 apprun(文本型 _apidata, 文本型 _pluginkey);

extern "C" __declspec(dllexport) 整数型 _AppStart();

extern "C" __declspec(dllexport) 整数型 _AppEnd();

extern "C" __declspec(dllexport) 整数型 _AppUnload();

extern "C" __declspec(dllexport) 整数型 _ControlPanel();