/*
 * ���� �̸� : main.cpp
 * ���� ��¥ : 2017-07-25
 * ���� ��� : Ruvendix
 *
 * ���� ���� : IOManger�� ���� �κ��Դϴ�.
 */

#include "IOManager.h"

namespace mgr
{
	// static �ʵ带 �ʱ�ȭ�ϴ� ���
	std::string IOManager::m_strLastFileName = "NoFileName";

	// static �޼���� �׳� �Ϲ� �޼���ó�� �����ص� ��
	int IOManager::AppendStringToFile(const std::string& strFileName, const std::string& strText)
	{
		FILE* pFile = fopen(strFileName.c_str(), "at");
		assert(pFile != nullptr);

		if (pFile == nullptr) perror("���� ��Ʈ�� ���� ����!");

		fprintf(pFile, "%s\n", strText.c_str());

		fclose(pFile);

		m_strLastFileName = strFileName;

		return 0;
	}
}