cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h
        include/Bank.h
        src/Bank.cpp
        src/Account.cpp
        include/Account.h
        src/SavingsAccount.cpp
        include/SavingsAccount.h
        src/CurrentAccount.cpp
        include/CurrentAccount.h
        src/Client.cpp
        include/Client.h
        src/Interest.cpp
        include/Interest.h
        src/Transaction.cpp
        include/Transaction.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/AccountRepository.cpp include/repositories/AccountRepository.h src/managers/AccountMenager.cpp include/managers/AccountMenager.h src/managers/ClientManager.cpp include/managers/ClientManager.h)
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
        test/master.cpp
        test/AccountsTest.cpp
        test/ClientsTest.cpp
        test/TransactionsTests.cpp
        test/InterestTest.cpp
        test/RepositoriesTest.cpp
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