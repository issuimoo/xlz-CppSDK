#include <Windows.h>
#include <direct.h>
#include <fstream>
#include <io.h>
#include <string>
#include <vector>

#include "enum.hpp"
#include "e2c.hpp"

#pragma pack(4)

struct __declspec(align(4)) 私聊消息数据
{
	std::int64_t 发送人QQ;
	std::int64_t 框架QQ;
	std::int32_t 消息Req;
	std::int64_t 消息Seq;
	std::int32_t 消息接收时间;
	std::int64_t 消息群号;   //当为群临时会话时可取
	std::int32_t 消息发送时间;
	std::int64_t 消息Random;   //消息random
	std::int32_t 消息分片序列;
	std::int32_t 消息分片数量;
	std::int64_t 消息分片标识;
	const char* 消息内容;   //消息内容
	std::int32_t 气泡Id;   //发送人气泡id
	std::int32_t 消息类型;   //消息type
	std::int32_t 消息子类型;   //消息subtype
	std::int32_t 消息子临时类型;   //0 群 1 讨论组 129 腾讯公众号 201 QQ咨询
	std::int32_t 红包类型;   //红包类型:  2已转入余额 4点击收款 10红包
	const std::uint8_t* 会话token;   //会话Token
	std::int64_t 来源事件QQ;   //当消息是其他设备上本QQ的私聊消息时,该值代表发送目标QQ
	const char* 来源事件QQ昵称;   //来源事件QQ的昵称(平时为发送者QQ昵称)
	const char* 保留参数1;
	const std::uint8_t* 保留参数2;
	const char* 保留参数3;
	std::int64_t 消息群Id;   //当为群临时会话时可取
};

struct __declspec(align(4)) 服务信息
{
	std::int32_t 服务代号;   //1SVIP 113QQ大会员 105微云会员 101红钻 102黄钻 103绿钻 104情侣黄钻 4腾讯视频VIP 107SVIP+腾讯视频 110SVIP+QQ音乐 108大王超级会员
	std::int32_t 服务等级;   //级别,由于TCP返回数据不足,故精确查询对方的服务信息推荐解析网页如:https://h5.vip.qq.com/p/mc/privilegelist/other?_wvx=2&friend=173746043
};

struct __declspec(align(4)) 好友信息
{
	const char* 邮箱;
	std::int64_t 账号;
	const char* 昵称;
	const char* 备注;
	const char* 在线状态;   //只能使用[取好友列表]获取,信息不够详细,可通过API[取好友在线状态]获取详细在线信息
	std::int32_t 赞数量;   //只能使用[查询好友信息]获取
	const char* 签名;   //只能使用[查询好友信息]获取
	std::int32_t 性别;   //255隐藏 0男 1女,只能使用[查询好友信息]获取
	std::int32_t Q等级;   //只能使用[查询好友信息]获取
	std::int32_t 年龄;   //只能使用[查询好友信息]获取
	const char* 国家;   //只能使用[查询好友信息]获取
	const char* 省份;   //只能使用[查询好友信息]获取
	const char* 城市;   //只能使用[查询好友信息]获取
	服务信息* 服务列表; //只能使用[查询好友信息]获取 服务列表;
	std::int32_t 连续在线天数;   //只能使用[查询好友信息]获取
	const char* 所属分组名;   //只能使用[取好友列表]获取
	std::int32_t 今日已赞;   //只能使用[查询好友信息]获取
	std::int32_t 今日可赞数;   //只能使用[查询好友信息]获取
};

struct __declspec(align(4)) 群信息
{
	std::int64_t 群ID;
	std::int64_t 群号;
	std::int64_t 保留参数1;
	std::int64_t 群信息查询Seq;
	std::int64_t 保留参数2;
	std::int64_t 群等级查询Seq;
	std::int64_t 保留参数3;
	std::int64_t 全员禁言解除时间戳;   //默认0，如果开了全员禁言，返回腾讯自动解除全员禁言的时间戳(QQ全员禁言开启8年左右后会自动解除)
	std::int64_t 解除禁言时间戳;   //默认0，如果自己被禁言了，返回解除禁言的时间戳
	std::int64_t 保留参数4;
	std::int64_t 保留参数5;
	std::int64_t 保留参数6;
	std::int64_t 群信用等级;
	std::int64_t 保留参数8;
	std::int64_t 保留参数9;
	std::int64_t 保留参数10;
	std::int64_t 保留参数11;
	std::int64_t 群成员数量;
	std::int64_t 群成员数量查询Seq;
	std::int64_t 群成员名片查询Seq;
	std::int64_t 保留参数12;
	std::int64_t 群主QQ;
	std::int64_t 保留参数13;
	std::int64_t 保留参数14;
	std::int64_t 保留参数15;
	std::int64_t 入群时间戳;
	const char* 群名称;
	const char* 新人公告;
};

