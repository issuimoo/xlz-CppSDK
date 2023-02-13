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
	std::string 群聊生僻字红包(std::int64_t 框架QQ, std::int32_t 总数量, std::int32_t 总金额, std::int64_t 讨论组Id, std::string 生僻字, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 支付代付请求(std::int64_t 框架QQ, std::string 代付订单号, std::int32_t 支付金额, std::string 支付密码, std::int32_t 银行卡序列, 验证码信息& 验证码);
	std::string 查询代付状态(std::int64_t 框架QQ, std::string 代付订单号, std::string 代付数据);
	std::string 拉起代付(std::int64_t 框架QQ, std::string 订单号, std::string 代付QQ列表);
	bool 取好友能量值与QID(std::int64_t 框架QQ, std::int64_t 对方QQ, std::int32_t& 能量值, std::string& QID);

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