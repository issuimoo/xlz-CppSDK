#include <Windows.h>
#include <direct.h>
#include <fstream>
#include <io.h>

#include "Data_type.hpp"
#include "json.hpp"
#include "Text.hpp"

#define DLLOUT extern "C" __declspec(dllexport)

class API_Text
{
public:
	std::string 小黄豆表情(emoji 表情);
};

class API : public API_Text
{
public:
	std::string 初始化(std::string _pluginkey, std::string _apidata, std::string 插件名称, std::string 插件作者, std::string 插件版本, std::string 插件说明,  std::int32_t 被启用处理函数,  std::int32_t 被禁用处理函数,  std::int32_t 将被卸载处理函数,  std::int32_t 插件菜单处理函数,  std::int32_t 私聊消息处理函数,  std::int32_t 群聊消息处理函数,  std::int32_t 频道推送统一处理函数,  std::int32_t 事件消息处理函数);
	std::string 输出日志(std::string 日志,  std::int32_t 文字颜色 = 32768,  std::int32_t 背景颜色 = 16777215);
	std::string 发送好友消息(std::int64_t 框架QQ, std::int64_t 好友QQ, std::string 发送内容, std::int64_t& Random, std::int32_t& Req);
	std::string 发送群消息(std::int64_t 框架QQ, std::int64_t 群号,std::string 发送内容,bool 匿名发送);
	std::string 发送群临时消息(std::int64_t 框架QQ, std::int64_t 群ID, std::int64_t 对方QQ, std::string 发送内容, std::int64_t& Random, std::int32_t& Req);
	std::string 添加好友(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string 问题答案, std::string 备注);
	std::string 添加群(std::int64_t 框架QQ, std::int64_t 群号, std::string 验证消息);
	std::string 删除好友(std::int64_t 框架QQ, std::int64_t 对方QQ);
	std::string 置屏蔽好友(std::int64_t 框架QQ, std::int64_t 对方QQ, bool 是否屏蔽);
	std::string 置特别关心好友(std::int64_t 框架QQ, std::int64_t 对方QQ, bool 是否关心);
	std::string 发送好友json消息(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string json代码, std::int64_t& Random, std::int32_t& Req);
	std::string 发送群json消息(std::int64_t 框架QQ, std::int64_t 群号, std::string json代码, bool 匿名发送);
	std::string 上传好友图片(std::int64_t 框架QQ, std::int64_t 好友QQ, bool 是否闪照, const std::int8_t* pic, std::int32_t 宽度 = 0, std::int32_t 高度 = 0, bool 动图 = false, std::string 预览文字 = "");
	std::string 上传群图片(std::int64_t 框架QQ, std::int64_t 群号, bool 是否闪照, const std::int8_t* pic, std::int32_t 宽度 = 0, std::int32_t 高度 = 0, bool 动图 = false, std::string 预览文字 = "");
	std::string 上传好友语音(std::int64_t 框架QQ, std::int64_t 好友QQ, std::int32_t 语音类型, std::string 语音文字, const std::int8_t* audio, std::int32_t 时长);
	std::string 上传群语音(std::int64_t 框架QQ, std::int64_t 好友QQ, std::int32_t 语音类型, std::string 语音文字, const std::int8_t* audio, std::int32_t 时长);
	std::string 上传头像(std::int64_t 框架QQ, const std::int8_t* pic);
	std::string 设置群名片(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, std::string 新名片);
	std::string 取昵称_从缓存(std::string 对方QQ);
	std::string 强制取昵称(std::int64_t 框架QQ, std::string 对方QQ);
	std::string 取群名称_从缓存(std::string 群号);
	std::string 获取skey(std::int64_t 框架QQ);
	std::string 获取pskey(std::int64_t 框架QQ, std::string 域);
	std::string 获取clientkey(std::int64_t 框架QQ);
	nlohmann::json 取框架QQ();
	std::int32_t 取好友列表(std::int64_t 框架QQ, std::vector<好友信息>& 数据);
	std::int32_t 取群列表(std::int64_t 框架QQ, std::vector<群信息>& 数据);
	std::int32_t 取群成员列表(std::int64_t 框架QQ, std::int64_t 群号, std::vector<群成员信息>& 数据);
	bool 设置管理员(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, bool 取消管理);
	std::string 取管理层列表(std::int64_t 框架QQ, std::int64_t 群号);
	std::string 取群名片(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ);
	std::string 取个性签名(std::int64_t 框架QQ, std::int64_t 对方QQ);
	bool 修改昵称(std::int64_t 框架QQ, std::string 昵称);
	bool 修改个性签名(std::int64_t 框架QQ, std::string 签名, std::string 签名地点);
	bool 删除群成员(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, bool 拒绝加群申请);
	bool 禁言群成员(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 群成员QQ, std::int32_t 禁言时长);
	bool 退群(std::int64_t 框架QQ, std::int64_t 群号);
	bool 解散群(std::int64_t 框架QQ, std::int64_t 群号);
	bool 上传群头像(std::int64_t 框架QQ, std::int64_t 群号, const std::int8_t* pic);
	bool 全员禁言(std::int64_t 框架QQ, std::int64_t 群号, bool 是否开启);
	bool 群权限_发起新的群聊(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_发起临时会话(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_上传文件(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_上传相册(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_邀请好友加群(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_匿名聊天(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_坦白说(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_新成员查看历史消息(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	bool 群权限_邀请方式设置(std::int64_t 框架QQ, std::int64_t 群号, 审核方式 方式);
	bool 撤回消息_群聊(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t Random, std::int32_t Req);
	bool 撤回消息_私聊本身(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int64_t Random, std::int32_t Req, std::int32_t 消息接收时间);
	bool 设置位置共享(std::int64_t 框架QQ, std::int64_t 群号, double 经度, double 纬度, bool 是否开启);
	bool 上报当前位置(std::int64_t 框架QQ, std::int64_t 群号, double 经度, double 纬度);
	std::int64_t 是否被禁言(std::int64_t 框架QQ, std::int64_t 群号);
	void 处理群验证事件(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 触发QQ, std::int64_t 消息Seq, 操作类型 操作, 群事件 事件类型, std::string 拒绝理由);
	void 处理群验证事件(std::int64_t 框架QQ, std::int64_t 触发QQ, std::int64_t 消息Seq, 操作类型 操作);
	void 查看转发聊天记录内容(std::int64_t 框架QQ, std::string resId, 群消息数据 消息内容);
	std::string 上传群文件(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件路径, std::string 文件夹名);
	std::string 创建群文件夹(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件夹名);
	std::string 重命名群文件夹(std::int64_t 框架QQ, std::int64_t 群号, std::string 旧文件夹名, std::string 新文件夹名);
	std::string 删除群文件夹(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件夹名);
	std::string 删除群文件(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件fileid, std::string 文件夹名);
	std::string 保存文件到微云(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件fileid);
	std::string 移动群文件(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件fileid, std::string 当前文件夹名, std::string 目标文件夹名);
	std::string 取群文件列表(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件夹名, std::vector<群文件信息>& 数据);
	bool 设置在线状态(std::int64_t 框架QQ, 在线状态 main, 在线状态V2 sun, std::int32_t 电量);
	std::string 取插件数据目录();
	std::string QQ点赞(std::int64_t 框架QQ, std::int64_t 对方QQ);
	std::string 取图片下载地址(std::string 图片代码, std::int64_t 框架QQ, std::int64_t 群号);
	bool 查询好友信息(std::int64_t 框架QQ, std::int64_t 对方QQ, 好友信息& 数据);
	bool 查询群信息(std::int64_t 框架QQ, std::int64_t 群号, 群卡片信息& 数据);
	void 框架重启();
	bool 群文件转发至群(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 目标群号, std::string fileId);
	bool 群文件转发至好友(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 目标QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time);
	bool 好友文件转发至好友(std::int64_t 框架QQ, std::int64_t 目标QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time);
	bool 置群消息接收(std::int64_t 框架QQ, std::int64_t 群号, 接收类型 设置类型);
	std::string 取好友在线状态(std::int64_t 框架QQ, std::int64_t 对方QQ);
	std::string 取QQ钱包个人信息(std::int64_t 框架QQ, QQ钱包信息& 数据);
	std::string 获取订单详情(std::int64_t 框架QQ, std::string 订单号, 订单详情& 数据);
	std::string 提交支付验证码(std::int64_t 框架QQ, 验证码信息& 信息, std::string 验证码, std::string 支付密码);
	bool 分享音乐(std::int64_t 框架QQ, std::int64_t 分享对象, std::string 歌曲名, std::string 歌手名, std::string 跳转地址, std::string 封面地址, std::string 文件地址, 音乐应用类型 应用类型, 音乐分享类型 分享类型);
	bool 更改群聊消息内容(std::int32_t 数据指针, std::string 新消息内容);
	bool 更改私聊消息内容(std::int32_t 数据指针, std::string 新消息内容);

	const std::int8_t* silk解码(std::string 音频文件路径);
	const std::int8_t* silk编码(std::string 音频文件路径);
	const std::int8_t* amr编码(std::string 音频文件路径);
private:
	std::string pluginkey;
	nlohmann::json apidata;
protected:
	const char* SDK版本 = "CSDK 1.0";
	 std::int32_t 取API函数地址(std::string 函数名);
}static SDK;