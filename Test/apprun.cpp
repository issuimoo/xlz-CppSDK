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
	try
	{
		资料展示设置数据 msg;
		SDK->取资料展示设置(1992724048, 3498896843, msg);
		SDK->输出日志(std::to_string(msg.年龄));
		SDK->群聊签到(1992724048, 756661453, "");
		SDK->头像双击_群(1992724048, 3427824586, 756661453);
	}
	catch (...) //事实证明并没有太大用处
	{

	}
	
	return 启用响应::启用响应_完成;
}

int _OnGroup(群消息数据* 数据指针)
{

	return 消息处理::消息处理_忽略;
}