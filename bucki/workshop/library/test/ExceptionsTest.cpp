#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include <memory>
#include "model/clients/Bronze.h"
#include "model/clients/Client.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "model/vehicles/Bicycle.h"
#include "typedefs.h"
#include "exceptions/VehicleException.h"
#include "exceptions/ClientException.h"
#include "exceptions/RentException.h"
BOOST_AUTO_TEST_SUITE(ExceptionsTest)

    BOOST_AUTO_TEST_CASE(ClientExceptionTest) {
        ClientTypePtr gold = std::make_shared<Bronze>();
        AddressPtr address = std::make_shared<Address>("Lodz", "Politechniki", "38");
        BOOST_CHECK_NO_THROW(ClientPtr clientError = std::make_shared<Client>("Jan", "Kowalski", "12345678900",address,gold));
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("","Kowalski", "12345678900",address,gold), ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Jan","","12345678900",address,gold),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Jan","Kowalski","",address,gold),ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Jan", "Kowalski", "12345678900",nullptr,gold), ClientException::exception);
        BOOST_CHECK_THROW(ClientPtr clientError = std::make_shared<Client>("Jan", "Kowalski", "12345678900",address,nullptr), ClientException::exception);
    }
    
    BOOST_AUTO_TEST_CASE(VehicleExceptionTest) {
        BOOST_CHECK_NO_THROW(VehiclePtr vehicleError = std::make_shared<Bicycle>("AB1234",100));
        BOOST_CHECK_THROW(VehiclePtr vehicleError = std::make_shared<Bicycle>("AB1234",0), VehicleException::exception);
        BOOST_CHECK_THROW(VehiclePtr vehicleError = std::make_shared<Bicycle>("",100), VehicleException::exception);
    }
    
    BOOST_AUTO_TEST_CASE(RentExceptionTest) {
        ClientTypePtr bronze = std::make_shared<Bronze>();
        AddressPtr address = std::make_shared<Address>("Lodz", "Politechniki", "38");
        VehiclePtr bicycle = std::make_shared<Bicycle>("AB1234",100);
        ClientPtr client = std::make_shared<Client>("Jan", "Kowalski", "12345678900",address,bronze);
        boost::uuids::random_generator generator;
        BOOST_CHECK_NO_THROW(RentPtr rentError = std::make_shared<Rent>(generator(),client,bicycle,
                                                                        boost::posix_time::second_clock::local_time()));
        BOOST_CHECK_THROW(RentPtr rentError = std::make_shared<Rent>(generator(),nullptr,bicycle,
                                                                     boost::posix_time::second_clock::local_time()),RentException::exception);
        BOOST_CHECK_THROW(RentPtr rentError = std::make_shared<Rent>(generator(),client,nullptr,
                                                                     boost::posix_time::second_clock::local_time()),RentException::exception);
    }
    
BOOST_AUTO_TEST_SUITE_END()