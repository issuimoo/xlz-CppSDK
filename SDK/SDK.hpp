#include "Data_type.hpp"
#include "json/json.hpp"
#include "Text/Text.hpp"

class corn
{
public:
	void ��ʼ��(�ı��� _pluginkey, �ı��� _apidata);
	������ ȡAPI������ַ(�ı��� ������);
	�ı��� �����־(�ı��� ��־, ������ ������ɫ = 32768, ������ ������ɫ = 16777215);
private:
	�ı��� pluginkey;
	nlohmann::json apidata;
};