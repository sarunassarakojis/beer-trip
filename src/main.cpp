#include <iostream>
#include <sqlite3.h>

int callback(void* unused, int argc, char** argv, char** column_name) {
    for (auto i = 0; i < argc; ++i) {
        printf("%s = %s; ", column_name[i], argv[i]);
    }
    printf("\n");

    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3* db_handle;
    int status = sqlite3_open("beer.db", &db_handle);
    char* error_message;

    printf("VER: %s, status: %d\n", SQLITE_VERSION, status);

    if (status != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db_handle));
        return 1;
    }

    status = sqlite3_exec(db_handle, "SELECT * FROM Stuff", callback, 0, &error_message);

    if (status != SQLITE_OK) {
        fprintf(stderr, "Error: %s\n", error_message);
        sqlite3_free(error_message);
    }

    sqlite3_close(db_handle);
}
