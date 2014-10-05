#include "testonline.h"

void TestOnline::run()
{
    list_comp.clear();
    QSqlQuery query(QSqlDatabase::database());
    query.exec("select device.name,device.inn,persona.fio,device.host,device.ip from device inner join persona on device.id_persona=persona.id");

    //qDebug()<<"Count Record="<<query.size();

    while (query.next())
    {
        Comp tmp;
        tmp.name=query.value(0).toString();
        tmp.inn=query.value(1).toString();
        tmp.fio=query.value(2).toString();
        tmp.host=query.value(3).toString();
        tmp.ip=query.value(4).toString();
        tmp.online=tmp.open_port=false;

        if (!tmp.host.isEmpty())
        {
            tmp.online=test_ping.PingHost(tmp.host);
            tmp.open_port=test_ping.isOpenPort(tmp.host);
        }else
        {
            if (!tmp.ip.isEmpty())
            {
                tmp.online=test_ping.PingHost(tmp.ip);
                tmp.open_port=test_ping.isOpenPort(tmp.ip);
            }
        }
        list_comp.append(tmp);
    }
}

QList<Comp>* TestOnline::GetList()
{
    return &list_comp;
}
