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
	文本型 小黄豆表情(emoji 表情);
};

class API : public API_Text
{
public:
	文本型 初始化(文本型 _pluginkey, 文本型 _apidata, 文本型 插件名称, 文本型 插件作者, 文本型 插件版本, 文本型 插件说明, 整数型 被启用处理函数, 整数型 被禁用处理函数, 整数型 将被卸载处理函数, 整数型 插件菜单处理函数, 整数型 私聊消息处理函数, 整数型 群聊消息处理函数, 整数型 频道推送统一处理函数, 整数型 事件消息处理函数);
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
	文本型 上传群图片(长整数型 框架QQ, 长整数型 群号, 字节集 pic, 逻辑型 是否闪照 = false, 整数型 宽度 = 0, 整数型 高度 = 0, 逻辑型 动图 = false, 文本型 预览文字 = "");
	文本型 上传好友语音(长整数型 框架QQ, 长整数型 好友QQ, 字节集 audio, 语音类型 类型 = 语音类型::普通语音, 文本型 语音文字 = "", 整数型 时长 = 0);
	文本型 上传群语音(长整数型 框架QQ, 长整数型 群号, 字节集 audio, 语音类型 类型 = 语音类型::普通语音, 文本型 语音文字 = "", 整数型 时长 = 0);
	文本型 上传头像(长整数型 框架QQ, 字节集 pic);
	字节集 silk解码(文本型 音频文件路径);//请使用delete []释放内存缓存区
	字节集 silk编码(文本型 音频文件路径);//请使用delete []释放内存缓存区
	字节集 amr编码(文本型 音频文件路径);//请使用delete []释放内存缓存区
	文本型 设置群名片(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ, 文本型 新名片 = "");
	文本型 取昵称_从缓存(文本型 对方QQ);
	文本型 强制取昵称(长整数型 框架QQ, 文本型 对方QQ);
	文本型 取群名称_从缓存(文本型 群号);
	文本型 获取skey(长整数型 框架QQ);
	文本型 获取pskey(长整数型 框架QQ, 文本型 域);
	文本型 获取clientkey(长整数型 框架QQ);
	文本型 取框架QQ();
	文本型 取好友列表(长整数型 框架QQ, 好友信息** 数据);
	文本型 取群列表(长整数型 框架QQ, 群信息** 数据);
	文本型 取群成员列表(长整数型 框架QQ, 长整数型 群号, 群成员信息** 数据);
	逻辑型 设置管理员(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ, 逻辑型 取消管理 = false);
	文本型 取管理层列表(长整数型 框架QQ, 长整数型 群号);
	文本型 取群名片(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ);
	文本型 取个性签名(长整数型 框架QQ, 长整数型 对方QQ);
	逻辑型 修改昵称(长整数型 框架QQ, 文本型 昵称);
	逻辑型 修改个性签名(长整数型 框架QQ, 文本型 签名, 文本型 签名地点 = "CN");
	逻辑型 删除群成员(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ, 逻辑型 拒绝加群申请 = false);
	逻辑型 禁言群成员(长整数型 框架QQ, 长整数型 群号, 长整数型 群成员QQ, 整数型 禁言时长 = 60);
	逻辑型 退群(长整数型 框架QQ, 长整数型 群号);
	逻辑型 解散群(长整数型 框架QQ, 长整数型 群号);
	逻辑型 上传群头像(长整数型 框架QQ, 长整数型 群号, 字节集 pic);
	逻辑型 全员禁言(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否开启 = false);
	逻辑型 群权限_发起新的群聊(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = false);
	逻辑型 群权限_发起临时会话(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = false);
	逻辑型 群权限_上传文件(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = true);
	逻辑型 群权限_上传相册(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = true);
	逻辑型 群权限_邀请好友加群(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = true);
	逻辑型 群权限_匿名聊天(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = false);
	逻辑型 群权限_坦白说(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = false);
	逻辑型 群权限_新成员查看历史消息(长整数型 框架QQ, 长整数型 群号, 逻辑型 是否允许 = true);
	逻辑型 群权限_邀请方式设置(长整数型 框架QQ, 长整数型 群号, 审核方式 方式);
	逻辑型 撤回消息_群聊(长整数型 框架QQ, 长整数型 群号, 长整数型 消息Random, 整数型 消息Req);
	逻辑型 撤回消息_私聊本身(长整数型 框架QQ, 长整数型 对方QQ, 长整数型 消息Random, 整数型 消息Req, 整数型 消息接收时间);
	逻辑型 设置位置共享(长整数型 框架QQ, 长整数型 群号, 双精度小数型 经度, 双精度小数型 纬度, 逻辑型 是否开启);
	逻辑型 上报当前位置(长整数型 框架QQ, 长整数型 群号, 双精度小数型 经度, 双精度小数型 纬度);
	长整数型 是否被禁言(长整数型 框架QQ, 长整数型 群号);
	void 处理群验证事件(长整数型 框架QQ, 长整数型 来源群号, 长整数型 触发QQ, 长整数型 消息Seq, 操作类型 操作类型_, 群事件 事件类型, 文本型 拒绝理由);
	void 处理好友验证事件(长整数型 框架QQ, 长整数型 触发QQ, 长整数型 消息Seq, 操作类型 操作类型_);
	void 查看转发聊天记录内容(长整数型 框架QQ, 文本型 resId, 群消息数据** 消息内容);
	文本型 上传群文件(长整数型 框架QQ, 长整数型 群号, 文本型 文件路径, 文本型 文件夹名 = "");
	文本型 创建群文件夹(长整数型 框架QQ, 长整数型 群号, 文本型 文件夹名 = "");
	文本型 重命名群文件夹(长整数型 框架QQ, 长整数型 群号, 文本型 旧文件夹名, 文本型 新文件夹名);
	文本型 删除群文件夹(长整数型 框架QQ, 长整数型 群号, 文本型 文件夹名 = "");
	文本型 删除群文件(长整数型 框架QQ, 长整数型 群号, 文本型 文件fileid, 文本型 文件夹名 = "");
	文本型 保存文件到微云(长整数型 框架QQ, 长整数型 群号, 文本型 文件fileid);
	文本型 移动群文件(长整数型 框架QQ, 长整数型 群号, 文本型 文件fileid, 文本型 当前文件夹名, 文本型 目标文件夹名);
	文本型 取群文件列表(长整数型 框架QQ, 长整数型 群号, 文本型 文件夹名, 群文件信息** 数据);
	逻辑型 设置在线状态(长整数型 框架QQ, 在线状态 main = 在线状态::在线, 在线状态V2 sun = 在线状态V2::我的电量, 整数型 电量 = 128); //sun=1000时，可以设置上报电量，取值1到100，如果想显示正在充电，取值为128+电量
	文本型 取插件数据目录();
	文本型 QQ点赞(长整数型 框架QQ, 长整数型 对方QQ);
private:
	std::string pluginkey;
	nlohmann::json apidata;
protected:
	const char* SDK版本 = "CSDK 1.0";
	整数型 取API函数地址(文本型 函数名);
}static SDK;