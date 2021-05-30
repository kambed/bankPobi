cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h
        include/model/Bank.h
        src/model/Bank.cpp
        src/model/Account.cpp
        include/model/Account.h
        src/model/SavingsAccount.cpp
        include/model/SavingsAccount.h
        src/model/CurrentAccount.cpp
        include/model/CurrentAccount.h
        src/model/Client.cpp
        include/model/Client.h
        src/model/Interest.cpp
        include/model/Interest.h
        src/model/Transaction.cpp
        include/model/Transaction.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/AccountRepository.cpp
        include/repositories/AccountRepository.h
        src/managers/AccountManager.cpp
        include/managers/AccountManager.h
        src/managers/ClientManager.cpp
        include/managers/ClientManager.h
        src/repositories/TransactionRepository.cpp
        include/repositories/TransactionRepository.h
        src/managers/TransactionManager.cpp
        include/managers/TransactionManager.h
        src/model/TurboLogger.cpp
        include/model/TurboLogger.h
        include/functions.h
        src/functions.cpp

        )
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

#Włączenie testów powoduje pojawienie się celu test w makefiles
enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        ../program/test/master.cpp
        ../program/test/AccountsTest.cpp
        ../program/test/ClientsTest.cpp
        ../program/test/TransactionsTests.cpp
        ../program/test/InterestTest.cpp
        ../program/test/RepositoriesTest.cpp
        ../program/test/ManagersTests.cpp
        ../program/test/TurboLoggersTest.cpp

        ) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
#Aby raport testów był szczegółowo wypisany na konsolę, można dodać własny cel budowy o nazwie np. check (make check) w postaci:

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})