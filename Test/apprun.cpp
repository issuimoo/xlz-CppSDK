#include "apprun.hpp"

文本型 apprun(文本型 _apidata, 文本型 _pluginkey)
{
	SDK.初始化(_pluginkey, _apidata);
	nlohmann::json json;
	json["sdkv"] = SDK版本;
	json["appname"] = "C++SDK";
	return json.dump().c_str();
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
	SDK.输出日志(Text::UTF8TOGBK("666").c_str());
	return 启用响应::启用响应_完成;
}