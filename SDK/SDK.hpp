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
	std::string С�ƶ�����(emoji ����);
};

class API : public API_Text
{
public:
	std::string ��ʼ��(std::string _pluginkey, std::string _apidata, std::string �������, std::string �������, std::string ����汾, std::string ���˵��,  std::int32_t �����ô�����,  std::int32_t �����ô�����,  std::int32_t ����ж�ش�����,  std::int32_t ����˵�������,  std::int32_t ˽����Ϣ������,  std::int32_t Ⱥ����Ϣ������,  std::int32_t Ƶ������ͳһ������,  std::int32_t �¼���Ϣ������);
	std::string �����־(std::string ��־,  std::int32_t ������ɫ = 32768,  std::int32_t ������ɫ = 16777215);
	std::string ���ͺ�����Ϣ(std::int64_t ���QQ, std::int64_t ����QQ, std::string ��������, std::int64_t& Random, std::int32_t& Req);
	std::string ����Ⱥ��Ϣ(std::int64_t ���QQ, std::int64_t Ⱥ��,std::string ��������,bool ��������);
	std::string ����Ⱥ��ʱ��Ϣ(std::int64_t ���QQ, std::int64_t ȺID, std::int64_t �Է�QQ, std::string ��������, std::int64_t& Random, std::int32_t& Req);
	std::string ��Ӻ���(std::int64_t ���QQ, std::int64_t �Է�QQ, std::string �����, std::string ��ע);
	std::string ���Ⱥ(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string ��֤��Ϣ);
	std::string ɾ������(std::int64_t ���QQ, std::int64_t �Է�QQ);
	std::string �����κ���(std::int64_t ���QQ, std::int64_t �Է�QQ, bool �Ƿ�����);
	std::string ���ر���ĺ���(std::int64_t ���QQ, std::int64_t �Է�QQ, bool �Ƿ����);
	std::string ���ͺ���json��Ϣ(std::int64_t ���QQ, std::int64_t �Է�QQ, std::string json����, std::int64_t& Random, std::int32_t& Req);
	std::string ����Ⱥjson��Ϣ(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string json����, bool ��������);
	std::string �ϴ�����ͼƬ(std::int64_t ���QQ, std::int64_t ����QQ, bool �Ƿ�����, const std::int8_t* pic, std::int32_t ��� = 0, std::int32_t �߶� = 0, bool ��ͼ = false, std::string Ԥ������ = "");
	std::string �ϴ�ȺͼƬ(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����, const std::int8_t* pic, std::int32_t ��� = 0, std::int32_t �߶� = 0, bool ��ͼ = false, std::string Ԥ������ = "");
	std::string �ϴ���������(std::int64_t ���QQ, std::int64_t ����QQ, std::int32_t ��������, std::string ��������, const std::int8_t* audio, std::int32_t ʱ��);
	std::string �ϴ�Ⱥ����(std::int64_t ���QQ, std::int64_t ����QQ, std::int32_t ��������, std::string ��������, const std::int8_t* audio, std::int32_t ʱ��);
	std::string �ϴ�ͷ��(std::int64_t ���QQ, const std::int8_t* pic);
	std::string ����Ⱥ��Ƭ(std::int64_t ���QQ, std::int64_t Ⱥ��, std::int64_t Ⱥ��ԱQQ, std::string ����Ƭ);
	std::string ȡ�ǳ�_�ӻ���(std::string �Է�QQ);
	std::string ǿ��ȡ�ǳ�(std::int64_t ���QQ, std::string �Է�QQ);
	std::string ȡȺ����_�ӻ���(std::string Ⱥ��);
	std::string ��ȡskey(std::int64_t ���QQ);
	std::string ��ȡpskey(std::int64_t ���QQ, std::string ��);
	std::string ��ȡclientkey(std::int64_t ���QQ);
	nlohmann::json ȡ���QQ();
	std::int32_t ȡ�����б�(std::int64_t ���QQ, std::vector<������Ϣ>& ����);
	std::int32_t ȡȺ�б�(std::int64_t ���QQ, std::vector<Ⱥ��Ϣ>& ����);
	std::int32_t ȡȺ��Ա�б�(std::int64_t ���QQ, std::int64_t Ⱥ��, std::vector<Ⱥ��Ա��Ϣ>& ����);
	bool ���ù���Ա(std::int64_t ���QQ, std::int64_t Ⱥ��, std::int64_t Ⱥ��ԱQQ, bool ȡ������);
	std::string ȡ������б�(std::int64_t ���QQ, std::int64_t Ⱥ��);
	std::string ȡȺ��Ƭ(std::int64_t ���QQ, std::int64_t Ⱥ��, std::int64_t Ⱥ��ԱQQ);
	std::string ȡ����ǩ��(std::int64_t ���QQ, std::int64_t �Է�QQ);
	bool �޸��ǳ�(std::int64_t ���QQ, std::string �ǳ�);
	bool �޸ĸ���ǩ��(std::int64_t ���QQ, std::string ǩ��, std::string ǩ���ص�);
	bool ɾ��Ⱥ��Ա(std::int64_t ���QQ, std::int64_t Ⱥ��, std::int64_t Ⱥ��ԱQQ, bool �ܾ���Ⱥ����);
	bool ����Ⱥ��Ա(std::int64_t ���QQ, std::int64_t Ⱥ��, std::int64_t Ⱥ��ԱQQ, std::int32_t ����ʱ��);
	bool ��Ⱥ(std::int64_t ���QQ, std::int64_t Ⱥ��);
	bool ��ɢȺ(std::int64_t ���QQ, std::int64_t Ⱥ��);
	bool �ϴ�Ⱥͷ��(std::int64_t ���QQ, std::int64_t Ⱥ��, const std::int8_t* pic);
	bool ȫԱ����(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ���);
	bool ȺȨ��_�����µ�Ⱥ��(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_������ʱ�Ự(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_�ϴ��ļ�(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_�ϴ����(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_������Ѽ�Ⱥ(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_��������(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_̹��˵(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_�³�Ա�鿴��ʷ��Ϣ(std::int64_t ���QQ, std::int64_t Ⱥ��, bool �Ƿ�����);
	bool ȺȨ��_���뷽ʽ����(std::int64_t ���QQ, std::int64_t Ⱥ��, ��˷�ʽ ��ʽ);
	bool ������Ϣ_Ⱥ��(std::int64_t ���QQ, std::int64_t Ⱥ��, std::int64_t Random, std::int32_t Req);
	bool ������Ϣ_˽�ı���(std::int64_t ���QQ, std::int64_t �Է�QQ, std::int64_t Random, std::int32_t Req, std::int32_t ��Ϣ����ʱ��);
	bool ����λ�ù���(std::int64_t ���QQ, std::int64_t Ⱥ��, double ����, double γ��, bool �Ƿ���);
	bool �ϱ���ǰλ��(std::int64_t ���QQ, std::int64_t Ⱥ��, double ����, double γ��);
	std::int64_t �Ƿ񱻽���(std::int64_t ���QQ, std::int64_t Ⱥ��);
	void ����Ⱥ��֤�¼�(std::int64_t ���QQ, std::int64_t ��ԴȺ��, std::int64_t ����QQ, std::int64_t ��ϢSeq, �������� ����, Ⱥ�¼� �¼�����, std::string �ܾ�����);
	void ����Ⱥ��֤�¼�(std::int64_t ���QQ, std::int64_t ����QQ, std::int64_t ��ϢSeq, �������� ����);
	void �鿴ת�������¼����(std::int64_t ���QQ, std::string resId, Ⱥ��Ϣ���� ��Ϣ����);
	std::string �ϴ�Ⱥ�ļ�(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�·��, std::string �ļ�����);
	std::string ����Ⱥ�ļ���(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�����);
	std::string ������Ⱥ�ļ���(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string ���ļ�����, std::string ���ļ�����);
	std::string ɾ��Ⱥ�ļ���(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�����);
	std::string ɾ��Ⱥ�ļ�(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�fileid, std::string �ļ�����);
	std::string �����ļ���΢��(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�fileid);
	std::string �ƶ�Ⱥ�ļ�(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�fileid, std::string ��ǰ�ļ�����, std::string Ŀ���ļ�����);
	std::string ȡȺ�ļ��б�(std::int64_t ���QQ, std::int64_t Ⱥ��, std::string �ļ�����, std::vector<Ⱥ�ļ���Ϣ>& ����);
	bool ��������״̬(std::int64_t ���QQ, ����״̬ main, ����״̬V2 sun, std::int32_t ����);
	std::string ȡ�������Ŀ¼();
	std::string QQ����(std::int64_t ���QQ, std::int64_t �Է�QQ);
	std::string ȡͼƬ���ص�ַ(std::string ͼƬ����, std::int64_t ���QQ, std::int64_t Ⱥ��);
	bool ��ѯ������Ϣ(std::int64_t ���QQ, std::int64_t �Է�QQ, ������Ϣ& ����);
	bool ��ѯȺ��Ϣ(std::int64_t ���QQ, std::int64_t Ⱥ��, Ⱥ��Ƭ��Ϣ& ����);
	void �������();
	bool Ⱥ�ļ�ת����Ⱥ(std::int64_t ���QQ, std::int64_t ��ԴȺ��, std::int64_t Ŀ��Ⱥ��, std::string fileId);
	bool Ⱥ�ļ�ת��������(std::int64_t ���QQ, std::int64_t ��ԴȺ��, std::int64_t Ŀ��QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time);
	bool �����ļ�ת��������(std::int64_t ���QQ, std::int64_t Ŀ��QQ, std::string fileId, std::string filename, std::int64_t filesize, std::int32_t& Req, std::int64_t& Random, std::int32_t& time);
	bool ��Ⱥ��Ϣ����(std::int64_t ���QQ, std::int64_t Ⱥ��, �������� ��������);
	std::string ȡ��������״̬(std::int64_t ���QQ, std::int64_t �Է�QQ);
	std::string ȡQQǮ��������Ϣ(std::int64_t ���QQ, QQǮ����Ϣ& ����);
	std::string ��ȡ��������(std::int64_t ���QQ, std::string ������, ��������& ����);
	std::string �ύ֧����֤��(std::int64_t ���QQ, ��֤����Ϣ& ��Ϣ, std::string ��֤��, std::string ֧������);
	bool ��������(std::int64_t ���QQ, std::int64_t �������, std::string ������, std::string ������, std::string ��ת��ַ, std::string �����ַ, std::string �ļ���ַ, ����Ӧ������ Ӧ������, ���ַ������� ��������);
	bool ����Ⱥ����Ϣ����(std::int32_t ����ָ��, std::string ����Ϣ����);
	bool ����˽����Ϣ����(std::int32_t ����ָ��, std::string ����Ϣ����);

	const std::int8_t* silk����(std::string ��Ƶ�ļ�·��);
	const std::int8_t* silk����(std::string ��Ƶ�ļ�·��);
	const std::int8_t* amr����(std::string ��Ƶ�ļ�·��);
private:
	std::string pluginkey;
	nlohmann::json apidata;
protected:
	const char* SDK�汾 = "CSDK 1.0";
	 std::int32_t ȡAPI������ַ(std::string ������);
}static SDK;