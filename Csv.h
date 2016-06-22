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

	//��ȡcsv�ļ�
	void Load(const QString &fileName);
	
	//��������
	void Parse(const QVector<QString> &data);
	
	//��ȡcsv�ļ� �����������ݴ���Vector
	void ReadAll(const QString &fileName, QVector<QString> &data);
	
	//ͨ���ָ�����ȡ����
	void Sqlite(const QString &data, const QString &split, QVector<QString> &subData);
	
	//��ȡ�洢���ݵĶ�άVector
	QVector<QVector<QString>> getData();
private:
	QVector<QVector<QString>> m_data;
};

#endif // CSV_H
