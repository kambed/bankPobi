#include "model/TurboLogger.h"
#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "typedefs.h"
#include <memory>
#include <fstream>
#include "functions.h"

BOOST_AUTO_TEST_SUITE(TestSuiteTurboLogger)
    BOOST_AUTO_TEST_CASE(TurboLoggerConstructorTest) {
        TurboLoggerPtr tl = std::make_shared<TurboLogger>();
        std::ifstream logs;
        logs.open(tl->getFileName(), std::ifstream::in | std::ifstream::app);
        std::string lineContent;
        if (logs.is_open()) {
            std::getline(logs, lineContent);
            logs.close();
        }
        BOOST_CHECK_EQUAL(lineContent,"Logs file, created at: " + nowString());
    }

    BOOST_AUTO_TEST_CASE(TurboLoggerLogAddTestTest) {
        TurboLoggerPtr tl = std::make_shared<TurboLogger>();
        std::ifstream logs;
        logs.open(tl->getFileName(), std::ifstream::in | std::ifstream::app);
        int lines = 0;
        if (logs.is_open()) {
            std::string lineContent;
            for (; std::getline(logs, lineContent); lines++) {}
            logs.close();
        }
        BOOST_CHECK_EQUAL(tl->addLog("test"), true);
        logs.open(tl->getFileName(), std::ifstream::in | std::ifstream::app);
        int lines2 = 0;
        std::string lastNonEmptyLineContent;
        if (logs.is_open()) {
            std::string lineContent;
            for (; std::getline(logs, lineContent); lines2++) {
                if(lineContent!="")
                    lastNonEmptyLineContent=lineContent;
            }
            logs.close();
        }
        BOOST_CHECK_EQUAL(lines2,lines+1);
        BOOST_CHECK_EQUAL(lastNonEmptyLineContent,nowString()+"   test");
    }
BOOST_AUTO_TEST_SUITE_END()