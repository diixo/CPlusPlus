
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Song;
class ClassFactory;

/////////////// Example-1 ///////////////
unique_ptr<Song> Factory(const std::wstring& artist, const std::wstring& title)
{
    // Implicit move operation into the variable that stores the result.
    return make_unique<Song>(artist, title);
}

void MakeSongs()
{
    // Create a new unique_ptr with a new object.
    auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

    // Move raw pointer from one unique_ptr to another.
    unique_ptr<Song> song2 = std::move(song);

    // Obtain unique_ptr from function that returns by value.
    auto song3 = Factory(L"Michael Jackson", L"Beat It");
}

/////////////// Example-2 /////////////
void SongVector()
{
    vector<unique_ptr<Song>> songs;
    
    // Create a few new unique_ptr<Song> instances
    // and add them to vector using implicit move semantics.
    songs.push_back(make_unique<Song>(L"B'z", L"Juice")); 
    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town")); 
    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de")); 
    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));

    // Pass by const reference when possible to avoid copying.
    for (const auto& song : songs)
    {
        //...
    }    
}


/////////////// Example-4 /////////////
class MyClass
{
private:
    // MyClass owns the unique_ptr.
    unique_ptr<ClassFactory> factory;
public:

    // Initialize by using make_unique with ClassFactory default constructor.
    MyClass() : factory (make_unique<ClassFactory>())
    {
    }
};

/////////// Example-6 /////////
void makeSome()
{
    auto p = make_unique<int[]>(5);

    // Initialize the array.
    for (int i = 0; i < 5; ++i)
    {
        p[i] = i;
        //wcout << p[i] << endl;
    }
}
