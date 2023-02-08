#include "SDK.hpp"
文本型 API_Text::小黄豆表情(emoji 表情)
{
	return fmt::format("[bq{}]", (int)表情).c_str();
}
文本型 API::SDK信息()
{
	nlohmann::json json;
	json["SDKV"] = SDK版本;
	json["pluginkey"] = pluginkey;
	json["appapi"] = apidata;
	return json.dump().c_str();
}
文本型 API::初始化(文本型 _pluginkey, 文本型 _apidata, 文本型 Name)
{
	pluginkey = _pluginkey;
	apidata = nlohmann::json::parse(Text::GBKTOUTF8(_apidata));
	nlohmann::json json;
	json["sdkv"] = SDK版本;
	json["appname"] = Text::GBKTOUTF8(Name);
	return Text::UTF8TOGBK(json.dump()).c_str();
}
整数型 API::取API函数地址(文本型 函数名)
{
	std::string func = Text::GBKTOUTF8(函数名);
	if (apidata.find(func) != apidata.end())
		return apidata[func];
	else
		MessageBox(NULL, fmt::format("未找到该函数: {}", 函数名).c_str(), "错误", NULL);
		return 0;
}
文本型 API::输出日志(文本型 日志, 整数型 文字颜色, 整数型 背景颜色)
{
	return ((文本型(WINAPI*)(文本型, 文本型, 整数型, 整数型))取API函数地址("输出日志"))(pluginkey, 日志, 文字颜色, 背景颜色);
}
文本型 API::发送好友消息(长整数型 框架QQ, 长整数型 好友QQ, 文本型 发送内容, 长整数型* Random, 整数型* Req)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 长整数型*, 整数型*))取API函数地址("发送好友消息"))(pluginkey, 框架QQ, 好友QQ, 发送内容, Random, Req);
}
文本型 API::发送群消息(长整数型 框架QQ, 长整数型 群号, 文本型 发送内容, 逻辑型 匿名发送)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 逻辑型))取API函数地址("发送群消息"))(pluginkey, 框架QQ, 群号, 发送内容, 匿名发送);
}
文本型 API::发送群临时消息(长整数型 框架QQ, 长整数型 群ID, 长整数型 对方QQ, 文本型 发送内容, 长整数型* Random, 整数型* Req)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 长整数型, 文本型, 长整数型*, 整数型*))取API函数地址("发送群临时消息"))(pluginkey, 框架QQ, 群ID, 对方QQ, 发送内容, Random, Req);
}
文本型 API::添加好友(长整数型 框架QQ, 长整数型 对方QQ, 文本型 问题答案, 文本型 备注)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 文本型))取API函数地址("添加好友"))(pluginkey, 框架QQ, 对方QQ, 问题答案, 备注);
}
文本型 API::添加群(长整数型 框架QQ, 长整数型 群号, 文本型 验证消息)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型))取API函数地址("添加群"))(pluginkey, 框架QQ, 群号, 验证消息);
}
文本型 API::删除好友(长整数型 框架QQ, 长整数型 对方QQ)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型))取API函数地址("删除好友"))(pluginkey, 框架QQ, 对方QQ);
}
文本型 API::置屏蔽好友(长整数型 框架QQ, 长整数型 对方QQ, 逻辑型 是否屏蔽)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型))取API函数地址("置屏蔽好友"))(pluginkey, 框架QQ, 对方QQ, 是否屏蔽);
}
文本型 API::置特别关心好友(长整数型 框架QQ, 长整数型 对方QQ, 逻辑型 是否关心)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型))取API函数地址("置特别关心好友"))(pluginkey, 框架QQ, 对方QQ, 是否关心);
}
文本型 API::发送好友json消息(长整数型 框架QQ, 长整数型 好友QQ, 文本型 json代码, 长整数型* Random, 整数型* Req)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 长整数型*, 整数型*))取API函数地址("发送好友json消息"))(pluginkey, 框架QQ, 好友QQ, json代码, Random, Req);
}
文本型 API::发送群json消息(长整数型 框架QQ, 长整数型 群号, 文本型 json代码, 逻辑型 匿名发送)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 逻辑型))取API函数地址("发送群json消息"))(pluginkey, 框架QQ, 群号, json代码, 匿名发送);
}
文本型 API::上传好友图片(长整数型 框架QQ, 长整数型 好友QQ, 字节集 pic, 逻辑型 是否闪照, 整数型 宽度, 整数型 高度, 逻辑型 动图, 文本型 预览文字)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型, 字节集, 整数型))取API函数地址("上传好友图片"))(pluginkey, 框架QQ, 好友QQ, 是否闪照, pic, strlen((char*)pic) + 1);
	ret.pop_back();
	ret += fmt::format(",wide={},high={},cartoon={},str={}]", 宽度, 高度, (bool)动图, 预览文字);
	return ret.c_str();
}
文本型 API::上传群图片(长整数型 框架QQ, 长整数型 群号, 字节集 pic, 逻辑型 是否闪照, 整数型 宽度, 整数型 高度, 逻辑型 动图, 文本型 预览文字)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型, 字节集, 整数型))取API函数地址("上传群图片"))(pluginkey, 框架QQ, 群号, 是否闪照, pic, strlen((char*)pic) + 1);
	ret.pop_back();
	ret += fmt::format(",wide={},high={},cartoon={},str={}]", 宽度, 高度, (bool)动图, 预览文字);
	return ret.c_str();
}
文本型 API::上传好友语音(长整数型 框架QQ, 长整数型 好友QQ, 字节集 audio, 语音类型 类型, 文本型 语音文字, 整数型 时长)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 语音类型, 文本型, 字节集, 整数型))取API函数地址("上传好友语音"))(pluginkey, 框架QQ, 好友QQ, 类型, 语音文字, audio, strlen((char*)audio) + 1);
	ret.pop_back();
	ret += fmt::format(",time={}]", 时长);
	return ret.c_str();
}
文本型 API::上传群语音(长整数型 框架QQ, 长整数型 群号, 字节集 audio, 语音类型 类型, 文本型 语音文字, 整数型 时长)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 语音类型, 文本型, 字节集, 整数型))取API函数地址("上传群语音"))(pluginkey, 框架QQ, 群号, 类型, 语音文字, audio, strlen((char*)audio) + 1);
	ret.pop_back();
	ret += fmt::format(",time={}]", 时长);
	return ret.c_str();
}
文本型 API::上传头像(长整数型 框架QQ, 字节集 pic)
{
	return ((文本型(*)(文本型, 长整数型, 字节集))取API函数地址("上传头像"))(pluginkey, 框架QQ, pic);
}
字节集 API::silk解码(文本型 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1)
		输出日志("->corn文件夹缺少语音转码库，请自行到官网或交流群下载");
		return;
	if (_access(音频文件路径, 00) == -1)
		输出日志("->音频文件不存在");
		return;
	if (_access(".\\main\\data\\voice\\", 00) == -1)
		_mkdir(".\\main\\data\\voice\\");
	std::string voicefile = 音频文件路径;
	std::string Name = fmt::format(".\\main\\data\\voice\\{}.{}",
		std::to_string(10 * rand() % RAND_MAX + 1),
		voicefile.substr(voicefile.find_last_of('.') + 1));
	std::string buff;
	std::fstream bin(音频文件路径,std::ios::in);
	if (bin)
	{
		while (getline(bin, buff)){}
		bin.close();
	}
	else
	{
		return;
	}
	if (buff.substr(0,5) == "#!AMR")
	{
		system(fmt::format(".\\main\\corn\\ffmpeg -i \"{}\" \"{}.mp3\"", 音频文件路径, Name).c_str());
	}
	else
	{
		system(fmt::format(".\\main\\corn\\silk_v3_decoder \"{}\" \"{}.pcm\"", 音频文件路径, Name).c_str());
		system(fmt::format(".\\main\\corn\\ffmpeg -f s16le -ar 24000 -ac 1 -i  \"{}.pcm\" \"{}.mp3\"", Name, Name).c_str());
	}
	buff.clear();
	std::fstream bin2(Name, std::ios::in);
	while (getline(bin2, buff)) {}
	system(fmt::format("del \"{}.mp3\"", Name).c_str());
	system(fmt::format("del \"{}.pcm\"", Name).c_str());
	return (unsigned char*)buff.c_str();
}



