#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; i++)
        cout << azColName[i] << " : " << argv[i] << endl;
    cout << endl;

    return 0;
}

int main() {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    rc = sqlite3_open("my.db", &db);

    if(rc)
        cout<<"Connection error\n";
    else
        cout<<"Connection successful\n";
    
    string sql = "SELECT * FROM <table>;";

    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    cout<<endl;

    sql = "INSERT INTO contatto (<row>) VALUES ('" + value + "','" + value + "');";
    
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    
    if(rc)
        cout<<"Query error\n";
    else
        cout<<"\nDone\n\n";

    return 0;
}