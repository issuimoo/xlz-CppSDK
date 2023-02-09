﻿#include <cstdint>

typedef std::uint8_t		字节型;		// 易语言字节型
typedef std::int16_t		短整数型;		// 易语言短整数型
typedef std::int32_t		整数型;		// 易语言整数型
typedef std::int64_t		长整数型;		// 易语言长整数型
typedef float				小数型;		// 易语言小数型
typedef double				双精度小数型;	// 易语言双精度小数型
typedef std::uint64_t		日期时间型;	// 易语言日期时间型
typedef std::int32_t		逻辑型;		// 易语言逻辑型
typedef const char*			文本型;		// 易语言文本型(GBK)
typedef const std::uint8_t* 字节集;		// 易语言字节集
typedef std::uintptr_t		子程序指针;	// 易语言子程序指针

enum emoji : 整数型
{
	惊讶
};

enum 审核方式 : 整数型
{
	无需审核 = 1,
	需要管理员审核,
	_100人以内无需审核
};

enum 语音类型 : 整数型
{
	普通语音,
	变声语音,
	文字语音,
	红包匹配语音
};

enum 消息处理 : 整数型
{
	消息处理_忽略,
	消息处理_拦截
};

enum 消息类型 : 整数型
{
	消息类型_临时会话_群临时,
	消息类型_临时会话_讨论组临时,
	消息类型_讨论组消息 = 83,
	消息类型_临时会话_公众号 = 129,
	消息类型_临时会话_好友申请验证消息 = 134,
	消息类型_临时会话 = 141,
	消息类型_好友通常消息 = 166,
	消息类型_临时会话_网页QQ咨询 = 201
};

enum 频道推送类型 : 整数型
{
	频道推送类型_子频道消息,
	频道推送类型_私信消息,
	频道推送类型_事件消息
};

enum 群事件 : 整数型
{
	群事件_我被邀请加入群 = 1,
	群事件_某人加入了群,
	群事件_某人申请加群,
	群事件_群被解散,
	群事件_某人退出了群,
	群事件_某人被踢出群,
	群事件_某人被禁言,
	群事件_某人撤回事件,
	群事件_某人被取消管理,
	群事件_某人被赋予管理,
	群事件_开启全员禁言,
	群事件_关闭全员禁言,
	群事件_开启匿名聊天,
	群事件_关闭匿名聊天,
	群事件_开启坦白说,
	群事件_关闭坦白说,
	群事件_允许群临时会话,
	群事件_禁止群临时会话,
	群事件_允许发起新的群聊,
	群事件_禁止发起新的群聊,
	群事件_允许上传群文件,
	群事件_禁止上传群文件,
	群事件_允许上传相册,
	群事件_禁止上传相册,
	群事件_某人被邀请入群,
	群事件_展示成员群头衔,
	群事件_隐藏成员群头衔,
	群事件_某人被解除禁言,
	群事件_群名变更 = 32,
	群事件_系统提示,
	群事件_群头像事件,
	群事件_入场特效,
	群事件_修改群名片,
	群事件_群被转让,
	群事件_匿名被禁言 = 40,
	群事件_匿名被解除禁言,
	群事件_某人的加群申请被拒绝,
	群事件_展示群互动标识,
	群事件_隐藏群互动标识,
	群事件_展示群成员等级,
	群事件_隐藏群成员等级
};

enum 空间事件 : 整数型
{
	空间事件_与我相关 = 29
};

enum 框架事件 : 整数型
{
	框架事件_登录成功 = 31,
	框架事件_登录失败 = 38,
	框架事件_即将重启更新自身
};

enum 讨论组事件 : 整数型
{
	讨论组事件_讨论组名变更 = 300,
	讨论组事件_某人撤回事件,
	讨论组事件_某人被邀请入群,
	讨论组事件_某人退出了群,
	讨论组事件_某人被踢出群
};

enum 好友事件 : 整数型
{
	好友事件_被好友删除 = 100,
	好友事件_签名变更,
	好友事件_昵称改变,
	好友事件_某人撤回事件,
	好友事件_有新好友,
	好友事件_好友请求,
	好友事件_对方同意了您的好友请求,
	好友事件_对方拒绝了您的好友请求,
	好友事件_资料卡点赞,
	好友事件_签名点赞,
	好友事件_签名回复,
	好友事件_个性标签点赞,
	好友事件_随心贴回复,
	好友事件_随心贴增添,
	好友事件_系统提示,
	好友事件_随心贴点赞,
	好友事件_匿名提问_被提问,
	好友事件_匿名提问_被点赞,
	好友事件_匿名提问_被回复,
	好友事件_输入状态
};

enum 登录事件 : 整数型
{
	登录事件_电脑上线 = 200,
	登录事件_电脑下线,
	登录事件_移动设备上线,
	登录事件_移动设备下线,
	登录事件_其他应用登录验证请求
};

enum 子频道事件 : 整数型
{
	子频道事件_系统提示 = 0,
	子频道事件_消息贴表情变更,
	子频道事件_消息被撤回,
	子频道事件_直播频道状态变更,
	频道事件_频道用户申请加入频道
};

