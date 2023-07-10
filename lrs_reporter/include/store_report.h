#pragma once

#include "mysql.h"
#include "lrs.pb.h"

class StoreReport
{
public:
    StoreReport();

    void store(lrs::ReportStatusRequest req);

private:
    MYSQL _db_conn;
};