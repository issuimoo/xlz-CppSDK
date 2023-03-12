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
	群消息数据* Msg = new 群消息数据(*数据指针);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)GroupMsg, Msg, NULL, NULL);
	return 消息处理::消息处理_忽略;
}

void GroupMsg(群消息数据* msg)
{
	Sleep(3000);
	try
	{
		if (757649840 == msg->消息群号 && std::string(msg->消息内容).find("msg:") == std::string::npos)
		{
			SDK->发送群消息(3498896843, msg->消息群号, std::format("msg:\n{}\n{}\n{}", msg->消息群号, msg->发送人群名片, _msize(msg->匿名标识)), false);
		}
	}
	catch (const std::exception& e)
	{

	}
	catch (...)
	{

	}
	delete msg;
}