enum 启用响应 : 整数型
{
	启用响应_完成,
	启用响应_拒绝 = 8
};

enum 权限 : 整数型
{
	权限_输出日志 = 1,
	权限_发送好友消息,
	权限_发送群消息,
	权限_发送群临时消息,
	权限_添加好友,
	权限_添加群,
	权限_删除好友,
	权限_置屏蔽好友,
	权限_置特别关心好友,
	权限_发送好友xml消息,
	权限_发送群xml消息,
	权限_发送好友json消息,
	权限_发送群json消息,
	权限_上传好友图片,
	权限_上传群图片,
	权限_上传好友语音,
	权限_上传群语音,
	权限_上传头像,
	权限_设置群名片,
	权限_取昵称_从缓存,
	权限_强制取昵称,
	权限_获取skey,
	权限_获取pskey,
	权限_获取clientkey,
	权限_取框架QQ,
	权限_取好友列表,
	权限_取群列表,
	权限_取群成员列表,
	权限_设置管理员,
	权限_取管理层列表,
	权限_取群名片,
	权限_取个性签名,
	权限_修改昵称,
	权限_修改个性签名,
	权限_删除群成员,
	权限_禁言群成员,
	权限_退群,
	权限_解散群,
	权限_上传群头像,
	权限_全员禁言,
	权限_群权限_发起新的群聊,
	权限_群权限_发起临时会话,
	权限_群权限_上传文件,
	权限_群权限_上传相册,
	权限_群权限_邀请好友加群,
	权限_群权限_匿名聊天,
	权限_群权限_坦白说,
	权限_群权限_新成员查看历史消息,
	权限_群权限_邀请方式设置,
	权限_撤回消息_群聊,
	权限_撤回消息_私聊本身,
	权限_设置位置共享,
	权限_上报当前位置,
	权限_是否被禁言,
	权限_处理好友验证事件,
	权限_处理群验证事件,
	权限_查看转发聊天记录内容,
	权限_上传群文件,
	权限_创建群文件夹,
	权限_设置在线状态,
	权限_QQ点赞,
	权限_取图片下载地址,
	权限_查询好友信息,
	权限_查询群信息,
	权限_框架重启,
	权限_群文件转发至群,
	权限_群文件转发至好友,
	权限_好友文件转发至好友,
	权限_置群消息接收,
	权限_取群名称_从缓存,
	权限_取好友在线状态,
	权限_取QQ钱包个人信息,
	权限_获取订单详情,
	权限_提交支付验证码,
	权限_分享音乐,
	权限_更改群聊消息内容,
	权限_更改私聊消息内容,
	权限_群聊口令红包,
	权限_群聊拼手气红包,
	权限_群聊普通红包,
	权限_群聊画图红包,
	权限_群聊语音红包,
	权限_群聊接龙红包,
	权限_群聊专属红包,
	权限_好友口令红包,
	权限_好友普通红包,
	权限_好友画图红包,
	权限_好友语音红包,
	权限_好友接龙红包,
	权限_重命名群文件夹,
	权限_删除群文件夹,
	权限_删除群文件,
	权限_保存文件到微云,
	权限_移动群文件,
	权限_取群文件列表,
	权限_设置专属头衔,
	权限_下线指定QQ,
	权限_登录指定QQ,
	权限_取群未领红包,
	权限_发送输入状态,
	权限_修改资料,
	权限_打好友电话,
	权限_取群文件下载地址,
	权限_头像双击_好友,
	权限_头像双击_群,
	权限_取群成员简略信息,
	权限_群聊置顶,
	权限_私聊置顶,
	权限_取加群链接,
	权限_设为精华,
	权限_群权限_设置群昵称规则,
	权限_群权限_设置群发言频率,
	权限_群权限_设置群查找方式,
	权限_邀请好友加群,
	权限_置群内消息通知,
	权限_修改群名称,
	权限_下线其他设备,
	权限_登录网页取ck,
	权限_发送群公告,
	权限_取群成员信息,
	权限_取钱包cookie,
	权限_取群网页cookie,
	权限_转账,
	权限_取收款链接,
	权限_取群小视频下载地址,
	权限_取私聊小视频下载地址,
	权限_上传小视频,
	权限_取群成员概况,
	权限_添加好友_取验证类型,
	权限_群聊打卡,
	权限_群聊签到,
	权限_置群聊备注,
	权限_红包转发,
	权限_发送数据包,
	权限_请求ssoseq,
	权限_取sessionkey,
	权限_获取bkn_gtk,
	权限_置好友验证方式,
	权限_上传照片墙图片,
	权限_付款,
	权限_修改支付密码,
	权限_账号搜索,
	权限_添加群_取验证类型,
	权限_领取红包,
	权限_获取红包领取详情,
	权限_取好友文件下载地址,
	权限_删除群成员_批量,
	权限_取扩列资料,
	权限_取资料展示设置,
	权限_设置资料展示,
	权限_获取当前登录设备信息,
	权限_提取图片文字,
	权限_取消精华,
	权限_群权限_设置加群方式,
	权限_群权限_群幸运字符,
	权限_群权限_一起写,
	权限_取QQ空间cookie,
	权限_修改指定QQ缓存密码,
	权限_处理群验证事件_风险号,
	权限_查询网址安全性,
	权限_消息合并转发至好友,
	权限_消息合并转发至群,
	权限_禁言群匿名,
	权限_领取私聊普通红包,
	权限_领取群聊专属红包,
	权限_发送讨论组消息,
	权限_发送讨论组json消息,
	权限_发送讨论组xml消息,
	权限_发送讨论组临时消息,
	权限_撤回消息_讨论组,
	权限_回复QQ咨询会话,
	权限_发送订阅号私聊消息,
	权限_取讨论组名称_从缓存,
	权限_修改讨论组名称,
	权限_取讨论组成员列表,
	权限_强制取自身匿名Id,
	权限_取订阅号列表,
	权限_取讨论组列表,
	权限_邀请好友加群_批量,
	权限_邀请好友加入讨论组_批量,
	权限_讨论组口令红包,
	权限_讨论组拼手气红包,
	权限_讨论组普通红包,
	权限_讨论组画图红包,
	权限_讨论组语音红包,
	权限_讨论组接龙红包,
	权限_讨论组专属红包,
	权限_领取讨论组专属红包,
	权限_取讨论组未领红包,
	权限_取讨论组文件下载地址,
	权限_发送QQ咨询会话,
	权限_创建群聊,
	权限_取群应用列表,
	权限_退出讨论组,
	权限_群验证消息接收设置,
	权限_转让群,
	权限_修改好友备注,
	权限_删除讨论组成员,
	权限_讨论组文件转发至群,
	权限_讨论组文件转发至好友,
	权限_拉起群收款,
	权限_结束群收款,
	权限_查询群收款状态,
	权限_支付群收款,
	权限_消息合并转发至讨论组,
	权限_群收款_催单,
	权限_取好友Diy名片数据,
	权限_设置Diy名片,
	权限_好友生僻字红包,
	权限_群聊生僻字红包,
	权限_讨论组生僻字红包,
	权限_支付代付请求,
	权限_查询代付状态,
	权限_拉起代付,
	权限_取好友能量值与QID,
	权限_文字转语音,
	权限_翻译,
	权限_撤回消息_群聊s,
	权限_QQ列表_添加手表协议QQ,
	权限_QQ列表_二维码登录_拉取二维码,
	权限_QQ列表_二维码登录_查询二维码状态,
	权限_删除群成员_批量s,
	权限_拍一拍好友在线状态,
	权限_发送验证消息会话消息,
	权限_回复验证消息会话消息,
	权限_取群文件内存利用状态,
	权限_取群文件总数,
	权限_上传涂鸦,
	权限_上传好友文件s,
	权限_上传群文件s,
	权限_取群艾特全体剩余次数,
	权限_是否已开启QQ咨询,
	权限_创建群相册,
	权限_删除群相册,
	权限_取群相册列表,
	权限_取群相册照片列表,
	权限_删除群相册照片,
	权限_修改群相册信息,
	权限_取群Id_从缓存,
	权限_上传频道图片,
	权限_发送频道消息,
	权限_发送频道私信消息,
	权限_取私信频道Id,
	权限_频道消息粘贴表情,
	权限_撤回频道消息,
	权限_撤回频道私信消息,
	权限_设置子频道精华消息,
	权限_禁言频道成员,
	权限_设置频道全员禁言,
	权限_移除频道成员,
	权限_移除频道成员_批量,
	权限_退出频道,
	权限_更改频道名称,
	权限_修改频道简介,
	权限_设置我的频道昵称,
	权限_置子频道观看权限,
	权限_置子频道发言权限,
	权限_子频道消息提醒设置,
	权限_子频道慢速模式设置,
	权限_修改子频道名称,
	权限_删除子频道,
	权限_修改我的频道用户信息_昵称,
	权限_修改我的频道用户信息_性别,
	权限_修改我的频道用户信息_年龄,
	权限_修改我的频道用户信息_所在地,
	权限_设置是否允许别人私信我,
	权限_设置频道加入验证方式,
	权限_搜索频道,
	权限_取频道封面,
	权限_取频道头像,
	权限_获取频道成员列表,
	权限_取频道信息,
	权限_取频道加入验证方式,
	权限_申请加入频道,
	权限_取频道文件下载地址,
	权限_频道拼手气红包,
	权限_频道普通红包,
	权限_频道专属红包,
	权限_领取频道专属红包,
	权限_取频道成员身份组,
	权限_设置频道成员身份组,
	权限_修改身份组信息,
	权限_删除身份组,
	权限_新增身份组,
	权限_取频道身份组列表,
	权限_取子频道列表,
	权限_取频道用户个性档案,
	权限_取频道用户资料,
	权限_刷新频道列表缓存,
	权限_取频道列表_从缓存,
	权限_取频道用户昵称_从缓存,
	权限_取频道名称_从缓存,
	权限_取子频道名称_从缓存,
	权限_取频道昵称_从缓存,
	权限_取私信频道列表_从缓存,
	权限_取子频道分组列表,
	权限_上传频道文件,
	权限_更改频道消息内容,
	权限_Emoji转频道EmojiId,
	权限_频道EmojiId转Emoji,
	权限_Emoji转QQ空间EmId,
	权限_QQ空间EmId转Emoji,
	权限_小黄豆Id转QQ空间EmId,
	权限_QQ空间EmId转小黄豆Id,
	权限_取特定身份组成员列表,
	权限_取子频道分组结构,
	权限_设置子频道分组结构,
	权限_删除子频道_批量,
	权限_创建子频道,
	权限_构造卡片消息文本代码,
	权限_分享音乐_频道,
	权限_修改频道排序,
	权限_处理频道加入申请,
	权限_查询群设置,
	权限_取子频道管理列表,
	权限_设置子频道管理,
	权限_设置指定身份组子频道观看权限,
	权限_设置指定身份组子频道发言权限,
	权限_设置直播子频道主播,
	权限_获取频道分享链接,
	权限_获取子频道分享链接,
	权限_子频道消息通知设置,
	权限_获取红包领取详情s,
	权限_取话题子频道帖子列表,
	权限_获取日程列表,
	权限_获取日程链接,
	权限_取日程信息,
	权限_创建日程,
	权限_取QQ头像K值,
	权限_删除日程,
	权限_发送通行证到群,
	权限_发送通行证到好友,
	权限_屏蔽频道用户私信,
	权限_频道用户私信免打扰,
	权限_QQ列表_添加QQ,
	权限_QQ列表_删除QQ,
	权限_登录指定QQ_二次登录,
	权限_取框架插件列表,
	权限_取在线移动设备列表,
	权限_设置频道全局公告_指定消息,
	权限_取频道号,
	权限_设置位置共享s,
	权限_上报当前位置s,
	权限_移动好友分组,
	权限_修改好友分组名,
	权限_删除好友分组,
	权限_取好友分组列表,
	权限_新增好友分组,
	权限_取频道红包pre_grap_token,
	权限_语音红包匹配,
	权限_上传群聊语音红包匹配语音,
	权限_取合并转发消息内容,
	权限_上传合并转发消息,
	权限_语音转文字,
	权限_发送功能包,
	权限_二维码扫一扫授权登录其他应用,
	权限_取历史登录设备guid列表,
	权限_二维码扫一扫授权其他设备资料辅助验证登录,
	权限_关闭设备锁,
	权限_恢复设备锁,
	权限_余额提现,
	权限_取h5钱包cookie,
	权限_取QQ会员中心cookie,
	权限_说说点赞,
	权限_说说评论,
	权限_取最新动态列表,
	权限_搜索表情包,
	权限_发布说说,
	权限_经纬度定位查询详细地址,
	权限_上传群临时文件s,
	权限_删除说说,
	权限_上传QQ封面
};

