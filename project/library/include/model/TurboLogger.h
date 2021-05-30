#ifndef BANK_TURBOLOGGER_H
#define BANK_TURBOLOGGER_H


#include <string>
#include <fstream>

class TurboLogger {
private:
    std::string fileName;
    std::ofstream logs;

public:
    ///CONSTRUCTOR
    TurboLogger();
    ///DESTRUCTOR

    ///GETTER
    const std::string &getFileName() const;
    ///METHODS
    bool addLog(std::string whatToLog);
};


#endif //BANK_TURBOLOGGER_H
