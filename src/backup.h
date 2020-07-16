#pragma once

class backup
{
private:
    const char* PATH_BACKUP = "../datos/backup.dat";
public:
    backup();
    ~backup();
    bool crearBackup ();
};



backup::backup()
{

}

backup::~backup()
{

}