enum 性别 : 整数型
{
	
	男,
	女,
	未知 = 255
};

enum 服务代号 : 整数型
{
	SVIP = 1,
	腾讯视频VIP = 4,
	红钻 = 101,
	黄钻,
	绿钻,
	情侣黄钻,
	微云会员,
	SVIP腾讯视频 = 107,
	大王超级会员,
	SVIPQQ音乐 = 110,
	QQ大会员 = 113,
};

#pragma pack(4)

struct __declspec(align(4)) 私聊消息数据
{
	长整数型 发送人QQ;
	长整数型 框架QQ;
	整数型 消息Req;
	长整数型 消息Seq;
	整数型 消息接收时间;
	长整数型 消息群号;   //当为群临时会话时可取
	整数型 消息发送时间;
	长整数型 消息Random;   //消息random
	整数型 消息分片序列;
	整数型 消息分片数量;
	长整数型 消息分片标识;
	文本型 消息内容;   //消息内容
	整数型 气泡Id;   //发送人气泡id
	整数型 消息类型;   //消息type
	整数型 消息子类型;   //消息subtype
	整数型 消息子临时类型;   //0 群 1 讨论组 129 腾讯公众号 201 QQ咨询
	整数型 红包类型;   //红包类型:  2已转入余额 4点击收款 10红包
	字节集 会话token;   //会话Token
	长整数型 来源事件QQ;   //当消息是其他设备上本QQ的私聊消息时,该值代表发送目标QQ
	文本型 来源事件QQ昵称;   //来源事件QQ的昵称(平时为发送者QQ昵称)
	文本型 保留参数1;
	字节集 保留参数2;
	文本型 保留参数3;
	长整数型 消息群Id;   //当为群临时会话时可取
};

