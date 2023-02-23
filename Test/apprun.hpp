#include "../SDK/SDK.hpp"

API *SDK;

DLLOUT const char* apprun(const char* _apidata, const char* _pluginkey);

int _AppStart();

int _AppEnd();

int _AppUnload();

int _ControlPanel();

int _OnGroup(群消息数据* 数据指针);