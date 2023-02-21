﻿#include <Windows.h>
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
	std::int8_t* ReadDiskFile(std::string File);
	const char* 初始化(const char* _pluginkey, const char* _apidata, std::string 插件名称, std::string 插件作者, std::string 插件版本, std::string 插件说明,  std::int32_t 被启用处理函数,  std::int32_t 被禁用处理函数,  std::int32_t 将被卸载处理函数,  std::int32_t 插件菜单处理函数,  std::int32_t 私聊消息处理函数,  std::int32_t 群聊消息处理函数,  std::int32_t 频道推送统一处理函数,  std::int32_t 事件消息处理函数);
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
	std::string 上传好友图片(std::int64_t 框架QQ, std::int64_t 好友QQ, bool 是否闪照, const std::int8_t* pic, std::int32_t 宽度 = 0, std::int32_t 高度 = 0, bool 动图 = false, std::string 预览文字 = "[图片]");
	std::string 上传群图片(std::int64_t 框架QQ, std::int64_t 群号, bool 是否闪照, const std::int8_t* pic, std::int32_t 宽度 = 0, std::int32_t 高度 = 0, bool 动图 = false, std::string 预览文字 = "[图片]");
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
	std::string 群聊口令红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊拼手气红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊普通红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊画图红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 题目名, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊语音红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 语音口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊接龙红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 接龙内容, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊专属红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 领取人, std::string 祝福语, bool 是否均分, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 好友口令红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 好友普通红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 好友画图红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 题目名, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 好友语音红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 语音口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 好友接龙红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 接龙内容, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	bool 设置专属头衔(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, std::string 头衔);
	bool 下线指定QQ(std::int64_t 框架QQ);
	bool 登录指定QQ(std::int64_t 框架QQ);
	std::int32_t 取群未领红包(std::int64_t 框架QQ, std::int64_t 群号, std::vector<群未领红包数据>& 数据);
	bool 发送输入状态(std::int64_t 框架QQ, std::int64_t 对方QQ, 输入状态 状态);
	bool 修改资料(std::int64_t 框架QQ, std::string 昵称, 性别类型 性别, std::string 生日, 职业类型 职业, std::string 公司名, std::string 所在地, std::string 家乡, std::string 邮箱, std::string 个人说明);
	std::string 取群文件下载地址(std::int64_t 框架QQ, std::int64_t 来源群号, std::string 文件id, std::string 文件名);
	void 打好友电话(std::int64_t 框架QQ, std::int64_t 对方QQ);
	bool 头像双击_好友(std::int64_t 框架QQ, std::int64_t 对方QQ);
	bool 头像双击_群(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int64_t 群号);
	std::string 取群成员简略信息(std::int64_t 框架QQ, std::int64_t 群号, 群成员状况简略信息& 数据);
	bool 群聊置顶(std::int64_t 框架QQ, std::int64_t 群号, bool 置顶);
	bool 私聊置顶(std::int64_t 框架QQ, std::int64_t 对方QQ, bool 置顶);
	std::string 取加群链接(std::int64_t 框架QQ, std::int64_t 群号);
	bool 设为精华(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 消息Req, std::int64_t 消息Random);
	bool 群权限_设置群昵称规则(std::int64_t 框架QQ, std::int64_t 群号, std::string 名片规则);
	bool 群权限_设置群发言频率(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 名片规则);
	bool 群权限_设置群查找方式(std::int64_t 框架QQ, std::int64_t 群号, 查找类型 查找方式);
	bool 邀请好友加群(std::int64_t 框架QQ, std::int64_t 目标群号, std::int64_t 对方QQ, std::int64_t 来源群号);
	bool 置群内消息通知(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, std::int32_t 通知类型);
	bool 修改群名称(std::int64_t 框架QQ, std::int64_t 群号, std::string 名称);
	void 重载自身(std::string 新文件路径);
	void 下线其他设备(std::int64_t 框架QQ, bool 移动设备, std::int32_t appid);
	bool 登录网页取ck(std::int64_t 框架QQ, std::string 回调跳转地址, std::string appid, std::string daid, std::string cookie);
	std::string 发送群公告(std::int64_t 框架QQ, std::int64_t 群号, std::string 标题, std::string 内容, std::int8_t* 图片, std::string 视频, bool 弹窗展示, bool 需要确认, bool 置顶, bool 发送给新成员, bool 引导修改群昵称);
	std::string 取框架版本();
	std::string 取群成员信息(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, 群成员信息V2& 数据);
	std::string 取钱包cookie(std::int64_t 框架QQ);
	std::string 取群网页cookie(std::int64_t 框架QQ);
	std::string 转账(std::int64_t 框架QQ, std::int32_t 转账金额, std::int64_t 对方QQ, std::string 转账留言, 转账类型 类型, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 取收款链接(std::int64_t 框架QQ, std::int32_t 收款金额, std::string 说明文本);
	std::string 取群小视频下载地址(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 来源QQ, std::string param, std::string hash1, std::string 文件名);
	std::string 取私聊小视频下载地址(std::int64_t 框架QQ, std::int64_t 来源QQ, std::string param, std::string hash1, std::string 文件名);
	std::string 上传小视频(std::int64_t 框架QQ, std::int64_t 群号, std::string 本地小视频路径, std::int8_t* 小视频封面图, std::int32_t 宽度, std::int32_t 高度, std::int32_t 时长);
	std::string 发送好友xml消息(std::int64_t 框架QQ, std::int64_t 好友QQ, std::string xml代码, std::int64_t& Random, std::int32_t& Req);
	std::string 发送群xml消息(std::int64_t 框架QQ, std::int64_t 群号, std::string xml代码, bool 匿名发送);
	nlohmann::json 取群成员概况(std::int64_t 框架QQ, std::int64_t 群号);
	nlohmann::json 添加好友_取验证类型(std::int64_t 框架QQ, std::int64_t 对方QQ);
	nlohmann::json 群聊打卡(std::int64_t 框架QQ, std::int64_t 群号);
	bool 群聊签到(std::int64_t 框架QQ, std::int64_t 群号, std::string 附加参数);
	bool 置群聊备注(std::int64_t 框架QQ, std::int64_t 群号, std::string 备注);
	std::string 红包转发(std::int64_t 框架QQ, std::string 红包ID, std::int64_t 目标对象, std::int32_t Type);//1为好友,2为群,3为讨论组
	bool 发送数据包(std::int64_t 框架QQ, std::int32_t 包体序号, std::int32_t 最大等待时长, std::int8_t* 数据);
	std::int32_t 请求ssoseq(std::int64_t 框架QQ);
	std::string 取sessionkey(std::int64_t 框架QQ);
	std::string 获取bkn_gtk(std::int64_t 框架QQ, std::string 自定义bkn_gtk);
	bool 置好友验证方式(std::int64_t 框架QQ, std::int32_t 验证方式, std::string Q_and_A);//1：禁止任何人添加 2：允许任何人添加 3：需要验证信息 4：需要正确回答问题 5：需要回答问题并由我确认
	std::string 上传照片墙图片(std::int64_t 框架QQ, std::int8_t* pic);
	std::string 付款(std::int64_t 框架QQ, std::string QrcodeUrl, std::int32_t 银行卡序列, std::string 支付密码, 验证码信息& 验证码);
	std::string 修改支付密码(std::int64_t 框架QQ, std::string 原密码, std::string 新密码);
	std::string 账号搜索(std::int64_t 框架QQ, std::string 关键词);
	nlohmann::json 添加群_取验证类型(std::int64_t 框架QQ, std::int64_t 群号);
	nlohmann::json 获取红包领取详情(std::int64_t 框架QQ, std::int64_t 来源群号, std::string 红包文本代码, std::string 红包类型);
	std::string 取好友文件下载地址(std::int64_t 框架QQ, std::string FileId, std::string FileName);
	bool 删除群成员_批量(std::int64_t 框架QQ, std::int64_t 群号, std::vector<std::int64_t>& 群成员QQ, bool 拒绝加群申请);
	std::string 取扩列资料(std::int64_t 框架QQ, std::int64_t 对方QQ);
	std::string 取资料展示设置(std::int64_t 框架QQ, std::int64_t 对方QQ, 资料展示设置数据& 数据);
	std::string 设置资料展示(std::int64_t 框架QQ, 资料展示设置数据 数据);
	std::string 获取当前登录设备信息(std::int64_t 框架QQ, 登录设备信息& 信息);
	bool 提取图片文字(std::int64_t 框架QQ, std::string 图片地址, std::string& 识别结果);
	std::string 取插件文件名();
	void TEA加密(std::int8_t*& 内容, std::int8_t* 秘钥);
	void TEA解密(std::int8_t*& 内容, std::int8_t* 秘钥);
	std::string 红包数据加密(std::string str, std::int32_t random);
	std::string 红包数据解密(std::string str, std::int32_t random);
	std::string 红包msgno计算(std::int64_t 目标QQ);
	bool 取消精华(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 消息Req, std::int64_t 消息Random);
	bool 群权限_设置加群方式(std::int64_t 框架QQ, std::int64_t 群号, std::int32_t 加群方式, std::string 问题, std::string 答案); //默认0, 0允许任何人 1需要发送验证消息 2需要回答问题并由管理员审核 3需要正确回答问题 4不允许任何人加群
	bool 群权限_群幸运字符(std::int64_t 框架QQ, std::int64_t 群号, bool 是否开启);
	bool 群权限_一起写(std::int64_t 框架QQ, std::int64_t 群号, bool 是否允许);
	std::string 取QQ空间cookie(std::int64_t 框架QQ);
	bool 框架是否为单Q();
	bool 修改指定QQ缓存密码(std::int64_t 框架QQ, std::string 新密码);
	void 处理群验证事件_风险号(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 触发QQ, std::int64_t 消息Seq, 操作类型 操作, 群事件 事件类型, std::string 拒绝理由);
	std::int32_t 查询网址安全性(std::int64_t 框架QQ, std::string 网址);//403无权限,404框架QQ不存在,405框架QQ未登录,0正常访问,-1查询失败,1包含不安全内容,2非官方页面,3未知状态
	std::string 消息合并转发至好友(std::int64_t 框架QQ, std::int64_t 对方QQ, std::vector<群消息数据> 聊天记录, std::int64_t& Random, std::int32_t& Req, std::string 消息记录来源);
	std::string 消息合并转发至群(std::int64_t 框架QQ, std::int64_t 群号, std::vector<群消息数据> 聊天记录, bool 匿名发送, std::string 消息记录来源);
	std::string 取卡片消息代码(std::string 卡片消息文本代码);
	bool 禁言群匿名(std::int64_t 框架QQ, std::int64_t 群号, std::string 匿名昵称, std::int8_t* 匿名标识, std::int32_t 禁言时长);
	std::int32_t 置文件下载(std::string 文件下载地址, std::string 文件保存路径, std::uintptr_t 下载回调函数/*无返回值 (文件总长度 长整数型,文件已下载长度 长整数型,文件名 文本型) 错误的回调函数将导致崩溃*/, std::string 文件名, std::int32_t 下载起点);
	std::string 领取私聊普通红包(std::int64_t 框架QQ, std::int64_t 来源QQ, std::string 红包文本代码, std::int32_t 类型);//0好友红包,1群临时红包
	std::string 领取群聊专属红包(std::int64_t 框架QQ, std::int64_t 来源群号, std::int64_t 来源QQ, std::string 红包文本代码);
	bool 加载网页(std::string 网址);
	void 压缩包_7za解压(std::string 压缩包路径, std::string 解压保存路径, std::string 解压密码, bool 跳过已存在的文件);
	void 压缩包_7za压缩(std::string 保存路径, std::string 欲压缩的文件, std::string 压缩格式, std::int32_t 压缩等级, std::string 压缩密码);
	std::string 发送讨论组消息(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::string 消息内容);
	std::string 发送讨论组json消息(std::int64_t 框架QQ, std::int64_t 讨论组Id, nlohmann::json Json代码);
	std::string 发送讨论组xml消息(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::string Xml代码);
	std::string 发送讨论组临时消息(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::int64_t 对方QQ, std::string 消息内容, std::int64_t& Random, std::int32_t& Req);
	bool 撤回消息_讨论组(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::int64_t Random, std::int32_t Req);
	std::string 回复QQ咨询会话(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int8_t* 会话Token, std::string 消息内容, std::int64_t& Random, std::int32_t& Req);
	std::string 发送订阅号私聊消息(std::int64_t 框架QQ, std::int64_t 订阅号Id, std::string 消息内容, std::int64_t& Random, std::int32_t& Req);
	std::string 取讨论组名称_从缓存(std::string 讨论组Id);
	bool 修改讨论组名称(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::string 新名称);
	std::int32_t 取讨论组成员列表(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::vector<讨论组成员信息>& 数据);
	std::int64_t 强制取自身匿名Id(std::int64_t 框架QQ, std::int64_t 群号);
	std::int32_t 取订阅号列表(std::int64_t 框架QQ, std::vector<订阅号信息>& 数据);
	std::int32_t 取讨论组列表(std::int64_t 框架QQ, std::vector<讨论组信息>& 数据);
	bool 邀请好友加群_批量(std::int64_t 框架QQ, std::int64_t 目标群号, std::vector<std::int64_t> 邀请QQ, std::int64_t 来源群号);
	bool 邀请好友加入讨论组_批量(std::int64_t 框架QQ, std::int64_t 目标讨论组Id, std::vector<std::int64_t> 邀请QQ, std::int64_t 来源群号);
	std::string 取框架到期时间();
	std::string 讨论组口令红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组拼手气红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组普通红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组画图红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 题目名, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组语音红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 语音口令, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组接龙红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 接龙内容, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组专属红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 领取人, std::string 祝福语, bool 是否均分, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 领取讨论组专属红包(std::int64_t 框架QQ, std::int64_t 来源讨论组Id, std::int64_t 来源QQ, std::string 红包文本代码);
	std::int32_t 取讨论组未领红包(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::vector<群未领红包数据>& 取讨论组未领红包);
	std::string 取讨论组文件下载地址(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::string 文件id, std::string 文件名);
	std::string 发送QQ咨询会话(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string 消息内容, std::int64_t& Random, std::int32_t& Req);
	std::string 创建群聊(std::int64_t 框架QQ, std::vector<std::int64_t> 邀请QQ, std::int64_t 来源群号, std::int64_t& 新群群号);
	std::int32_t 取群应用列表(std::int64_t 框架QQ, std::int64_t 群号, std::vector<群应用信息>& 数据);
	bool 退出讨论组(std::int64_t 框架QQ, std::int64_t 讨论组Id);
	bool 群验证消息接收设置(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ, bool 接收验证消息);
	bool 转让群(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t 对方QQ);
	bool 修改好友备注(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string 备注);
	bool 删除讨论组成员(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::int64_t 对方QQ);
	bool 讨论组文件转发至群(std::int64_t 框架QQ, std::int64_t 来源讨论组Id, std::int64_t 目标群号, std::string fileId, std::string filename, std::int64_t filesize);
	bool 讨论组文件转发至群(std::int64_t 框架QQ, std::int64_t 来源讨论组Id, std::int64_t 目标QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time);
	std::string 取QQ头像(std::int64_t 对方QQ, bool 高清原图);
	std::string 取群头像(std::int64_t 目标群号);
	std::string 取大表情图片下载地址(std::string 大表情文本代码, std::int32_t 长, std::int32_t 宽);
	std::string 拉起群收款(std::int64_t 框架QQ, std::int64_t 群号, std::vector<待付款者信息> 待付款成员, std::string 收款留言, std::string& 收款订单号);
	std::string 结束群收款(std::int64_t 框架QQ, std::string 收款订单号);
	std::string 查询群收款状态(std::int64_t 框架QQ, std::string 收款订单号, std::vector<群收款信息>& 收款数据);
	std::string 支付群收款(std::int64_t 框架QQ, std::int64_t 收款发起人, std::string 收款订单号, std::int32_t 支付金额, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 消息合并转发至讨论组(std::int64_t 框架QQ, std::int64_t 讨论组Id, std::vector<群消息数据> 聊天记录, std::string 消息记录来源);
	std::string 群收款_催单(std::int64_t 框架QQ, std::string 收款订单号);
	bool 取好友Diy名片数据(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string& Diy名片数据);
	std::string 设置Diy名片(std::int64_t 框架QQ, std::string Diy名片数据);
	HWND 取框架主窗口句柄();
	std::string 好友生僻字红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 对方QQ, std::string 生僻字, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 群聊生僻字红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 群号, std::string 生僻字, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 讨论组生僻字红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 生僻字, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 支付代付请求(std::int64_t 框架QQ, std::string 代付订单号, std::int32_t 支付金额, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 查询代付状态(std::int64_t 框架QQ, std::string 代付订单号, std::string 代付数据);
	std::string 拉起代付(std::int64_t 框架QQ, std::string 订单号, std::string 代付QQ列表);
	bool 取好友能量值与QID(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int32_t& 能量值, std::string& QID);
	std::int32_t 创建小栗子文本代码解析类对象();
	std::string 文字转语音(std::int64_t 框架QQ, std::string 文本内容, std::int8_t*& 语音结果);
	std::string 翻译(std::int64_t 框架QQ, std::string 源语言语种, std::string 目标语言语种, std::string 原文, std::string& 翻译结果);
	std::string 撤回消息_群聊s(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t Random, std::int32_t Req);
	std::string QQ列表_添加手表协议QQ(std::int64_t QQ, std::string 品牌, std::string 型号);
	std::string QQ列表_二维码登录_拉取二维码(std::int64_t QQ, std::int8_t*& 二维码数据);
	std::string QQ列表_二维码登录_查询二维码状态(std::int64_t QQ);
	bool 拍一拍好友在线状态(std::int64_t 框架QQ, std::int64_t 对方QQ);
	std::string 发送验证消息会话消息(std::int64_t 框架QQ, std::int64_t 对方QQ, std::string 消息内容, std::int64_t& 消息Random, std::int32_t& 消息Req);
	std::string 回复验证消息会话消息(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int8_t* 会话Token, std::string 消息内容, std::int64_t& 消息Random, std::int32_t& 消息Req);
	std::string 取群文件内存利用状态(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t& 已使用容量, std::int64_t& 总容量);
	std::string 取群文件总数(std::int64_t 框架QQ, std::int64_t 群号, std::int64_t& 已上传文件数, std::int64_t& 文件数量上限);
	std::string 上传涂鸦(std::int64_t 框架QQ, std::int32_t 模型Id, std::int8_t* 涂鸦数据);
	bool 删除群成员_批量s(std::int64_t 框架QQ, std::int64_t 群号, std::vector<欲移除群成员列表> 群成员列表);
	std::string 上传好友文件s(std::int64_t 框架QQ, std::int64_t 好友QQ, std::string 文件路径, std::uintptr_t 上传进度回调函数, std::int64_t& 消息Random, std::int32_t& 消息Req);//void func(int64 框架QQ,int64 好友QQ,eString 本地文件路径,int32 总长度,int32 已上传长度),错误的函数格式将导致崩溃
	std::string 上传群文件s(std::int64_t 框架QQ, std::int64_t 群号, std::string 文件路径, std::string 文件夹名, std::uintptr_t 上传进度回调函数);//void func(int64 框架QQ,int64 群号,eString 本地文件路径,int32 总长度,int32 已上传长度),错误的函数格式将导致崩溃
	std::int32_t 取群艾特全体剩余次数(std::int64_t 框架QQ, std::int64_t 群号);
	std::int32_t 是否已开启QQ咨询(std::int64_t 框架QQ, std::int64_t 对方QQ);
	std::string 创建群相册(std::int64_t 框架QQ, std::int64_t 群号, std::string 相册名, std::string 相册描述);
	std::string 删除群相册(std::int64_t 框架QQ, std::int64_t 群号, std::string 相册Id);
	nlohmann::json 取群相册列表(std::int64_t 框架QQ, std::int64_t 群号);
	nlohmann::json 取群相册照片列表(std::int64_t 框架QQ, std::int64_t 群号, std::string 相册Id, std::int32_t 获取数量);
	nlohmann::json 删除群相册照片(std::int64_t 框架QQ, std::int64_t 群号, std::string 相册Id, std::string 照片Id);
	nlohmann::json 修改群相册信息(std::int64_t 框架QQ, std::int64_t 群号, std::string 相册Id, std::string 相册名, std::string 相册描述,bool 相册置顶);
	std::int64_t 取群Id_从缓存(std::int64_t 群号);
	std::string 上传频道图片(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int8_t* pic, std::int32_t 宽度, std::int32_t 高度, bool 动图);
	nlohmann::json 发送频道消息(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 消息内容);
	nlohmann::json 发送频道私信消息(std::int64_t 框架QQ, std::int64_t 私信频道Id, std::int64_t 私信子频道Id, std::string 消息内容);
	bool 取私信频道Id(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 目标频道用户Id, std::int64_t& 私信频道Id, std::int64_t& 私信子频道Id);
	bool 频道消息粘贴表情(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 消息req, std::string 表情Id, bool 是否为emoji, bool 取消粘贴);
	std::string 撤回频道消息(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 消息req);
	bool 设置子频道精华消息(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 消息req, bool 移除);
	bool 禁言频道成员(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 频道用户Id, std::int32_t 禁言秒数);
	bool 设置频道全员禁言(std::int64_t 框架QQ, std::int64_t 频道Id, std::int32_t 禁言秒数);
	bool 移除频道成员(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 频道用户Id, bool 拉入黑名单);
	bool 移除频道成员_批量(std::int64_t 框架QQ, std::int64_t 频道Id, std::vector<std::int64_t> 频道用户Id列表, bool 拉入黑名单);
	bool 退出频道(std::int64_t 框架QQ, std::int64_t 频道Id);
	bool 更改频道名称(std::int64_t 框架QQ, std::int64_t 频道Id, std::string 新名称, std::int64_t 字色);
	bool 修改频道简介(std::int64_t 框架QQ, std::int64_t 频道Id, std::string 新简介);
	bool 设置我的频道昵称(std::int64_t 框架QQ, std::int64_t 频道Id, std::string 频道昵称);
	bool 置子频道观看权限(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 类型/*1全部成员可看,2指定成员可看,默认1*/, std::int64_t 指定身份组Id, bool 是否取消身份组观看权限, std::int64_t 指定频道成员Id, bool 是否取消频道成员观看权限);
	bool 置子频道发言权限(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 类型/*1全部成员可看,2指定成员可发言,默认1*/, std::int64_t 指定身份组Id, bool 是否取消身份组发言权限, std::int64_t 指定频道成员Id, bool 是否取消频道成员发言权限);
	bool 子频道消息提醒设置(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, bool 对成员打开消息提醒);
	bool 子频道慢速模式设置(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 模式);//默认关闭,0关闭,1每分钟一条,2每分钟两条,3每分钟5条,4每分钟十条,5每5分钟1条,6每10分钟1条,7每15分钟一条,8每30分钟一条,9每一小时一条,10每12小时一条,11每24小时1条
	bool 修改子频道名称(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 新名称);
	bool 删除子频道(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id);
	bool 修改我的频道用户信息_昵称(std::int64_t 框架QQ, std::string 新昵称);
	bool 修改我的频道用户信息_性别(std::int64_t 框架QQ, std::int32_t 性别);//1男,2女,默认男
	bool 修改我的频道用户信息_年龄(std::int64_t 框架QQ, std::int32_t 年龄);
	bool 修改我的频道用户信息_所在地(std::int64_t 框架QQ, std::int32_t 国家代码, std::string 国家名称, std::int32_t 省份代码, std::string 省份名称, std::int32_t 市区代码, std::string 市区名称);
	bool 设置是否允许别人私信我(std::int64_t 框架QQ, bool 不允许);
	bool 设置频道加入验证方式(std::int64_t 框架QQ, std::int64_t 频道Id, std::int32_t 验证方式/*1允许任何人 2需要验证消息 3不允许任何人 4需要正确回答问题 5需要回答问题,默认1*/, std::string 问题, std::string 答案);
	std::int32_t 搜索频道(std::int64_t 框架QQ, std::string 关键词, std::int32_t 第几页, std::vector<频道搜索结果>& 结果);
	std::string 取频道封面(std::int64_t 频道Id);
	std::string 取频道头像(std::int64_t 频道Id, bool 高清大图);
	std::int32_t 获取频道成员列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::vector<频道成员信息>& 结果, std::int32_t& 翻页数据, std::string& 翻页信息);
	bool 取频道信息(std::int64_t 框架QQ, std::int64_t 频道Id, 频道信息& 结果);
	bool 取频道加入验证方式(std::int64_t 框架QQ, std::int64_t 频道Id, std::int32_t& 验证方式/*参考传回,1允许任何人 2需要验证消息 3不允许任何人 4需要正确回答问题 5需要回答问题*/, std::string& 问题);
	std::string 申请加入频道(std::int64_t 框架QQ, std::int32_t 验证方式, std::int64_t 频道Id, std::string 频道Token, std::string 答案);//errcode=22010是申请成功
	std::string 取频道文件下载地址(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::string fileid, std::string filename);
	nlohmann::json 频道拼手气红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	nlohmann::json 频道普通红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 祝福语, std::int32_t 红包皮肤Id, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	nlohmann::json 讨论组专属红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 频道Id, std::int64_t 子频道Id, std::int64_t 领取人频道用户Id, std::string 祝福语, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	nlohmann::json 领取频道专属红包(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int64_t 发送人频道用户Id, std::string 红包文本代码);
	std::int32_t 取频道成员身份组(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 频道用户Id, std::vector<频道用户身份组信息>& 结果);
	bool 设置频道成员身份组(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 频道用户Id, std::vector<std::int64_t> 身份组Id列表, bool 是否取消身份组);
	bool 修改身份组信息(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 身份组Id, std::string 身份组名, std::int64_t 身份组外显颜色代码, bool 是否在成员列表中单独展示);
	bool 删除身份组(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 身份组Id);
	std::int64_t 新增身份组(std::int64_t 框架QQ, std::int64_t 频道Id, std::string 身份组名, std::int64_t 身份组外显颜色代码, bool 是否在成员列表中单独展示);
	std::int32_t 取频道身份组列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::vector<频道身份组信息>& 结果);
	std::int32_t 取子频道列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::vector<子频道信息>& 结果);
	std::int32_t 取频道用户个性档案(std::int64_t 框架QQ, std::int64_t 频道用户Id, std::vector<频道用户个性档案信息>& 结果);
	bool 取频道用户资料(std::int64_t 框架QQ, std::int64_t 频道用户Id, 频道用户信息& 结果);
	bool 刷新频道列表缓存(std::int64_t 框架QQ);
	nlohmann::json  取频道列表_从缓存(std::int64_t 框架QQ);
	std::string 取频道用户昵称_从缓存(std::int64_t 频道用户Id);
	std::string 取频道名称_从缓存(std::int64_t 频道Id);
	std::string 取子频道名称_从缓存(std::int64_t 频道Id,std::int64_t 子频道Id);
	std::string 取频道昵称_从缓存(std::int64_t 频道Id,std::int64_t 频道用户Id);
	std::int32_t 取子频道分组列表(std::int64_t 框架QQ, std::int64_t 子频道Id, std::vector<子频道分组信息>& 结果);
	nlohmann::json 取私信频道列表_从缓存(std::int64_t 框架QQ);
	std::string 上传频道文件(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 文件路径, std::int32_t 上传进度回调函数/*void func(int64 框架QQ,int64 频道Id,int64 子频道Id,eString 本地文件路径,int32 总长度,int32 已上传长度),错误的函数格式将导致崩溃*/, std::int32_t 图片宽度, std::int32_t 图片高度);
	bool 更改频道消息内容(std::int32_t 数据指针, std::string 新消息内容);
	std::string Emoji转频道EmojiId(std::string Emoji代码);
	std::string 频道EmojiId转Emoji(std::string 频道EmojiId);
	std::string Emoji转QQ空间EmId(std::string Emoji代码);
	std::string QQ空间EmId转Emoji(std::string QQ空间EmId);
	std::string 小黄豆Id转QQ空间EmId(std::string 小黄豆Id);
	std::string QQ空间EmId转小黄豆Id(std::string QQ空间EmId);
	std::int32_t 取特定身份组成员列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 身份组Id/*1普通人,2频道管理员,4创建者,5子频道管理员,其他身份组Id通过API【取频道身份组列表】取*/, std::vector<特定身份组成员信息>& 结果, std::int32_t 开始位置);
	nlohmann::json 取子频道分组结构(std::int64_t 框架QQ,std::int64_t 频道Id);
	nlohmann::json 设置子频道分组结构(std::int64_t 框架QQ,std::int64_t 频道Id,std::string 子频道分组结构);
	bool 删除子频道_批量(std::int64_t 框架QQ, std::int64_t 频道Id, std::vector<std::int64_t> 子频道Id列表);
	bool 创建子频道(std::int64_t 框架QQ, std::int64_t 频道Id, std::string 原始子频道分组结构, std::string 子频道名称, std::int32_t 消息提醒设置/*1对成员打开消息提醒 2不对成员打开消息提醒,默认2*/, std::int32_t 子频道类型/*1讨论频道 2语音频道 5直播频道 6应用频道 7话题频道,默认1*/, std::int32_t 子频道子类型 /*0闲聊,1公告,2攻略,默认0,当子频道类型不为1时,恒为0*/, std::int32_t 应用Id /*当子频道类型为6时设置,1000050日程提醒 1000010腾讯投票 1000000王者开黑大厅 1000001互动小游戏 1000070CoDM开黑大厅 1000051飞车开黑大厅 1010000和平精英开黑大厅*/, std::int32_t 可视类型/*1全部成员可看,2指定成员可看,默认1*/, std::vector<std::int64_t> 指定成员频道用户Id列表, std::vector<std::int64_t> 指定身份组Id, std::int32_t 所属分组index, std::int32_t 分组内位置);
	std::string 构造卡片消息文本代码(std::string 卡片代码, std::int32_t 类型/*0xml,1json,默认xml*/, bool 强制发送);
	bool 分享音乐_频道(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 歌曲名, std::string 歌手名, std::string 跳转地址, std::string 封面地址, std::string 文件地址, std::int32_t 应用类型);
	bool 修改频道排序(std::int64_t 框架QQ, std::vector<std::int64_t> 频道Id列表);
	bool 处理频道加入申请(std::int64_t 框架QQ, std::string 频道用户标识, std::int32_t 操作/*0拒绝 1同意*/);
	nlohmann::json 查询群设置(std::int64_t 框架QQ, std::int64_t 群号);
	std::int32_t 取子频道管理列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::vector<特定身份组成员信息>& 结果);
	bool 设置子频道管理(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::vector<std::int64_t> 频道用户Id列表, bool 是否取消子频道管理);
	bool 设置指定身份组子频道观看权限(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 身份组Id, std::vector<std::int64_t> 欲设置的子频道Id列表, bool 是否取消观看权限);
	bool 设置指定身份组子频道发言权限(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 身份组Id, std::vector<std::int64_t> 欲设置的子频道Id列表, bool 是否取消发言权限);
	bool 设置直播子频道主播(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 直播子频道Id, std::vector<std::int64_t> 欲设置的频道用户Id列表, bool 是否取消主播身份);
	std::string 获取频道分享链接(std::int64_t 框架QQ, std::int64_t 频道Id);
	std::string 获取子频道分享链接(std::int64_t 框架QQ, std::int64_t 频道Id,std::int64_t 子频道Id);
	bool 子频道消息通知设置(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, bool 开启消息通知);
	std::string 获取红包领取详情s(std::int64_t 框架QQ, std::int64_t 红包来源, std::int64_t 子频道Id, std::string 红包文本代码, std::int32_t 红包类型/*1:好友,2:群聊,3:讨论组,4:群临时,5:子频道*/, std::int32_t 起始位置);
	std::int32_t 取话题子频道帖子列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 话题子频道Id, std::vector<话题帖子信息>& 结果, std::string& 翻页信息);
	std::int32_t 获取日程列表(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 日程子频道Id, std::int64_t 时间戳, std::vector<日程信息>& 结果);
	std::string 获取日程链接(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 日程子频道Id, std::int64_t 日程Id);
	bool 取日程信息(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 日程子频道Id, std::int64_t 日程Id, 日程信息& 信息);
	bool 创建日程(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 日程子频道Id, std::string 日程名, std::string 日程描述, std::int64_t 开始时间戳, std::int64_t 结束时间戳, std::int32_t 提醒, std::int64_t 开始时跳转的子频道Id, 日程信息& 信息);
	std::string 取QQ头像K值(std::int64_t 框架QQ, std::int64_t 对方QQ);
	bool 删除日程(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 日程子频道Id, 日程信息& 信息);
	bool 发送通行证到群(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 群号, std::int32_t 通行证数量);
	bool 发送通行证到好友(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 对方QQ);
	bool 屏蔽频道用户私信(std::int64_t 框架QQ, std::int64_t 频道用户Id, bool 解除屏蔽);
	bool 频道用户私信免打扰(std::int64_t 框架QQ, std::int64_t 频道用户Id, bool 关闭免打扰);
	std::string QQ列表_添加QQ(std::int64_t QQ, std::string 密码, std::string 手机品牌, std::string 手机型号, std::int32_t 协议/*0 安卓QQ,1 企点QQ,2 QQaPad,3 企业QQ,4 手机Tim,5 手表QQ,6 QQiPad,7 苹果QQ 8 MacQQ,普通QQ无法登录企业/企点*/, std::string guid);
	std::string QQ列表_删除QQ(std::int64_t QQ, bool 彻底删除);
	bool 登录指定QQ_二次登录(std::int64_t 框架QQ);
	bool 是否已设置QQ密码(std::int64_t 框架QQ);
	nlohmann::json 取框架插件列表();
	std::string 取在线移动设备列表(std::int64_t 框架QQ);
	bool 设置频道全局公告_指定消息(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::int32_t 消息req);
	std::string 取频道号(std::int64_t 框架QQ, std::int64_t 频道Id);
	bool 设置位置共享s(std::int64_t 框架QQ, std::int64_t 目标, double 经度, double 纬度, bool 是否开启, std::int32_t 类型/*0群,1好友,默认群*/);
	bool 上报当前位置s(std::int64_t 框架QQ, std::int64_t 目标, double 经度, double 纬度, double 指针偏角);
	bool 移动好友分组(std::int64_t 框架QQ, std::int64_t 好友QQ, std::int32_t 分组Id);
	bool 修改好友分组名(std::int64_t 框架QQ, std::int64_t 分组Id, std::string 分组名/*支持emoji*/);
	bool 删除好友分组(std::int64_t 框架QQ, std::int64_t 分组Id);
	nlohmann::json 取好友分组列表(std::int64_t 框架QQ);
	std::int32_t 新增好友分组(std::int64_t 框架QQ, std::string 分组名/*支持emoji*/);
	nlohmann::json 取频道红包pre_grap_token(std::int64_t 框架QQ, std::int64_t 频道Id, std::int64_t 子频道Id, std::string 红包listid, std::string 红包authkey, std::string 红包channel, std::int64_t 红包发送人频道用户Id);
	nlohmann::json 语音红包匹配(std::int64_t 框架QQ, std::int64_t 红包接收对象, std::string 红包标题, std::string 匹配语音hash, std::string 红包listid, std::string 红包authkey, std::int64_t 红包发送者QQ, std::string 红包来源类型/*0:群聊红包,1:好友红包,默认0*/);
	std::string 上传群聊语音红包匹配语音(std::int64_t 框架QQ, std::int64_t 红包来源群号, std::int8_t* audio);
	std::string 取合并转发消息内容(std::int64_t 框架QQ, std::string resId);
	std::string 上传合并转发消息(std::int64_t 框架QQ, std::string 消息来源/*"xxx的聊天记录",可填如:群聊、A和B*/, std::string 消息封面/*定义封面消息内容,多条消息用符号"<[#]>"分隔,如 A: 巴拉巴拉<[#]>B: 巴拉巴拉<[#]>C: 巴拉巴拉*/, std::string 合并转发消息内容/*json格式,数据结构可参照API【取合并转发消息内容】的返回结果,"MultiMsg"是最外层的消息,嵌套使用filename作为索引*/);
	std::string 语音转文字(std::int64_t 框架QQ, std::string 语音hash, std::string 语音token);
	bool 发送功能包(std::int64_t 框架QQ, std::string 功能cmd, std::int32_t 最大等待时长, std::int8_t*& 数据);
	std::string 二维码扫一扫授权登录其他应用(std::int64_t 框架QQ, std::string k值);
	nlohmann::json 取历史登录设备guid列表(std::int64_t 框架QQ);
	std::string 二维码扫一扫授权其他设备资料辅助验证登录(std::int64_t 框架QQ, std::string str_url);
	bool 关闭设备锁(std::int64_t 框架QQ);
	bool 恢复设备锁(std::int64_t 框架QQ);
	std::string 余额提现(std::int64_t 框架QQ, std::int32_t 提现金额, std::string 支付密码, std::int32_t 银行卡序列);
	std::string 取h5钱包cookie(std::int64_t 框架QQ);
	std::string 取QQ会员中心cookie(std::int64_t 框架QQ);
	bool 说说点赞(std::int64_t 框架QQ, std::int64_t 说说发布者QQ, std::string 说说feedskey, bool 取消点赞);
	bool 说说评论(std::int64_t 框架QQ, std::int64_t 说说发布者QQ, std::string 说说feedskey, std::string 评论内容);
	std::string 取最新动态列表(std::int64_t 框架QQ);
	std::string 搜索表情包(std::int64_t 框架QQ, std::string 关键词);
	std::string 发布说说(std::int64_t 框架QQ, std::string 内容);
	std::string 经纬度定位查询详细地址(std::int64_t 框架QQ, double 经度, double 纬度);
	std::string 取插件自身版本号();
	std::string 上传群临时文件s(std::int64_t 框架QQ, std::int64_t 好友QQ, std::int64_t 对方QQ, std::int64_t 群号, std::string 文件路径, std::uintptr_t 上传进度回调函数/*void func(int64 框架QQ,int64 好友QQ,eString 本地文件路径,int32 总长度,int32 已上传长度),错误的函数格式将导致崩溃*/, std::int64_t& Random, std::int32_t& Req);
	bool 删除说说(std::int64_t 框架QQ, std::string 说说feedskey);
	std::string 上传QQ封面(std::int64_t 框架QQ, std::int8_t* 图片);
	std::string ark消息签名(std::int64_t 框架QQ, nlohmann::json json);
	const std::int8_t* silk解码(std::string 音频文件路径);
	const std::int8_t* silk编码(std::string 音频文件路径);
	const std::int8_t* amr编码(std::string 音频文件路径);