struct __declspec(align(4)) 服务信息
{
	整数型 服务代号;   //1SVIP 113QQ大会员 105微云会员 101红钻 102黄钻 103绿钻 104情侣黄钻 4腾讯视频VIP 107SVIP+腾讯视频 110SVIP+QQ音乐 108大王超级会员
	整数型 服务等级;   //级别,由于TCP返回数据不足,故精确查询对方的服务信息推荐解析网页如:https://h5.vip.qq.com/p/mc/privilegelist/other?_wvx=2&friend=173746043
};

struct __declspec(align(4)) 好友信息
{
	文本型 邮箱;
	长整数型 账号;
	文本型 昵称;
	文本型 备注;
	文本型 在线状态;   //只能使用[取好友列表]获取,信息不够详细,可通过API[取好友在线状态]获取详细在线信息
	整数型 赞数量;   //只能使用[查询好友信息]获取
	文本型 签名;   //只能使用[查询好友信息]获取
	整数型 性别;   //255隐藏 0男 1女,只能使用[查询好友信息]获取
	整数型 Q等级;   //只能使用[查询好友信息]获取
	整数型 年龄;   //只能使用[查询好友信息]获取
	文本型 国家;   //只能使用[查询好友信息]获取
	文本型 省份;   //只能使用[查询好友信息]获取
	文本型 城市;   //只能使用[查询好友信息]获取
	服务信息* 服务列表; //只能使用[查询好友信息]获取 服务列表;
	整数型 连续在线天数;   //只能使用[查询好友信息]获取
	文本型 所属分组名;   //只能使用[取好友列表]获取
	整数型 今日已赞;   //只能使用[查询好友信息]获取
	整数型 今日可赞数;   //只能使用[查询好友信息]获取
};

