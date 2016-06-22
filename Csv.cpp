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
Description:读取csv文件
Input:fileName//读取文件名
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
Description:读取csv文件里的所有数据
Input:fileName//读取文件名
Output:data//按行读取数据并存入Vector
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
Description:解析数据
Input:data//被解析数据
Output:null
Return:void
Others:将解析后数据插入成员变量m_data
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
Description:分割数据
Input:data//被分割数据
	  split//分割符
Output:subData//被分割后的数据
Return:void
Others:将解析后数据插入成员变量m_data
*************************************************/
void Csv::Sqlite(const QString &data, const QString &split, QVector<QString> &subData)
{
	subData.clear();
	QStringList strList = data.split(split);
	subData = strList.toVector();
}

/************************************************* 
Function:getData
Description:获取解析后数据
Input:null
Output:null
Return:void
Others:所有解析后数据存储在二维Vector中
*************************************************/
QVector<QVector<QString>> Csv::getData()
{
	return m_data;
}