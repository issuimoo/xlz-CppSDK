#include "apprun.hpp"

const char* apprun(const char* _apidata, const char* _pluginkey)
{
	return SDK.初始化(
		_pluginkey,
		_apidata,
		"测试",
		"遂沫",
		"1.0",
		"",
		(unsigned int)&_AppStart,
		(unsigned int)&_AppEnd,
		(unsigned int)&_AppUnload,
		(unsigned int)&_ControlPanel,
		0,
		(unsigned int)&_OnGroup,
		0,
		0).c_str();
}

int _AppStart()
{
	
	return 启用响应::启用响应_完成;
}

int _AppEnd()
{
	
	return 启用响应::启用响应_完成;
}

int _AppUnload()
{

	return 启用响应::启用响应_完成;
}

int _ControlPanel()
{
	std::int64_t r2;
	std::int32_t r;

	SDK.发送好友消息(3498896843, 1992724048, "123", r2, r);

	MessageBox(NULL, std::format("R1:{}\nR2:{}", r2, r).c_str(), "", NULL);

	return 启用响应::启用响应_完成;
}

int _OnGroup(群消息数据* 数据指针)
{

	return 消息处理::消息处理_忽略;
}