struct __declspec(align(4)) 群信息
{
	长整数型 群ID;
	长整数型 群号;
	长整数型 保留参数1;
	长整数型 群信息查询Seq;
	长整数型 保留参数2;
	长整数型 群等级查询Seq;
	长整数型 保留参数3;
	长整数型 全员禁言解除时间戳;   //默认0，如果开了全员禁言，返回腾讯自动解除全员禁言的时间戳(QQ全员禁言开启8年左右后会自动解除)
	长整数型 解除禁言时间戳;   //默认0，如果自己被禁言了，返回解除禁言的时间戳
	长整数型 保留参数4;
	长整数型 保留参数5;
	长整数型 保留参数6;
	长整数型 群信用等级;
	长整数型 保留参数8;
	长整数型 保留参数9;
	长整数型 保留参数10;
	长整数型 保留参数11;
	长整数型 群成员数量;
	长整数型 群成员数量查询Seq;
	长整数型 群成员名片查询Seq;
	长整数型 保留参数12;
	长整数型 群主QQ;
	长整数型 保留参数13;
	长整数型 保留参数14;
	长整数型 保留参数15;
	长整数型 入群时间戳;
	文本型 群名称;
	文本型 新人公告;
};

struct __declspec(align(4)) 讨论组成员信息
{
	长整数型 账号;
	文本型 昵称;
	长整数型 加入时间;
};

struct __declspec(align(4)) 群成员信息
{
	文本型 账号;
	整数型 年龄;
	整数型 性别;   //255隐藏 0男 1女
	文本型 昵称;
	文本型 邮箱;
	文本型 名片;   //无名片则为空
	文本型 备注;
	文本型 头衔;   //无专属头衔则为空
	文本型 手机号;
	长整数型 头衔到期时间;
	长整数型 解禁时间戳;   //被禁言者何时会解除禁言
	长整数型 加群时间;
	长整数型 发言时间;
	长整数型 群等级;
};

struct __declspec(align(4)) 群消息数据
{
	长整数型 发送人QQ;   //当消息为匿名消息时,此为匿名Id
	长整数型 框架QQ;
	整数型 消息Req;
	整数型 消息接收时间;
	长整数型 消息群号;
	文本型 来源群名称;   //消息来源群名
	文本型 发送人群名片;   //当对方未设置群名片时,此处为[其QQ昵称(群聊当中) 或 自己给对方的备注(讨论组当中)]
	整数型 消息发送时间;   //消息发送时间
	长整数型 消息Random;   //消息random
	整数型 消息分片序列;
	整数型 消息分片数量;
	长整数型 消息分片标识;
	消息类型 消息类型;   //消息subtype
	文本型 发送人群头衔;   //发送者QQ群头衔
	文本型 消息内容;   //消息内容
	文本型 回复对象消息内容;   //如果是回复消息,这个变量保存回复的消息的信息
	整数型 气泡Id;   //发送者气泡id
	整数型 群聊等级;
	整数型 挂件Id;
	文本型 匿名昵称;   //消息是匿名消息时,此为对方的匿名昵称,否则为空
	字节集 匿名标识;   //可用于禁言等
	文本型 保留参数;   //暂时保留
	长整数型 框架QQ匿名Id;   //用于判断框架开启匿名时,收到的消息是否为自身的消息
	整数型 字体Id;
};

struct __declspec(align(4)) 群卡片信息
{
	文本型 群名称;
	文本型 群地点;
	文本型 群分类;
	文本型 群标签;   //以|分割
	文本型 群介绍;
};

struct __declspec(align(4)) 银行卡信息
{
	整数型 序列;
	文本型 尾号;
	文本型 银行;
	文本型 绑定手机;
	文本型 bind_serial;
	文本型 bank_type;
};

struct __declspec(align(4)) QQ钱包信息
{
	文本型 余额;
	文本型 身份证号;
	文本型 实名;
	银行卡信息* 银行卡列表;
};