struct __declspec(align(4)) 讨论组成员信息
{
	std::int64_t 账号;
	const char* 昵称;
	std::int64_t 加入时间;
};

struct __declspec(align(4)) 群成员信息
{
	const char* 账号;
	std::int32_t 年龄;
	std::int32_t 性别;   //255隐藏 0男 1女
	const char* 昵称;
	const char* 邮箱;
	const char* 名片;   //无名片则为空
	const char* 备注;
	const char* 头衔;   //无专属头衔则为空
	const char* 手机号;
	std::int64_t 头衔到期时间;
	std::int64_t 解禁时间戳;   //被禁言者何时会解除禁言
	std::int64_t 加群时间;
	std::int64_t 发言时间;
	std::int64_t 群等级;
};

struct __declspec(align(4)) 群消息数据
{
	std::int64_t 发送人QQ;   //当消息为匿名消息时,此为匿名Id
	std::int64_t 框架QQ;
	std::int32_t 消息Req;
	std::int32_t 消息接收时间;
	std::int64_t 消息群号;
	const char* 来源群名称;   //消息来源群名
	const char* 发送人群名片;   //当对方未设置群名片时,此处为[其QQ昵称(群聊当中) 或 自己给对方的备注(讨论组当中)]
	std::int32_t 消息发送时间;   //消息发送时间
	std::int64_t 消息Random;   //消息random
	std::int32_t 消息分片序列;
	std::int32_t 消息分片数量;
	std::int64_t 消息分片标识;
	消息类型 消息类型;   //消息subtype
	const char* 发送人群头衔;   //发送者QQ群头衔
	const char* 消息内容;   //消息内容
	const char* 回复对象消息内容;   //如果是回复消息,这个变量保存回复的消息的信息
	std::int32_t 气泡Id;   //发送者气泡id
	std::int32_t 群聊等级;
	std::int32_t 挂件Id;
	const char* 匿名昵称;   //消息是匿名消息时,此为对方的匿名昵称,否则为空
	std::uint8_t* 匿名标识;   //可用于禁言等
	const char* 保留参数;   //暂时保留
	std::int64_t 框架QQ匿名Id;   //用于判断框架开启匿名时,收到的消息是否为自身的消息
	std::int32_t 字体Id;
	群消息数据(群消息数据* info):
		发送人QQ{ info->发送人QQ },
		框架QQ{ info->框架QQ },
		消息Req{ info->消息Req },
		消息接收时间{ info->消息接收时间 },
		消息群号{ info->消息群号 },
		消息发送时间{ info->消息发送时间 },
		消息Random{ info->消息Random },
		消息分片序列{ info->消息分片序列 },
		消息分片数量{ info->消息分片数量 },
		消息分片标识{ info->消息分片标识 },
		消息类型{ info->消息类型 },
		气泡Id{ info->气泡Id },
		群聊等级{ info->群聊等级 },
		挂件Id{ info->挂件Id },
		框架QQ匿名Id{ info->框架QQ匿名Id },
		字体Id{ info->字体Id }
	{
		this->来源群名称 = strdup(info->来源群名称);
		this->发送人群名片 = strdup(info->发送人群名片);
		this->发送人群头衔 = strdup(info->发送人群头衔);
		this->消息内容 = strdup(info->消息内容);
		this->回复对象消息内容 = strdup(info->回复对象消息内容);
		this->匿名昵称 = strdup(info->匿名昵称);
		this->保留参数 = strdup(info->保留参数);
		this->匿名标识 = ebin2cbin(info->匿名标识);
	}
	~群消息数据()
	{
		free((void*)this->来源群名称);
		free((void*)this->发送人群名片);
		free((void*)this->发送人群头衔);
		free((void*)this->消息内容);
		free((void*)this->回复对象消息内容);
		free((void*)this->匿名昵称);
		free((void*)this->保留参数);
		delete[] this->匿名标识;
	}
};

