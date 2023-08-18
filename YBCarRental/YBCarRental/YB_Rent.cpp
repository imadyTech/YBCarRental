#include "YB_DataBasis.h"
#include "YB_Rent.h"
#include "YB_User.h"
#include "YB_Car.h"

#include <string>
using namespace std;


namespace YBCarRental
{
    YB_Rent::YB_Rent()
    {
    }
    YB_Rent::YB_Rent(YB_User user, YB_Car car, tm start, int days)
    {
    }
    YB_Rent::YB_Rent(int userId, int carId, tm start, int days)
    {
    }
    std::string YB_Rent::Serialize()
    {
        return std::string();
    }

    void YB_Rent::Deserialize(std::string line)
    {
    }

}