struct __declspec(align(4)) 订单详情
{
	文本型 订单时间;
	文本型 订单说明;
	文本型 订单类名;
	文本型 订单类型;
	文本型 订单手续费;
	文本型 操作人QQ;
	文本型 操作人昵称;
	文本型 接收人QQ;
	文本型 接收人昵称;
	文本型 操作金额;
};

struct __declspec(align(4)) 验证码信息
{
	文本型 token_id;
	文本型 skey;
	文本型 bank_type;
	文本型 mobile;
	文本型 business_type;
	整数型 random;
	文本型 transaction_id;
	文本型 purchaser_id;
	文本型 token;
	文本型 auth_params;
};

struct __declspec(align(4)) 事件消息数据
{
	长整数型 框架QQ;
	长整数型 来源群号;
	长整数型 操作QQ;
	长整数型 触发QQ;
	长整数型 消息Seq;
	整数型 消息时间戳;
	文本型 来源群名;
	文本型 操作QQ昵称;
	文本型 触发QQ昵称;
	文本型 消息内容;
	整数型 消息类型;
	整数型 消息子类型;
};

struct __declspec(align(4)) 群文件信息
{
	文本型 fileid;   //文件夹fileid或者文件fileid
	文本型 filename;   //文件夹名或文件名
	长整数型 filesize;   //文件大小，文件夹时表示有多少个文件
	字节集 filemd5;   //文件夹时为空，部分文件类型也可能是空
	长整数型 filefromuin;   //创建文件夹或上传文件的QQ
	文本型 filefromnick;   //创建文件夹或上传文件QQ的昵称
	整数型 filetype;   //1文件 2文件夹
};

struct __declspec(align(4)) 群未领红包数据
{
	长整数型 来源QQ;
	文本型 listid;
	文本型 authkey;
	文本型 标题;
	文本型 channel;
};

struct __declspec(align(4)) 群成员状况简略信息
{
	整数型 群上限;
	整数型 群人数;
	长整数型 群主;
	长整数型* 管理员列表;
};

struct __declspec(align(4)) 群成员信息V2
{
	文本型 群名片;   //无则为空白
	文本型 昵称;
	文本型 群聊等级;   //文本型等级,取决于群等级设置,如：冒泡
	长整数型 入群时间戳;
	长整数型 最后发言时间戳;
	整数型 管理权限;   //1:普通用户;2:管理员;3:群主
	文本型 头衔;   //无则为空白
};

struct __declspec(align(4)) 资料展示设置数据
{
	整数型 性别;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 年龄;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 生日;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 星座;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 职业;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 公司;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 学校;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 所在地;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 故乡;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 邮箱;   //0所有人可见 1仅好友可见 2所有人不可见
	整数型 个人说明;   //0所有人可见 1仅好友可见 2所有人不可见
	逻辑型 我的王者战绩;   //假 关闭 真 开启
	逻辑型 我的粉籍;   //假 关闭 真 开启
	逻辑型 个性标签;   //假 关闭 真 开启
	逻辑型 匿问我答;   //假 关闭 真 开启
	逻辑型 人生成就;   //假 关闭 真 开启
	逻辑型 最近常听;   //假 关闭 真 开启
	逻辑型 收到礼物;   //假 关闭 真 开启
	逻辑型 最近在玩;   //假 关闭 真 开启
	逻辑型 我的音乐盒;   //假 关闭 真 开启
	逻辑型 随心贴;   //假 关闭 真 开启
	逻辑型 我的小世界;   //假 关闭 真 开启
	逻辑型 我的微视;   //假 关闭 真 开启
	逻辑型 扩列资料;   //假 关闭 真 开启
};

struct __declspec(align(4)) 登录设备信息
{
	文本型 QQ版本号;
	整数型 QQappid;
	文本型 imsi;
	文本型 imei;
	文本型 安卓Id;   //AndroidId
	文本型 BssId;
	文本型 Mac;
	文本型 Guid;
	文本型 SsId;
	文本型 设备品牌;
	文本型 设备型号;
	整数型 登录协议类型;   //0手Q855,1企点QQ,2安卓HD,3企业QQ,4Tim311
};

struct __declspec(align(4)) 订阅号信息
{
	长整数型 订阅号Id;
	文本型 昵称;
	文本型 公众号;
	文本型 信息简介;
};

struct __declspec(align(4)) 讨论组信息
{
	长整数型 讨论组Id;
	整数型 成员总数;
	长整数型 加入时间戳;
};

struct __declspec(align(4)) 群应用信息
{
	长整数型 应用Id;   //当唤醒链接是qq.com时,需要根据应用Id来唤醒应用
	文本型 应用名;
	文本型 唤醒链接;   //mqqapi,部分是qq.com,如:一起看、一起听歌,内含变量,如:$GCODE$代表群号,自行替换
	文本型 应用图标;   //应用图标链接
};

struct __declspec(align(4)) 待付款者信息
{
	长整数型 QQ;   //定义待被收款者的QQ
	整数型 待付款金额;   //定义待被收款者的收取金额,单位为分
};