struct __declspec(align(4)) 群卡片信息
{
	const char* 群名称;
	const char* 群地点;
	const char* 群分类;
	const char* 群标签;   //以|分割
	const char* 群介绍;
};

struct __declspec(align(4)) 银行卡信息
{
	std::int32_t 序列;
	const char* 尾号;
	const char* 银行;
	const char* 绑定手机;
	const char* bind_serial;
	const char* bank_type;
};

struct __declspec(align(4)) QQ钱包信息
{
	const char* 余额;
	const char* 身份证号;
	const char* 实名;
	银行卡信息* 银行卡列表;
};

struct __declspec(align(4)) 订单详情
{
	const char* 订单时间;
	const char* 订单说明;
	const char* 订单类名;
	const char* 订单类型;
	const char* 订单手续费;
	const char* 操作人QQ;
	const char* 操作人昵称;
	const char* 接收人QQ;
	const char* 接收人昵称;
	const char* 操作金额;
};

struct __declspec(align(4)) 验证码信息
{
	const char* token_id;
	const char* skey;
	const char* bank_type;
	const char* mobile;
	const char* business_type;
	std::int32_t random;
	const char* transaction_id;
	const char* purchaser_id;
	const char* token;
	const char* auth_params;
};

struct __declspec(align(4)) 事件消息数据
{
	std::int64_t 框架QQ;
	std::int64_t 来源群号;
	std::int64_t 操作QQ;
	std::int64_t 触发QQ;
	std::int64_t 消息Seq;
	std::int32_t 消息时间戳;
	const char* 来源群名;
	const char* 操作QQ昵称;
	const char* 触发QQ昵称;
	const char* 消息内容;
	std::int32_t 消息类型;
	std::int32_t 消息子类型;
};

struct __declspec(align(4)) 群文件信息
{
	const char* fileid;   //文件夹fileid或者文件fileid
	const char* filename;   //文件夹名或文件名
	std::int64_t filesize;   //文件大小，文件夹时表示有多少个文件
	const std::uint8_t* filemd5;   //文件夹时为空，部分文件类型也可能是空
	std::int64_t filefromuin;   //创建文件夹或上传文件的QQ
	const char* filefromnick;   //创建文件夹或上传文件QQ的昵称
	std::int32_t filetype;   //1文件 2文件夹
};

struct __declspec(align(4)) 群未领红包数据
{
	std::int64_t 来源QQ;
	const char* listid;
	const char* authkey;
	const char* 标题;
	const char* channel;
};

struct __declspec(align(4)) 群成员状况简略信息
{
	std::int32_t 群上限;
	std::int32_t 群人数;
	std::int64_t 群主;
	std::int64_t* 管理员列表;
};

struct __declspec(align(4)) 群成员信息V2
{
	const char* 群名片;   //无则为空白
	const char* 昵称;
	const char* 群聊等级;   //const char*等级,取决于群等级设置,如：冒泡
	std::int64_t 入群时间戳;
	std::int64_t 最后发言时间戳;
	std::int32_t 管理权限;   //1:普通用户;2:管理员;3:群主
	const char* 头衔;   //无则为空白
};

struct __declspec(align(4)) 资料展示设置数据
{
	std::int32_t 性别;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 年龄;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 生日;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 星座;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 职业;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 公司;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 学校;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 所在地;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 故乡;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 邮箱;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 个人说明;   //0所有人可见 1仅好友可见 2所有人不可见
	std::int32_t 我的王者战绩;   //假 关闭 真 开启
	std::int32_t 我的粉籍;   //假 关闭 真 开启
	std::int32_t 个性标签;   //假 关闭 真 开启
	std::int32_t 匿问我答;   //假 关闭 真 开启
	std::int32_t 人生成就;   //假 关闭 真 开启
	std::int32_t 最近常听;   //假 关闭 真 开启
	std::int32_t 收到礼物;   //假 关闭 真 开启
	std::int32_t 最近在玩;   //假 关闭 真 开启
	std::int32_t 我的音乐盒;   //假 关闭 真 开启
	std::int32_t 随心贴;   //假 关闭 真 开启
	std::int32_t 我的小世界;   //假 关闭 真 开启
	std::int32_t 我的微视;   //假 关闭 真 开启
	std::int32_t 扩列资料;   //假 关闭 真 开启
};

