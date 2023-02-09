﻿#include "SDK.hpp"
文本型 API_Text::小黄豆表情(emoji 表情)
{
	return std::format("[bq{}]", (int)表情).c_str();
}
文本型 API::初始化(文本型 _pluginkey, 文本型 _apidata, 文本型 插件名称, 文本型 插件作者, 文本型 插件版本, 文本型 插件说明, 整数型 被启用处理函数, 整数型 被禁用处理函数, 整数型 将被卸载处理函数, 整数型 插件菜单处理函数, 整数型 私聊消息处理函数, 整数型 群聊消息处理函数, 整数型 频道推送统一处理函数, 整数型 事件消息处理函数)
{
	pluginkey = _pluginkey; //不知道是什么bug,但pluginkey必须为string类型,貌似因为_pluginkey会释放
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
	const char* 权限列表[372] = { "输出日志", "发送好友消息", "发送群消息", "发送群临时消息", "添加好友", "添加群", "删除好友", "置屏蔽好友", "置特别关心好友", "发送好友xml消息", "发送群xml消息", "发送好友json消息", "发送群json消息", "上传好友图片", "上传群图片", "上传好友语音", "上传群语音", "上传头像", "设置群名片", "取昵称_从缓存", "强制取昵称", "获取skey", "获取pskey", "获取clientkey", "取框架QQ", "取好友列表", "取群列表", "取群成员列表", "设置管理员", "取管理层列表", "取群名片", "取个性签名", "修改昵称", "修改个性签名", "删除群成员", "禁言群成员", "退群", "解散群", "上传群头像", "全员禁言", "群权限_发起新的群聊", "群权限_发起临时会话", "群权限_上传文件", "群权限_上传相册", "群权限_邀请好友加群", "群权限_匿名聊天", "群权限_坦白说", "群权限_新成员查看历史消息", "群权限_邀请方式设置", "撤回消息_群聊", "撤回消息_私聊本身", "设置位置共享", "上报当前位置", "是否被禁言", "处理好友验证事件", "处理群验证事件", "查看转发聊天记录内容", "上传群文件", "创建群文件夹", "设置在线状态", "QQ点赞", "取图片下载地址", "查询好友信息", "查询群信息", "框架重启", "群文件转发至群", "群文件转发至好友", "好友文件转发至好友", "置群消息接收", "取群名称_从缓存", "取好友在线状态", "取QQ钱包个人信息", "获取订单详情", "提交支付验证码", "分享音乐", "更改群聊消息内容", "更改私聊消息内容", "群聊口令红包", "群聊拼手气红包", "群聊普通红包", "群聊画图红包", "群聊语音红包", "群聊接龙红包", "群聊专属红包", "好友口令红包", "好友普通红包", "好友画图红包", "好友语音红包", "好友接龙红包", "重命名群文件夹", "删除群文件夹", "删除群文件", "保存文件到微云", "移动群文件", "取群文件列表", "设置专属头衔", "下线指定QQ", "登录指定QQ", "取群未领红包", "发送输入状态", "修改资料", "打好友电话", "取群文件下载地址", "头像双击_好友", "头像双击_群", "取群成员简略信息", "群聊置顶", "私聊置顶", "取加群链接", "设为精华", "群权限_设置群昵称规则", "群权限_设置群发言频率", "群权限_设置群查找方式", "邀请好友加群", "置群内消息通知", "修改群名称", "下线其他设备", "登录网页取ck", "发送群公告", "取群成员信息", "取钱包cookie", "取群网页cookie", "转账", "取收款链接", "取群小视频下载地址", "取私聊小视频下载地址", "上传小视频", "取群成员概况", "添加好友_取验证类型", "群聊打卡", "群聊签到", "置群聊备注", "红包转发", "发送数据包", "请求ssoseq", "取sessionkey", "获取bkn_gtk", "置好友验证方式", "上传照片墙图片", "付款", "修改支付密码", "账号搜索", "添加群_取验证类型", "领取红包", "获取红包领取详情", "取好友文件下载地址", "删除群成员_批量", "取扩列资料", "取资料展示设置", "设置资料展示", "获取当前登录设备信息", "提取图片文字", "取消精华", "群权限_设置加群方式", "群权限_群幸运字符", "群权限_一起写", "取QQ空间cookie", "修改指定QQ缓存密码", "处理群验证事件_风险号", "查询网址安全性", "消息合并转发至好友", "消息合并转发至群", "禁言群匿名", "领取私聊普通红包", "领取群聊专属红包", "发送讨论组消息", "发送讨论组json消息", "发送讨论组xml消息", "发送讨论组临时消息", "撤回消息_讨论组", "回复QQ咨询会话", "发送订阅号私聊消息", "取讨论组名称_从缓存", "修改讨论组名称", "取讨论组成员列表", "强制取自身匿名Id", "取订阅号列表", "取讨论组列表", "邀请好友加群_批量", "邀请好友加入讨论组_批量", "讨论组口令红包", "讨论组拼手气红包", "讨论组普通红包", "讨论组画图红包", "讨论组语音红包", "讨论组接龙红包", "讨论组专属红包", "领取讨论组专属红包", "取讨论组未领红包", "取讨论组文件下载地址", "发送QQ咨询会话", "创建群聊", "取群应用列表", "退出讨论组", "群验证消息接收设置", "转让群", "修改好友备注", "删除讨论组成员", "讨论组文件转发至群", "讨论组文件转发至好友", "拉起群收款", "结束群收款", "查询群收款状态", "支付群收款", "消息合并转发至讨论组", "群收款_催单", "取好友Diy名片数据", "设置Diy名片", "好友生僻字红包", "群聊生僻字红包", "讨论组生僻字红包", "支付代付请求", "查询代付状态", "拉起代付", "取好友能量值与QID", "文字转语音", "翻译", "撤回消息_群聊s", "QQ列表_添加手表协议QQ", "QQ列表_二维码登录_拉取二维码", "QQ列表_二维码登录_查询二维码状态", "删除群成员_批量s", "拍一拍好友在线状态", "发送验证消息会话消息", "回复验证消息会话消息", "取群文件内存利用状态", "取群文件总数", "上传涂鸦", "上传好友文件s", "上传群文件s", "取群艾特全体剩余次数", "是否已开启QQ咨询", "创建群相册", "删除群相册", "取群相册列表", "取群相册照片列表", "删除群相册照片", "修改群相册信息", "取群Id_从缓存", "上传频道图片", "发送频道消息", "发送频道私信消息", "取私信频道Id", "频道消息粘贴表情", "撤回频道消息", "撤回频道私信消息", "设置子频道精华消息", "禁言频道成员", "设置频道全员禁言", "移除频道成员", "移除频道成员_批量", "退出频道", "更改频道名称", "修改频道简介", "设置我的频道昵称", "置子频道观看权限", "置子频道发言权限", "子频道消息提醒设置", "子频道慢速模式设置", "修改子频道名称", "删除子频道", "修改我的频道用户信息_昵称", "修改我的频道用户信息_性别", "修改我的频道用户信息_年龄", "修改我的频道用户信息_所在地", "设置是否允许别人私信我", "设置频道加入验证方式", "搜索频道", "取频道封面", "取频道头像", "获取频道成员列表", "取频道信息", "取频道加入验证方式", "申请加入频道", "取频道文件下载地址", "频道拼手气红包", "频道普通红包", "频道专属红包", "领取频道专属红包", "取频道成员身份组", "设置频道成员身份组", "修改身份组信息", "删除身份组", "新增身份组", "取频道身份组列表", "取子频道列表", "取频道用户个性档案", "取频道用户资料", "刷新频道列表缓存", "取频道列表_从缓存", "取频道用户昵称_从缓存", "取频道名称_从缓存", "取子频道名称_从缓存", "取频道昵称_从缓存", "取私信频道列表_从缓存", "取子频道分组列表", "上传频道文件", "更改频道消息内容", "Emoji转频道EmojiId", "频道EmojiId转Emoji", "Emoji转QQ空间EmId", "QQ空间EmId转Emoji", "小黄豆Id转QQ空间EmId", "QQ空间EmId转小黄豆Id", "取特定身份组成员列表", "取子频道分组结构", "设置子频道分组结构", "删除子频道_批量", "创建子频道", "构造卡片消息文本代码", "分享音乐_频道", "修改频道排序", "处理频道加入申请", "查询群设置", "取子频道管理列表", "设置子频道管理", "设置指定身份组子频道观看权限", "设置指定身份组子频道发言权限", "设置直播子频道主播", "获取频道分享链接", "获取子频道分享链接", "子频道消息通知设置", "获取红包领取详情s", "取话题子频道帖子列表", "获取日程列表", "获取日程链接", "取日程信息", "创建日程", "取QQ头像K值", "删除日程", "发送通行证到群", "发送通行证到好友", "屏蔽频道用户私信", "频道用户私信免打扰", "QQ列表_添加QQ", "QQ列表_删除QQ", "登录指定QQ_二次登录", "取框架插件列表", "取在线移动设备列表", "设置频道全局公告_指定消息", "取频道号", "设置位置共享s", "上报当前位置s", "移动好友分组", "修改好友分组名", "删除好友分组", "取好友分组列表", "新增好友分组", "取频道红包pre_grap_token", "语音红包匹配", "上传群聊语音红包匹配语音", "取合并转发消息内容", "上传合并转发消息", "语音转文字", "发送功能包", "二维码扫一扫授权登录其他应用", "取历史登录设备guid列表", "二维码扫一扫授权其他设备资料辅助验证登录", "关闭设备锁", "恢复设备锁", "余额提现", "取h5钱包cookie", "取QQ会员中心cookie", "说说点赞", "说说评论", "取最新动态列表", "搜索表情包", "发布说说", "经纬度定位查询详细地址", "上传群临时文件s", "删除说说", "上传QQ封面" };
	for (int i = 0; i < 371; i++)
	{
		if(权限列表[i] != "")
			json["data"]["needapilist"][Text::GBKTOUTF8(权限列表[i])]["desc"] = Text::GBKTOUTF8("CSDK必须");
	}
	return Text::UTF8TOGBK(json.dump()).c_str();
}
整数型 API::取API函数地址(文本型 函数名)
{
	std::string func = Text::GBKTOUTF8(函数名);
	if (apidata.find(func) != apidata.end())
		return apidata[func];
	else
		MessageBox(NULL, std::format("未找到该函数: {}", 函数名).c_str(), "错误", NULL);
		return 0;
}
文本型 API::输出日志(文本型 日志, 整数型 文字颜色, 整数型 背景颜色)
{
	return ((文本型(WINAPI*)(文本型, 文本型, 整数型, 整数型))取API函数地址("输出日志"))(pluginkey.c_str(), 日志, 文字颜色, 背景颜色);
}
文本型 API::发送好友消息(长整数型 框架QQ, 长整数型 好友QQ, 文本型 发送内容, 长整数型* Random, 整数型* Req)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 长整数型*, 整数型*))取API函数地址("发送好友消息"))(pluginkey.c_str(), 框架QQ, 好友QQ, 发送内容, Random, Req);
}
文本型 API::发送群消息(长整数型 框架QQ, 长整数型 群号, 文本型 发送内容, 逻辑型 匿名发送)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 逻辑型))取API函数地址("发送群消息"))(pluginkey.c_str(), 框架QQ, 群号, 发送内容, 匿名发送);
}
文本型 API::发送群临时消息(长整数型 框架QQ, 长整数型 群ID, 长整数型 对方QQ, 文本型 发送内容, 长整数型* Random, 整数型* Req)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 长整数型, 文本型, 长整数型*, 整数型*))取API函数地址("发送群临时消息"))(pluginkey.c_str(), 框架QQ, 群ID, 对方QQ, 发送内容, Random, Req);
}
文本型 API::添加好友(长整数型 框架QQ, 长整数型 对方QQ, 文本型 问题答案, 文本型 备注)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 文本型))取API函数地址("添加好友"))(pluginkey.c_str(), 框架QQ, 对方QQ, 问题答案, 备注);
}
文本型 API::添加群(长整数型 框架QQ, 长整数型 群号, 文本型 验证消息)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型))取API函数地址("添加群"))(pluginkey.c_str(), 框架QQ, 群号, 验证消息);
}
文本型 API::删除好友(长整数型 框架QQ, 长整数型 对方QQ)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型))取API函数地址("删除好友"))(pluginkey.c_str(), 框架QQ, 对方QQ);
}
文本型 API::置屏蔽好友(长整数型 框架QQ, 长整数型 对方QQ, 逻辑型 是否屏蔽)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型))取API函数地址("置屏蔽好友"))(pluginkey.c_str(), 框架QQ, 对方QQ, 是否屏蔽);
}
文本型 API::置特别关心好友(长整数型 框架QQ, 长整数型 对方QQ, 逻辑型 是否关心)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型))取API函数地址("置特别关心好友"))(pluginkey.c_str(), 框架QQ, 对方QQ, 是否关心);
}
文本型 API::发送好友json消息(长整数型 框架QQ, 长整数型 好友QQ, 文本型 json代码, 长整数型* Random, 整数型* Req)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 长整数型*, 整数型*))取API函数地址("发送好友json消息"))(pluginkey.c_str(), 框架QQ, 好友QQ, json代码, Random, Req);
}
文本型 API::发送群json消息(长整数型 框架QQ, 长整数型 群号, 文本型 json代码, 逻辑型 匿名发送)
{
	return ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 文本型, 逻辑型))取API函数地址("发送群json消息"))(pluginkey.c_str(), 框架QQ, 群号, json代码, 匿名发送);
}
文本型 API::上传好友图片(长整数型 框架QQ, 长整数型 好友QQ, 字节集 pic, 逻辑型 是否闪照, 整数型 宽度, 整数型 高度, 逻辑型 动图, 文本型 预览文字)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型, 字节集, 整数型))取API函数地址("上传好友图片"))(pluginkey.c_str(), 框架QQ, 好友QQ, 是否闪照, pic, strlen((char*)pic) + 1);
	ret.pop_back();
	ret += std::format(",wide={},high={},cartoon={},str={}]", 宽度, 高度, (bool)动图, 预览文字);
	return ret.c_str();
}
文本型 API::上传群图片(长整数型 框架QQ, 长整数型 群号, 字节集 pic, 逻辑型 是否闪照, 整数型 宽度, 整数型 高度, 逻辑型 动图, 文本型 预览文字)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 逻辑型, 字节集, 整数型))取API函数地址("上传群图片"))(pluginkey.c_str(), 框架QQ, 群号, 是否闪照, pic, strlen((char*)pic) + 1);
	ret.pop_back();
	ret += std::format(",wide={},high={},cartoon={},str={}]", 宽度, 高度, (bool)动图, 预览文字);
	return ret.c_str();
}
文本型 API::上传好友语音(长整数型 框架QQ, 长整数型 好友QQ, 字节集 audio, 语音类型 类型, 文本型 语音文字, 整数型 时长)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 语音类型, 文本型, 字节集, 整数型))取API函数地址("上传好友语音"))(pluginkey.c_str(), 框架QQ, 好友QQ, 类型, 语音文字, audio, strlen((char*)audio) + 1);
	ret.pop_back();
	ret += std::format(",time={}]", 时长);
	return ret.c_str();
}
文本型 API::上传群语音(长整数型 框架QQ, 长整数型 群号, 字节集 audio, 语音类型 类型, 文本型 语音文字, 整数型 时长)
{
	std::string ret = ((文本型(WINAPI*)(文本型, 长整数型, 长整数型, 语音类型, 文本型, 字节集, 整数型))取API函数地址("上传群语音"))(pluginkey.c_str(), 框架QQ, 群号, 类型, 语音文字, audio, strlen((char*)audio) + 1);
	ret.pop_back();
	ret += std::format(",time={}]", 时长);
	return ret.c_str();
}
文本型 API::上传头像(长整数型 框架QQ, 字节集 pic)
{
	return ((文本型(*)(文本型, 长整数型, 字节集))取API函数地址("上传头像"))(pluginkey.c_str(), 框架QQ, pic);
}
字节集 API::silk解码(文本型 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1 || 
		_access(".\\main\\corn\\silk_v3_decoder.exe", 00) == -1) //判断转码程序是否存在
		输出日志("silk解码->corn文件夹缺少语音转码库，请自行到官网或交流群下载"); //不存在输出错误日志
		return {};
	if (_access(音频文件路径, 00) == -1) //判断音频文件是否存在
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
	char* buffer2 = new char[length2];  //创建内存缓存区
	bin2.read(buffer2,length2); //写入缓存区
	bin2.close(); //关闭文件
	system(std::format("del \"{}.mp3\"", Name).c_str()); //删除硬盘文件
	system(std::format("del \"{}.pcm\"", Name).c_str()); //删除硬盘文件
	输出日志("silk解码->解码完成");
	return (unsigned char*)buffer2; //返回缓冲区 请使用delete []释放内存缓存区
}
字节集 API::silk编码(文本型 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1 ||
		_access(".\\main\\corn\\silk_v3_decoder.exe", 00) == -1) //判断转码程序是否存在
		输出日志("silk编码->corn文件夹缺少语音转码库，请自行到官网或交流群下载"); //不存在输出错误日志
	return {};
	if (_access(音频文件路径, 00) == -1) //判断音频文件是否存在
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
	return (unsigned char*)buffer;
}
字节集 API::amr编码(文本型 音频文件路径)
{
	if (_access(".\\main\\corn\\ffmpeg.exe", 00) == -1 ||
		_access(".\\main\\corn\\silk_v3_decoder.exe", 00) == -1) //判断转码程序是否存在
		输出日志("amr编码->corn文件夹缺少语音转码库，请自行到官网或交流群下载"); //不存在输出错误日志
	return {};
	if (_access(音频文件路径, 00) == -1) //判断音频文件是否存在
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
	return (unsigned char*)buffer;
}
文本型 API::设置群名片(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ, 文本型 新名片)
{
	return ((文本型(*)(文本型, 长整数型, 长整数型, 长整数型, 文本型))取API函数地址("设置群名片"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ, 新名片);
}
文本型 API::取昵称_从缓存(文本型 对方QQ)
{
	return ((文本型(*)(文本型, 文本型))取API函数地址("取昵称_从缓存"))(pluginkey.c_str(), 对方QQ);
}
文本型 API::强制取昵称(长整数型 框架QQ, 文本型 对方QQ)
{
	return ((文本型(*)(文本型, 长整数型, 文本型))取API函数地址("强制取昵称"))(pluginkey.c_str(), 框架QQ, 对方QQ);
}
文本型 API::取群名称_从缓存(文本型 群号)
{
	return ((文本型(*)(文本型, 文本型))取API函数地址("取群名称_从缓存"))(pluginkey.c_str(), 群号);
}
文本型 API::获取skey(长整数型 框架QQ)
{
	return ((文本型(*)(文本型, 长整数型))取API函数地址("获取skey"))(pluginkey.c_str(), 框架QQ);
}
文本型 API::获取pskey(长整数型 框架QQ, 文本型 域)
{
	return ((文本型(*)(文本型, 长整数型, 文本型))取API函数地址("获取pskey"))(pluginkey.c_str(), 框架QQ, 域);
}
文本型 API::获取clientkey(长整数型 框架QQ)
{
	return ((文本型(*)(文本型, 长整数型))取API函数地址("获取clientkey"))(pluginkey.c_str(), 框架QQ);
}
文本型 API::取框架QQ()
{
	return ((文本型(*)(文本型))取API函数地址("取框架QQ"))(pluginkey.c_str());
}
文本型 API::取好友列表(长整数型 框架QQ, 好友信息** 数据)
{
	return ((文本型(*)(文本型, 长整数型, 好友信息**))取API函数地址("取好友列表"))(pluginkey.c_str(), 框架QQ, 数据);
}
文本型 API::取群列表(长整数型 框架QQ, 群信息** 数据)
{
	return ((文本型(*)(文本型, 长整数型, 群信息**))取API函数地址("取群列表"))(pluginkey.c_str(), 框架QQ, 数据);
}
文本型 API::取群成员列表(长整数型 框架QQ, 长整数型 群号, 群成员信息** 数据)
{
	return ((文本型(*)(文本型, 长整数型, 长整数型, 群成员信息**))取API函数地址("取群成员列表"))(pluginkey.c_str(), 框架QQ, 群号, 数据);
}
逻辑型 API::设置管理员(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ, 逻辑型 取消管理)
{
	return ((逻辑型(*)(文本型, 长整数型, 长整数型, 长整数型, 逻辑型))取API函数地址("设置管理员"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ, 取消管理);
}
文本型 API::取管理层列表(长整数型 框架QQ, 长整数型 群号)
{
	return ((文本型(*)(文本型, 长整数型, 长整数型))取API函数地址("取管理层列表"))(pluginkey.c_str(), 框架QQ, 群号);
}
文本型 API::取群名片(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ)
{
	return ((文本型(*)(文本型, 长整数型, 长整数型, 长整数型))取API函数地址("取群名片"))(pluginkey.c_str(), 框架QQ, 群号, 群成员QQ);
}









