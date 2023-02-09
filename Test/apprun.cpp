#include "apprun.hpp"

文本型 apprun(文本型 _apidata, 文本型 _pluginkey)
{
	return SDK.初始化(_pluginkey, _apidata,"测试","遂沫","1.0","",(整数型)&_AppStart, (整数型)&_AppEnd, (整数型)&_AppUnload, (整数型)&_ControlPanel,0, (整数型)&_OnGroup,0,0);
}

整数型 _AppStart()
{
	
	return 启用响应::启用响应_完成;
}

整数型 _AppEnd()
{
	
	return 启用响应::启用响应_完成;
}

整数型 _AppUnload()
{

	return 启用响应::启用响应_完成;
}

整数型 _ControlPanel()
{
	
	return 启用响应::启用响应_完成;
}

整数型 _OnGroup(群消息数据* 数据指针)
{
	群消息数据 数据 = *数据指针;
	if (数据.发送人QQ != 3498896843)
	{
		SDK.发送群消息(数据.框架QQ, 数据.消息群号, fmt::format("发送人QQ:{}\n框架QQ:{}\n消息Req:{}\n消息接收时间:{}\n消息群号:{}\n来源群名称:{}\n发送人群名片:{}\n消息发送时间:{}\n消息Random:{}\n消息分片序列:{}\n消息分片数量:{}\n消息分片标识:{}\n消息类型:{}\n发送人群头衔:{}\n消息内容:{}\n", 数据.发送人QQ, 数据.框架QQ, 数据.消息Req, 数据.消息接收时间, 数据.消息群号, 数据.来源群名称, 数据.发送人群名片, 数据.消息发送时间, 数据.消息Random, 数据.消息分片序列, 数据.消息分片数量, 数据.消息分片标识, 数据.消息类型, 数据.发送人群头衔, 数据.消息内容).c_str());
	}
	return 消息处理::消息处理_忽略;
}