struct __declspec(align(4)) 登录设备信息
{
	const char* QQ版本号;
	std::int32_t QQappid;
	const char* imsi;
	const char* imei;
	const char* 安卓Id;   //AndroidId
	const char* BssId;
	const char* Mac;
	const char* Guid;
	const char* SsId;
	const char* 设备品牌;
	const char* 设备型号;
	std::int32_t 登录协议类型;   //0手Q855,1企点QQ,2安卓HD,3企业QQ,4Tim311
};

struct __declspec(align(4)) 订阅号信息
{
	std::int64_t 订阅号Id;
	const char* 昵称;
	const char* 公众号;
	const char* 信息简介;
};

struct __declspec(align(4)) 讨论组信息
{
	std::int64_t 讨论组Id;
	std::int32_t 成员总数;
	std::int64_t 加入时间戳;
};

struct __declspec(align(4)) 群应用信息
{
	std::int64_t 应用Id;   //当唤醒链接是qq.com时,需要根据应用Id来唤醒应用
	const char* 应用名;
	const char* 唤醒链接;   //mqqapi,部分是qq.com,如:一起看、一起听歌,内含变量,如:$GCODE$代表群号,自行替换
	const char* 应用图标;   //应用图标链接
};

struct __declspec(align(4)) 待付款者信息
{
	std::int64_t QQ;   //定义待被收款者的QQ
	std::int32_t 待付款金额;   //定义待被收款者的收取金额,单位为分
};

struct __declspec(align(4)) 付款者信息
{
	const char* 昵称;
	std::int64_t QQ;
	std::int32_t 应支付金额;   //其应支付的金额,单位分
	std::int32_t 支付状态;   //0:未支付,2:已支付
};

struct __declspec(align(4)) 群收款信息
{
	std::int32_t 订单状态;   //1:等待支付,2:已完成,3:已主动结束
	std::int64_t 收款发起人;   //发起人QQ
	std::int64_t 收款来源群;   //发起来源群(讨论组相关功能已下架,不考虑)
	const char* 收款留言;
	std::int32_t 目标金额;   //群收款订单目标总金额(单位分)
	std::int32_t 已支付金额;   //群收款订单已支付完成金额(单位分)
	付款者信息* 支付详情; //收款支付详情;
};

struct __declspec(align(4)) 文本代码_解析结果
{
	std::int32_t 结果类型;   //0:普通文本,1:文本代码
	const char* 命令;   //文本代码类型,全部到【小写】处理了(因此不管文本代码命令实际是大写还是小写,这里结果都是小写),比如图片类型命令是:pic,厘米秀类型命令是:limishow
	const char* 文本代码数据;   //普通文本原内容 或 文本代码参数数据
};

struct __declspec(align(4)) 文本代码_参数列表
{
	const char* 参数名;   //参数名,全部到【小写】处理了,(因此不管参数名实际是大写还是小写,这里结果都是小写)
	std::int32_t 是否存在;   //是否包含该参数名
	const char* 参数值;   //参数值
};

struct __declspec(align(4)) 欲移除群成员列表
{
	std::int64_t 对方QQ;
	std::int32_t 拒绝下次加群申请;   //是否拒绝此用户的申请
};