private:
	const char* pluginkey;
	nlohmann::json apidata;
protected:
	const char* SDK版本 = "CSDK 1.0";
	 std::int32_t 取API函数地址(std::string 函数名);
}static SDK;





/*
Cornerstone SDK v1.0.1
-- 面向现代 C++ 的 Corn SDK
兼容小栗子框架 v2.7.1-v2.7.2 和 Corn SDK v2.7.1
https://github.com/Sc-Softs/CornerstoneSDK
使用 MIT License 进行许可
SPDX-License-Identifier: MIT
Copyright © 2020 Contributors of Cornerstone SDK
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

struct earray_head
{
	void* data;
	HANDLE heap;

	earray_head() noexcept
	{
		this->heap = GetProcessHeap();
		this->data = HeapAlloc(heap, HEAP_ZERO_MEMORY, 1);
		reinterpret_cast<std::uint8_t*>(this->data)[0] = 1;
	}

	~earray_head() noexcept
	{
		HeapFree(this->heap, 0, this->data);
	}

	operator void** ()
	{
		return &this->data;
	}
};

template <typename EType, typename CPPType>
size_t earray1d2vector(const earray_head& earr, ::std::vector<CPPType>& out)
{
	auto srcptr = reinterpret_cast<std::int32_t*>(earr.data);
	auto dim = srcptr[0];
	if (dim != 1)
		return static_cast<size_t>(-1);
	auto size = srcptr[1];
	if constexpr (::std::is_compound<CPPType>::value)
	{
		auto pptr = reinterpret_cast<EType**>(srcptr + 2);
		out.clear();
		out.reserve(size);
		::std::for_each(pptr, pptr + size, [&](auto ptr) {
			out.emplace_back(*ptr);
			});
	}
	else
	{
		auto ptr = reinterpret_cast<EType*>(srcptr + 2);
		out.clear();
		out.reserve(size);
		::std::for_each(ptr, ptr + size, [&](auto val) {
			out.emplace_back(val);
			});
	}
	return size;
}