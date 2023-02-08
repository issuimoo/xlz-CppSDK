#include <Windows.h>

#include "Data_type.hpp"
#include "json/json.hpp"
#include "Text/Text.hpp"
#include "fmt/format.h"

#define DLLOUT extern "C" __declspec(dllexport)

static const char* SDK版本 = "CSDK 1.0";

class API
{
public:
	文本型 初始化(文本型 _pluginkey, 文本型 _apidata, 文本型 Name);
	整数型 取API函数地址(文本型 函数名);
	文本型 输出日志(文本型 日志, 整数型 文字颜色 = 32768, 整数型 背景颜色 = 16777215);
	文本型 发送好友消息(长整数型 框架QQ, 长整数型 好友QQ, 文本型 发送内容, 长整数型* Random = nullptr, 整数型* Req = nullptr);
	文本型 发送群消息(长整数型 框架QQ, 长整数型 群号, 文本型 发送内容, 逻辑型 匿名发送 = false);
	文本型 发送群临时消息(长整数型 框架QQ, 长整数型 群ID, 长整数型 对方QQ, 文本型 发送内容, 长整数型* Random = nullptr, 整数型* Req = nullptr);
	文本型 添加好友(长整数型 框架QQ, 长整数型 对方QQ, 文本型 问题答案 = "", 文本型 备注 = "");
	文本型 添加群(长整数型 框架QQ, 长整数型 群号, 文本型 验证消息 = "");
	文本型 删除好友(长整数型 框架QQ, 长整数型 对方QQ);
	文本型 置屏蔽好友(长整数型 框架QQ, 长整数型 对方QQ, 逻辑型 是否屏蔽 = true);
	文本型 置特别关心好友(长整数型 框架QQ, 长整数型 对方QQ, 逻辑型 是否关心 = true);
	文本型 发送好友json消息(长整数型 框架QQ, 长整数型 好友QQ, 文本型 json代码, 长整数型* Random = nullptr, 整数型* Req = nullptr);
	文本型 发送群json消息(长整数型 框架QQ, 长整数型 群号, 文本型 json代码, 逻辑型 匿名发送 = false);
	文本型 上传好友图片(长整数型 框架QQ, 长整数型 好友QQ, 字节集 pic, 逻辑型 是否闪照 = false, 整数型 宽度 = 0, 整数型 高度 = 0, 逻辑型 动图 = false, 文本型 预览文字 = "");
private:
	文本型 pluginkey;
	nlohmann::json apidata;
protected:
}static SDK;