struct __declspec(align(4)) 频道推送数据
{
	std::int64_t 框架QQ;   //全部有效
	std::int64_t 框架频道用户Id;   //全部有效
	std::int32_t 消息Req;   //全部有效,可用于撤回消息,事件下代表事件对应的消息
	std::int32_t 消息接收时间;   //全部有效,事件下代表事件接收时间
	std::int64_t 消息频道Id;   //全部有效
	const char* 来源频道名称;   //全部有效
	std::int64_t 消息子频道Id;   //事件、公聊下有效
	const char* 来源子频道名称;   //事件、公聊下有效
	std::int64_t 发送人频道用户Id;   //私信、公聊下有效
	const char* 发送人频道昵称;   //私信、公聊下有效,这个相当于发送者的群名片,未设置时为空白
	const char* 发送人频道用户昵称;   //私信、公聊下有效,发送者的原始昵称
	std::int32_t 事件类型;   //事件下有效
	std::int64_t 私信频道Id;   //私信下有效,可用于回复私信
	std::int64_t 私信子频道Id;   //私信下有效,可用于回复私信
	std::int64_t 接收人频道用户Id;   //私信下有效,为私信接收者
	const char* 接收人频道昵称;   //私信下有效,为私信接收者,这个相当于接收者的群名片,未设置时为空白
	const char* 接收人频道用户昵称;   //私信下有效,为私信接收者,接收者的原始昵称
	std::int64_t 事件触发者频道用户Id;   //事件下有效,为事件触发者
	const char* 事件触发者频道昵称;   //事件下有效,为事件触发者,这个相当于触发者的群名片,未设置时为空白
	const char* 事件触发者频道用户昵称;   //事件下有效,为事件触发者,触发者的原始昵称
	std::int32_t 消息发送时间;   //私信、公聊下有效
	std::int64_t 消息Random;   //私信、公聊下有效
	std::int32_t 事件原始消息Req;
	std::int32_t 消息子Req;
	std::int64_t 事件触发者QQ;
	std::int32_t 频道推送类型;   //0子频道消息,1私信消息,2事件消息
	const char* 身份组;   //公聊下有效,收到消息的时候,只可以知道身份组之一
	const char* 消息内容;   //全部有效,消息内容或事件数据
	const char* 回复对象消息内容;   //如果是回复消息,这个变量保存回复的消息的信息
	const char* 平台身份标志名;   //公聊下有效
	std::int32_t 平台身份标志Id;   //公聊下有效
};

struct __declspec(align(4)) 频道搜索结果
{
	const char* 频道名称;
	const char* 频道简介;
	const char* 频道封面地址;
	const char* 频道Token;
	std::int64_t 频道Id;
	const char* 频道头像地址;
};

struct __declspec(align(4)) 频道成员信息
{
	const char* 频道昵称;   //相当于群名片
	const char* 频道用户昵称;   //原始昵称
	std::int64_t 加入时间戳;
	std::int64_t 频道用户Id;
	const char* 平台身份标志名;
	std::int32_t 平台身份标志Id;
	std::int32_t 成员类型;   //0腾讯机器人,1普通成员,2管理员,3创建者
};

struct __declspec(align(4)) 频道信息
{
	std::int64_t 频道Id;
	std::int64_t 频道创建时间戳;
	std::int32_t 频道成员数量上限;
	std::int32_t 成员数量;
	const char* 频道名称;
	std::int32_t 频道腾讯机器人数量上限;
	std::int32_t 频道管理员数量上限;
	const char* 频道简介;
	std::int64_t 创始人频道用户Id;
};

struct __declspec(align(4)) 频道用户身份组信息
{
	const char* 身份组名;
	std::int64_t 身份组Id;   //1普通人,2频道管理员,4创建者,5子频道管理员
	std::int64_t 身份组外显颜色代码;
};

struct __declspec(align(4)) 频道身份组信息
{
	const char* 身份组名;
	std::int64_t 身份组Id;   //1普通人,2频道管理员,4创建者,5子频道管理员
	std::int64_t 身份组外显颜色代码;
};

struct __declspec(align(4)) 子频道信息
{
	std::int64_t 子频道Id;
	const char* 子频道名称;
	std::int64_t 子频道创建时间戳;
	std::int64_t 所属频道Id;
	std::int32_t 子频道类型;   //1文字,2语音,5直播,7话题,1000050日程提醒,1000010腾讯投票,1000000王者开黑大厅,1000001互动小游戏,1000070CoDM开黑大厅,1000051飞车开黑大厅,1010000和平精英开黑大厅
	std::int32_t 慢速模式;   //0关闭,1每分钟1条,2每分钟2条,3每分钟5条,4每分钟10条,5每5分钟1条,6每10分钟1条,7每15分钟一条,8每30分钟一条,9每一小时一条,10每12小时一条,11每24小时1条
	std::int32_t 发言权限类型;   //1所有频道成员可发言,2仅管理员可发言
	std::int32_t 可视性类型;   //1全部成员可看,2指定成员可看
};

