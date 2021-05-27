#ifndef BANK_TURBOLOGGER_H
#define BANK_TURBOLOGGER_H


#include <string>

class TurboLogger {
public:
    ///CONSTRUCTOR
    TurboLogger();
    ///METHODS
    bool addLog(std::string whatToLog);
};


#endif //BANK_TURBOLOGGER_H
