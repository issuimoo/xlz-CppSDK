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

struct 私聊消息数据
{
	长整数型	发送人QQ;
	长整数型	框架QQ;
	整数型	消息Req;
	长整数型	消息Seq;
	整数型	消息接收时间;
	长整数型	消息群号;			//当为群临时会话时可取
	整数型	消息发送时间;
	长整数型	消息Random;		//消息random
	整数型	消息分片序列;
	整数型	消息分片数量;
	长整数型	消息分片标识;
	文本型	消息内容;			//消息内容
	整数型	气泡Id;			//发送人气泡id
	整数型	消息类型;			//消息type
	整数型	消息子类型;		//消息subtype
	整数型	消息子临时类型;	// 0 群 1 讨论组 129 腾讯公众号 201 QQ咨询
	整数型	红包类型;			//红包类型:  2已转入余额 4点击收款 10红包
	字节集	会话Token;		//会话Token
	长整数型	来源事件QQ;		//当消息是其他设备上本QQ的私聊消息时,该值代表发送目标QQ
	文本型	来源事件QQ昵称;	//来源事件QQ的昵称(平时为发送者QQ昵称)
	文本型	保留参数1;
	字节集	保留参数2;
	文本型	保留参数3;
	长整数型	消息群Id;			//当为群临时会话时可取
};