struct __declspec(align(4)) 付款者信息
{
	文本型 昵称;
	长整数型 QQ;
	整数型 应支付金额;   //其应支付的金额,单位分
	整数型 支付状态;   //0:未支付,2:已支付
};

struct __declspec(align(4)) 群收款信息
{
	整数型 订单状态;   //1:等待支付,2:已完成,3:已主动结束
	长整数型 收款发起人;   //发起人QQ
	长整数型 收款来源群;   //发起来源群(讨论组相关功能已下架,不考虑)
	文本型 收款留言;
	整数型 目标金额;   //群收款订单目标总金额(单位分)
	整数型 已支付金额;   //群收款订单已支付完成金额(单位分)
	付款者信息* 支付详情; //收款支付详情;
};

struct __declspec(align(4)) 文本代码_解析结果
{
	整数型 结果类型;   //0:普通文本,1:文本代码
	文本型 命令;   //文本代码类型,全部到【小写】处理了(因此不管文本代码命令实际是大写还是小写,这里结果都是小写),比如图片类型命令是:pic,厘米秀类型命令是:limishow
	文本型 文本代码数据;   //普通文本原内容 或 文本代码参数数据
};

struct __declspec(align(4)) 文本代码_参数列表
{
	文本型 参数名;   //参数名,全部到【小写】处理了,(因此不管参数名实际是大写还是小写,这里结果都是小写)
	逻辑型 是否存在;   //是否包含该参数名
	文本型 参数值;   //参数值
};

struct __declspec(align(4)) 欲移除群成员列表
{
	长整数型 对方QQ;
	逻辑型 拒绝下次加群申请;   //是否拒绝此用户的申请
};

struct __declspec(align(4)) 频道推送数据
{
	长整数型 框架QQ;   //全部有效
	长整数型 框架频道用户Id;   //全部有效
	整数型 消息Req;   //全部有效,可用于撤回消息,事件下代表事件对应的消息
	整数型 消息接收时间;   //全部有效,事件下代表事件接收时间
	长整数型 消息频道Id;   //全部有效
	文本型 来源频道名称;   //全部有效
	长整数型 消息子频道Id;   //事件、公聊下有效
	文本型 来源子频道名称;   //事件、公聊下有效
	长整数型 发送人频道用户Id;   //私信、公聊下有效
	文本型 发送人频道昵称;   //私信、公聊下有效,这个相当于发送者的群名片,未设置时为空白
	文本型 发送人频道用户昵称;   //私信、公聊下有效,发送者的原始昵称
	整数型 事件类型;   //事件下有效
	长整数型 私信频道Id;   //私信下有效,可用于回复私信
	长整数型 私信子频道Id;   //私信下有效,可用于回复私信
	长整数型 接收人频道用户Id;   //私信下有效,为私信接收者
	文本型 接收人频道昵称;   //私信下有效,为私信接收者,这个相当于接收者的群名片,未设置时为空白
	文本型 接收人频道用户昵称;   //私信下有效,为私信接收者,接收者的原始昵称
	长整数型 事件触发者频道用户Id;   //事件下有效,为事件触发者
	文本型 事件触发者频道昵称;   //事件下有效,为事件触发者,这个相当于触发者的群名片,未设置时为空白
	文本型 事件触发者频道用户昵称;   //事件下有效,为事件触发者,触发者的原始昵称
	整数型 消息发送时间;   //私信、公聊下有效
	长整数型 消息Random;   //私信、公聊下有效
	整数型 事件原始消息Req;
	整数型 消息子Req;
	长整数型 事件触发者QQ;
	整数型 频道推送类型;   //0子频道消息,1私信消息,2事件消息
	文本型 身份组;   //公聊下有效,收到消息的时候,只可以知道身份组之一
	文本型 消息内容;   //全部有效,消息内容或事件数据
	文本型 回复对象消息内容;   //如果是回复消息,这个变量保存回复的消息的信息
	文本型 平台身份标志名;   //公聊下有效
	整数型 平台身份标志Id;   //公聊下有效
};

struct __declspec(align(4)) 频道搜索结果
{
	文本型 频道名称;
	文本型 频道简介;
	文本型 频道封面地址;
	文本型 频道Token;
	长整数型 频道Id;
	文本型 频道头像地址;
};

struct __declspec(align(4)) 频道成员信息
{
	文本型 频道昵称;   //相当于群名片
	文本型 频道用户昵称;   //原始昵称
	长整数型 加入时间戳;
	长整数型 频道用户Id;
	文本型 平台身份标志名;
	整数型 平台身份标志Id;
	整数型 成员类型;   //0腾讯机器人,1普通成员,2管理员,3创建者
};

struct __declspec(align(4)) 频道信息
{
	长整数型 频道Id;
	长整数型 频道创建时间戳;
	整数型 频道成员数量上限;
	整数型 成员数量;
	文本型 频道名称;
	整数型 频道腾讯机器人数量上限;
	整数型 频道管理员数量上限;
	文本型 频道简介;
	长整数型 创始人频道用户Id;
};

struct __declspec(align(4)) 频道用户身份组信息
{
	文本型 身份组名;
	长整数型 身份组Id;   //1普通人,2频道管理员,4创建者,5子频道管理员
	长整数型 身份组外显颜色代码;
};

