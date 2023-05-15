#include <set>
#include <memory>
using namespace std;

class AA
{
///
};

class BB : public AA
{
///
};

auto cmp = [](const AA* const& a, const AA* const& b) -> bool
{ return true; };

std::set<AA*, decltype(cmp)> s(cmp);

/////////////////////////////////////////////////////////////

class Vehicle
{
   friend struct cmp;
   int mId = -1;  // while it did not parked

public:
   struct cmp
   {
      bool operator() (const Vehicle* const &a, const Vehicle* const &b) const
      {
         return a->mId < b->mId;
      }

      bool operator() (const std::unique_ptr<Vehicle> &a, const std::unique_ptr<Vehicle> &b) const
      {
         return a->mId < b->mId;
      }
   };
};

int main()
{
    std::set <std::unique_ptr<Vehicle>, Vehicle::cmp> vehicles1;
    std::set <Vehicle*, Vehicle::cmp> vehicles2;

    return 0;
}
