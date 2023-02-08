#include "apprun.hpp"

文本型 apprun(文本型 _apidata, 文本型 _pluginkey)
{

	return SDK.初始化(_pluginkey, _apidata,"C++ SDK Demo");
}

整数型 _AppStart()
{
	
	return 启用响应::启用响应_完成;
}

整数型 _AppEnd()
{
	
	return 启用响应::启用响应_完成;
}

整数型 _AppUnload()
{

	return 启用响应::启用响应_完成;
}

整数型 _ControlPanel()
{
	SDK.发送群消息(3498896843, 829179397, "C++SDKTest", false);
	return 启用响应::启用响应_完成;
}