struct __declspec(align(4)) 频道身份组信息
{
	文本型 身份组名;
	长整数型 身份组Id;   //1普通人,2频道管理员,4创建者,5子频道管理员
	长整数型 身份组外显颜色代码;
};

struct __declspec(align(4)) 子频道信息
{
	长整数型 子频道Id;
	文本型 子频道名称;
	长整数型 子频道创建时间戳;
	长整数型 所属频道Id;
	整数型 子频道类型;   //1文字,2语音,5直播,7话题,1000050日程提醒,1000010腾讯投票,1000000王者开黑大厅,1000001互动小游戏,1000070CoDM开黑大厅,1000051飞车开黑大厅,1010000和平精英开黑大厅
	整数型 慢速模式;   //0关闭,1每分钟1条,2每分钟2条,3每分钟5条,4每分钟10条,5每5分钟1条,6每10分钟1条,7每15分钟一条,8每30分钟一条,9每一小时一条,10每12小时一条,11每24小时1条
	整数型 发言权限类型;   //1所有频道成员可发言,2仅管理员可发言
	整数型 可视性类型;   //1全部成员可看,2指定成员可看
};

struct __declspec(align(4)) 频道用户个性档案信息
{
	长整数型 档案Id;
	文本型 档案名;
	文本型 档案图标地址;
	文本型 档案信息; //json数据
};

struct __declspec(align(4)) 频道用户信息
{
	长整数型 频道用户Id;
	文本型 频道用户昵称;
	文本型 频道用户头像地址;
	文本型 频道用户所在国家;
	文本型 频道用户所在省份;   //直辖市也是放在这里
	文本型 频道用户所在市区;
};

struct __declspec(align(4)) 子频道分组信息
{
	文本型 分组名;
	长整数型 分组Id;
	长整数型* 子频道Id列表;
};

struct __declspec(align(4)) 特定身份组成员信息
{
	文本型 频道昵称;   //相当于群名片
	文本型 频道用户昵称;   //原始昵称
	长整数型 频道用户Id;   //1普通人,2频道管理员(这两个是总的两个大分类,通过这两个总的大分类,可以取到所有频道成员)
};

struct __declspec(align(4)) 话题帖子子评论信息
{
	文本型 评论Id;
	长整数型 评论者频道用户Id;
	文本型 评论者频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	文本型 评论者头像链接;
	文本型 评论者平台身份标志名;
	整数型 评论者平台身份标志Id;
	频道用户身份组信息* 评论者身份组信息;
	长整数型 评论时间戳;
	文本型 评论token;
	文本型 评论内容;
};

struct __declspec(align(4)) 话题帖子评论信息
{
	文本型 评论Id;
	长整数型 评论者频道用户Id;
	文本型 评论者频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	文本型 评论者头像链接;
	文本型 评论者平台身份标志名;
	整数型 评论者平台身份标志Id;
	频道用户身份组信息* 评论者身份组信息;
	长整数型 评论时间戳;
	文本型 评论token;
	文本型 评论内容;
	话题帖子子评论信息* 子评论;//由于腾讯限制, TCP下只能获取到前几个评论;
};

struct __declspec(align(4)) 话题帖子信息
{
	文本型 帖子Id;
	文本型 帖子标题;
	长整数型 发布人频道用户Id;
	文本型 发布人频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	文本型 发布人头像链接;
	文本型 发布人平台身份标志名;
	整数型 发布人平台身份标志Id;
	频道用户身份组信息* 发布人身份组信息;
	文本型 帖子原始内容;   //json数据,但只包含帖子内容
	文本型 帖子详细内容链接;   //帖子的网页链接,内容非常详细,不过需要自行解析,访问需要带上机器人QQ的Cookie和手Q的UA
	文本型 帖子内容;   //由于腾讯自身的原因,TCP下获取到的内容节点顺序与实际内容节点顺序存在差异
	话题帖子评论信息* 帖子评论; //由于腾讯限制, TCP下只能获取到前几个评论;
	文本型 帖子分享卡片代码;   //json
	长整数型 帖子发布时间戳;
};

struct __declspec(align(4)) 日程信息
{
	长整数型 创建者频道用户Id;
	文本型 创建者频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	文本型 创建者头像链接;
	长整数型 日程Id;
	文本型 日程名;
	文本型 日程描述;
	长整数型 开始时间戳;   //13位时间戳
	长整数型 结束时间戳;   //13位时间戳
	长整数型 创建时间戳;   //13位时间戳
	整数型 提醒;   //默认不提醒,0:不提醒 1:日程开始时 2:5分钟前 3:15分钟前 4:30分钟前 5:1小时前
	长整数型 开始时跳转的子频道Id;   //默认无
};

struct __declspec(align(4)) 插件消息发送数据
{
	文本型 插件文件名;
	文本型 插件应用名;
	文本型 插件调用API信息;   //此插件通过哪个API利用哪些参数数据进行消息发送的,如:发送群消息(框架QQ:10001,目标群号:111101,消息内容:$message,匿名发送:假)
	文本型 消息内容;
};
#pragma pack()