struct __declspec(align(4)) 频道用户个性档案信息
{
	std::int64_t 档案Id;
	const char* 档案名;
	const char* 档案图标地址;
	const char* 档案信息; //json数据
};

struct __declspec(align(4)) 频道用户信息
{
	std::int64_t 频道用户Id;
	const char* 频道用户昵称;
	const char* 频道用户头像地址;
	const char* 频道用户所在国家;
	const char* 频道用户所在省份;   //直辖市也是放在这里
	const char* 频道用户所在市区;
};

struct __declspec(align(4)) 子频道分组信息
{
	const char* 分组名;
	std::int64_t 分组Id;
	std::int64_t* 子频道Id列表;
};

struct __declspec(align(4)) 特定身份组成员信息
{
	const char* 频道昵称;   //相当于群名片
	const char* 频道用户昵称;   //原始昵称
	std::int64_t 频道用户Id;   //1普通人,2频道管理员(这两个是总的两个大分类,通过这两个总的大分类,可以取到所有频道成员)
};

struct __declspec(align(4)) 话题帖子子评论信息
{
	const char* 评论Id;
	std::int64_t 评论者频道用户Id;
	const char* 评论者频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	const char* 评论者头像链接;
	const char* 评论者平台身份标志名;
	std::int32_t 评论者平台身份标志Id;
	频道用户身份组信息* 评论者身份组信息;
	std::int64_t 评论时间戳;
	const char* 评论token;
	const char* 评论内容;
};

struct __declspec(align(4)) 话题帖子评论信息
{
	const char* 评论Id;
	std::int64_t 评论者频道用户Id;
	const char* 评论者频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	const char* 评论者头像链接;
	const char* 评论者平台身份标志名;
	std::int32_t 评论者平台身份标志Id;
	频道用户身份组信息* 评论者身份组信息;
	std::int64_t 评论时间戳;
	const char* 评论token;
	const char* 评论内容;
	话题帖子子评论信息* 子评论;//由于腾讯限制, TCP下只能获取到前几个评论;
};

struct __declspec(align(4)) 话题帖子信息
{
	const char* 帖子Id;
	const char* 帖子标题;
	std::int64_t 发布人频道用户Id;
	const char* 发布人频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	const char* 发布人头像链接;
	const char* 发布人平台身份标志名;
	std::int32_t 发布人平台身份标志Id;
	频道用户身份组信息* 发布人身份组信息;
	const char* 帖子原始内容;   //json数据,但只包含帖子内容
	const char* 帖子详细内容链接;   //帖子的网页链接,内容非常详细,不过需要自行解析,访问需要带上机器人QQ的Cookie和手Q的UA
	const char* 帖子内容;   //由于腾讯自身的原因,TCP下获取到的内容节点顺序与实际内容节点顺序存在差异
	话题帖子评论信息* 帖子评论; //由于腾讯限制, TCP下只能获取到前几个评论;
	const char* 帖子分享卡片代码;   //json
	std::int64_t 帖子发布时间戳;
};

struct __declspec(align(4)) 日程信息
{
	std::int64_t 创建者频道用户Id;
	const char* 创建者频道昵称;   //相当于群名片,此处和频道推送数据不一样,当用户未设置频道昵称时,此处为[频道用户昵称](原始昵称)
	const char* 创建者头像链接;
	std::int64_t 日程Id;
	const char* 日程名;
	const char* 日程描述;
	std::int64_t 开始时间戳;   //13位时间戳
	std::int64_t 结束时间戳;   //13位时间戳
	std::int64_t 创建时间戳;   //13位时间戳
	std::int32_t 提醒;   //默认不提醒,0:不提醒 1:日程开始时 2:5分钟前 3:15分钟前 4:30分钟前 5:1小时前
	std::int64_t 开始时跳转的子频道Id;   //默认无
};

struct __declspec(align(4)) 插件消息发送数据
{
	const char* 插件文件名;
	const char* 插件应用名;
	const char* 插件调用API信息;   //此插件通过哪个API利用哪些参数数据进行消息发送的,如:发送群消息(框架QQ:10001,目标群号:111101,消息内容:$message,匿名发送:假)
	const char* 消息内容;
};
#pragma pack()