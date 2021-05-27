#include "model/TurboLogger.h"
#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "typedefs.h"
#include <memory>
#include <fstream>

BOOST_AUTO_TEST_SUITE(TestSuiteTurboLogger)
    BOOST_AUTO_TEST_CASE(TurboLoggerLogAddTestTest) {
        TurboLoggerPtr tl = std::make_shared<TurboLogger>();
        std::ifstream logs;
        logs.open("logs.txt", std::ifstream::in | std::ifstream::app);
        int lines = 0;
        if (logs.is_open()) {
            std::string lineContent;
            for (; std::getline(logs, lineContent); lines++) {}
            logs.close();
        }
        BOOST_CHECK_EQUAL(tl->addLog("test"), true);
        logs.open("logs.txt", std::ifstream::in | std::ifstream::app);
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
        std::stringstream ss;
        ss << boost::posix_time::second_clock::local_time();
        std::string now= ss.str();
        std::string log = now+"   test";
        BOOST_CHECK_EQUAL(lastNonEmptyLineContent,log);
    }
BOOST_AUTO_TEST_SUITE_END()