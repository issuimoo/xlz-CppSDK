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
		0);
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
	try
	{
		std::int64_t r1;
		std::int32_t r2;
		std::int8_t* pic = SDK.ReadDiskFile("A:\\Users\\A1992\\OneDrive\\图片\\99956974.jpg");
		std::string ret = SDK.上传好友图片(1992724048, 1992724048, false, pic);
		SDK.发送好友消息(1992724048, 1992724048, ret,r1,r2);
		delete[] pic;
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