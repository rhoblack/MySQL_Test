#include <iostream>
#include <mysql.h>

#include <string.h>

int main(int argc, char **argv)
{
    MYSQL *conn, connection;
    MYSQL_RES *dbReturnValue;
    MYSQL_ROW dbRowData;

    const char DB_HOST[] = "10.10.30.21";
    const char DB_USER[] = "root";
    const char DB_PASS[] = "rkdgus!@34";
    const char DB_SCHEMA[] = "mydb";
    unsigned int DB_PORT = 3306;
    char sql[1024];
    char str1[1024], str2[1024], str3[1024];

    mysql_init(&connection);
    conn = mysql_real_connect(
                &connection, 
                DB_HOST, 
                DB_USER, 
                DB_PASS, 
                DB_SCHEMA, 
                DB_PORT, 
                (char *)NULL, 
                0
            );
    if (!conn)
    {
        std::cout << "Unable to connect to DB: " << mysql_error(conn) << std::endl;
        std::printf("%s\n", mysql_error(conn));
        exit(-1);
    }
    /*
       // INSERT / UPDATE / DELETE 쿼리
       strcpy(sql, "INSERT INTO test VALUES(1, 'test')");
       if(mysql_query(conn, sql) != 0){
           // 에러
       }
    */

    // SELECT 쿼리
    strcpy(sql, "SELECT * FROM members");
    if (mysql_query(conn, sql) == 0)
    {
        dbReturnValue = mysql_store_result(conn);
        while ((dbRowData = mysql_fetch_row(dbReturnValue)) != NULL)
        {
            strcpy(str1, dbRowData[0]);
            strcpy(str2, dbRowData[1]);
            strcpy(str3, dbRowData[2]);
            std::cout << str1 << str2 << str3 << std::endl;
        }
        mysql_free_result(dbReturnValue);
    }
    else
    {
        std::cout << "error SELECT" << std::endl;
    }

    mysql_close(conn);

    return 0;
}
