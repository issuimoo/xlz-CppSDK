﻿#include "apprun.hpp"

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

void GroupMsgInput(群消息数据* point);

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
	群消息数据* Msg = new 群消息数据;
	memcpy(Msg, 数据指针, sizeof 群消息数据);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)GroupMsgInput, Msg, NULL, NULL);
	return 消息处理::消息处理_忽略;
}

void GroupMsgInput(群消息数据* point)
{

	delete point;
}