#include "Csv.h"
#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QIODevice>

Csv::Csv(QObject *parent)
	: QObject(parent)
{

}

Csv::~Csv()
{

}

/************************************************* 
Function:Load
Description:��ȡcsv�ļ�
Input:fileName//��ȡ�ļ���
Output:null
Return:void
Others:null
*************************************************/
void Csv::Load(const QString &fileName)
{
	QFile file(fileName);
	if (!file.exists()) return;
	
	QVector<QString> data;
	ReadAll(fileName, data);
	Parse(data);
}

/************************************************* 
Function:ReadAll
Description:��ȡcsv�ļ������������
Input:fileName//��ȡ�ļ���
Output:data//���ж�ȡ���ݲ�����Vector
Return:void
Others:null
*************************************************/
void Csv::ReadAll(const QString &fileName, QVector<QString> &data)
{
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text | QIODevice::Truncate))
		return;

	QTextStream stream(&file);

	while (!stream.atEnd())
	{
		data.push_back(stream.readLine());
	}
	
	file.close();
}

/************************************************* 
Function:Parse
Description:��������
Input:data//����������
Output:null
Return:void
Others:�����������ݲ����Ա����m_data
*************************************************/
void Csv::Parse(const QVector<QString> &data)
{
	m_data.clear();
	QVector<QString> subData;
	for (int i = 0; i < data.size(); ++i)
	{
		Sqlite(data[i], ",", subData);
		m_data.push_back(subData);
		subData.clear();
	}
}

/************************************************* 
Function:Sqlite
Description:�ָ�����
Input:data//���ָ�����
	  split//�ָ��
Output:subData//���ָ�������
Return:void
Others:�����������ݲ����Ա����m_data
*************************************************/
void Csv::Sqlite(const QString &data, const QString &split, QVector<QString> &subData)
{
	subData.clear();
	QStringList strList = data.split(split);
	subData = strList.toVector();
}

/************************************************* 
Function:getData
Description:��ȡ����������
Input:null
Output:null
Return:void
Others:���н��������ݴ洢�ڶ�άVector��
*************************************************/
QVector<QVector<QString>> Csv::getData()
{
	return m_data;
}