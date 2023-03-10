#include "SDK.hpp"

std::int8_t* API::ReadDiskFile(std::string File) //请使用delete []释放内存缓存区
{
	if (_access(File.c_str(), 00) == -1)
	return {};
	std::fstream bin(File, std::ios::in | std::ios::binary);
	bin.seekg(0, bin.end);
	unsigned int length = bin.tellg();
	bin.seekg(0, bin.beg);
	char* buffer = new char[length];
	bin.read(buffer, length);
	bin.close();
	return (std::int8_t*)buffer;
}

std::string API_Text::小黄豆表情(emoji 表情)
{
	return std::format("[bq{}]", (int)表情).c_str();
}
API::API(const char*& ret, const char* _pluginkey, const char* _apidata, std::string 插件名称, std::string 插件作者, std::string 插件版本, std::string 插件说明, std::int32_t 被启用处理函数, std::int32_t 被禁用处理函数, std::int32_t 将被卸载处理函数, std::int32_t 插件菜单处理函数, std::int32_t 私聊消息处理函数, std::int32_t 群聊消息处理函数, std::int32_t 频道推送统一处理函数, std::int32_t 事件消息处理函数)
{
	pluginkey = _pluginkey;
	apidata = nlohmann::json::parse(Text::GBKTOUTF8(_apidata));

	nlohmann::json json;
	json["sdkv"] = SDK版本;
	json["appname"] = Text::GBKTOUTF8(插件名称);
	json["author"] = Text::GBKTOUTF8(插件作者);
	json["appv"] = Text::GBKTOUTF8(插件版本);
	json["describe"] = Text::GBKTOUTF8(插件说明);
	if (被启用处理函数)
		json["useproaddres"] = 被启用处理函数;
	if (被禁用处理函数)
		json["banproaddres"] = 被禁用处理函数;
	if (将被卸载处理函数)
		json["unitproaddres"] = 将被卸载处理函数;
	if (插件菜单处理函数)
		json["setproaddres"] = 插件菜单处理函数;
	if (私聊消息处理函数)
		json["friendmsaddres"] = 私聊消息处理函数;
	if (群聊消息处理函数)
		json["groupmsaddres"] = 群聊消息处理函数;
	if (频道推送统一处理函数)
		json["ChannelFunc"] = 频道推送统一处理函数;
	if (事件消息处理函数)
		json["eventmsaddres"] = 事件消息处理函数;
	const char* 权限列表[] = { "输出日志", "发送好友消息", "发送群消息", "发送群临时消息", "添加好友", "添加群", "删除好友", "置屏蔽好友", "置特别关心好友", "发送好友xml消息", "发送群xml消息", "发送好友json消息", "发送群json消息", "上传好友图片", "上传群图片", "上传好友语音", "上传群语音", "上传头像", "设置群名片", "取昵称_从缓存", "强制取昵称", "获取skey", "获取pskey", "获取clientkey", "取框架QQ", "取好友列表", "取群列表", "取群成员列表", "设置管理员", "取管理层列表", "取群名片", "取个性签名", "修改昵称", "修改个性签名", "删除群成员", "禁言群成员", "退群", "解散群", "上传群头像", "全员禁言", "群权限_发起新的群聊", "群权限_发起临时会话", "群权限_上传文件", "群权限_上传相册", "群权限_邀请好友加群", "群权限_匿名聊天", "群权限_坦白说", "群权限_新成员查看历史消息", "群权限_邀请方式设置", "撤回消息_群聊", "撤回消息_私聊本身", "设置位置共享", "上报当前位置", "是否被禁言", "处理好友验证事件", "处理群验证事件", "查看转发聊天记录内容", "上传群文件", "创建群文件夹", "设置在线状态", "QQ点赞", "取图片下载地址", "查询好友信息", "查询群信息", "框架重启", "群文件转发至群", "群文件转发至好友", "好友文件转发至好友", "置群消息接收", "取群名称_从缓存", "取好友在线状态", "取QQ钱包个人信息", "获取订单详情", "提交支付验证码", "分享音乐", "更改群聊消息内容", "更改私聊消息内容", "群聊口令红包", "群聊拼手气红包", "群聊普通红包", "群聊画图红包", "群聊语音红包", "群聊接龙红包", "群聊专属红包", "好友口令红包", "好友普通红包", "好友画图红包", "好友语音红包", "好友接龙红包", "重命名群文件夹", "删除群文件夹", "删除群文件", "保存文件到微云", "移动群文件", "取群文件列表", "设置专属头衔", "下线指定QQ", "登录指定QQ", "取群未领红包", "发送输入状态", "修改资料", "打好友电话", "取群文件下载地址", "头像双击_好友", "头像双击_群", "取群成员简略信息", "群聊置顶", "私聊置顶", "取加群链接", "设为精华", "群权限_设置群昵称规则", "群权限_设置群发言频率", "群权限_设置群查找方式", "邀请好友加群", "置群内消息通知", "修改群名称", "下线其他设备", "登录网页取ck", "发送群公告", "取群成员信息", "取钱包cookie", "取群网页cookie", "转账", "取收款链接", "取群小视频下载地址", "取私聊小视频下载地址", "上传小视频", "取群成员概况", "添加好友_取验证类型", "群聊打卡", "群聊签到", "置群聊备注", "红包转发", "发送数据包", "请求ssoseq", "取sessionkey", "获取bkn_gtk", "置好友验证方式", "上传照片墙图片", "付款", "修改支付密码", "账号搜索", "添加群_取验证类型", "领取红包", "获取红包领取详情", "取好友文件下载地址", "删除群成员_批量", "取扩列资料", "取资料展示设置", "设置资料展示", "获取当前登录设备信息", "提取图片文字", "取消精华", "群权限_设置加群方式", "群权限_群幸运字符", "群权限_一起写", "取QQ空间cookie", "修改指定QQ缓存密码", "处理群验证事件_风险号", "查询网址安全性", "消息合并转发至好友", "消息合并转发至群", "禁言群匿名", "领取私聊普通红包", "领取群聊专属红包", "发送讨论组消息", "发送讨论组json消息", "发送讨论组xml消息", "发送讨论组临时消息", "撤回消息_讨论组", "回复QQ咨询会话", "发送订阅号私聊消息", "取讨论组名称_从缓存", "修改讨论组名称", "取讨论组成员列表", "强制取自身匿名Id", "取订阅号列表", "取讨论组列表", "邀请好友加群_批量", "邀请好友加入讨论组_批量", "讨论组口令红包", "讨论组拼手气红包", "讨论组普通红包", "讨论组画图红包", "讨论组语音红包", "讨论组接龙红包", "讨论组专属红包", "领取讨论组专属红包", "取讨论组未领红包", "取讨论组文件下载地址", "发送QQ咨询会话", "创建群聊", "取群应用列表", "退出讨论组", "群验证消息接收设置", "转让群", "修改好友备注", "删除讨论组成员", "讨论组文件转发至群", "讨论组文件转发至好友", "拉起群收款", "结束群收款", "查询群收款状态", "支付群收款", "消息合并转发至讨论组", "群收款_催单", "取好友Diy名片数据", "设置Diy名片", "好友生僻字红包", "群聊生僻字红包", "讨论组生僻字红包", "支付代付请求", "查询代付状态", "拉起代付", "取好友能量值与QID", "文字转语音", "翻译", "撤回消息_群聊s", "QQ列表_添加手表协议QQ", "QQ列表_二维码登录_拉取二维码", "QQ列表_二维码登录_查询二维码状态", "删除群成员_批量s", "拍一拍好友在线状态", "发送验证消息会话消息", "回复验证消息会话消息", "取群文件内存利用状态", "取群文件总数", "上传涂鸦", "上传好友文件s", "上传群文件s", "取群艾特全体剩余次数", "是否已开启QQ咨询", "创建群相册", "删除群相册", "取群相册列表", "取群相册照片列表", "删除群相册照片", "修改群相册信息", "取群Id_从缓存", "上传频道图片", "发送频道消息", "发送频道私信消息", "取私信频道Id", "频道消息粘贴表情", "撤回频道消息", "撤回频道私信消息", "设置子频道精华消息", "禁言频道成员", "设置频道全员禁言", "移除频道成员", "移除频道成员_批量", "退出频道", "更改频道名称", "修改频道简介", "设置我的频道昵称", "置子频道观看权限", "置子频道发言权限", "子频道消息提醒设置", "子频道慢速模式设置", "修改子频道名称", "删除子频道", "修改我的频道用户信息_昵称", "修改我的频道用户信息_性别", "修改我的频道用户信息_年龄", "修改我的频道用户信息_所在地", "设置是否允许别人私信我", "设置频道加入验证方式", "搜索频道", "取频道封面", "取频道头像", "获取频道成员列表", "取频道信息", "取频道加入验证方式", "申请加入频道", "取频道文件下载地址", "频道拼手气红包", "频道普通红包", "频道专属红包", "领取频道专属红包", "取频道成员身份组", "设置频道成员身份组", "修改身份组信息", "删除身份组", "新增身份组", "取频道身份组列表", "取子频道列表", "取频道用户个性档案", "取频道用户资料", "刷新频道列表缓存", "取频道列表_从缓存", "取频道用户昵称_从缓存", "取频道名称_从缓存", "取子频道名称_从缓存", "取频道昵称_从缓存", "取私信频道列表_从缓存", "取子频道分组列表", "上传频道文件", "更改频道消息内容", "Emoji转频道EmojiId", "频道EmojiId转Emoji", "Emoji转QQ空间EmId", "QQ空间EmId转Emoji", "小黄豆Id转QQ空间EmId", "QQ空间EmId转小黄豆Id", "取特定身份组成员列表", "取子频道分组结构", "设置子频道分组结构", "删除子频道_批量", "创建子频道", "构造卡片消息文本代码", "分享音乐_频道", "修改频道排序", "处理频道加入申请", "查询群设置", "取子频道管理列表", "设置子频道管理", "设置指定身份组子频道观看权限", "设置指定身份组子频道发言权限", "设置直播子频道主播", "获取频道分享链接", "获取子频道分享链接", "子频道消息通知设置", "获取红包领取详情s", "取话题子频道帖子列表", "获取日程列表", "获取日程链接", "取日程信息", "创建日程", "取QQ头像K值", "删除日程", "发送通行证到群", "发送通行证到好友", "屏蔽频道用户私信", "频道用户私信免打扰", "QQ列表_添加QQ", "QQ列表_删除QQ", "登录指定QQ_二次登录", "取框架插件列表", "取在线移动设备列表", "设置频道全局公告_指定消息", "取频道号", "设置位置共享s", "上报当前位置s", "移动好友分组", "修改好友分组名", "删除好友分组", "取好友分组列表", "新增好友分组", "取频道红包pre_grap_token", "语音红包匹配", "上传群聊语音红包匹配语音", "取合并转发消息内容", "上传合并转发消息", "语音转文字", "发送功能包", "二维码扫一扫授权登录其他应用", "取历史登录设备guid列表", "二维码扫一扫授权其他设备资料辅助验证登录", "关闭设备锁", "恢复设备锁", "余额提现", "取h5钱包cookie", "取QQ会员中心cookie", "说说点赞", "说说评论", "取最新动态列表", "搜索表情包", "发布说说", "经纬度定位查询详细地址", "上传群临时文件s", "删除说说", "上传QQ封面" };
	for (int i = 0; i < sizeof 权限列表 / sizeof 权限列表[0]; i++)
	{
		if(权限列表[i] != "")
			json["data"]["needapilist"][Text::GBKTOUTF8(权限列表[i])]["desc"] = Text::GBKTOUTF8("CSDK必须");
	}

	ret = Text::UTF8TOGBK(json.dump()).c_str();
}
API::~API()
{
	apidata.clear();
	pluginkey.clear();
}
const std::int8_t* API::silk解码(std::string 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1 || 
		_access(".\\main\\corn\\silk_v3_decoder.exe", 00) == -1) //判断转码程序是否存在
		输出日志("silk解码->corn文件夹缺少语音转码库，请自行到官网或交流群下载"); //不存在输出错误日志
		return {};
	if (_access(音频文件路径.c_str(), 00) == -1) //判断音频文件是否存在
		输出日志("silk解码->音频文件不存在"); //不存在输出错误日志
		return {};
	if (_access(".\\main\\data\\voice\\", 00) == -1) //判断缓存目录是否存在
		_mkdir(".\\main\\data\\voice\\"); //不存在就创建
	std::string voicefile = 音频文件路径; //const char* 转 string
	std::string Name = std::format(".\\main\\data\\voice\\{}.{}",
		std::to_string(10 * rand() % RAND_MAX + 1),
		voicefile.substr(voicefile.find_last_of('.') + 1)); //新文件路径名
	std::string buff; //音频转文本
	std::fstream bin(音频文件路径,std::ios::in | std::ios::binary); //读入音频文件
	bin.seekg(0, bin.end); //移至文件末尾
	unsigned int length = bin.tellg(); //计算文件大小
	bin.seekg(0, bin.beg); //移至文件开始
	char* buffer = new char[length]; //创建内存缓存区
	bin.read(buffer, length); //写入缓存区
	buff = buffer; //音频转文本
	bin.close(); //关闭文件
	if (buff.substr(0,5) == "#!AMR") //判断编码格式
	{
		system(std::format(".\\main\\corn\\ffmpeg -i \"{}\" \"{}.mp3\"", 音频文件路径, Name).c_str());
	}
	else
	{
		system(std::format(".\\main\\corn\\silk_v3_decoder \"{}\" \"{}.pcm\"", 音频文件路径, Name).c_str());
		system(std::format(".\\main\\corn\\ffmpeg -f s16le -ar 24000 -ac 1 -i  \"{}.pcm\" \"{}.mp3\"", Name, Name).c_str());
	}
	buff.clear(); //清除文本
	delete[] buffer; //删除缓存区
	std::fstream bin2(Name + ".mp3", std::ios::in | std::ios::binary); //读取转换完成音频
	bin2.seekg(0, bin2.end); //移至文件末尾
	unsigned int length2 = bin2.tellg(); //计算文件大小
	bin2.seekg(0, bin2.beg); //移至文件开始
	char* buffer2 = new char[length2];  //创建内存缓存区 +1分给\0
	bin2.read(buffer2,length2); //写入缓存区
	bin2.close(); //关闭文件
	system(std::format("del \"{}.mp3\"", Name).c_str()); //删除硬盘文件
	system(std::format("del \"{}.pcm\"", Name).c_str()); //删除硬盘文件
	输出日志("silk解码->解码完成");
	return (std::int8_t*)buffer2; //返回缓冲区 请使用delete []释放内存缓存区
}
const std::int8_t* API::silk编码(std::string 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1 ||
		_access(".\\main\\corn\\silk_v3_decoder.exe", 00) == -1) //判断转码程序是否存在
		输出日志("silk编码->corn文件夹缺少语音转码库，请自行到官网或交流群下载"); //不存在输出错误日志
	return {};
	if (_access(音频文件路径.c_str(), 00) == -1) //判断音频文件是否存在
		输出日志("silk编码->音频文件不存在"); //不存在输出错误日志
	return {};
	if (_access(".\\main\\data\\voice\\", 00) == -1) //判断缓存目录是否存在
		_mkdir(".\\main\\data\\voice\\"); //不存在就创建
	std::string voicefile = 音频文件路径; //const char* 转 string
	std::string Name = std::format(".\\main\\data\\voice\\{}.{}",
		std::to_string(10 * rand() % RAND_MAX + 1),
		voicefile.substr(voicefile.find_last_of('.') + 1)); //新文件路径名
	system(std::format(".\\main\\corn\\ffmpeg -i \"{}\" -f s16le -ar 24000 -ac 1 -acodec pcm_s16le \"{}.pcm\"", 音频文件路径, Name).c_str());
	system(std::format(".\\main\\corn\\silkencoder pts -i \"{}.pcm\" -o \"{}.silk\" -s 24000", Name, Name).c_str());
	std::fstream bin(Name + ".silk", std::ios::in | std::ios::binary);
	bin.seekg(0, bin.end);
	unsigned int length = bin.tellg();
	bin.seekg(0, bin.beg);
	char* buffer = new char[length];
	bin.read(buffer, length);
	bin.close();
	system(std::format("del \"{}.pcm\"", Name).c_str());
	system(std::format("del \"{}.silk\"", Name).c_str());
	输出日志("silk编码->编码完成");
	return (std::int8_t*)buffer;
}
const std::int8_t* API::amr编码(std::string 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1 ||
		_access(".\\main\\corn\\silk_v3_decoder.exe", 00) == -1) //判断转码程序是否存在
		输出日志("amr编码->corn文件夹缺少语音转码库，请自行到官网或交流群下载"); //不存在输出错误日志
	return {};
	if (_access(音频文件路径.c_str(), 00) == -1) //判断音频文件是否存在
		输出日志("amr编码->音频文件不存在"); //不存在输出错误日志
	return {};
	if (_access(".\\main\\data\\voice\\", 00) == -1) //判断缓存目录是否存在
		_mkdir(".\\main\\data\\voice\\"); //不存在就创建
	std::string voicefile = 音频文件路径; //const char* 转 string
	std::string Name = std::format(".\\main\\data\\voice\\{}.{}",
		std::to_string(10 * rand() % RAND_MAX + 1),
		voicefile.substr(voicefile.find_last_of('.') + 1)); //新文件路径名
	system(std::format(".\\main\\corn\\ffmpeg -i \"{}\" -f wav \"{}.wav\"", 音频文件路径, Name).c_str());
	system(std::format(".\\main\\corn\\ffmpeg -i \"{}.wav\" -ar 8000 -ab 12.2k -ac 1 \"{}.amr\"", Name, Name).c_str());
	std::fstream bin(Name + ".amr", std::ios::in | std::ios::binary);
	bin.seekg(0, bin.end);
	unsigned int length = bin.tellg();
	bin.seekg(0, bin.beg);
	char* buffer = new char[length];
	bin.read(buffer, length);
	bin.close();
	system(std::format("del \"{}.wav\"", Name).c_str());
	system(std::format("del \"{}.amr\"", Name).c_str());
	输出日志("amr编码->编码完成");
	return (std::int8_t*)buffer;
}
std::int32_t API::取API函数地址(std::string 函数名)
{
	std::string func = Text::GBKTOUTF8(函数名);
	if (apidata.find(func) != apidata.end())
		return apidata[func];
	else
		return 0;
}
std::string API::输出日志(std::string 日志, std::int32_t 文字颜色, std::int32_t 背景颜色)
{
	std::string ret = ((const char* (WINAPI*)(const char*, const char*, std::int32_t, std::int32_t))取API函数地址("输出日志"))(pluginkey.c_str(), 日志.c_str(), 文字颜色, 背景颜色);
	return ret;
}
std::string API::发送好友消息(std::int64_t 框架QQ, std::int64_t 好友QQ, std::string 发送内容, std::int64_t& Random, std::int32_t& Req)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char* , std::int64_t&, std::int32_t&))取API函数地址("发送好友消息"))(pluginkey.c_str(), 框架QQ, 好友QQ, 发送内容.c_str(), Random, Req);
	return ret;
}
std::string API::发送群消息(std::int64_t 框架QQ, std::int64_t 群号, std::string 发送内容, bool 匿名发送)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, bool))取API函数地址("发送群消息"))(pluginkey.c_str(), 框架QQ, 群号, 发送内容.c_str(), 匿名发送);
	return ret;
}
std::string API::发送群临时消息(std::int64_t 框架QQ, std::int64_t 群ID, std::int64_t 对方QQ, std::string 发送内容, std::int64_t& Random, std::int32_t& Req)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, const char*, std::int64_t&, std::int32_t&))取API函数地址("发送群临时消息"))(pluginkey.c_str(), 框架QQ, 群ID, 对方QQ, 发送内容.c_str(), Random, Req);
	return ret;
}
std::string API::添加好友(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string 问题答案, std::string 备注)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*))取API函数地址("添加好友"))(pluginkey.c_str(), 框架QQ, 对方QQ, 问题答案.c_str(), 备注.c_str());
	return ret;
}
std::string API::添加群(std::int64_t 框架QQ, std::int64_t 群号, std::string 验证消息)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("添加群"))(pluginkey.c_str(), 框架QQ, 群号, 验证消息.c_str());
	return ret;
}
std::string API::删除好友(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("删除好友"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	return ret;
}
std::string API::置屏蔽好友(std::int64_t 框架QQ, std::int64_t 对方QQ, bool 是否屏蔽)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t,bool))取API函数地址("置屏蔽好友"))(pluginkey.c_str(), 框架QQ, 对方QQ,是否屏蔽);
	return ret;
}
std::string API::置特别关心好友(std::int64_t 框架QQ, std::int64_t 对方QQ, bool 是否关心)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t,bool))取API函数地址("置特别关心好友"))(pluginkey.c_str(), 框架QQ, 对方QQ,是否关心);
	return ret;
}
std::string API::发送好友json消息(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string json代码, std::int64_t& Random, std::int32_t& Req)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, std::int64_t&, std::int32_t&))取API函数地址("发送好友json消息"))(pluginkey.c_str(), 框架QQ, 对方QQ, json代码.c_str(), Random, Req);
	return ret;
}
std::string API::发送群json消息(std::int64_t 框架QQ, std::int64_t 群号, std::string json代码, bool 匿名发送)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, bool))取API函数地址("发送群json消息"))(pluginkey.c_str(), 框架QQ, 群号, json代码.c_str(), 匿名发送);
	return ret;
}
std::string API::上传好友图片(std::int64_t 框架QQ, std::int64_t 好友QQ, bool 是否闪照, const std::int8_t* pic, std::int32_t 宽度, std::int32_t 高度, bool 动图, std::string 预览文字)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, bool, const std::int8_t*, std::int32_t))取API函数地址("上传好友图片"))(pluginkey.c_str(), 框架QQ, 好友QQ, 是否闪照, pic, _msize((void*)pic));
	ret.pop_back();
	ret = std::format("{},wide={},high={},cartoon={},str={}]", ret, 宽度, 高度, 动图, 预览文字);//F**K Bug 浪费人生3小时
	return ret;
}
std::string API::上传群图片(std::int64_t 框架QQ, std::int64_t 群号, bool 是否闪照, const std::int8_t* pic, std::int32_t 宽度, std::int32_t 高度, bool 动图, std::string 预览文字)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, bool, const std::int8_t*, std::int32_t))取API函数地址("上传群图片"))(pluginkey.c_str(), 框架QQ, 群号, 是否闪照, pic, _msize((void*)pic));
	ret.pop_back();
	ret = std::format("{},wide={},high={},cartoon={},str={}]", ret, 宽度, 高度, 动图, 预览文字);//F**K Bug 浪费人生3小时
	return ret;
}
std::string API::上传好友语音(std::int64_t 框架QQ, std::int64_t 好友QQ, std::int32_t 语音类型, std::string 语音文字, const std::int8_t* audio, std::int32_t 时长)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int32_t, const char*,const std::int8_t*))取API函数地址("上传好友语音"))(pluginkey.c_str(), 框架QQ, 好友QQ, 语音类型, 语音文字.c_str(), audio);
	ret.pop_back();
	ret = std::format("{},time={}]", ret, 时长);//F**K Bug 浪费人生3小时
	return ret;
}
std::string API::上传群语音(std::int64_t 框架QQ, std::int64_t 好友QQ, std::int32_t 语音类型, std::string 语音文字, const std::int8_t* audio, std::int32_t 时长)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int32_t, const char*,const std::int8_t*))取API函数地址("上传群语音"))(pluginkey.c_str(), 框架QQ, 好友QQ, 语音类型, 语音文字.c_str(), audio);
	ret.pop_back();
	ret = std::format("{},time={}]", ret, 时长);//F**K Bug 浪费人生3小时
	return ret;
}
std::string API::上传头像(std::int64_t 框架QQ, const std::int8_t* pic)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, const std::int8_t*))取API函数地址("上传头像"))(pluginkey.c_str(), 框架QQ, pic);
	return ret;
}
std::string API::设置群名片(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, std::string 新名片)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, const char*))取API函数地址("设置群名片"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ, 新名片.c_str());
	return ret;
}
std::string API::取昵称_从缓存(std::string 对方QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, const char*))取API函数地址("取昵称_从缓存"))(pluginkey.c_str(), 对方QQ.c_str());
	return ret;
}
std::string API::强制取昵称(std::int64_t 框架QQ, std::string 对方QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, const char*))取API函数地址("强制取昵称"))(pluginkey.c_str(), 框架QQ, 对方QQ.c_str());
	return ret;
}
std::string API::取群名称_从缓存(std::string 群号)
{
	std::string ret = ((const char* (WINAPI*)(const char*, const char*))取API函数地址("取群名称_从缓存"))(pluginkey.c_str(), 群号.c_str());
	return ret;
}
std::string API::获取skey(std::int64_t 框架QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t))取API函数地址("获取skey"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
std::string API::获取pskey(std::int64_t 框架QQ, std::string 域)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, const char*))取API函数地址("获取pskey"))(pluginkey.c_str(), 框架QQ, 域.c_str());
	return ret;
}
std::string API::获取clientkey(std::int64_t 框架QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t))取API函数地址("获取clientkey"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
nlohmann::json API::取框架QQ()
{
	std::string ret = ((const char* (WINAPI*)(const char*))取API函数地址("取框架QQ"))(pluginkey.c_str());
	ret = Text::GBKTOUTF8(ret);
	nlohmann::json json = nlohmann::json::parse(ret);
	return json;
}
std::int32_t API::取好友列表(std::int64_t 框架QQ, std::vector<好友信息>& 数据)
{
	earray_head arr;
	std::int32_t ret = ((std::int32_t(WINAPI*)(const char*, std::int64_t, void**))取API函数地址("取好友列表"))(pluginkey.c_str(), 框架QQ, arr);
	earray1d2vector<好友信息, 好友信息>(arr, 数据);
	return ret;
}
std::int32_t API::取群列表(std::int64_t 框架QQ, std::vector<群信息>& 数据)
{
	earray_head arr;
	std::int32_t ret = ((std::int32_t(WINAPI*)(const char*, std::int64_t, void**))取API函数地址("取群列表"))(pluginkey.c_str(), 框架QQ, arr);
	earray1d2vector<群信息, 群信息>(arr, 数据);
	return ret;
}
std::int32_t API::取群成员列表(std::int64_t 框架QQ, std::int64_t 群号, std::vector<群成员信息>& 数据)
{
	earray_head arr;
	std::int32_t ret = ((std::int32_t(WINAPI*)(const char*, std::int64_t, std::int64_t, void**))取API函数地址("取群成员列表"))(pluginkey.c_str(), 框架QQ, 群号, arr);
	earray1d2vector<群成员信息, 群成员信息>(arr, 数据);
	return ret;
}
bool API::设置管理员(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, bool 取消管理)
{
	bool ret = ((bool(WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, bool))取API函数地址("设置管理员"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ, 取消管理);
	return ret;
}
std::string API::取管理层列表(std::int64_t 框架QQ, std::int64_t 群号)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("取管理层列表"))(pluginkey.c_str(), 框架QQ, 群号);
	return ret;
}
std::string API::取群名片(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t))取API函数地址("取群名片"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ);
	return ret;
}
std::string API::取个性签名(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("取个性签名"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	return ret;
}
bool API::修改昵称(std::int64_t 框架QQ, std::string 昵称)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, const char*))取API函数地址("修改昵称"))(pluginkey.c_str(), 框架QQ, 昵称.c_str());
	return ret;
}
bool API::修改个性签名(std::int64_t 框架QQ, std::string 签名, std::string 签名地点)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, const char*, const char*))取API函数地址("修改个性签名"))(pluginkey.c_str(), 框架QQ, 签名.c_str(), 签名地点.c_str());
	return ret;
}
bool API::删除群成员(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, bool 拒绝加群申请)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, bool))取API函数地址("删除群成员"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ, 拒绝加群申请);
	return ret;
}
bool API::禁言群成员(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, std::int32_t 禁言时长)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int32_t))取API函数地址("禁言群成员"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ, 禁言时长);
	return ret;
}
bool API::退群(std::int64_t 框架QQ, std::int64_t 群号)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("退群"))(pluginkey.c_str(), 框架QQ, 群号);
	return ret;
}
bool API::解散群(std::int64_t 框架QQ, std::int64_t 群号)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("解散群"))(pluginkey.c_str(), 框架QQ, 群号);
	return ret;
}
bool API::上传群头像(std::int64_t 框架QQ, std::int64_t 群号, const std::int8_t* pic)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const std::int8_t*))取API函数地址("上传群头像"))(pluginkey.c_str(), 框架QQ, 群号, pic);
	return ret;
}
bool API::全员禁言(std::int64_t 框架QQ, std::int64_t 群号, bool 是否开启)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("全员禁言"))(pluginkey.c_str(), 框架QQ, 群号, 是否开启);
	return ret;
}
bool API::群权限_发起新的群聊(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_发起新的群聊"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_发起临时会话(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_发起临时会话"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_上传文件(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_上传文件"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_上传相册(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_上传相册"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_邀请好友加群(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_邀请好友加群"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_匿名聊天(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_匿名聊天"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_坦白说(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_坦白说"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_新成员查看历史消息(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_新成员查看历史消息"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
bool API::群权限_邀请方式设置(std::int64_t 框架QQ, std::int64_t 群号, 审核方式 方式)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, 审核方式))取API函数地址("群权限_邀请方式设置"))(pluginkey.c_str(), 框架QQ, 群号, 方式);
	return ret;
}
bool API::撤回消息_群聊(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t Random, std::int32_t Req)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int32_t))取API函数地址("撤回消息_群聊"))(pluginkey.c_str(), 框架QQ, 群号, Random, Req);
	return ret;
}
bool API::撤回消息_私聊本身(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int64_t Random, std::int32_t Req, std::int32_t 消息接收时间)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int32_t, std::int32_t))取API函数地址("撤回消息_私聊本身"))(pluginkey.c_str(), 框架QQ, 对方QQ, Random, Req, 消息接收时间);
	return ret;
}
bool API::设置位置共享(std::int64_t 框架QQ, std::int64_t 群号, double 经度, double 纬度, bool 是否开启)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, double, double, bool))取API函数地址("设置位置共享"))(pluginkey.c_str(), 框架QQ, 群号, 经度, 纬度, 是否开启);
	return ret;
}
bool API::上报当前位置(std::int64_t 框架QQ, std::int64_t 群号, double 经度, double 纬度)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, double, double))取API函数地址("上报当前位置"))(pluginkey.c_str(), 框架QQ, 群号, 经度, 纬度);
	return ret;
}
std::int64_t API::是否被禁言(std::int64_t 框架QQ, std::int64_t 群号)
{
	std::int64_t ret = ((std::int64_t (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("是否被禁言"))(pluginkey.c_str(), 框架QQ, 群号);
	return ret;
}
void API::处理群验证事件(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 触发QQ, std::int64_t 消息Seq, 操作类型 操作, 群事件 事件类型, std::string 拒绝理由)
{
	((void (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int64_t, 操作类型, 群事件, const char*))取API函数地址("处理群验证事件"))(pluginkey.c_str(), 框架QQ, 来源群号, 触发QQ, 消息Seq, 操作, 事件类型, 拒绝理由.c_str());
}
void API::处理好友验证事件(std::int64_t 框架QQ, std::int64_t 触发QQ, std::int64_t 消息Seq, 操作类型 操作)
{
	((void (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, 操作类型))取API函数地址("处理好友验证事件"))(pluginkey.c_str(), 框架QQ, 触发QQ, 消息Seq, 操作);
}
void API::查看转发聊天记录内容(std::int64_t 框架QQ, std::string resId, std::vector<群消息数据>& 消息内容)
{
	earray_head earr;
	((void (WINAPI*)(const char*, std::int64_t, const char*,void**))取API函数地址("查看转发聊天记录内容"))(pluginkey.c_str(), 框架QQ, resId.c_str(), earr);
	earray1d2vector<群消息数据, 群消息数据>(earr, 消息内容);
}
std::string API::上传群文件(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件路径, std::string 文件夹名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*))取API函数地址("上传群文件"))(pluginkey.c_str(), 框架QQ, 群号, 文件路径.c_str(), 文件夹名.c_str());
	return ret;
}
std::string API::创建群文件夹(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件夹名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("创建群文件夹"))(pluginkey.c_str(), 框架QQ, 群号, 文件夹名.c_str());
	return ret;
}
std::string API::重命名群文件夹(std::int64_t 框架QQ, std::int64_t 群号, std::string 旧文件夹名, std::string 新文件夹名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*))取API函数地址("重命名群文件夹"))(pluginkey.c_str(), 框架QQ, 群号, 旧文件夹名.c_str(), 新文件夹名.c_str());
	return ret;
}
std::string API::删除群文件夹(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件夹名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("删除群文件夹"))(pluginkey.c_str(), 框架QQ, 群号, 文件夹名.c_str());
	return ret;
}
std::string API::删除群文件(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件fileid, std::string 文件夹名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*))取API函数地址("删除群文件"))(pluginkey.c_str(), 框架QQ, 群号, 文件fileid.c_str(), 文件夹名.c_str());
	return ret;
}
std::string API::保存文件到微云(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件fileid)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("保存文件到微云"))(pluginkey.c_str(), 框架QQ, 群号, 文件fileid.c_str());
	return ret;
}
std::string API::移动群文件(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件fileid, std::string 当前文件夹名, std::string 目标文件夹名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*, const char*))取API函数地址("移动群文件"))(pluginkey.c_str(), 框架QQ, 群号, 文件fileid.c_str(), 当前文件夹名.c_str(), 目标文件夹名.c_str());
	return ret;
}
std::string API::取群文件列表(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件夹名, std::vector<群文件信息>& 数据)
{
	earray_head earr;
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, void**))取API函数地址("取群文件列表"))(pluginkey.c_str(), 框架QQ, 群号, 文件夹名.c_str(), earr);
	earray1d2vector<群文件信息, 群文件信息>(earr, 数据);
	return ret;
}
bool API::设置在线状态(std::int64_t 框架QQ, 在线状态 main, 在线状态V2 sun, std::int32_t 电量)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, 在线状态, 在线状态V2, std::int32_t))取API函数地址("设置在线状态"))(pluginkey.c_str(), 框架QQ, main, sun, 电量);
	return ret;
}
std::string API::取插件数据目录()
{
	std::string ret = ((const char* (WINAPI*)(const char*))取API函数地址("取插件数据目录"))(pluginkey.c_str());
	return ret;
}
std::string API::QQ点赞(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("QQ点赞"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	return ret;
}
std::string API::取图片下载地址(std::string 图片代码, std::int64_t 框架QQ, std::int64_t 群号)
{
	std::string ret = ((const char* (WINAPI*)(const char*, const char*, std::int64_t, std::int64_t))取API函数地址("取图片下载地址"))(pluginkey.c_str(), 图片代码.c_str(), 框架QQ, 群号);
	return ret;
}
bool API::查询好友信息(std::int64_t 框架QQ, std::int64_t 对方QQ, 好友信息& 数据)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, 好友信息&))取API函数地址("查询好友信息"))(pluginkey.c_str(), 框架QQ, 对方QQ, 数据);
	return ret;
}
bool API::查询群信息(std::int64_t 框架QQ, std::int64_t 群号, 群卡片信息& 数据)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, 群卡片信息&))取API函数地址("查询群信息"))(pluginkey.c_str(), 框架QQ, 群号, 数据);
	return ret;
}
void API::框架重启()
{
	((void (WINAPI*)(const char*))取API函数地址("框架重启"))(pluginkey.c_str());
}
bool API::群文件转发至群(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 目标群号, std::string fileId)
{

	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, const char*))取API函数地址("群文件转发至群"))(pluginkey.c_str(), 框架QQ, 来源群号, 目标群号, fileId.c_str());
	return ret;
}
bool API::群文件转发至好友(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 目标QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time)
{
	std::int32_t req, * ereq = &req, time_o,* etime = &time_o;
	std::int64_t ran, * eran = &ran;
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, const char*, const char*, std::int64_t, std::int32_t**, std::int64_t**, std::int32_t**))取API函数地址("群文件转发至好友"))(pluginkey.c_str(), 框架QQ, 来源群号, 目标QQ, fileId.c_str(), filename.c_str(), filesize, &ereq, &eran, &etime);
	Req = req;
	Random = ran;
	time = time_o;
	return ret;
}
bool API::好友文件转发至好友(std::int64_t 框架QQ, std::int64_t 目标QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time)
{
	std::int32_t req, * ereq = &req, time_o, * etime = &time_o;
	std::int64_t ran, * eran = &ran;
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*, std::int64_t, std::int32_t**, std::int64_t**, std::int32_t**))取API函数地址("好友文件转发至好友"))(pluginkey.c_str(), 框架QQ, 目标QQ, fileId.c_str(), filename.c_str(), filesize, &ereq, &eran, &etime);
	Req = req;
	Random = ran;
	time = time_o;
	return ret;
}
bool API::置群消息接收(std::int64_t 框架QQ, std::int64_t 群号, 接收类型 设置类型)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, 接收类型))取API函数地址("置群消息接收"))(pluginkey.c_str(), 框架QQ, 群号, 设置类型);
	return ret;
}
std::string API::取好友在线状态(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("取好友在线状态"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	return ret;
}
std::string API::取QQ钱包个人信息(std::int64_t 框架QQ, QQ钱包信息& 数据)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, QQ钱包信息&))取API函数地址("取QQ钱包个人信息"))(pluginkey.c_str(), 框架QQ, 数据);
	return ret;
}
std::string API::获取订单详情(std::int64_t 框架QQ, std::string 订单号, 订单详情& 数据)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, 订单详情&))取API函数地址("获取订单详情"))(pluginkey.c_str(), 框架QQ, 数据);
	return ret;
}
std::string API::提交支付验证码(std::int64_t 框架QQ, 验证码信息 信息, std::string 验证码, std::string 支付密码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, 验证码信息, const char*, const char*))取API函数地址("提交支付验证码"))(pluginkey.c_str(), 框架QQ, 信息, 验证码.c_str(), 支付密码.c_str());
	return ret;
}
bool API::分享音乐(std::int64_t 框架QQ, std::int64_t 分享对象, std::string 歌曲名, std::string 歌手名, std::string 跳转地址, std::string 封面地址, std::string 文件地址, 音乐应用类型 应用类型, 音乐分享类型 分享类型)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*, const char*, const char*, const char*, 音乐应用类型, 音乐分享类型))取API函数地址("分享音乐"))(pluginkey.c_str(), 框架QQ, 分享对象, 歌曲名.c_str(), 跳转地址.c_str(), 封面地址.c_str(), 封面地址.c_str(), 文件地址.c_str(), 应用类型, 分享类型);
	return ret;
}
bool API::更改群聊消息内容(std::int32_t 数据指针, std::string 新消息内容)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int32_t, const char*))取API函数地址("更改群聊消息内容"))(pluginkey.c_str(), 数据指针, 新消息内容.c_str());
	return ret;
}
bool API::更改私聊消息内容(std::int32_t 数据指针, std::string 新消息内容)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int32_t, const char*))取API函数地址("更改私聊消息内容"))(pluginkey.c_str(), 数据指针, 新消息内容.c_str());
	return ret;
}
std::string API::群聊口令红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊口令红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 口令.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::群聊拼手气红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, std::int32_t, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊拼手气红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 祝福语.c_str(), 红包皮肤Id, 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::群聊普通红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, std::int32_t, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊普通红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 祝福语.c_str(), 红包皮肤Id, 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::群聊画图红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 题目名, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊画图红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 题目名.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::群聊语音红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 语音口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊语音红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 语音口令.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::群聊接龙红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 接龙内容, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊接龙红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 接龙内容.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::群聊专属红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 领取人, std::string 祝福语, bool 是否均分, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, bool, const char*, std::int32_t, 验证码信息&))取API函数地址("群聊专属红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 群号, 领取人.c_str(), 祝福语.c_str(), 是否均分, 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::好友口令红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("好友口令红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 对方QQ, 口令.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::好友普通红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, std::int32_t, const char*, std::int32_t, 验证码信息&))取API函数地址("好友普通红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 对方QQ, 祝福语.c_str(), 红包皮肤Id, 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::好友画图红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 题目名, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("好友画图红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 对方QQ, 题目名.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::好友语音红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 语音口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("好友语音红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 对方QQ, 语音口令.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::好友接龙红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 接龙内容, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int64_t, const char*, const char*, std::int32_t, 验证码信息&))取API函数地址("好友接龙红包"))(pluginkey.c_str(), 框架QQ, 总数量, 总金额, 对方QQ, 接龙内容.c_str(), 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
bool API::设置专属头衔(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, std::string 头衔)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, const char*))取API函数地址("设置专属头衔"))(pluginkey.c_str(), 框架QQ, 群号, 对方QQ, 头衔.c_str());
	return ret;
}
bool API::下线指定QQ(std::int64_t 框架QQ)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t))取API函数地址("下线指定QQ"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
bool API::登录指定QQ(std::int64_t 框架QQ)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t))取API函数地址("登录指定QQ"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
std::int32_t API::取群未领红包(std::int64_t 框架QQ, std::int64_t 群号, std::vector<群未领红包数据>& 数据)
{
	earray_head arr;
	std::int32_t ret = ((std::int32_t(WINAPI*)(const char*, std::int64_t, std::int64_t, void**))取API函数地址("取群未领红包"))(pluginkey.c_str(), 框架QQ, 群号, arr);
	earray1d2vector<群未领红包数据, 群未领红包数据>(arr, 数据);
	return ret;
}
bool API::发送输入状态(std::int64_t 框架QQ, std::int64_t 对方QQ, 输入状态 状态)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, 输入状态))取API函数地址("发送输入状态"))(pluginkey.c_str(), 框架QQ, 对方QQ, 状态);
	return ret;
}
bool API::修改资料(std::int64_t 框架QQ, std::string 昵称, 性别类型 性别, std::string 生日, 职业类型 职业, std::string 公司名, std::string 所在地, std::string 家乡, std::string 邮箱, std::string 个人说明)
{
	nlohmann::json json;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("昵称")] = 昵称;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("性别")] = 性别;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("生日")] = 生日;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("职业")] = 职业;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("公司名")] = 公司名;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("所在地")] = 所在地;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("家乡")] = 家乡;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("邮箱")] = 邮箱;
	json[Text::GBKTOUTF8("info")][Text::GBKTOUTF8("个人说明")] = 个人说明;
	const char* info = strdup(json.dump().c_str());
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, const char*))取API函数地址("修改资料"))(pluginkey.c_str(), 框架QQ, info);
	delete[] info;
	return ret;
}
std::string API::取群文件下载地址(std::int64_t 框架QQ, std::int64_t 来源群号, std::string 文件id, std::string 文件名)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*))取API函数地址("取群文件下载地址"))(pluginkey.c_str(), 框架QQ, 来源群号, 文件id.c_str(), 文件名.c_str());
	return ret;
}
void API::打好友电话(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	((void (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("打好友电话"))(pluginkey.c_str(), 框架QQ, 对方QQ);
}
bool API::头像双击_好友(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("头像双击_好友"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	return ret;
}
bool API::头像双击_群(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int64_t 群号)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t))取API函数地址("头像双击_群"))(pluginkey.c_str(), 框架QQ, 对方QQ, 群号);
	return ret;
}
std::string API::取群成员简略信息(std::int64_t 框架QQ, std::int64_t 群号, 群成员状况简略信息& 数据)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, 群成员状况简略信息&))取API函数地址("取群成员简略信息"))(pluginkey.c_str(), 框架QQ, 群号, 数据);
	return ret;
}
bool API::群聊置顶(std::int64_t 框架QQ, std::int64_t 群号, bool 置顶)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群聊置顶"))(pluginkey.c_str(), 框架QQ, 群号, 置顶);
	return ret;
}
bool API::私聊置顶(std::int64_t 框架QQ, std::int64_t 对方QQ, bool 置顶)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("私聊置顶"))(pluginkey.c_str(), 框架QQ, 对方QQ, 置顶);
	return ret;
}
std::string API::取加群链接(std::int64_t 框架QQ, std::int64_t 群号)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t))取API函数地址("取加群链接"))(pluginkey.c_str(), 框架QQ, 群号);
	return ret;
}
bool API::设为精华(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 消息Req, std::int64_t 消息Random)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int32_t, std::int64_t))取API函数地址("设为精华"))(pluginkey.c_str(), 框架QQ, 群号, 消息Req, 消息Random);
	return ret;
}
bool API::群权限_设置群昵称规则(std::int64_t 框架QQ, std::int64_t 群号, std::string 名片规则)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("群权限_设置群昵称规则"))(pluginkey.c_str(), 框架QQ, 群号, 名片规则.c_str());
	return ret;
}
bool API::群权限_设置群发言频率(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 限制条数)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int32_t))取API函数地址("群权限_设置群发言频率"))(pluginkey.c_str(), 框架QQ, 群号, 限制条数 < 0 ? 0 : 限制条数);
	return ret;
}
bool API::群权限_设置群查找方式(std::int64_t 框架QQ, std::int64_t 群号, 查找类型 查找方式)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, 查找类型))取API函数地址("群权限_设置群查找方式"))(pluginkey.c_str(), 框架QQ, 群号, 查找方式 < 0 || 查找方式 > 2 ? 查找类型::通过群号或关键词 : 查找方式);
	return ret;
}
bool API::邀请好友加群(std::int64_t 框架QQ, std::int64_t 目标群号, std::int64_t 对方QQ, std::int64_t 来源群号)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int64_t))取API函数地址("邀请好友加群"))(pluginkey.c_str(), 框架QQ, 目标群号, 对方QQ, 来源群号);
	return ret;
}
bool API::置群内消息通知(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, std::int32_t 通知类型)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int32_t))取API函数地址("置群内消息通知"))(pluginkey.c_str(), 框架QQ, 群号, 对方QQ, 通知类型 < 0 || 通知类型 > 2 ? 2 : 通知类型);
	return ret;
}
bool API::修改群名称(std::int64_t 框架QQ, std::int64_t 群号, std::string 名称)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("修改群名称"))(pluginkey.c_str(), 框架QQ, 群号, 名称.c_str());
	return ret;
}
void API::重载自身(std::string 新文件路径)
{
	((void (WINAPI*)(const char*, const char*))取API函数地址("重载自身"))(pluginkey.c_str(), 新文件路径 == "" ? "empty" : 新文件路径.c_str());
}
void API::下线其他设备(std::int64_t 框架QQ, bool 移动设备, std::int32_t appid)
{
	((void (WINAPI*)(const char*, std::int64_t, bool, std::int32_t))取API函数地址("下线其他设备"))(pluginkey.c_str(), 框架QQ, 移动设备, appid);
}
bool API::登录网页取ck(std::int64_t 框架QQ, std::string 回调跳转地址, std::string appid, std::string daid, std::string cookie)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, const char*, const char*, const char*, const char*))取API函数地址("登录网页取ck"))(pluginkey.c_str(), 框架QQ, 回调跳转地址.c_str(), appid.c_str(), daid.c_str(), cookie.c_str());
	return ret;
}
std::string API::发送群公告(std::int64_t 框架QQ, std::int64_t 群号, std::string 标题, std::string 内容, std::int8_t* 图片, std::string 视频, bool 弹窗展示, bool 需要确认, bool 置顶, bool 发送给新成员, bool 引导修改群昵称)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*, const char*, std::int8_t*, const char*, bool, bool, bool, bool, bool))取API函数地址("发送群公告"))(pluginkey.c_str(), 框架QQ, 群号, 标题.c_str(), 内容.c_str(), 图片, 视频.c_str(), 弹窗展示, 需要确认, 置顶, 发送给新成员, 引导修改群昵称);
	return ret;
}
std::string API::取框架版本()
{
	std::string ret = ((const char* (WINAPI*)(const char*))取API函数地址("取框架版本"))(pluginkey.c_str());
	return ret;
}
std::string API::取群成员信息(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, 群成员信息V2& 数据)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int64_t, std::int64_t, 群成员信息V2&))取API函数地址("取群成员信息"))(pluginkey.c_str(), 框架QQ, 群号, 对方QQ, 数据);
	return ret;
}
std::string API::取钱包cookie(std::int64_t 框架QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t))取API函数地址("取钱包cookie"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
std::string API::取群网页cookie(std::int64_t 框架QQ)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t))取API函数地址("取群网页cookie"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
std::string API::转账(std::int64_t 框架QQ, std::int32_t 转账金额, std::int64_t 对方QQ, std::string 转账留言, 转账类型 类型, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码)
{
	std::string ret = ((const char* (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int64_t, const char*, 转账类型, const char*, std::int32_t, 验证码信息&))取API函数地址("转账"))(pluginkey.c_str(), 框架QQ, 转账金额, 对方QQ, 转账留言.c_str(), 类型, 支付密码.c_str(), 银行卡序列, 验证码);
	return ret;
}
std::string API::取收款链接(std::int64_t 框架QQ, std::int32_t 收款金额, std::string 说明文本)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int32_t, const char*))取API函数地址("取收款链接"))(pluginkey.c_str(), 框架QQ, 收款金额 <= 0 ? 50000 * 100 : 收款金额, 说明文本.c_str());
	return ret;
}
std::string API::取群小视频下载地址(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 来源QQ, std::string param, std::string hash1, std::string 文件名)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, std::int64_t, const char*, const char*, const char*))取API函数地址("取群小视频下载地址"))(pluginkey.c_str(), 框架QQ, 来源群号, 来源QQ, param.c_str(), hash1.c_str(), 文件名.c_str());
	return ret;
}
std::string API::取私聊小视频下载地址(std::int64_t 框架QQ, std::int64_t 来源QQ, std::string param, std::string hash1, std::string 文件名)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, const char*, const char*, const char*))取API函数地址("取私聊小视频下载地址"))(pluginkey.c_str(), 框架QQ, 来源QQ, param.c_str(), hash1.c_str(), 文件名.c_str());
	return ret;
}
std::string API::上传小视频(std::int64_t 框架QQ, std::int64_t 群号, std::string 本地小视频路径, std::int8_t* 小视频封面图, std::int32_t 宽度, std::int32_t 高度, std::int32_t 时长)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, const char*, std::int8_t*, std::int32_t))取API函数地址("上传小视频"))(pluginkey.c_str(), 框架QQ, 群号, 本地小视频路径.c_str(), 小视频封面图, _msize((void*)小视频封面图));
	ret.pop_back();
	ret = std::format("{},wide={},high={},time={}]", ret, 宽度, 高度, 时长);
	return ret;
}
std::string API::发送好友xml消息(std::int64_t 框架QQ, std::int64_t 好友QQ, std::string xml代码, std::int64_t& Random, std::int32_t& Req)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, const char*, std::int64_t&, std::int32_t&))取API函数地址("发送好友xml消息"))(pluginkey.c_str(), 框架QQ, 好友QQ, xml代码.c_str(), Random, Req);
	return ret;
}
std::string API::发送群xml消息(std::int64_t 框架QQ, std::int64_t 群号, std::string xml代码, bool 匿名发送)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, const char*, bool))取API函数地址("发送群xml消息"))(pluginkey.c_str(), 框架QQ, 群号, xml代码.c_str(), 匿名发送);
	return ret;
}
nlohmann::json API::取群成员概况(std::int64_t 框架QQ, std::int64_t 群号)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t))取API函数地址("取群成员概况"))(pluginkey.c_str(), 框架QQ, 群号);
	ret = Text::GBKTOUTF8(ret);
	nlohmann::json json = nlohmann::json::parse(ret);
	return json;
}
nlohmann::json API::添加好友_取验证类型(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t))取API函数地址("添加好友_取验证类型"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	ret = Text::GBKTOUTF8(ret);
	nlohmann::json json = nlohmann::json::parse(ret);
	return json;
}
nlohmann::json API::群聊打卡(std::int64_t 框架QQ, std::int64_t 群号)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t))取API函数地址("群聊打卡"))(pluginkey.c_str(), 框架QQ, 群号);
	ret = Text::GBKTOUTF8(ret);
	nlohmann::json json = nlohmann::json::parse(ret);
	return json;
}
bool API::群聊签到(std::int64_t 框架QQ, std::int64_t 群号, std::string 附加参数)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("群聊签到"))(pluginkey.c_str(), 框架QQ, 群号, 附加参数 == "" ? "template_data=&gallery_info=%7B%22category_id%22%3A9%2C%22page%22%3A0%2C%22pic_id%22%3A124%7D&template_id=%7B%7D&client=2&lgt=0&lat=0&poi=&pic_id=&text=%E5%AD%A6%E4%B9%A0%E6%89%93%E5%8D%A1" : 附加参数.c_str());
	return ret;
}
bool API::置群聊备注(std::int64_t 框架QQ, std::int64_t 群号, std::string 备注)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, const char*))取API函数地址("置群聊备注"))(pluginkey.c_str(), 框架QQ, 群号, 备注.c_str());
	return ret;
}
std::string API::红包转发(std::int64_t 框架QQ, std::string 红包ID, std::int64_t 目标对象, std::int32_t Type)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, const char*, std::int64_t, std::int32_t))取API函数地址("红包转发"))(pluginkey.c_str(), 框架QQ, 红包ID.c_str(), 目标对象, Type);
	return ret;
}
bool API::发送数据包(std::int64_t 框架QQ, std::int32_t 包体序号, std::int32_t 最大等待时长, std::int8_t* 数据)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int32_t, std::int32_t, std::int8_t*))取API函数地址("发送数据包"))(pluginkey.c_str(), 框架QQ, 包体序号, 最大等待时长, 数据);
	return ret;
}
std::int32_t API::请求ssoseq(std::int64_t 框架QQ)
{
	std::int32_t ret = ((std::int32_t(WINAPI*)(const char*, std::int64_t))取API函数地址("请求ssoseq"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
std::string API::取sessionkey(std::int64_t 框架QQ)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t))取API函数地址("取sessionkey"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
std::string API::获取bkn_gtk(std::int64_t 框架QQ, std::string 自定义bkn_gtk)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, const char*))取API函数地址("获取bkn_gtk"))(pluginkey.c_str(), 框架QQ, 自定义bkn_gtk.c_str());
	return ret;
}
bool API::置好友验证方式(std::int64_t 框架QQ, std::int32_t 验证方式, std::string Q_and_A)
{
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int32_t, const char*))取API函数地址("置好友验证方式"))(pluginkey.c_str(), 框架QQ, 验证方式, Q_and_A.c_str());
	return ret;
}
std::string API::上传照片墙图片(std::int64_t 框架QQ, std::int8_t* pic)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int8_t*, std::int32_t))取API函数地址("上传照片墙图片"))(pluginkey.c_str(), 框架QQ, pic, _msize((void*)pic));
	return ret;
}
std::string API::付款(std::int64_t 框架QQ, std::string QrcodeUrl, std::int32_t 银行卡序列, std::string 支付密码, 验证码信息& 验证码)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, const char*, std::int32_t, const char*, 验证码信息&))取API函数地址("付款"))(pluginkey.c_str(), 框架QQ, QrcodeUrl.c_str(), 银行卡序列, 支付密码.c_str(), 验证码);
	return ret;
}
std::string API::修改支付密码(std::int64_t 框架QQ, std::string 原密码, std::string 新密码)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, const char*, const char*))取API函数地址("修改支付密码"))(pluginkey.c_str(), 框架QQ, 原密码.c_str(), 新密码.c_str());
	return ret;
}
std::string API::账号搜索(std::int64_t 框架QQ, std::string 关键词)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, const char*))取API函数地址("账号搜索"))(pluginkey.c_str(), 框架QQ, 关键词.c_str());
	return ret;
}
nlohmann::json API::添加群_取验证类型(std::int64_t 框架QQ, std::int64_t 群号)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t))取API函数地址("添加群_取验证类型"))(pluginkey.c_str(), 框架QQ, 群号);
	ret = Text::GBKTOUTF8(ret);
	nlohmann::json json = nlohmann::json::parse(ret);
	return json;
}
nlohmann::json API::获取红包领取详情(std::int64_t 框架QQ, std::int64_t 来源群号, std::string 红包文本代码, std::string 红包类型)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, const char*, const char*))取API函数地址("获取红包领取详情"))(pluginkey.c_str(), 框架QQ, 来源群号, 红包文本代码.c_str(), 红包类型.c_str());
	ret = Text::GBKTOUTF8(ret);
	nlohmann::json json = nlohmann::json::parse(ret);
	return json;
}
std::string API::取好友文件下载地址(std::int64_t 框架QQ, std::string FileId, std::string FileName)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, const char*, const char*))取API函数地址("取好友文件下载地址"))(pluginkey.c_str(), 框架QQ, FileId.c_str(), FileName.c_str());
	return ret;
}
bool API::删除群成员_批量(std::int64_t 框架QQ, std::int64_t 群号, std::vector<std::int64_t> 群成员QQ, bool 拒绝加群申请)
{
	int Num = 群成员QQ.size();
	int* address = (int*)malloc((Num + 1) * 8);
	address[0] = 1;
	address[1] = Num;
	for (size_t i = 0; i < Num; i++)
	{
		((std::int64_t*)(address))[i + 2] = 群成员QQ[i];
	}
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, std::int64_t, void*, bool))取API函数地址("删除群成员_批量"))(pluginkey.c_str(), 框架QQ, 群号, address, 拒绝加群申请);
	free(address);
	return ret;
}
std::string API::取扩列资料(std::int64_t 框架QQ, std::int64_t 对方QQ)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t))取API函数地址("取扩列资料"))(pluginkey.c_str(), 框架QQ, 对方QQ);
	return ret;
}
std::string API::取资料展示设置(std::int64_t 框架QQ, std::int64_t 对方QQ, 资料展示设置数据& 数据)
{
	资料展示设置数据 info, * einfo = &info;
	std::string ret = ((const char* (*)(const char*, std::int64_t, std::int64_t, 资料展示设置数据**))取API函数地址("取资料展示设置"))(pluginkey.c_str(), 框架QQ, 对方QQ, &einfo);
	数据 = *(const_cast<资料展示设置数据*>(einfo));
	return ret;
}
std::string API::设置资料展示(std::int64_t 框架QQ, 资料展示设置数据 数据)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, 资料展示设置数据))取API函数地址("设置资料展示"))(pluginkey.c_str(), 框架QQ, 数据);
	return ret;
}
std::string API::获取当前登录设备信息(std::int64_t 框架QQ, 登录设备信息& 信息)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t, 登录设备信息&))取API函数地址("获取当前登录设备信息"))(pluginkey.c_str(), 框架QQ, 信息);
	return ret;
}
bool API::提取图片文字(std::int64_t 框架QQ, std::string 图片地址, std::string& 识别结果)
{
	const char* eret;
	bool ret = ((bool (WINAPI*)(const char*, std::int64_t, const char*, const char*&))取API函数地址("提取图片文字"))(pluginkey.c_str(), 框架QQ, 图片地址.c_str(), eret);
	识别结果 = eret;
	return ret;
}
std::string API::取插件文件名()
{
	std::string ret = ((const char* (*)(const char*))取API函数地址("取插件文件名"))(pluginkey.c_str());
	return ret;
}
void API::TEA加密(std::int8_t*& 内容, std::int8_t* 秘钥)
{
	return ((void(*)(const char*, std::int8_t*&, std::int8_t*))取API函数地址("TEA加密"))(pluginkey.c_str(), 内容, 秘钥);
}
void API::TEA解密(std::int8_t*& 内容, std::int8_t* 秘钥)
{
	return ((void(*)(const char*, std::int8_t*&, std::int8_t*))取API函数地址("TEA解密"))(pluginkey.c_str(), 内容, 秘钥);
}
std::string API::红包数据加密(std::string str, std::int32_t random)
{
	std::string ret = ((const char* (*)(const char*, const char*, std::int32_t))取API函数地址("红包数据加密"))(pluginkey.c_str(), str.c_str(), random);
	return ret;
}
std::string API::红包数据解密(std::string str, std::int32_t random)
{
	std::string ret = ((const char* (*)(const char*, const char*, std::int32_t))取API函数地址("红包数据解密"))(pluginkey.c_str(), str.c_str(), random);
	return ret;
}
std::string API::红包msgno计算(std::int64_t 目标QQ)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t))取API函数地址("红包msgno计算"))(pluginkey.c_str(), 目标QQ);
	return ret;
}
bool API::取消精华(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 消息Req, std::int64_t 消息Random)
{
	bool ret;
	ret = ((bool(*)(const char*, std::int64_t, std::int64_t, std::int32_t, std::int64_t))取API函数地址("取消精华"))(pluginkey.c_str(), 框架QQ, 群号, 消息Req, 消息Random);
	return ret;
}
bool API::群权限_设置加群方式(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 加群方式, std::string 问题, std::string 答案)
{
	bool ret;
	ret = ((bool(*)(const char*, std::int64_t, std::int64_t, std::int32_t, const char*, const char*))取API函数地址("群权限_设置加群方式"))(pluginkey.c_str(), 框架QQ, 群号, 加群方式, 问题.c_str(), 答案.c_str());
	return ret;
}
bool API::群权限_群幸运字符(std::int64_t 框架QQ, std::int64_t 群号, bool 是否开启)
{
	bool ret;
	ret = ((bool(*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_群幸运字符"))(pluginkey.c_str(), 框架QQ, 群号, 是否开启);
	return ret;
}
bool API::群权限_一起写(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许)
{
	bool ret;
	ret = ((bool(*)(const char*, std::int64_t, std::int64_t, bool))取API函数地址("群权限_一起写"))(pluginkey.c_str(), 框架QQ, 群号, 是否允许);
	return ret;
}
std::string API::取QQ空间cookie(std::int64_t 框架QQ)
{
	std::string ret = ((const char* (*)(const char*, std::int64_t))取API函数地址("取QQ空间cookie"))(pluginkey.c_str(), 框架QQ);
	return ret;
}
bool API::框架是否为单Q()
{
	bool ret;
	ret = ((bool(*)(const char*))取API函数地址("框架是否为单Q"))(pluginkey.c_str());
	return ret;
}
bool API::修改指定QQ缓存密码(std::int64_t 框架QQ, std::string 新密码)
{
	bool ret;
	ret = ((bool(*)(const char*, std::int64_t, const char*))取API函数地址("修改指定QQ缓存密码"))(pluginkey.c_str(), 框架QQ, 新密码.c_str());
	return ret;
}
void API::处理群验证事件_风险号(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 触发QQ, std::int64_t 消息Seq, 操作类型 操作, 群事件 事件类型, std::string 拒绝理由)
{
	return ((void(*)(const char*, std::int64_t, std::int64_t, std::int64_t, std::int64_t, 操作类型, 群事件, const char*))取API函数地址("处理群验证事件_风险号"))(pluginkey.c_str(), 框架QQ, 来源群号, 触发QQ, 消息Seq, 操作, 事件类型, 拒绝理由.c_str());
}
std::int32_t API::查询网址安全性(std::int64_t 框架QQ, std::string 网址)
{
	std::int32_t ret = ((std::int32_t(*)(const char*, std::int64_t, const char*))取API函数地址("查询网址安全性"))(pluginkey.c_str(), 框架QQ, 网址.c_str());
	return ret;
}