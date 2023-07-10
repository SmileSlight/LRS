#include "lrs_reactor.h"
#include "lrs.pb.h"
#include "store_report.h"
#include <string>

void get_report_status(const char *data, uint32_t len, int msgid, net_connection *conn, void *user_data)
{
    lrs::ReportStatusRequest req;

    req.ParseFromArray(data, len);

    //将上报数据存储到db 
    StoreReport sr;
    sr.store(req);
}

int main(int argc, char **argv)
{
    event_loop loop;

    //加载配置文件
    config_file::setPath("./conf/lrs_reporter.conf");
    std::string ip = config_file::instance()->GetString("reactor", "ip", "0.0.0.0");
    short port = config_file::instance()->GetNumber("reactor", "port", 7779);

    //创建tcp server
    tcp_server server(&loop, ip.c_str(), port);

    //添加数据上报请求处理的消息分发处理业务
    server.add_msg_router(lrs::ID_ReportStatusRequest, get_report_status);
  
    //启动事件监听
    loop.event_process(); 

    return 0;
}