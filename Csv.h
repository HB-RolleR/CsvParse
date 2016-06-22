/************************************************* 
*@Brief:CsvParse
*@Author:RolleR
*@Version:1.0
*@Date:20160621
*************************************************/

#ifndef CSV_H
#define CSV_H

#include <QObject>
#include <QVector>

class Csv : public QObject
{
	Q_OBJECT

public:
	Csv(QObject *parent = 0);
	~Csv();

	//读取csv文件
	void Load(const QString &fileName);
	
	//解析数据
	void Parse(const QVector<QString> &data);
	
	//读取csv文件 并把所有数据存入Vector
	void ReadAll(const QString &fileName, QVector<QString> &data);
	
	//通过分隔符截取数据
	void Sqlite(const QString &data, const QString &split, QVector<QString> &subData);
	
	//读取存储数据的二维Vector
	QVector<QVector<QString>> getData();
private:
	QVector<QVector<QString>> m_data;
};

#endif // CSV_H
