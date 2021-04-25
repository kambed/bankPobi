cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/Clients/Client.cpp
        include/model/Clients/Client.h
        src/model/Address.cpp
        include/model/Address.h
        src/model/Vehicles/Vehicle.cpp
        include/model/Vehicles/Vehicle.h
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
        src/model/Vehicles/Bicycle.cpp
        include/model/Vehicles/Bicycle.h
        src/model/Vehicles/MotorVehicle.cpp
        include/model/Vehicles/MotorVehicle.h
        src/model/Vehicles/Moped.cpp
        include/model/Vehicles/Moped.h
        src/model/Vehicles/Car.cpp
        include/model/Vehicles/Car.h src/model/Clients/ClientType.cpp include/model/Clients/ClientType.h src/model/Clients/Default.cpp include/model/Clients/Default.h src/model/Clients/Bronze.cpp include/model/Clients/Bronze.h src/model/Clients/Silver.cpp include/model/Clients/Silver.h src/model/Clients/Gold.cpp include/model/Clients/Gold.h src/model/Clients/Platinum.cpp include/model/Clients/Platinum.h src/model/Clients/Diamond.cpp include/model/Clients/Diamond.h)
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