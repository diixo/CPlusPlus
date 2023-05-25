
// shared_ptr-examples.cpp
// The following examples assume these declarations:
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

int main()
{
    // The examples go here, in order:
    // Example 1
    // Example 2
    // Example 3
    // Example 4
    // Example 6
}

////////////////////////////////////////////////////////////////////

vector<shared_ptr<Song>> v {
  make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
  make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
  make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")
};

void example_3()
{
    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s) 
    {
        return s->artist.compare(L"Bob Dylan") == 0;
    });

    for (const auto& s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }
}

//////////////////////////////////////////////////////////////////

vector<shared_ptr<MediaAsset>> assets {
  make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
  make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
  make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
};

void example_4()
{
    vector<shared_ptr<MediaAsset>> photos;

    copy_if(assets.begin(), assets.end(), back_inserter(photos), [] (shared_ptr<MediaAsset> p) -> bool
    {
        // Use dynamic_pointer_cast to test whether
        // element is a shared_ptr<Photo>.
        shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
        return temp.get() != nullptr;
    });

    for (const auto&  p : photos)
    {
        // We know that the photos vector contains only 
        // shared_ptr<Photo> objects, so use static_cast.
        wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
    }
}

//////////////////////////////////////////////////////////////////

