#ifndef BANK_TURBOLOGGER_H
#define BANK_TURBOLOGGER_H

#include <fstream>

class TurboLogger {
private:
    std::string fileName;
    std::ofstream logs;
public:
    ///CONSTRUCTOR
    TurboLogger();

    ///GETTER

    /// \return string
    const std::string &getFileName() const;

    ///METHODS

    /// \param whatToLog
    /// \return bool
    bool addLog(std::string whatToLog);
};


#endif //BANK_TURBOLOGGER_H
