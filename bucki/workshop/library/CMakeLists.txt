cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/clients/Client.cpp
        include/model/clients/Client.h
        src/model/Address.cpp
        include/model/Address.h
        src/model/vehicles/Vehicle.cpp
        include/model/vehicles/Vehicle.h
        src/model/Rent.cpp
        include/model/Rent.h
        include/typedefs.h
        src/repositories/ClientRepository.cpp
        include/repositories/ClientRepository.h
        src/repositories/VehicleRepository.cpp
        include/repositories/VehicleRepository.h
        src/repositories/RentRepository.cpp
        include/repositories/RentRepository.h
        src/repositories/StorageContainer.cpp
        include/repositories/StorageContainer.h
        src/model/vehicles/Bicycle.cpp
        include/model/vehicles/Bicycle.h
        src/model/vehicles/MotorVehicle.cpp
        include/model/vehicles/MotorVehicle.h
        src/model/vehicles/Moped.cpp
        include/model/vehicles/Moped.h
        src/model/vehicles/Car.cpp
        include/model/vehicles/Car.h src/model/clients/ClientType.cpp include/model/clients/ClientType.h src/model/clients/Default.cpp include/model/clients/Default.h src/model/clients/Bronze.cpp include/model/clients/Bronze.h src/model/clients/Silver.cpp include/model/clients/Silver.h src/model/clients/Gold.cpp include/model/clients/Gold.h src/model/clients/Platinum.cpp include/model/clients/Platinum.h src/model/clients/Diamond.cpp include/model/clients/Diamond.h src/model/managers/ClientManager.cpp include/model/managers/ClientManager.h src/model/managers/LogicContainer.cpp include/model/managers/LogicContainer.h src/model/managers/VehicleManager.cpp include/model/managers/VehicleManager.h src/model/managers/RentManager.cpp include/model/managers/RentManager.h src/exceptions/ClientException.cpp include/exceptions/ClientException.h src/exceptions/VehicleException.cpp include/exceptions/VehicleException.h src/exceptions/RentException.cpp include/exceptions/RentException.h include/repositories/Repository.h)
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
        test/ClientTest.cpp
        test/AddressTest.cpp
        test/VehicleTest.cpp
        test/RentTest.cpp
        test/RepositoriesTest.cpp
        test/VehiclePricesTest.cpp
        test/ClientManagerTest.cpp test/VehicleManagerTest.cpp test/RentManagerTest.cpp test/ExceptionsTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

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