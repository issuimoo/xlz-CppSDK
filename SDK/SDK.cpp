#include <Windows.h>

#include "SDK.hpp"

void corn::初始化(文本型 _pluginkey, 文本型 _apidata)
{
	pluginkey = _pluginkey;
	apidata = Text::GBKTOUTF8(_apidata);
}

整数型 corn::取API函数地址(文本型 函数名)
{
	if (apidata.find(函数名) != apidata.end())
		return apidata[函数名];
	else
		return 0;
}

文本型 corn::输出日志(文本型 日志, 整数型 文字颜色, 整数型 背景颜色)
{
	MessageBox(NULL, (LPCSTR)std::to_string(取API函数地址(Text::GBKTOUTF8("输出日志").c_str())).c_str(), "", NULL);
	return ((文本型(*)(文本型, 整数型, 整数型))取API函数地址(Text::GBKTOUTF8("输出日志").c_str()))(日志, 文字颜色, 背景颜色);
}



