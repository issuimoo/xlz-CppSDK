#include "Data_type.hpp"
#include "json/json.hpp"
#include "Text/Text.hpp"

class corn
{
public:
	void 初始化(文本型 _pluginkey, 文本型 _apidata);
	整数型 取API函数地址(文本型 函数名);
	文本型 输出日志(文本型 日志, 整数型 文字颜色 = 32768, 整数型 背景颜色 = 16777215);
private:
	文本型 pluginkey;
	nlohmann::json apidata;
};