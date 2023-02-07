#include <Windows.h>

#include "SDK.hpp"

#include "fmt/format.h"

#include <fstream>

void corn::初始化(文本型 _pluginkey, 文本型 _apidata)
{
	pluginkey = _pluginkey;
	apidata = nlohmann::json::parse(Text::GBKTOUTF8(_apidata));
}

整数型 corn::取API函数地址(文本型 函数名)
{
	std::string func = Text::GBKTOUTF8(函数名);
	if (apidata.find(func) != apidata.end())
		return apidata[func];
	else
		MessageBox(NULL, fmt::format("未找到该函数 {}", 函数名).c_str(), "错误", NULL);
		return 0;
}

文本型 corn::输出日志(文本型 日志, 整数型 文字颜色, 整数型 背景颜色)
{
	return ((文本型(*)(文本型, 文本型, 整数型, 整数型))取API函数地址("输出日志"))(pluginkey, 日志, 文字颜色, 背景颜色);
}



