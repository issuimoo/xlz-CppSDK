#include "apprun.hpp"

const char* apprun(const char* _apidata, const char* _pluginkey)
{
	const char* ret;
	SDK = new API(
		ret,
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
		0);
	return ret;
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
	delete SDK;
	return 启用响应::启用响应_完成;
}

int _ControlPanel()
{
	return 启用响应::启用响应_完成;
}

int _OnGroup(群消息数据* 数据指针)
{
	if (数据指针->发送人QQ == 1992724048 && std::string(数据指针->消息内容).find("喵~") == std::string::npos)
	{
		SDK->发送群消息(
			1992724048,
			数据指针->消息群号,
			"喵~",
			false);
	}
	if (数据指针->发送人QQ != 1992724048 && std::string(数据指针->消息内容).find(std::format("[@{}]", 1992724048)) != std::string::npos)
	{
		SDK->发送群消息(
			1992724048,
			数据指针->消息群号,
			"喵喵不知道,喵喵是一只会动的绒布球",
			false);
	}
	return 消息处理::消息处理_忽略;
}