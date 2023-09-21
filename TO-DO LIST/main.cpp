#include <iostream>
#include<bits/stdc++.h>
#include "sqlite-amalgamation-3430100/sqlite3.h"
using namespace std;
void task_input(int& rc, sqlite3* db, int& id) {
    string taskName, taskStatus;
    cin.ignore();
    cout << "Enter task name: ";
    getline(cin, taskName);
    int ch;
    cout << "Enter task status (1 for Done, 2 for Not Done): ";
    while (cin >> ch) {
        if (ch == 1) {
            taskStatus = "Done";
            break;
        } else if (ch == 2) {
            taskStatus = "Not Done";
            break;
        } else {
            cout << "Invalid input. Enter 1 for Done or 2 for Not Done: ";
        }
    }
    string insertSQL = "INSERT INTO MyTable (ID, \"Task_Name\", \"Task_Status\") VALUES (?, ?, ?);";

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return;
    }

    id++;

    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, taskName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, taskStatus.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stdout, "Task added successfully\n");
    }

    sqlite3_finalize(stmt);
}
void View_Tasks(int& rc, sqlite3* db) {
    const char* selectSQL = "SELECT ID, \"Task_Name\", \"Task_Status\" FROM MyTable;";

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return;
    }
    printf("\nList of Tasks:\n");
    printf("ID\tTask Name\tTask Status\n");
    // Loop to fetch and print tasks
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int taskId = sqlite3_column_int(stmt, 0);
        const char* taskName = (const char*)sqlite3_column_text(stmt, 1);
        const char* taskStatus = (const char*)sqlite3_column_text(stmt, 2);
        printf("%d\t%s\t\t%s\n", taskId, taskName, taskStatus);
    }
    sqlite3_finalize(stmt);
}
void Mark_Task_As_Completed(int& rc, sqlite3* db) {
    int taskId;
    cout << "Enter the ID of the task you want to mark as completed: ";
    cin >> taskId;

    const char* selectSQL = "SELECT ID FROM MyTable WHERE ID = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_int(stmt, 1, taskId);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* updateSQL = "UPDATE MyTable SET \"Task_Status\" = 'Done' WHERE ID = ?;";
        sqlite3_stmt* updateStmt;
        rc = sqlite3_prepare_v2(db, updateSQL, -1, &updateStmt, NULL);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            return;
        }

        sqlite3_bind_int(updateStmt, 1, taskId);

        rc = sqlite3_step(updateStmt);

        if (rc != SQLITE_DONE) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        } else {
            fprintf(stdout, "Task marked as completed\n");
        }

        sqlite3_finalize(updateStmt);
    } else {
        fprintf(stderr, "Task with ID %d not found\n", taskId);
    }

    sqlite3_finalize(stmt);
}
void Remove_Task_By_ID(int& rc, sqlite3* db) {
    int taskId;
    cout << "Enter the ID of the task you want to remove: ";
    cin >> taskId;

    // Check if the task ID exists in the database
    const char* selectSQL = "SELECT ID FROM MyTable WHERE ID = ?;";
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, selectSQL, -1, &stmt, NULL);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_int(stmt, 1, taskId);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        // Task ID exists, delete the task
        const char* deleteSQL = "DELETE FROM MyTable WHERE ID = ?;";
        sqlite3_stmt* deleteStmt;
        rc = sqlite3_prepare_v2(db, deleteSQL, -1, &deleteStmt, NULL);

        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
            return;
        }

        sqlite3_bind_int(deleteStmt, 1, taskId);

        rc = sqlite3_step(deleteStmt);

        if (rc != SQLITE_DONE) {
            fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
        } else {
            fprintf(stdout, "Task with ID %d removed successfully\n", taskId);
        }

        sqlite3_finalize(deleteStmt);
    } else {
        fprintf(stderr, "Task with ID %d not found\n", taskId);
    }

    sqlite3_finalize(stmt);
}
int main() {
    static int id = 7 ;
    sqlite3* db;
    int rc;
    rc= sqlite3_open("Db.bb",&db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS MyTable ("
                                 "ID INT PRIMARY KEY NOT NULL,"
                                 "Task_Name TEXT NOT NULL ,""Task_Status TEXT  NULL);";
    rc = sqlite3_exec(db, createTableSQL, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
    int choice ;
    cout <<"welcome to our to do list \n";
    cout <<"if you want to add task press 1 \n";
    cout <<"if you want to view tasks press 2 \n";
    cout <<"if you want to delete task press 3 \n";
    cout <<"do you want to mark a task as competed ? press 4 \n";
    cout <<"To exit press 5 \n" ;
    while (cin>>choice)
    {
        if (choice==1)
        {
            id ++;
            task_input(rc,db,id);
        }
        else if (choice==2)
        {
            View_Tasks(rc, db);
        }
        else if (choice==3)
        {

            View_Tasks(rc, db);
            Remove_Task_By_ID( rc,  db);
        }
        else if (choice==4)
        {
            View_Tasks(rc, db);
            Mark_Task_As_Completed( rc,  db);
        }
        else if (choice==5)
        {
            return 0;
            break;
        }
        cout <<"welcome to our to do list \n";
        cout <<"if you want to add task press 1 \n";
        cout <<"if you want to view tasks press 2 \n";
        cout <<"if you want to delete task press 3 \n";
        cout <<"do you want to mark a task as competed ? press 4 \n";
        cout <<"To exit press 5 \n" ;
    }
    return 0;
}
