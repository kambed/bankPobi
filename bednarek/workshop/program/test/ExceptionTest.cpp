#include <boost/test/unit_test.hpp>
#include <model/Bicycle.h>
#include <repositories/StorageContainer.h>
#include "model/Moped.h"
#include "model/Car.h"
#include "typedefs.h"
#include "exceptions/VehicleException.h"
#include "exceptions/ClientException.h"
#include "exceptions/RentException.h"
BOOST_AUTO_TEST_SUITE(Exceptions)

BOOST_AUTO_TEST_CASE(VehicleExceptionTest) {
    BOOST_CHECK_NO_THROW(BicyclePtr bicycleError = std::make_shared<Bicycle>("EL95353",100));
    BOOST_CHECK_THROW(BicyclePtr bicycleError = std::make_shared<Bicycle>("EL95353",0), VehicleException::exception);
    BOOST_CHECK_THROW(BicyclePtr bicycleError = std::make_shared<Bicycle>("",100), VehicleException::exception);
}
BOOST_AUTO_TEST_CASE(RentExceptionTest) {
    GoldPtr gold = std::make_shared<Gold>();
    AddressPtr address = std::make_shared<Address>("Lodz","Zielona","23");
    BicyclePtr bicycle = std::make_shared<Bicycle>("EL95353",100);
    ClientPtr client = std::make_shared<Client>("Anna","Nowak","98765432109",address,gold);
    BOOST_CHECK_NO_THROW(RentPtr rentError = std::make_shared<Rent>(1,client,bicycle,boost::posix_time::not_a_date_time,bicycle->getBasePrice()));
    BOOST_CHECK_THROW(RentPtr rentError = std::make_shared<Rent>(0,client,bicycle,boost::posix_time::not_a_date_time,bicycle->getBasePrice()),RentException::exception);
    BOOST_CHECK_THROW(RentPtr rentError = std::make_shared<Rent>(1,nullptr,bicycle,boost::posix_time::not_a_date_time,bicycle->getBasePrice()),RentException::exception);
    BOOST_CHECK_THROW(RentPtr rentError = std::make_shared<Rent>(1,client,nullptr,boost::posix_time::not_a_date_time,bicycle->getBasePrice()),RentException::exception);
}
BOOST_AUTO_TEST_CASE(ClientExceptionTest) {
    GoldPtr gold = std::make_shared<Gold>();
    AddressPtr address = std::make_shared<Address>("Lodz","Zielona","23");
    BOOST_CHECK_NO_THROW(ClientPtr clientError = std::make_shared<Client>("Anna","Nowak","98765432109",address,gold));
    BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("","Nowak","98765432109",address,gold), ClientException::exception);
    BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Anna","","98765432109",address,gold), ClientException::exception);
    BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Anna","Nowak","",address,gold), ClientException::exception);
    BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Anna","Nowak","98765432109",nullptr,gold), ClientException::exception);
    BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Anna","Nowak","98765432109",address,nullptr), ClientException::exception);
}
BOOST_AUTO_TEST_SUITE_END()

